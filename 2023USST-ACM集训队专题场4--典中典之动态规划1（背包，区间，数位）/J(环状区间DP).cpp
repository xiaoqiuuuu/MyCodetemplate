// Problem: 
//     P1063 [NOIP2006 提高组] 能量项链
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1063


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n ;
	cin >> n ;
	vector<int>a(2 * n );
	for(int i = 1 ; i <= n ; i ++ )
	    cin >> a[i];
	for(int i = n + 1 ; i < a.size() ; i ++ )
	    a[i] = a[i - n];
	a.push_back(a[n]);
    
    vector f(2 * n + 1 , vector<LL>(2 * n + 1));
	
	for(int len = 2 ; len <= 2 * n - 1 ; len ++ )
	    for(int i = 1 ; i + len - 1 <= 2 * n; i ++ )
	    {
	        int l = i , r = i + len - 1;
	        for(int j = l  ; j < r ; j ++ )
	             f[l][r] = max(f[l][r] , f[l][j] + f[j + 1][r] + a[l] * a[j + 1] * a[r + 1]) ;
	    }
	
	
	//cout << f[3][5] << "\n";
	
	LL ans = 0 ;
	for(int i = 1 ; i <= n ; i ++ )
	    ans = max(ans , f[i][i + n - 1]);
	
	cout << ans << "\n";
	
	return 0;
}

