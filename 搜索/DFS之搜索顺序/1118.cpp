// Problem: 马走日
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1118/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 30;

int n , m , x , y ;
int cnt ;
bool st[N][N];

int dx[8] = {2 , 2 , 1 , -1 , -2 , -2 , -1 , 1};
int dy[8] = {-1 , 1 , 2 , 2 , 1 , -1 , -2 , - 2};


void dfs(int x , int y , int res)
{
    if(res == n * m )
    {
        cnt ++ ;
        return ;
    }
    
    for(int i = 0 ; i < 8 ; i ++ )
    {
        int u = x + dx[i] , v = y + dy[i];
        if(u >= 0 && u < n && v >= 0 && v < m && !st[u][v])
        {
            st[u][v] = true;
            dfs(u , v , res + 1);
            st[u][v] = false;
        }
    }
}

void solve()
{

    cin >> n >> m >> x >> y ;
    
    cnt = 0 ;
    memset(st , 0 , sizeof st);
    
    st[x][y] = true;
    dfs(x , y , 1);
    
    cout << cnt << "\n";
    
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1;
	cin>>tt;
	while(tt--)
		solve();
	
	return 0;
}
