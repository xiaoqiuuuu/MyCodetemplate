// Problem: 第K小数
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/257/

#include<bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 2e5 + 10 ;

int n , m;
int v[N] , cnt;
struct Node{
    int l , r , v;//表示的是左右儿子
}tr[21 * N];
int root[N] , idx;

int id(int x) {
    return lower_bound(v + 1 , v + 1 + cnt , x) - v ;
}

int build(int l , int r) {
    int q = ++ idx;
    tr[q] = {l , r};
    if(l == r) {
        return q ;
    }
    int mid = l + r >> 1;
    tr[q].l = build(l , mid);
    tr[q].r = build(mid + 1 , r);
    return q;
}

int insert(int p , int l , int r , int x) {    
    int q = ++ idx;
    tr[q] = tr[p];
    if(l == r) {
        tr[q].v ++ ;
        return q;
    }
    int mid = l + r >> 1;
    if(x <= mid) {
        tr[q].l = insert(tr[p].l , l , mid , x);
    } else {
        tr[q].r = insert(tr[p].r , mid + 1 , r , x);
    }
    tr[q].v = tr[tr[q].l].v + tr[tr[q].r].v;
    return q;
}

int query(int q , int p , int l , int r , int k) {
    if(l == r) {
        return r;
    }
    int mid = l + r >> 1;
    int cnt = tr[tr[q].l].v - tr[tr[p].l].v;
    if(k <= cnt) {
        return query(tr[q].l , tr[p].l , l , mid , k);
    } else {
        return query(tr[q].r , tr[p].r , mid + 1 , r , k - cnt);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<int>a(n + 1);
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
        v[++cnt] = a[i];
    }
    sort(v + 1 , v + 1 + cnt);
    cnt = unique(v + 1 , v + n + 1) - v - 1;
    
    root[0] = build(1 , cnt);
    
    for(int i = 1 ; i <= n ; i ++ ) {
        root[i] = insert(root[i - 1] , 1 , cnt , id(a[i]));
    }
    
    while(m -- ) {
        int a , b , x;
        cin >> a >> b >> x;
        cout << v[query(root[b] , root[a - 1] , 1 ,  cnt , x)] << "\n";
    }
        
    return 0;
}