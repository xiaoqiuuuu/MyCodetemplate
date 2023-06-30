// Problem: 新年好
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1137/

#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 50010 , M = 200010;

int n , m ;
int h[N] , e[M] , w[M] , ne[M] , idx;
int d[6][N];
int st[N];
int a[6];

void add(int a , int b , int c)
{
    e[idx] = b , w[idx] = c , ne[idx] = h[a] , h[a] = idx ++ ;
}

void spfa(int id , int u) //披着spfa皮的dijkstra 
{
    memset(st , 0 , sizeof st);
    
    typedef pair<int,int> PII ;
    priority_queue<PII , vector<PII> , greater<PII>> q;
    q.push({0 , u});d[id][u] = 0;
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
            if(d[id][j] > d[id][ver] + w[i])
            {
                d[id][j] = d[id][ver] + w[i];
                q.push({d[id][j] , j});
            }
        }
    }
    
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(d , 0x3f , sizeof d);
	memset(h , -1 , sizeof h);
	
	cin >> n >> m ;
	for(int i = 1 ; i < 6 ; i ++ )
	    cin >> a[i];
	a[0] = 1;
	
	while( m -- )
	{
	    int a , b , c;
	    cin >> a >> b >> c ;
	    add(a , b , c ) ;
	    add(b , a , c ) ;
	}
	
	for(int i = 0 ; i < 6 ; i ++ )
	    spfa(i , a[i]);
	

	
	int b[5] = {1 , 2 , 3 , 4 , 5};
	
	int ans = 0x3f3f3f3f;
	do{
	    int res = d[0][a[b[0]]];
	    for(int i = 1 ;i < 5 ; i ++ )
	        res += d[b[i - 1]][a[b[i]]];
	     
	    ans = min(ans , res);
	    
	}while(next_permutation(b , b + 5));
	
	cout << ans << "\n";
	
	return 0;
}
