// Problem: 山峰和山谷
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1108/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 1000010;

typedef pair<int,int> PII;

PII q[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n ;
	cin >> n ;
	
	vector g(n , vector<int>(n));
	vector st(n , vector<bool>(n));
	
	for(int i = 0 ; i < n ; i ++ )
	    for(int j = 0 ; j < n ; j ++ )
	        cin >> g[i][j];
	
	int cnt1 = 0 , cnt2 = 0 ;

	auto bfs =[&](int x , int y){
	    
	    int hh = 0 , tt = - 1;
	    q[++tt] = { x , y};
	    st[x][y] = true;
	    int ok1 = 0 , ok2 = 0;
	    while(hh <= tt)
	    {
	        auto t = q[hh ++ ];
	        
	        for(int i = -1 ; i <= 1 ; i ++ )
	            for(int j = - 1 ; j <= 1 ; j++ )
	            {
	                if(i == 0 && j == 0)continue;
	                
	                int u = t.first + i , v = t.second + j;
	                if(u >= 0 && u < n && v >= 0 && v < n)
	                {
	                    if(g[u][v] == g[x][y] && !st[u][v]){
	                            q[++tt] = {u , v} ,st[u][v] = true;
	                    }
	                    else
	                    {
	                        ok1 |= (g[u][v] > g[x][y]);
	                        ok2 |= (g[u][v] < g[x][y]);
	                    }
	                }
	            }
	    }
	    
	    if(!ok2)cnt2 ++ ;
	    if(!ok1)cnt1 ++ ;
	    
	};
	
	for(int i = 0 ; i < n ; i ++ )
	    for(int j = 0 ; j < n ; j ++ )
	        if(!st[i][j])
	            bfs(i , j);
	
	cout << cnt1 << " " << cnt2 << "\n";
	
	return 0;
}
