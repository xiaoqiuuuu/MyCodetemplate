// Problem: 
//     Legacy
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/CF786B


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 2e5 + 10 ;

struct Node{
    int l , r ,v;
}tr1[N << 2] , tr2[N << 2];

typedef pair<LL,int> PII;

int cnt;
int n , m , p , s ;
int h[16 * N] ,e[16 * N] ,  w[16 * N] , ne[16 * N] , idx;
int st[8 * N];
LL d[16 * N];
int id1[N] , id2[N];

void add(int a ,int b , int c) {
    e[idx] = b , w[idx] = c , ne[idx] = h[a] , h[a] = idx ++ ;
} 

void build(Node tr[] , int u , int l , int r , int op) {
    tr[u] = {l , r , ++cnt};
    if(op == 1 && u != 1) {
        add(tr[u / 2].v , cnt , 0);
       // cout <<tr[u / 2].v << " " << cnt << "\n";
    } else {
        add(cnt , tr[u / 2].v , 0);
    }
    
    if(l == r) {
        if(op == 1) {
            id1[l] = tr[u].v;
        } else {
            id2[l] = tr[u].v;
            add(id1[l] , id2[l] , 0);
            add(id2[l] , id1[l] , 0);
        }
        return;
    }
    int mid = l + r >> 1;
    build(tr , u << 1 , l ,  mid , op) ;
    build(tr , u << 1 | 1 , mid + 1 , r , op);
}

void query(Node tr[] , int u , int l , int r , int v , int w , int op) {
    if(tr[u].l >= l && tr[u].r <= r) {
        if(op == 1) {
            add(v , tr[u].v , w);
        } else {
            add(tr[u].v , v , w);
        }
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l) {
        query(tr , u << 1 , l ,r , v , w , op) ;
    }
    if(r > mid) {
        query(tr , u << 1 | 1 , l , r , v , w , op);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h , -1 ,sizeof h);

    cin >> n >> m >> s;
    build(tr1 , 1 , 1 , n , 1);
    build(tr2 , 1 , 1 , n , 2);
    
    // for(int i = 1 ; i <= cnt;  i ++ ) {
        // for(int j = 1 ; ~  j ; j = ne[j]) {
            // int k = e[i];
            // cout << i << " " << k << "\n";
        // }
    // }
    
    
    while(m -- ) {
        int op , u , v , l , r , w;
        cin >> op ;
        if(op == 1) {
            cin >> u >> v >> w;
            add(id1[u] , id1[v] , w);
        } else if(op == 2 ) {
            cin >> u >> l >> r >> w;
            query(tr1 , 1 , l , r , id1[u] ,w , 1);
        } else {
            cin >> u >> l >> r >> w;
            query(tr2 , 1 , l , r , id1[u] ,w , 2);
        }
    }
    
    for(int i = 0 ; i <= cnt ; i ++ ) {
        d[i] = 1e18;
    }
    
    priority_queue<PII ,vector<PII> , greater<PII>> q;
    q.push({0 , id1[s]});
    d[id1[s]] = 0; 
    while(q.size()) {
        auto t = q.top() ;
        q.pop();
        
        int ver = t.second;
        if(st[ver]) {
            continue;
        }
        st[ver] = true;
        for(int i = h[ver] ; ~ i ; i = ne[i] ) {
            int j = e[i];
            if(d[j] > d[ver] + w[i]) {
                d[j] = d[ver] + w[i];
                q.push({d[j] , j});
            }
        }
    }
    
    for(int i = 1 ; i <= n ; i ++ ) {
        if(d[id1[i]] == 1e18) {
            cout << "-1 ";
        } else {
            cout << d[id1[i]] << " ";
        }
    }
    cout << "\n";
    
    return 0;
}