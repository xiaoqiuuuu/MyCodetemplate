// Problem: P1629 邮递员送信
// Author : xiaoqiuuuu
// URL: https://www.luogu.com.cn/problem/P1629

//去的时候是1 到 n ，回来的时候是n 到 1
//题目变成了单源最短路 + 多源最短路问题了
//但仔细观察可以发现， 回来的时候都是回到的一个点
//意思是，只需要把回来的点倒过来，重新建一个图既可以转换为单源最短路的问题
//由于前面写了太多次spfa 了，这次写一个dijkstra

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL ;
const int N = 1e4 + 10 , M = 1e7 + 10;

int n ,m;
int h[N] , e[M] , w[M] , ne[M] , idx;  
bool st[N];
int dist[N];

void add(int a ,int b ,int c)
{
	e[idx] = b , w[idx] = c ,ne[idx] = h[a] , h[a] = idx ++;
}

void Dijkstra(int s)
{
	memset(dist,0x3f , sizeof dist);
	
	dist[s] = 0;
	
	priority_queue<PII,vector<PII>,greater<PII>> q;
	
	q.push({0 ,s});
	
	while(q.size())
	{
		auto t = q.top();
		q.pop();
		
		int ver = t.second;
		
		if(st[ver]) continue;
		st[ver] = true;
		
		for(int i = h[ver] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[ver] + w[i])
			{
				dist[j] = dist[ver] + w[i];
				q.push({dist[j], j});
			}
		}	
	}
}

void solve()
{
	memset(h , -1 ,sizeof h);
	
	cin >> n >> m;
	
	while(m--)
	{
		int a , b , c;
		cin >> a >> b >> c;
		add(a , b , c);
		add(b + n , a + n , c);
	}
	
	Dijkstra(1);
	
	LL ans = 0;
	
	for(int i = 2 ; i <= n ; i ++)
		ans += dist[i];
	
	Dijkstra(n + 1);
	
	for(int i = n + 2 ; i <= 2 * n  ; i ++ )
		ans += dist[i];
	
	cout<< ans << "\n";
	
	
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
