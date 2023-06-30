// Problem: 
//     P3870 [TJOI2009] 开关
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P3870


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 1e5 + 10;

struct Node{
    int l , r;
    int sum , lz;
}tr[N << 2];

void build(int u , int l , int r){
    tr[u] = {l , r , 0  , 0};
    if(l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(u << 1 , l , mid) , build(u << 1 | 1 , mid + 1 , r);
}

void pushup(int u ) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(Node &u , Node &l , Node & r) {
    if(u.lz) {
        l.sum = l.r - l.l + 1 - l.sum;
        r.sum = r.r - r.l + 1 - r.sum;
        u.lz = 0;l.lz ^= 1 , r.lz ^= 1;
    }
}

void pushdown(int u ) {
    pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
}

void modify(int u ,int l , int r) {
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum = tr[u].r - tr[u].l + 1 - tr[u].sum;
        tr[u].lz ^= 1;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l)modify(u << 1 , l , r);
    if(r > mid)modify(u << 1 | 1 , l , r);
    pushup(u);
}

int query(int u , int l , int r) {
    if(tr[u].l >= l && tr[u].r <= r) {
        return tr[u].sum;
    }
    
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    
    if(mid >= l)res += query(u << 1 , l , r );
    if(r > mid)res += query(u << 1 | 1 , l ,r);
    
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n , m;
    cin >> n >> m;
    
    build(1 , 1 , n);
    
    while(m -- ) {
        int op , l , r;
        cin >> op >> l >> r;
        if(op == 0) {
            modify(1 , l , r);
        } else {
            cout <<  query(1 , l , r) << "\n";
        }
    }
    
    
    return 0;
}