// Problem: 
//     P1637 三元上升子序列
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1637


#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct Node{
    int l , r , v;
}tr[N << 2] ;
int a[N];

void pushup(int u) {
    tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
}

void build(int u , int l , int r) {
    tr[u] = {l , r , 0} ;
    if(l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(u << 1 , l , mid) ;
    build(u << 1 | 1 , mid + 1 , r);
}

void modify(int u ,int x) {
    if(tr[u].l == tr[u].r) {
        tr[u].v ++ ;
        return;
    }
    
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= x) {
        modify(u << 1 , x);
    } else {
        modify(u << 1 | 1 ,x);
    }
    pushup(u);
}

int query(int u , int l , int r) {
    if(l > r) return 0;
    if(tr[u].l >= l && tr[u].r <= r) {
        return tr[u].v;
    }
    
    int res = 0 , mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l) {
        res += query(u << 1 , l , r);
    } 
    if(r > mid) {
        res += query(u << 1 | 1 , l , r);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    build(1 , 1 , 1e5);
    vector<int>down(n + 1 ) , up(n + 1);
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];       
        down[i] = query(1 , 1 , a[i] - 1) ;
        modify(1 , a[i]);
    }
    
    build(1 , 1 , 1e5);
    for(int i = n ; i >= 1 ; i -- ) {
        up[i] = query(1 , a[i] + 1 , 1e5);
        modify(1 , a[i]);
    }
    
    long long ans = 0;
    for(int i = 2 ; i <= n - 1 ; i ++ ) {
        ans += 1ll * down[i] * up[i];
    }
    
    cout << ans << "\n";
    
    return 0;
}