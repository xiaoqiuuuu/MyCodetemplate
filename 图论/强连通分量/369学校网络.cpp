// Problem: 学校网络
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/description/369/


#include<bits/stdc++.h>

using namespace std;

const int N = 110 , M = 2 * N * N ;

int n ;
int h[N] , e[M] , ne[M] , idx ;
int id[N] , scc_cnt ;
int dfn[N] , low[N] , tot;
int stk[N] , tt  , in_stk[N];
int d[N][2];


void add(int a , int b)
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ tot;
    
    stk[++ tt] = u , in_stk[u] = true;
    
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u] , low[j]);
        }
        else if(in_stk[j])
            low[u] = min(low[u] , dfn[j]);
    }
    
    if(dfn[u] == low[u]) // u 是这个强连通分量的根
    {
        ++ scc_cnt ;
        int cnt = 0, y ;
        do{
            y = stk[tt --];
            in_stk[y] = false;
            id[y] = scc_cnt;
        }while(y != u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(h , -1 , sizeof h);
    
    cin >> n;
    
    for(int i = 1 , k ; i <= n ; i ++ )
        while(cin >> k , k)add(i , k);
    
    for(int i = 1 ; i <= n ; i ++ )
        if(!dfn[i])tarjan(i);
        
    for(int i = 1 ; i <= n ; i ++ )
        for(int j = h[i] ; ~ j ; j = ne[j])
        {
            int k = e[j];
            if(id[i] != id[k])
            {
                d[id[i]][1] ++ ;
                d[id[k]][0] ++ ;
            }
        }
    
    int din = 0 , dout = 0;
    for(int i = 1 ; i <= scc_cnt ; i ++ )
    {
        if(!d[i][0])din ++ ;
        if(!d[i][1])dout ++ ;
    }
    
    cout << din << "\n";
    
    if(scc_cnt == 1)cout << "0\n";
    else cout << max(din , dout) << "\n";
    
    return 0 ;
}