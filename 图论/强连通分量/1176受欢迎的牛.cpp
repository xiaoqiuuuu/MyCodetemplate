// Problem: 受欢迎的牛
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/description/1176/


#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10 , M = 5e4 + 10;

int n , m ;
int h[N] , e[M] , ne[M] , idx ;
int scc[N] , scc_size[N] , id[N] , scc_cnt;
int stk[N] , in_stk[N] , tt;
int dfn[N] , low[N] , tot;
int d[N];

void tarjan(int u)
{
    dfn[u] = low[u] = ++ tot;
    stk[++tt] = u ,in_stk[u] = true;
    
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
    
    if(dfn[u] == low[u])
    {
        int y ; ++ scc_cnt;
        do{
            y = stk[tt -- ];
            id[y] = scc_cnt;
            in_stk[y] = false;
            scc_size[scc_cnt] ++ ;
        }while(u != y);
    }
}

void add(int a , int b)
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    memset(h , - 1 , sizeof h);

    cin >> n >> m ;
    while (m -- )
    {
        int a , b ;
        cin >> a >> b ;
        add(a , b);
    }

    for(int i = 1 ; i <= n ; i ++ )
        if(!dfn[i])tarjan(i);
    
    for(int i = 1 ; i <= n ; i ++ )
        for(int j = h[i] ; ~ j ; j = ne[j])
        {
            int k = e[j];
            if(id[i] != id[k])
                d[id[i]] ++;
        }
    
    int cnt = 0 , s ;
    for(int i = 1 ; i <= scc_cnt ; i ++ )
        if(!d[i])cnt ++ , s = i ;

    if(cnt == 1)cout << scc_size[s] << "\n";
    else cout << "0\n";
    
    return 0;
}