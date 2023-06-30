// Problem: 最优乘车
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/922/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 510;

int g[N][N] ;
int d[N];
bool st[N];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int n , m ;
    cin >> n >> m ;
    
    string line;
    getline(cin , line);
    
    while( n -- )
    {
        getline(cin , line);
        stringstream ss(line);
        int x;
        vector<int> res;
        while(ss >> x)
            res.push_back(x);
        for(int i = 0 ; i < res.size() ; i ++ )
            for(int j = i + 1 ; j < res.size() ; j ++ )
                g[res[i]][res[j]] = 1;
    }

    
    queue<int> q;
    q.push(1);
    st[1] = true;
    
    while(q.size())
    {
         auto t = q.front() ;
         q.pop();
         
         for(int i = 1 ; i <= m ; i ++ )
             if(!st[i] && g[t][i])
             {
                 d[i] = d[t] + 1;
                 q.push(i);
                 st[i] = true;
             }   
    }
    
    
    if(!st[m])cout << "NO\n";
    else cout << d[m] - 1 << "\n";
    	
	
	return 0;
}
