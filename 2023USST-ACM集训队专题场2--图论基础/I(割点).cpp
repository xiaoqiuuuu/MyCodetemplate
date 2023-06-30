#include<bits/stdc++.h> 

using namespace std;

const int N = 2e4 + 10 , M = 2e5 + 10;

int n , m ;
int h[N] , e[M] , ne[M] , idx;
int dfn[N] , low[N] , tot;
int cut[N];

void add(int a , int b)
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void tarjan(int u , int root)
{
    dfn[u] = low[u] = ++ tot;
    
    int flg = 0;
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        if(!dfn[j])
        {
            tarjan(j , root);
            low[u] = min(low[u] , low[j]);
            
            if(low[j] >= dfn[u])
            {
                flg ++ ;
                if(flg > 1 || u != root)
                    cut[u] = true;
            }
        
        }
        else low[u] = min(low[u] , dfn[j]);
        
    }
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(h , - 1 , sizeof h);
    
    cin >> n >> m;    
    while(m -- )
    {
        int a , b ;
        cin >> a >> b ;
        add(a , b) , add(b , a);
    }
    
    for(int i = 1 ; i <= n ; i ++ )
        if(!dfn[i])
            tarjan(i , i);
    
    int cnt = 0;
    for(int i = 1 ; i <= n ; i ++ )
        cnt += (cut[i] >= 1);
    
    cout << cnt << "\n";
    for(int i = 1 ; i <= n ; i ++ )
        if(cut[i])
            cout << i << " ";
    cout << "\n";
    
    return 0 ;
}