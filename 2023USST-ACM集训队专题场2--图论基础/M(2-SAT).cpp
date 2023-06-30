// Problem: 
//     P4782 【模板】2-SAT 问题
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P4782


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 2e6 + 10 , M = 2 * N ;

int n , m ;
int h[N] , e[M] , ne[M] , idx;
int dfn[N] , low[N] , tot;
int id[N] , scc_cnt;
int stk[N] , tt , in_stk[N];

void add(int a , int b)
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ tot;
    stk[++ tt] = u, in_stk[u] = true;
    
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u] , low[j]);
        }
        else if(in_stk[j])
        {
            low[u] = min(low[u] , dfn[j]);
        }
    }
    
    if(dfn[u] == low[u])
    {
        ++scc_cnt;
        int y;
        do{
            y = stk[tt --];
            id[y] = scc_cnt;
            in_stk[y] = false;
        }while(y != u);
    }
    
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    memset(h , - 1 , sizeof h);
	
	cin >> n >> m;
	while(m -- )
	{
	    int x , a , y , b;
	    cin >> x >> a >> y >> b;
	       
	    if(a && b)
	    {
	        add(x * 2 - 1, y * 2);
	        add(y * 2 - 1 , x * 2);     
	    }
	    else if(!a && b)
	    {
	        add(x * 2 , y * 2);
	        add(y * 2 - 1 ,x * 2 - 1);
	    }
	    else if(a && !b)
	    {   
	        add(x * 2 - 1 , y * 2 - 1);
	        add(y * 2 , x * 2);
	    }
	    else 
	    {
	         add(x * 2 , y * 2 - 1);
	         add(y * 2 , x * 2 - 1);
	    }
	}
	
	for(int i = 1 ; i <= 2 * n ; i ++ )
	    if(!dfn[i])
	        tarjan(i);
	
	int ok = 1;
	for(int i = 1 ; i <= n ; i ++ )
	{
	    if(id[2 * i] == id[i * 2 - 1])
	        ok = 0;
	}
	
	if(!ok)cout << "IMPOSSIBLE\n";
	else
	{
	    cout << "POSSIBLE\n";
	    for(int i = 1 ; i <= n ; i ++ )
	    {
	        int a = id[i * 2] , b = id[i * 2 - 1];
	        if(a < b)cout << "1 ";
	        else cout << "0 ";
	    }
	    cout << "\n";
	}
	
	
		
	return 0;
}
