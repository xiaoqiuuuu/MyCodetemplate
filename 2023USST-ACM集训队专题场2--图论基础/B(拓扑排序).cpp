#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 110 , M = 2 * N * N;

int n , m;
int h[N] , e[M] , ne[M] , idx;
int d[N] ,q[2 * N];
bool st[N];

void add(int a , int b)
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void solve()
{
    memset(d , 0 , sizeof d);
    memset(h  , - 1 , sizeof h);
    memset(st , 0 , sizeof st);
    idx = 0;
    
    while(m --)
    {
        int a , b ;
         cin >> a >> b ;
         d[b] ++ ;
         add(a , b);
    }
    
    int hh = 0 , tt = - 1;
    for(int i = 1 ; i <= n ; i ++ )
        if(!d[i])q[++ tt] = i , st[i] = true;
    
    while(hh <= tt)
    {
        int t = q[hh ++ ];
        for(int i = h[t] ; ~ i ; i = ne[i])
        {
            int j = e[i];
            if(--d[j] == 0)
                q[++tt] = j;
        }    
    }
    
    for(int i = 0 ; i < n ; i ++ )
        cout << q[i] << " ";
    cout << "\n";
    
    
    
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while(cin >> n >> m && (n || m))
	    solve();
	
	return 0;
}
