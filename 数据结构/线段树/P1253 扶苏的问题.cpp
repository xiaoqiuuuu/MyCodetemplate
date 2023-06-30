// Problem: 
//     P1253 扶苏的问题
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1253


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 1e6 + 10 , INF = 0x3f3f3f3f;

struct Node{
    int l , r ;
    LL val , lz1 , lz2;
}tr[N << 2];
int n , m , a[N];

void pushup(Node &u , Node &l , Node &r) {
    u.val = max(l.val , r.val);
}
void pushup(int u ) {
    pushup(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
}
void pushdown(Node &u , Node &l , Node &r) {
    if(u.lz2 != INF) {
        l.val = r.val = u.lz2;
        l.lz2 = r.lz2 = u.lz2;
        l.lz1 = r.lz1 = 0;
        u.lz2 = INF;
    }
    if(u.lz1) {
        l.val += u.lz1;
        r.val += u.lz1;
        l.lz1 += u.lz1;
        r.lz1 += u.lz1;
        u.lz1 = 0;
    }
}

void pushdown(int u) {
    pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
}


void build(int u , int l , int r) {
    tr[u] = {l , r , 0 , 0 , INF};
    if(l == r) {
        tr[u].val = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1 , l , mid) ;
    build(u << 1 | 1 , mid + 1 , r);
    pushup(u);
}

void modify(int u ,int l , int r , int x , int op) {
    if(tr[u].l >= l && tr[u].r <= r) {
        if(op == 1) {
            tr[u].val = x;
            tr[u].lz2 = x;
            tr[u].lz1 = 0;
        } else {
            tr[u].val += x;
            tr[u].lz1 += x;
        }
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l)modify(u << 1 , l , r , x , op);
    if(r > mid)modify(u << 1 | 1 , l , r , x , op);
    pushup(u);
}

LL query(int u , int l ,int r) {
    if(tr[u].l >= l && tr[u].r <= r) {
        return tr[u].val;
    }
    pushdown(u);
    LL res = -1e18 , mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l)res = max(res , query(u << 1 , l ,r ));
    if(r > mid) res = max(res , query(u << 1 | 1 , l , r));
    return res;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
    int n , m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
    }
    build(1 , 1 , n);
    while(m -- ) {
        int op , l , r ;
        cin >> op >> l >> r;
        if(op != 3) {
            int x;cin >> x;
            modify(1 , l , r , x , op);
        } else {
            cout << query(1 , l , r) << "\n";
        }
    }
    
    return 0;
}