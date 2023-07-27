#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int N = 410 , M = 2 * N * N;

int n , m;
int h[N] , e[M] , ne[M] , idx;
int match[N];
bool st[N];

void add(int a , int b )
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
} 

bool find(int u)
{
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j] == 0 || find(match[j]))
            {
                match[j] = u;
                return true;
            }
        }
    }
    
    return false;
}


void solve()
{
    memset(match , 0 , sizeof match);
    memset( h , - 1 , sizeof h);
    idx = 0 ;
    

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ )
    {
        int k;cin >> k;
        while(k -- )
        {
            int x ;cin >> x;
            add(i , x);
        }
    }
    
    int res = 0;
    for(int i = 1 ; i <= n ; i ++ )
    {
        memset(st , 0 , sizeof st);
        if(find(i))
            res ++ ;
    }
    
    cout << res << "\n";
    
    
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tt = 1;
	//cin>>tt;
	while(tt--)
		solve();
	
	return 0;
}
