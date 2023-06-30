// Problem: 
//     P6492 [COCI2010-2011#6] STEP
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P6492


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 2e5 + 10;

struct Node{
    int l ,r , v , flg ;
    int lmax , rmax , tmax;
}tr[N << 2];

int n , a[N];

void pushup(Node &u , Node &l , Node &r) {
    u.flg = (l.flg && r.flg) && (a[l.r] ^ a[r.l]);
    u.lmax = l.lmax ;
    u.rmax = r.rmax;
    u.tmax = max(l.tmax , r.tmax);
    
    if(u.flg)u.tmax = u.r - u.l + 1;
    if(a[l.r] ^ a[r.l]) {
        u.tmax = max(u.tmax , l.rmax + r.lmax);
        if(l.flg) {
            u.lmax = l.tmax + r.lmax;
        }
        if(r.flg) {
            u.rmax = l.rmax + r.tmax;
        }
    }
    
    u.tmax = max({u.tmax , u.lmax , u.rmax});
}

void pushup(int u){
    pushup(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
}

void build(int u ,int l ,int r) {
    tr[u] = {l , r , 0 , 0 , 1 , 1 , 1};
    if(l == r) {
        tr[u] = {l , r , 0 , 1 , 1 , 1 , 1};
        return;
    }
    int mid = l + r >> 1;
    build(u << 1 , l , mid) , build(u << 1 | 1 , mid + 1 ,r);    
    //pushup(u);
}



void modify(int u ,int x) {
    if(tr[u].l == x && tr[u].r == x) {
        tr[u].v ^= 1;a[x] ^= 1;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= x)modify(u << 1 , x);
    else modify(u << 1 | 1 , x);
    pushup(u);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
    int n , m;
    cin >> n >> m;
    build(1 , 1 , n);
    
    while(m -- ) {
        int x ;cin >> x;
        modify(1 , x);
        cout << tr[1].tmax << "\n";
    }
    
   
    
    return 0;
}