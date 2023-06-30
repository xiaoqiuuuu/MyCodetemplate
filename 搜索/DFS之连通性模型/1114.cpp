// Problem: 迷宫
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1114/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

void solve()
{
    int n ;
    cin >> n ;
    
    vector<string> g(n);
    for(int i = 0 ; i < n ; i ++ )
        cin >> g[i];
    vector st(n , vector<int>(n));
    
    int x1 , y1, x2 , y2 ;
    cin >> x1 >> y1 >> x2 >> y2;
    
    int ok = 0 ;
    int dx[4] = {0 , - 1,  0 , 1} , dy[4] = {1 , 0 , - 1 , 0};
   auto dfs = [&](auto dfs , int x , int y) -> void{
        if(st[x][y] || g[x][y] == '#')return;
        st[x][y] = true;
        
        if(x == x2 && y == y2)
        {
            ok = 1;
            return ;
        }
        
        
        for(int i = 0 ; i < 4 ; i ++ )
        {
            int u = x + dx[i] , v = y + dy[i];
            if(u >= 0 && u < n && v >= 0 && v < n )
                dfs(dfs ,u , v);
        }
        
    };
    
    
    dfs(dfs , x1 , y1);
    
    cout << (ok ? "YES\n" : "NO\n");
    
    
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1;
	cin>>tt;
	while(tt--)
		solve();
	
	return 0;
}
