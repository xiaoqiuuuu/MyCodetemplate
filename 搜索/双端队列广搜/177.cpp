// Problem: 电路维修
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/177/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

typedef pair<int,int> PII ;

void solve()
{
    int n , m ;
    cin >> n >> m ;
    
    vector<string> g(n);
    for(int i = 0 ; i < n ; i ++ )
        cin >> g[i];
    
    vector d(n + 1, vector<int>(m + 1 , 0x3f3f3f3f));
    vector st(n + 1 , vector<bool> (m + 1 , 0 ));
    
    int flg = 0 ;
    
    deque<PII> q;
    q.push_back({0 , 0});
    d[0][0] = 0;
    
    vector<int>dx = {-1 , -1 , 1 , 1};
    vector<int>dy = {- 1 , 1 , -1 , 1};
    vector<int>Dx = {- 1 , -1 , 0 ,0};
    vector<int>Dy = {- 1 , 0  , -1 ,0};
    string move = "\\\/\/\\";

    while(q.size())
    {
        auto t = q.front();
        q.pop_front();
    
        if(st[t.first][t.second])continue;
        st[t.first][t.second] = true;
        
        for(int i = 0 ; i < 4 ; i ++ )
        {
            int u = t.first + dx[i] , v = t.second + dy[i];
            if(u >= 0 && u <= n && v >= 0 && v <= m)
            {
                 
                 int w = (move[i] != g[t.first + Dx[i]][t.second + Dy[i]]);
                 if(d[u][v] > d[t.first][t.second] + w)
                 {
                     d[u][v] = d[t.first][t.second] + w;
                     if(w == 0)q.push_front({u , v});
                     else q.push_back({u , v});
                 } 
            }    
        }    
    }
    
  //  cout << d[2][4] << "\n";
    
    if(d[n][m] == 0x3f3f3f3f)cout << "NO SOLUTION\n";
    else cout << d[n][m] << "\n";
    
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
