// Problem: 
//     P3379 【模板】最近公共祖先（LCA）
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P3379


//tarjan 算法求lca


#include <bits/stdc++.h>

using namespace std;

const int N = 500010 , M = 2 * N;

int h[N] , e[M] , ne[M] , idx;
int p[N] , vis[N] , ans[N];
vector<pair<int,int>>query[N];

void add(int a , int b ) {
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

int find(int x) {
    if(p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}

void tarjan(int u) {
    vis[u] = true;
    for(int i = h[u] ; ~ i ; i = ne[i]) {
        int v = e[i];
        if(!vis[v]) {
            tarjan(v);
            p[v] = u;
        }

    }
    
    for(auto q : query[u]) {
        int v = q.first , i = q.second;
        if(vis[v]) {
            ans[i] = find(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h , -1 ,sizeof h);
    
    int n , m , root;
    cin >> n >> m >> root;
    
    for(int i = 1 ; i <= n ; i ++ ) {
        p[i] = i;
    }
    
    
    for(int i = 0 ; i < n - 1 ; i ++ ) {
        int a , b ;
        cin >> a >> b;
        add(a , b) , add(b , a);
    }
    
    for(int i = 1 ; i <= m ; i ++ ) {
        int a , b;
        cin >> a >> b;
        query[a].push_back({b , i});
        query[b].push_back({a , i});
    }
    
    tarjan(root);
    
    for(int i = 1 ; i <= m ; i ++ ) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}