// Problem: 
//     P1144 最短路计数
//   
// Author : xiaoqiuuuu
// URL: https://www.luogu.com.cn/problem/P1144?contestId=87416


#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL ;
const int N = 1e6 +10 , M = 4 * N;
const int mod = 100003;

int n , m ;
int h[N], e[M] , ne[M] , idx ;  
int d[N] , f[N];
bool st[N] ;


void add(int a , int b)
{
	e[idx] = b ,ne[idx] = h[a] , h[a] = idx ++ ;
}

void dijkstra(int be)
{
	for(int i = 1 ; i <= n ; i ++ )
		f[i] = 1 ;
	
	memset(d , 0x3f , sizeof d);
	d[be] = 0 ;
	queue<PII>q;
	q.push({0 , be});
	while(q.size())
	{
		auto t = q.front();q.pop();
		if(st[t.second])continue;
		st[t.second] = true;
		for(int i = h[t.second] ; ~ i ; i = ne[i])
		{
			int j = e[i];
			if(d[j] > d[t.second] + 1)
			{
				q.push({d[j] , j});
				d[j] = (d[t.second] + 1) % mod ;
				f[j] = f[t.second] ;
			}
			else if(d[j] == d[t.second] + 1)
			{
				f[j] = (f[j] + f[t.second]) % mod;
			}
		}
	}
	
}


void solve()
{
	memset(h , -1 , sizeof h);
	cin >> n >> m;
	while(m -- )
	{
		int a ,b ;
		cin >> a >> b ;
		add(a , b ) , add(b , a);
	}

	dijkstra(1);
	
	for(int i = 1 ; i <= n ; i ++ )
		cout << (d[i] == 0x3f3f3f3f ? 0 : f[i]) << "\n";
	
	
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
