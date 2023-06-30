// Problem: 迷宫问题
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1078/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n ;
	cin >> n ;
	typedef pair<int,int>PII;
	vector g(n , vector<int>(n));
	vector pre(n , vector<PII>(n , {-1 , -1}));
	vector<PII>q(n * n + 10);
	vector st(n , vector<int>(n));
	vector<int> dx = {0 , 1 , 0 , -1};
	vector<int> dy = {1 , 0 , -1 , 0};
	
	for(int i = 0 ; i < n ; i ++ )
	    for(int j = 0 ; j < n ; j ++ )
	        cin >> g[i][j];
	    
	auto bfs = [&](int x , int y){
	    
	    int hh = 0 , tt = - 1;
	    q[++tt] = {x , y};
	    st[x][y] = true;
	    pre[x][y] = {x ,y};
	    
	    while(hh <= tt)
	    {
	        auto t = q[hh ++];
	        
	        for(int i = 0 ; i < 4 ; i ++ )
	        {
	           int u = t.first + dx[i] , v = t.second + dy[i];
	            if(u >= 0 && u < n && v >= 0 && v < n && !st[u][v] && !g[u][v])
	            {
	                pre[u][v] = t;
	                st[u][v] = true;
	                q[++ tt] = {u , v};
	            }
	        }
	    }
	};
    
    bfs(0 , 0);
    
    vector<PII> d ;
    PII x = {n - 1 , n - 1};
    d.push_back(x);
    
    while(x != pre[x.first][x.second] && pre[x.first][x.second] != make_pair(-1 , -1))
        d.push_back(pre[x.first][x.second]) , x = pre[x.first][x.second];
	
	for(int i = d.size() - 1 ; i >= 0 ; i -- )
	    cout << d[i].first << " " << d[i].second << "\n";
	
	return 0;
}
