// Problem: 导弹防御系统
// Author : xiaoqiuuuu
// URL: https://www.acwing.com/problem/content/189/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n ; 
	while(cin >> n , n)
	{
		vector<int> h(n) ;
		for(int i = 0 ; i < n ; i ++ )
			cin >> h[i];
		
		vector<int>down(n + 1) , up(n + 1);
		int ans = n ;
		
		auto dfs = [&](auto dfs , int u , su , sd){
			
			if(su + sd >= ans) return ;
			
			if(u == n)
			{
				ans = su + sd;
				return ;
			}
			
			int k = 0 ;
			while(k < su && h[u] < up[k])k ++ ;
			if(k == su)
			{
				up[k] = h[u];
				dfs(dfs, u + 1 , su + 1 , sd);
			}
			else 
			{
				int t = up[k];
				up[k] = h[u];
				dfs(dfs, u + 1 , su , sd);
				up[k] = t;
			}
			
			k = 0 ;
			while(k < sd && h[u] > donw[k]) k ++ ;
			if(k == sd)
			{
				down[k] = h[u];
				dfs(dfs , u + 1 , su , sd + 1) ;
			}
			else 
			{
				int t = donw[k];
				down[k] = h[u] ;
				dfs(dfs , u + 1 , su , sd);
				down[k] = t;
			}
				
		};
		
		dfs(dfs , 0 , 0 , 0 ) ;
		
		cout << ans << "\n";
		
	}
	
	return 0;
}
