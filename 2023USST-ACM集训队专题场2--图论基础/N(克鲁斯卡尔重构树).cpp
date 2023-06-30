// Problem: H. Life is a Game
// Author : Weiqt
// URL: https://codeforces.com/gym/103446/problem/H


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 2e5 + 10 , M = 2 * N;

int n , m , q ;
struct Edge{
    int a , b , w;

    bool operator < (const Edge &S)const{
        return w < S.w;
    }
}edges[N];
int p[N];
int h[N] , v[N]  , e[M] , ne[M] , idx;
LL val[N] ;
int cnt , f[N][21];

void add(int a , int b )
{
    e[idx] = b ,ne[idx] = h[a] , h[a] = idx ++ ;
}

int find(int x)
{
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}

void kruskal()
{
    sort(edges + 1 , edges + 1 + m);
    
    cnt = n;
    
    for(int i = 1 ; i <= m ; i ++ )
    {        
        auto [a , b , w] = edges[i];
        
        a = find(a) , b = find(b);
        
        if(find(a) != find(b))
        {
            p[a] = p[b] = ++ cnt;
            add(cnt , a ) , add(a , cnt ) ;
            add(cnt , b ) , add(b , cnt );
            
            cout << cnt << " " << a << "\n";
            cout << cnt << " " << b << " "  << w << "\n";
            
            cout << "\n\n\n";
            
            v[cnt] = w;   
            val[cnt] = val[a] + val[b];
        }
    }
}

void dfs(int u , int fa)
{
    
    f[u][0] = fa;
    for(int i = 1 ; i <= 19 ; i ++ )
        f[u][i] = f[f[u][i - 1]][i - 1];
    
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        if(j == fa)continue;
        dfs(j , u);
    }
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    memset(h , -1 ,sizeof h);

    cin >> n >> m >> q;
    
    for(int i = 1 ; i <= 2 * n  ; i ++ )
        p[i] = i ; 
    
    for(int i = 1 ; i <= n ; i ++ )
        cin >> val[i];
    
    for(int i = 1 ; i <= m ; i ++ )
    {
        auto &[a , b , w] = edges[i];
        cin >> a >> b >> w;
    }
    
    kruskal();
    
    v[0] = 9e18;
    dfs(cnt , 0);
    
    while(q -- )
    {
       int a , x;
       cin >> a >> x;
       LL now = x + val[a];
       while(a != cnt)
       {
          int flg = a ;
          for(int i = 19 ; i >= 0 ; i -- )
          {
              if(now >= v[f[a][i]])
                  now = x + val[f[a][i]] , a = f[a][i];
          }
          if(flg == a)break;
       }
       cout << now << "\n";
     
    }	

	
	return 0;
}
