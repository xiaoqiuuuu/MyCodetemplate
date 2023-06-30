// Problem: 
//     P3366 【模板】最小生成树
//   
// Author : xiaoqiuuuu
// URL: https://www.luogu.com.cn/problem/P3366


#include<bits/stdc++.h>

using namespace std;

typedef long long LL ;

const int  N = 5010 , M = 200010 , INF = 0x3f3f3f3f;

int p[N] , n , m ; 
struct Edge{
	int a ,b , w ;

	bool operator < (const Edge &W)const{
		return w < W.w;
	}
}edges[M];

int find(int x)
{
	if(p[x] != x )p[x] = find(p[x]);
	return p[x];
}


int kruskal()
{
	iota(p + 1 , p + n + 1 , 1);
	sort(edges , edges + m );
	
	int res = 0 , cnt = 0 ;
	for(int i = 0 ; i < m ; i ++ )
	{
		int a = edges[i].a , b = edges[i].b , w = edges[i].w;
		
		a = find(a) , b = find(b);
		
		if(a != b )
		{
			p[a] = b ;
			res += w; 
			cnt ++ ;
		}
	}
	
	if(cnt < n - 1)return INF;
	return res;
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> m ;
	for(int i = 0 ; i < m ; i ++ )
	{
		int a , b , w ;
		cin >> a >> b >> w ;
		edges[i] = {a , b , w };
	}
	
	int t = kruskal() ;
	
	if(t == INF) cout << "orz\n";
	else cout << t << "\n";
	
		
	return 0;
}
