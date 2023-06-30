// Problem: 最小花费
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1128/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 2010 , M = 200010;

int h[N] , e[M] , ne[M] , idx;
double d[N] , w[M];
bool st[N];

void add(int a , int b , int c)
{
    e[idx] = b , w[idx] = c , ne[idx] = h[a] , h[a] = idx ++ ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout << fixed << setprecision(8);
	
	int n , m ;
	cin >> n >> m ;
	
	memset(h , - 1, sizeof h);
	
	while(m --)
	{
	    int a , b , c;
	    cin >> a >> b >> c ;
	    add(a , b , c) , add(b , a , c);
	}
	
	int a , b ;
	cin >> a >> b ;
	
	queue<int>q;
	for(int i = 0 ; i <= n ; i ++ )
	    d[i] = 1e9 + 10;
	q.push(b);st[b] = true;
	d[b] = 100;
	
	while(q.size())
	{
	    auto t = q.front() ;
	    q.pop();
	    
	    st[t] = false;
	    
	    for(int i = h[t] ; ~ i ; i = ne[i])
	    {
	        int j = e[i];
	        double now = d[t] / ((100.0 - w[i]) / 100);
	        if(now < d[j])
	        {
	            d[j] = now;
	            if(!st[j])
	                q.push(j) , st[j] = true;
	        }
	    }
	}
	
	cout << d[a] << "\n";
	
	
	
	return 0;
}
