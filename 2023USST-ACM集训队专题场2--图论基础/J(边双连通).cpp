#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 5e5 + 10 , M = 4e6 + 10;

int n , m;
int h[N] , e[M] , ne[M] , idx;
int dfn[N] , low[N] , tot;
int stk[N] , tt ;
vector<vector<int>>ans;

void add(int a , int b)
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void tarjan(int u , int from)
{
    dfn[u] = low[u] = ++ tot;
    stk[++ tt] = u ;
    
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        if(!dfn[j])
        {
            tarjan(j , i);
            low[u] = min(low[u] , low[j]);
        }else if(i != (from ^ 1))
            low[u] = min(low[u] , dfn[j]);
    }
    
    if(dfn[u] == low[u])
    {
        int y ;
        vector<int>res;
        do{
            y = stk[tt --];
            res.push_back(y);
        }while(y != u);
        ans.push_back(res);
    }
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(h , -1, sizeof h);
	
	cin >> n >> m;
	while( m -- )
	{
	    int a , b ;
	    cin >> a >> b ;
	    add(a , b ) , add(b , a);
	}
	
	for(int i = 1 ; i <= n ; i ++ )
	    if(!dfn[i])
	        tarjan(i , 0);
	
	cout << ans.size() << "\n";
	for(auto v : ans)
	{
	    cout << v.size() << " ";
	    for(auto i : v)
	        cout << i << " ";
	    cout << "\n";
	}
	
	
	return 0;
}
