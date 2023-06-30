#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n , m ;
	cin >> n >> m ;
	
	
	vector f(n + 1 , vector<int>(m + 1 , 0));
	auto a = f;
	
	vector<int>dx = {0 , 1 , 0 , -1};
	vector<int>dy = {1 , 0 , -1 , 0};
    auto dfs = [&](auto dfs , int x , int y)->int{
        
        if(f[x][y])return f[x][y];
        
        f[x][y] = 1;
        int mx = 0;
        for(int i = 0 ; i < 4 ; i ++ )
        {
            int u = x + dx[i] , v = y + dy[i];
            if(u >= 1 && u <= n && v >= 1 && v <= m && a[x][y] > a[u][v])
            {
                mx = max(mx ,dfs(dfs , u , v));
            }
        }
        
        f[x][y] += mx;
        return f[x][y];
    };
	
	for(int i = 1 ; i <= n ; i ++ )
	    for(int j = 1 ; j <= m ; j ++ )
	        cin >> a[i][j];
	    
	
	for(int i = 1 ; i <= n ; i ++ )
	    for(int j = 1 ; j <= m ; j ++ )
	        if(!f[i][j])
	            dfs(dfs , i , j);
	
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++ )
	     for(int j = 1 ; j <= m ; j ++ )
	         ans = max(ans , f[i][j]);
	
	cout << ans << "\n";
	
	return 0;
}
