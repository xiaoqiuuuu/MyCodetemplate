#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 2010 , M = 2000010;

int n , m;
int color[N];
int h[N] , e[M] , ne[M] , idx;

void add(int a , int b)
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

bool dfs(int u , int c)
{
    color[u] = c;
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        if(!color[j])
        {
            if(!dfs(j , 3 - c))return false;
        }
        else if(color[j] == c)return false;
    }
    
    return true;
}

void solve()
{
    memset(h , -1 , sizeof h);
    memset(color , 0 , sizeof color);
    idx = 0 ;

    cin >> n >> m ;
    
    while(m --)
    {
        int a , b ;
        cin >> a >> b ;
        add(a , b) , add(b , a);
    }
    
    int ok = 1;
    for(int i = 1 ; i <= n ; i ++ )
        if(!color[i])
            if(!dfs(i , 1))
            {
                ok = 0 ;
                break;
            }
    
    if(ok)cout << "No suspicious bugs found!\n";
    else cout << "Suspicious bugs found!\n";
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tt = 1;
	cin >> tt;
	
	for(int i = 1 ; i <= tt ; i ++ )
	{
	    cout << "Scenario #" << i <<":\n";
	    solve();
	    cout << "\n";
	}
	
	return 0;
}
