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
	
	vector<int>f(m + 1);
	
	for(int i = 1 ; i <= n ; i ++ )
	{
	    int w , v;
	    cin >> v >> w;
	    for(int j = m ; j >= v ; j -- )
	        f[j] = max(f[j] , f[j - v] + w);
	}
	
	cout << f[m] << "\n";
	
	
	return 0;
}
