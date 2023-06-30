 #include<bits/stdc++.h>
 
using namespace std;

const int N = 1e4 + 10 , M = 2e5 + 10;

int n , m ;
int h[N] ,hs[N] , w[N] , e[M] , ne[M] , idx;
int scc_size[N] , scc_cnt  , id[N];
int dfn[N] , low[N] , tot;
int stk[N] , tt , in_stk[N];
int f[N] ;


void add(int h[] , int a , int b)
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void tarjan(int u )
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
    
    if(dfn[u] == low[u])
    {
        scc_cnt ++ ;
        int y ;
        do{
            y = stk[tt -- ];
            in_stk[y] = false;
            id[y] = scc_cnt;
            scc_size[scc_cnt] += w[y];
        }while(y != u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(h , -1 , sizeof h);    
    memset(hs , -1, sizeof hs);
    
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i ++ )
        cin >> w[i];
    
    while(m -- )
    {
        int a , b ;
        cin >> a >> b ;
        add(h , a , b);
    }
    for(int i = 1 ; i <= n ; i ++ )
        if(!dfn[i])tarjan(i);
    
    unordered_set<int> s;
    for(int i = 1 ; i <= n ; i ++ )
        for(int j = h[i] ; ~ j ; j = ne[j])
        {
            int k = e[j];
            if(id[i] != id[k] && !s.count(id[i] * 10000 + id[k]))
            {
                add(hs , id[i] , id[k]);
                s.insert(id[i] * 10000 + id[k]);
            }
        }
    
    for(int i = scc_cnt ; i  ; i -- )
    {    
       if(!f[i])f[i] = scc_size[i];
    
        for(int j = hs[i] ; ~ j ; j = ne[j])
        {
            int k = e[j]; 
            f[k] = max(f[k] , f[i] + scc_size[k]);
        }
    }    
    
    int maxf = 0 ;
    for(int i = 1 ; i <= scc_cnt ; i ++ )
        maxf = max(maxf , f[i]);
    
    cout << maxf << "\n";
    
    return 0;
}