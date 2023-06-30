// Problem: 
//     P1438 无聊的数列
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1438


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 1e5 + 10;

struct Node{
    int l , r ;
    LL sum , lz;
}tr[N << 2];
int a[N] , n , m;

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(Node &u , Node &l , Node &r) {
    l.lz += u.lz , r.lz += u.lz;
    l.sum += (l.r - l.l + 1) * u.lz ;
    r.sum += (r.r - r.l + 1) * u.lz ;
    u.lz = 0;
}

void pushdown(int u) {
    pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
}

void build(int u , int l , int r) {
    tr[u] = {l , r};
    if(l == r) {
        tr[u].sum = a[l] - a[l - 1];
        return;
    }
    
    int mid = l + r >> 1;
    build(u << 1 , l , mid) , build(u << 1 | 1 , mid + 1 , r);
    pushup(u);
}

void modify(int u ,int l , int r , int x) {
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += x * (tr[u].r - tr[u].l + 1);
        tr[u].lz += x;
        return ;
    }
    
    pushdown(u);
    
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l)modify(u << 1 , l , r , x);
    if(r > mid) modify(u << 1 | 1 , l , r , x);
    pushup(u);
}

LL query(int u , int l , int r) {
    if(tr[u].l >= l && tr[u].r <= r) {
        return tr[u].sum;
    }
    pushdown(u);
    
    int res = 0 , mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l)res += query(u << 1 , l , r );
    if(r > mid)res += query(u << 1 | 1 , l , r);
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
    }
    build(1 , 1 , n);
    while(m -- ) {
        int op ;
        cin >> op;
        if(op == 1) {
            int l , r , k , d;
            cin >> l >> r >> k >> d;
            modify(1 , l , l , k);
            if(l + 1 <= r) {
                modify(1 , l + 1 , r , d);
            }
            if(r + 1 <= n){
                modify(1 , r + 1 , r + 1 , - d * ( r - l) - k);
            }
        } else {
            int x;cin >> x;
            cout << query(1 , 1 , x) << "\n";
        }
    }
    
    return 0;
}