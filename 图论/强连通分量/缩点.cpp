// Problem: P3387 【模板】缩点
// Author : xiaoqiuuuu
// URL: https://www.luogu.com.cn/problem/P3387

#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 10010 , M = 200010;

int n , m ;
int h[N] ,hs[N] , e[M] , w[M], ne[M] , idx;
int dfn[N] , low[N] ,timestamp;
int stk[N] , top;
bool in_stk[N]; 
int Size[N] , id[N] , scc_cnt;
int f[N];

void add(int h[], int a, int b )
{
	e[idx] = b , ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++ timestamp;
	stk[++top] = u , in_stk[u] = true;
	
	for(int i = h[u] ; ~ i ; i = ne[i])
	{
		int j = e[i]; 
		if(!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if(in_stk[j])low[u] = min(low[u] , dfn[j]);
	}
	
	if(dfn[u] == low[u])
	{
		scc_cnt++;
		int y ;
		do{
			y = stk[top--];
			in_stk[y] = false;
			Size[scc_cnt] += w[y];
			id[y] = scc_cnt;
		}while(y != u);
	}
}


int main()
{

	memset(h , - 1, sizeof h);
	memset(hs, - 1, sizeof hs);

	cin >> n  >> m ;
	for(int i = 1 ; i <= n ; i ++ )
		cin >> w[i] ;
	while(m -- )
	{
		int a , b ;
		cin >> a >> b;
		add(h ,a , b);
	}
	
	for(int i = 1 ; i <= n ;i ++ )
		if(!dfn[i])
			tarjan(i);
	
	unordered_set<int>S ;
	for(int i = 1 ; i <= n ; i ++ )
		for(int j = h[i]; ~ j ; j = ne[j])
		{
			int k = e[j];
			int a = id[i] , b = id[k];
			int hash = a * 100000 + b;
            
			if(a != b && !S.count(hash))
			{
			    //cout<<a<<' '<<b<<'\n';
				add(hs, a , b);
				S.insert(hash);
			}
		}
		
	for(int i = scc_cnt ; i ; i -- )
	{
		if(!f[i])f[i] = Size[i];

		for(int j = hs[i] ; ~ j ; j = ne[j])
		{
			int k = e[j]; 

			f[k] = max(f[k] , f[i] + Size[k]);
		}
	}
	
	//for(int i=1;i<=n;i++)cout<<id[i]<<'\n';
	int maxf = 0 ;
	for(int i = 1 ; i <= scc_cnt ; i ++ )
		maxf = max(maxf , f[i]);
	cout << maxf << endl;
	
	return 0;
}

