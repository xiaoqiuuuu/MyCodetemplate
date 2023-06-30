// Problem: 红与黑
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1115/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 30 , M = 30;

int n , m ;
char g[N][M];
bool st[N][M];

void solve(int n , int m)
{
    
    memset(st , 0 , sizeof st);
    
    auto dfs = [&](auto dfs , int x , int y) ->int{
        if(x < 0 || x >= n || y < 0 || y >= m || st[x][y] || g[x][y] != '.')return 0;
        st[x][y] = true;
        
        int sum = 0;
        sum += dfs(dfs , x + 1 , y);
        sum += dfs(dfs , x - 1 , y);
        sum += dfs(dfs , x , y + 1);
        sum += dfs(dfs , x , y - 1);
         
        return sum + 1;
    };

    for(int i = 0 ; i < n ; i ++ )
        cin >> g[i];
    
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < m ; j ++ )
        {
            if(g[i][j] == '@')
            {
                g[i][j] = '.';
                cout << dfs(dfs , i , j) << "\n";
                return ;
            }
        }
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    while(cin >> m >> n || m || n)
    {
        
       solve(n , m);
    	}
    	    
	
	
	
	return 0;
}
