// Problem: 
//     P3379 【模板】最近公共祖先（LCA）
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P3379

#include <bits/stdc++.h>

using namespace std;

const int N = 500010 , M = 2 * N;

int h[N] , e[M] , ne[M] , idx;
int top[N] , p[N] , son[N] , sz[N] , dep[N];
//top 存每个节点属于哪条重链
//p 存每个节点的父节点
//son 存每个节点的重儿子
//sz 存子树大小
//dep 存子树深度

void add(int a , int b) {
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}
//
void dfs1(int u , int fa) {
    sz[u] = 1 , dep[u] = dep[fa] + 1 , p[u] = fa;
    for(int i = h[u] ; ~ i ; i = ne[i]) {
        int j = e[i];
        if(j == fa) {
            continue;
        }
        dfs1(j , u);
        sz[u] += sz[j];
        if(sz[son[u]] < sz[j]) {
            son[u] = j ;
        }
    }
}
//搞定top 数组
void dfs2(int u , int fa) {
    top[u] = fa;
    if(!son[u])return;
    dfs2(son[u] , fa); // 搜重儿子
    for(int i = h[u] ; ~ i ; i = ne[i]) {
        int j = e[i];
        if(j == p[u] || j == son[u]) { 
            continue;
        }
        dfs2(j , j) ;//搜轻儿子
    }
}

int lca(int a , int b) {
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) {
            swap(a , b);
        }
        a = p[top[a]];
    }
    return dep[a] < dep[b] ? a : b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h , - 1, sizeof h);  
    
    int n , m , root;
    cin >> n >> m >> root;
    
    for(int i = 0 ; i < n - 1 ; i ++ ) {
        int a , b;
        cin >> a >> b;
        add(a , b) , add(b , a);
    }  
    
    dfs1(root , root);
    dfs2(root , root);

    while(m -- ) {
        int a , b;
        cin >> a >> b;
        
        cout << lca(a , b) << "\n";
    }
    
    return 0;
}