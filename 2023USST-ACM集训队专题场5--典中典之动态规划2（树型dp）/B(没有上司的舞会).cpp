#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 1e4 + 10;

int n;
int h[N] , e[2 * N] , ne[2 * N] , idx;
int f[N][2] , w[N];
int d[N] , root;


void add(int a , int b)
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void dfs(int u , int fa)
{
    f[u][1] = w[u];
    for(int i = h[u] ; ~ i ;  i = ne[i])
    {
        int j = e[i];
        
        if(j == fa)continue;
        
        dfs(j , u); // 不选 u
        
        f[u][1] += f[j][0] ;
        f[u][0] += max(f[j][1] , f[j][1]);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(h , - 1 , sizeof h);
	
	cin >> n;
	for(int i = 1 ; i <= n ; i ++ )
	    cin >> w[i];
	
	for(int i = 0 ; i < n - 1 ; i ++ )
	{
	    int a, b;
	    cin >> a >> b ;
	    add(b , a);
	    d[a] ++ ;
	}
	
	for(int i = 1 ; i <= n ; i ++ )
	    if(!d[i])
	    {
	        root = i;
	        break;
	    }
	
	dfs(root , root);
	
	cout << max(f[root][0] , f[root][1]) << "\n";
		
	return 0;
}
