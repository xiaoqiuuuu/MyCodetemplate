// Problem: 
//     P1558 色板游戏
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1558


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 1e5 + 10;

struct Node{
    int l , r , v , lz;
}tr[N << 2];

void pushup(int u) {
    tr[u].v = tr[u << 1].v | tr[u << 1 | 1].v ;
}

void pushdown(int u) {
    if(tr[u].lz != -1) {
        tr[u << 1].v = tr[u << 1 | 1].v = tr[u].lz;
        tr[u << 1].lz = tr[u << 1 | 1].lz = tr[u].lz;
        tr[u].lz = -1;
    }
}

void build(int u , int l , int r) {
    tr[u] = {l , r , 1 , - 1};
    if(l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(u << 1 , l , mid) ;
    build(u << 1 | 1 , mid + 1 , r);
}

void modify(int u , int l , int r , int x) {
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].v = tr[u].lz = x;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l ) {
        modify(u << 1 , l , r , x);
    }
    if(r > mid) {
        modify(u << 1 | 1 , l , r , x);
    }
    pushup(u);
}

int query(int u , int l , int r ) {
    if(tr[u].l >= l && tr[u].r <= r) {
        return tr[u].v;
    }
    pushdown(u);
    int res = 0 , mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l) {
        res |= query(u << 1 , l , r );
    }
    if(r > mid) {
        res |= query(u << 1 | 1 , l , r);
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n , t , m;
    cin >> n >> t >> m;
    build(1 , 1 , n);
    while(m -- ) {
        string op ;
        int l , r , x ;
        cin >> op >> l >> r;
        if(l > r) {
            swap(l , r);
        }
        if(op == "C") {
            cin >> x;
            modify(1 , l , r , 1 << (x - 1));
        } else {
            cout << __builtin_popcount(query(1 , l , r)) << "\n";
        }
    }
    
    return 0;
}