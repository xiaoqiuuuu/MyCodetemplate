// Problem: 武士风度的牛
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/190/


#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int n , m ;
    cin >> m >> n ;
    
    vector<string>g(n);
    for(int i = 0 ; i < n ; i ++ )
        cin >> g[i];
        
    typedef pair<int,int> PII;
    PII be , ed;
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < m ; j ++ )
        {
            if(g[i][j] == 'K')be = {i , j} ,g[i][j] = '.'; 
            if(g[i][j] == 'H')ed = {i , j} , g[i][j] = '.';
        }
    
    vector<PII> q(n * m + 10);
    vector st(n , vector<int> (m , 0));
    
    vector<int> dx = {1 , 2 , 2 , 1 , -1 , -2 , -2 , -1};
    vector<int> dy = {-2, -1 ,1 , 2 , 2 , 1 , -1 , -2 };
    
    
    auto bfs = [&](PII be){
        
        int hh = 0 , tt = - 1;
        q[++ tt] = be ;
        st[be.first][be.second] = 1;
        
        while(hh <= tt)
        {
            auto t = q[hh ++ ];
            
            for(int i = 0 ; i < 8 ; i ++ )
            {
                int u = t.first + dx[i] , v = t.second + dy[i];
                if(u >= 0 && u < n && v >= 0 && v < m && !st[u][v] && g[u][v] == '.')
                {
                    
                    st[u][v] = st[t.first][t.second] + 1;
                    q[++ tt] = {u , v};
                }
            }
        }
    };
    
    
	bfs(be);
	
	cout << st[ed.first][ed.second] - 1<< "\n";
	
	return 0;
}
