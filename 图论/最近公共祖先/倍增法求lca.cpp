// Problem: 
//     P3379 【模板】最近公共祖先（LCA）
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P3379


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 500010 , M = 2 * N;

int h[N] , e[M] , ne[M] , idx;
int f[N][20] , dep[N];

void add(int a , int b) {
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void dfs(int u , int fa) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    
    for(int i = 1 ; i <= 19 ; i ++ ) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    
    for(int i = h[u] ; ~ i ; i = ne[i]) {
        int v = e[i];
        if(v == fa) {
            continue;
        }
        dfs(v , u);
    }
}

int lca(int a , int b){
    if(dep[a] < dep[b]) {
        swap(a , b);
    }
    //先跳到同一层
    for(int i = 19 ; i >= 0 ; i -- ) {
        if(dep[f[a][i]] >= dep[b]) {
            a = f[a][i];
        }
    }
    
    if(a == b) {
        return b;
    }
    
    //跳到lca 的下一层
    for(int i = 19 ; i >= 0 ; i -- ) {
        if(f[a][i] != f[b][i]) {
            a = f[a][i] , b = f[b][i];
        }
    }
    
    return f[a][0];
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(h , -1 , sizeof h);
    
    int n , q , root;
    cin >> n >> q >> root ;
    
    for(int i = 0 ; i < n - 1 ; i ++ ) {
        int a , b;
        cin >> a >> b;
        add(a , b) , add(b , a);
    }
    
    dfs(root , root);
    
    while(q -- ) {
        
        int a , b;
        cin >> a >> b;
        cout << lca(a , b) << "\n";
    }
    
    return 0;
}