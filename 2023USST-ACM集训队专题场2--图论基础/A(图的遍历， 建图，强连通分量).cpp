#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 100010 , M = 2 * N;

int h[N] , e[M] , ne[M] , idx;
bool st[N];
int v[N];

void add(int a , int b)
{
    e[idx] = b ,ne[idx] = h[a] , h[a] = idx ++ ;
}

void dfs(int u)
{
    st[u] = true;
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        v[j] = max(v[j] , v[u]);
        if(st[j])continue;
        dfs(j);
    }
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int n , m ;
	cin >> n >> m ;
	
	memset(h , - 1, sizeof h);
	for(int i = 1 ; i <= n ; i ++ )
	    v[i] = i ;
	
	
	while(m -- )
	{
	    int a , b ;
	    cin >> a >> b ;
	    add(b , a);
	}
	
	for(int i = n ; i >= 1 ; i -- )
	    if(!st[i])dfs(i);
	    
	for(int i = 1 ; i <= n ; i ++ )
	    cout << v[i] << " ";
	cout << "\n";
	
	return 0;
}
