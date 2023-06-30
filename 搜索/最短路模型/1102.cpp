// Problem: 抓住那头牛
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1102/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 1e5 + 10 , M = 2 * N;

int q[M] , d[M] ;
bool st[M];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n , k ;
	cin >> n >> k ;
	
	st[n] = true;
	int hh = 0 , tt = - 1;
	q[++tt] = n;
	
	while(hh <= tt)
	{
	    auto t = q[hh ++ ];
	    
	    if(t == k)break;
	    
	    if(t + 1 < M && !st[t + 1])d[t + 1] = d[t] + 1 , st[t + 1] = true ,q[++ tt] = t + 1;
	    if(t - 1 >= 0 && !st[t - 1])d[t - 1] = d[t] + 1 , st[t - 1] = true, q[++ tt] = t - 1;
	    if(t * 2 < M && !st[t * 2])d[t * 2 ] = d[t] + 1 , st[t * 2] = true, q[++ tt] = t * 2;
	}
	
	
	cout << d[k] << "\n";
	
	
	return 0;
}
