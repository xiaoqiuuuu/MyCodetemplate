// Problem: 池塘计数
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/description/1099/


#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>PII;

PII q[1000010] ;
int hh = 0, tt = - 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<string>g(n);
    for(int i = 0 ; i < n ; i ++ )
        cin >> g[i];
    int dx[8] = {0 , 1 , 0 ,- 1, 1 , 1 , -1 ,-1};
    int dy[8] = {1 , 0 , -1 , 0 ,-1 , 1, 1 , -1};
    
    vector vis(n , vector<int>(m , 0));
    
    auto bfs = [&](int x , int y){
        hh = 0 , tt = -1 ;
        
        q[++tt] = {x , y};
        vis[x][y] = true;
        
        while(hh <= tt)
        {
            auto t = q[hh ++];
            for(int i = 0 ; i < 8 ; i ++ )
            {
                int u = t.first + dx[i] ,  v = t.second + dy[i];
                if(u >= 0 && u < n && v >= 0 && v < m && g[u][v] == 'W' && !vis[u][v])
                    q[++tt] = {u , v} ,  vis[u][v] = true;
                    
            }
            
        }
       
    };
    
    int ans = 0;
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < m ;j ++ )
            if(g[i][j] == 'W' && !vis[i][j])
                ans ++ ,bfs(i , j);
                
    cout << ans << "\n";
    
    return 0;
}