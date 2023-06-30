#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10 , M = 2 * N;

int n , m ;
vector<int>g[N];
int d[N][2];
int stk[2 * N] , tt = 0;
int h[N] , e[M] , ne[M] , idx;
bool st[M];

void add(int a , int b)
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void dfs(int u)
{
    
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        
        if(!st[j])
        }
    
        dfs(j);
    }

    stk[++tt] = u;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >>  m;
    while(m -- )
    {
        int a , b ;
        cin >> a >> b ;
        g[a].push_back(b);
        d[b][0] ++ , d[a][1] ++ ;   
    }
    
    
    
    for(int i = 1 ; i <= n ; i ++ )
        sort(g[i].begin() , g[i].end());
    
    //判断是否为欧拉路或者是欧拉回路
    int cnt[2] = {0} , ok = -1;
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(d[i][1] == d[i][0])continue;
        
        if(d[i][1] - d[i][0] == 1)cnt[1] ++ , ok = i;
        else if(d[i][1] - d[i][0] == -1)cnt[0] ++ ;
        else ok = 0;
    }
    
    if(ok == -1 || (cnt[1] == cnt[0] && cnt[1] == 1))    
    {
        if(ok == -1)ok = 1;
        
        memset(h , -1 ,sizeof h);
        for(int i = 1 ; i <= n ; i ++ )
        {
            for(int j = g[i].size() - 1 ; j >= 0 ; j -- )
                add(i , g[i][j]);
        }
            
        
        
        dfs(ok);
        for(int i = tt ;  i >= 1 ; i -- )
            cout << stk[i] << " ";
        cout << "\n";
    }
    else cout << "No\n";
    
    
    return 0 ;
}