// Problem: 
//     P1757 通天之分组背包
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1757


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n , m ;
	cin >> m >> n;
	
	map<int,vector<pair<int,int>>> mp;
	
	for(int i = 1;  i <= n ; i ++ )
	{
	    int v , w , s;
	    cin >> v >> w >> s;
	    mp[s].push_back({v , w});
	}
	
	n = mp.size();
	
	vector<int>f(m + 1);
	
	for(int i = 1 ; i <= n ; i ++ )
	    for(int j = m ; j >= 0 ; j -- )
	    {
	        auto g = mp[i];
	        for(auto [v , w] : g)
	        {
                if(j >= v)
	                f[j] = max(f[j] , f[j - v] + w);
	        }
	    }
	
	cout << f[m] << "\n";
	
	return 0;
}
