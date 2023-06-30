#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
//using LL = long long ;

const int N = 1e6 + 10 , M = 2 * N ;

int n , m ;
int h[N] , e[M] , ne[M] , w[M] , idx ;
int d[N] , c = 1 , ans ;
bool st[N] ;

void add(int a , int b , int c)
{
    e[idx] = b , w[idx] = c , ne[idx] = h[a] , h[a] = idx ++ ;
}

void dfs(int u)
{
    if(st[u])return ;
    st[u] = true;
    
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        d[j] = min(d[j] , d[u] + w[i]);
        if(d[j] > d[c])
        {
            c = j ;
            ans = d[j];
        }
        dfs(j);
    }
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(h , - 1 , sizeof h);
	
	cin >> n >> m ;
	
	string s;
	while(m -- )
	{
	    int a, b , c;
	    cin >> a >> b >> c >> s;
	    add(a , b , c) , add( b , a , c);
	}
	
	memset(d , 0x3f , sizeof d);
    d[1] = 0 ;
    dfs(1);
    
    memset(st , 0 , sizeof st);
	memset(d , 0x3f , sizeof d);
	d[c] = 0 , ans = 0;
	
	dfs(c);
	
	cout << ans << "\n";
	
	return 0;
}
