#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n , m ;
    cin >> n >> m ;
    vector g(n , vector<int>(m + 1 ,0)) ;
    vector st(n , vector<bool>(m + 1 , 0));
    
    int cnt = 0 , ans = 0;s
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < m ; j ++ )
            cin >> g[i][j];
    
    typedef pair<int,int> PII;
    vector<PII> q(5000);
    int hh = 0 , tt = - 1;
    
    int dx[4] = {0 , -1 , 0 , 1 } ;
    int dy[4] = {-1 , 0 , 1 , 0 } ;
    
    auto bfs = [&](int x , int y){
        
        int res = 1;
        
        hh = 0 , tt = -1;
        q[++tt] = {x , y};
        st[x][y] = true;
        
        while(hh <= tt)
        {
            auto t = q[hh ++ ];
            for(int i = 0 ; i < 4 ; i ++ )
                if(g[t.first][t.second] >> i & 1)continue;
                else
                {
                    int u = t.first + dx[i] , v = t.second + dy[i];
                    if(u >= 0 && u < n && v >= 0 && v < m && !st[u][v])
                    {
                        q[++tt] = {u , v};
                        st[u][v] = true ,res ++ ;
                    }
                }
        }
        
        return res ;
    };
    
    
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < m ; j ++ )
            if(!st[i][j])
              cnt ++ , ans = max(ans , bfs(i , j)) ;
    
    cout << cnt << "\n" << ans << "\n";
    
    
    
    
    return 0 ;
}