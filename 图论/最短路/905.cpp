// Problem: 昂贵的聘礼
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/905/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 110 , M = 2 * N * N;

int h[N] , e[M] , w[M] , ne[M] , idx;
int a[N] , W[N];
int d[N];
bool st[N];

void add(int a , int b, int c)
{
    e[idx] = b , w[idx] = c , ne[idx] = h[a] , h[a] = idx ++ ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	memset(h , - 1 , sizeof h);
	
	int n , m ;
	cin >> m >> n ;

	for(int i = 1 ; i <= n ; i ++ )
	{
	    int x ;
	    cin >> W[i] >> a[i] >> x;
	    add(0 , i , W[i]);
	    while(x -- )
	    {
	        int b , t ;
	        cin >> b >> t ;
            add(b , i , t);
	    }
	}
	
	auto dijkstra = [&](int x){
	    
	    memset(d , 0x3f , sizeof d);
	    memset(st , 0 , sizeof st);
	    
        	typedef pair<int,int> PII ;
        	priority_queue<PII , vector<PII> , greater<PII>>q;
        	
        	q.push({0 , 0});d[0] = 0 ; 	
        	while(q.size())
        	{
        	    auto t = q.top();
        	    q.pop();
        	    
        	    int ver = t.second;
        	    if(st[ver])continue;
        	    st[ver] = true;
        	
        	    for(int i = h[ver] ; ~ i ; i = ne[i])
        	    {
        	        int j = e[i];
        	        if(d[j] > d[ver] + w[i] && a[j] >= x && a[j] <= x + m)
        	        {
        	            d[j] =  d[ver] + w[i];
        	            q.push({d[j] , j});
        	        }
        	    }
        	    
        	}
        	return d[1];
    };
    
    int ans = 0x3f3f3f3f;
    
    for(int i = 1 ; i + m <= 100 ; i ++ )
        ans = min(ans , dijkstra(i));
    
    cout << ans << "\n";
	
	return 0;
}
