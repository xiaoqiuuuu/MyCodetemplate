// Problem: A. Hacker Cups and Balls
// Author : Weiqt
// URL: https://codeforces.com/gym/101234/problem/A


#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10 ;

struct Node{
    int l , r , s , lz;
}tr[N << 2];

int n , m ;
int a[N];

void pushup(Node &u , Node &l , Node &r) {
    u.s = l.s + r.s;
}

void pushup(int u) {
    pushup(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
}

void pushdown(Node &u , Node &l , Node &r) {
    if(u.lz == -1){
        return;
    }
    
    if(u.lz == 0 ) {
        
        l.s = r.s = 0;
        l.lz = r.lz = 0;
        
    } else {
        l.s = l.r - l.l + 1;
        r.s = r.r - r.l + 1;
        l.lz = r.lz = 1;
    }
    u.lz = -1;
}

void pushdown(int u) {
    pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
}

void build(int u , int l , int r , int jb){
    tr[u] = {l , r , 0 , - 1} ;
    if(l == r) {
        tr[u].s = (a[l] >= jb);
        return;
    }
    int mid = l + r >> 1;
    build(u << 1 , l , mid , jb);
    build(u << 1 | 1 , mid + 1 , r , jb);
    pushup(u);
}

void modify(int u , int l , int r , int x) {
    if(l > r)return;
    if(tr[u].l >= l && tr[u].r <= r) {
        if(x == 0) {
            tr[u].s = 0;
        } else {
            tr[u].s = tr[u].r - tr[u].l + 1;
        }
        tr[u].lz = x;
        return;
    }
    pushdown(u);
    
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l ) {
        modify(u << 1 , l , r , x) ;
    } 
    if(r > mid) {
        modify(u << 1 | 1 , l ,r , x);
    }
    pushup(u);
}

int query(int u , int l , int r) {
    if(tr[u].l >= l && tr[u].r <= r) {
        return tr[u].s;
    }
    
    pushdown(u);
    int mid = tr[u].l + tr[u]. r >> 1;
    int res = 0;
    if(mid >= l) {
        res += query(u << 1 , l , r );
    }
    if(r > mid) {
        res += query(u << 1 | 1 , l , r);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
    }
    
    vector<array<int ,2>> op(m);
    for(auto &[l , r] : op) {
        cin >> l >> r;
    }
    
    auto check = [&](int x) {
        build(1 , 1 , n , x);

        for(auto [l , r] : op) {
            int vis = l <= r;
            if(l > r) {
                swap(l , r) ;
            }
            int t = query(1 , l , r);
            if(vis) {
                modify(1 , l , r - t  , 0);
                modify(1 , r - t + 1 , r , 1);
                
            } else {
                modify(1 , l , l + t - 1 , 1);
                modify(1 , l + t , r , 0);
            }
        }
        int t = query(1 , (n + 1) / 2 , (n + 1) / 2);

        return t;
    };


    int l = 1 , r = *max_element(a + 1 , a + n + 1); 
    while(l < r) {
        int mid = l + r + 1>> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    
    cout << l<< "\n";
    
    return 0;
}