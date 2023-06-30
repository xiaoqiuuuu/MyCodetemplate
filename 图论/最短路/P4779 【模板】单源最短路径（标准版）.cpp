// Problem: P4779 【模板】单源最短路径（标准版）
// Author : xiaoqiuuuu
// URL: https://www.luogu.com.cn/problem/P4779


#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL ;
const int N = 1e5 +10 , M = 1e7 + 10;  


int n , m  ,s ;
int h[N], e[M] , w[M], ne[M] ,idx;
int dist[N];
bool st[N];

void add(int a ,int b ,int c)
{
	e[idx] = b ,w[idx] = c , ne[idx] = h[a] , h[a] = idx ++;
}

void Dijkstra(int s)
{
	memset(dist , 0x3f , sizeof dist);
	dist[s] = 0;
	
	priority_queue<PII, vector<PII> ,greater<PII>> q;
	q.push({0 ,s});
	
	while(q.size())
	{
		auto t = q.top();
		q.pop();
		
		int ver = t.second;
		if(st[ver])continue;
		st[ver] = true;
		
		for(int i = h[ver] ; i != -1 ; i = ne[i])
		{
			int j = e[i] ; 
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
	memset(h , -1 , sizeof h);
	
	cin >> n >> m >> s;
	
	while(m --)
	{
		int a ,b , c; 
		cin >> a >> b >> c;
		add(a, b , c);
	}
	
	Dijkstra(s);
	
	
	for(int i = 1; i <= n ; i ++)
		cout << dist[i] <<" ";
	cout << "\n";
	
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
