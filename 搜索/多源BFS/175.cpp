// Problem: 矩阵距离
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/175/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n , m ;
	cin >> n >> m ;
	
	typedef pair<int,int> PII ;
	
	vector<PII> q(n * m + 20);
	vector<string>g(n);
	vector d(n , vector<int>(m , -1));
	
	int hh = 0 , tt = -1 ;
	for(int i = 0 ; i < n ; i ++ )
	{
	    cin >> g[i];
	    for(int j = 0 ; j < m ; j ++ )
	    {
	        if(g[i][j] == '1')q[++ tt] = {i , j} , d[i][j] = 0;
	    }
	}
	
	vector<int>dx = {0 , 1 , -1 , 0 };
	vector<int>dy = {1 , 0 , 0 , -1};
	
	while(hh <= tt)
	{
	    auto t = q[hh ++ ];
	    
	    for(int i = 0 ; i < 4 ; i ++ )
	    {
	        int u = t.first + dx[i] , v = t.second + dy[i];
	        if(u >= 0 && u < n && v >= 0 && v < m && g[u][v] == '0' && d[u][v] == -1)
	        {
	            d[u][v] = d[t.first][t.second] + 1;
	            q[++ tt] = {u , v};
	        }   
	    }
	}
	
	for(int i = 0 ; i < n ; i ++ )
	    for(int j = 0 ; j < m ; j ++ )
	        cout << d[i][j] << " \n"[j == m - 1];
	
	return 0;
}
