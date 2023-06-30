#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s , t ;
	cin >> t >> s ;
	
	int n = s.size() , m = t.size();
	
	t = " " + t , s = " " + s ;
	
	vector<int>z(n + 1);
	z[1] = n ;
	for(int i = 2 , l , r = 0 ; i <= n ; i ++ )
	{
	    if(i <= r)z[i] = min(z[i - l + 1] , r - i + 1);
	    while(s[z[i] + 1] == s[i + z[i]])z[i] ++ ;
	    if(i + z[i] - 1 > r)l = i , r = i + z[i] - 1;
	}
	
	vector<int>p(m + 1);
	for(int i = 1 , l , r = 0 ; i <= m ; i ++ )
	{
	    if(i <= r)p[i] = min(z[i - l + 1] , r - i + 1);
	    while(1 + p[i] <= n && i + p[i] <= m && s[1 + p[i]] == t[i + p[i]])p[i] ++ ;
	    if(i + p[i] - 1 > r)r = i + p[i] - 1 , l = i;
	}
	
    LL ans = 0;
    for(int i = 1 ; i <= n ; i ++ )
        ans ^= 1ll * i * (z[i] + 1);
	
    cout << ans << "\n";
    ans = 0 ;
    for(int i = 1 ; i <= m ; i ++ )
        ans ^= 1ll * i * (p[i] + 1);
    cout << ans << "\n";
	
	
	return 0;
}
