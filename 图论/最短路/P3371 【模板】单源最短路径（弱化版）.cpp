// Problem: P3371 【模板】单源最短路径（弱化版）
// Author : xiaoqiuuuu
// URL: https://www.luogu.com.cn/problem/P3371

//题目说数据比较弱，我就采用的spfa ，个人感觉spfa 比dijkstra 好写


#include<bits/stdc++.h>

using namespace std;

typedef long long LL ;
const int N = 1e4 +10 , M = 1e6 + 10;
const int Inf = 0x7fffffff;


int n , m , s;
int h[N] ,e[M] ,w[M] , ne[M] , idx;
int st[N];
int dist[N];

void add(int a , int b , int c)
{
	e[idx] = b, w[idx] = c , ne[idx] = h[a] ,h[a] = idx ++;
}  

void Spfa()
{
	
	for(int i = 0 ; i <= n ; i ++ )
	 	dist[i] = Inf;
	
	dist[s] = 0;
	
	queue<int>q;
	q.push(s);
	st[s] = true;
	
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		st[t] = false;
		
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!st[j])
				{
					st[j] = true;
					q.push(j);
				}
			}
		}
	}
			
}

void solve()
{
	memset(h , -1 ,sizeof h);
	
	cin >> n >> m >> s;
	

	for(int i = 0 ; i < m ; i ++ )
	{
		int a ,  b  , c ; 
		cin >> a >> b >> c;
		add(a , b , c);
	}
	
	Spfa();
	
	for(int i = 1 ; i <= n ; i ++)
		cout << dist[i] << " "; 
	
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
