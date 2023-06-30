// Problem: P1119 灾后重建
// Author : xiaoqiuuuu
// URL: https://www.luogu.com.cn/problem/P1119

#include<bits/stdc++.h>

using namespace std;

typedef long long LL ;
const int N = 220;

int n , m , q;
int g[N][N]; 
int st[N]; 
int last = 0;

void Floyed(int x)
{
	int k;
	for(k = last ; k < n ; k ++)
	{
		if(st[k] > x)break;
		for(int i = 0 ; i < n; i ++)
			for(int j = 0 ; j < n ; j ++)
			{
				g[i][j] = min(g[i][j] , g[i][k] + g[k][j]);
			}
	}
	
	last = k;
}

void solve()
{
	memset(g,0x3f , sizeof g);
	
	cin >> n >> m;
	for(int i = 0 ; i < n  ; i ++ )
		cin >> st[i] ,g[i][i] = 0;
	for(int i = 0 ; i < m ; i ++ )
	{
		int a , b , c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = c;
	}
	
	cin >> q;
	while(q--)
	{
		
		
		int a , b , c;
		cin >> a >> b >> c;
		
		Floyed(c);	
		
		if(st[a] > c || st[b] > c || g[a][b] > 0x3f3f3f3f /2)cout<<"-1\n";
		else cout << g[a][b] << "\n";
	}
	
	return ;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int tt = 1;
	//cin>>tt;
	while(tt--)
		solve();
	
	return 0;
}
