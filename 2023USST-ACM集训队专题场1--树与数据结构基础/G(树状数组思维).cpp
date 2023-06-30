#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

void solve()
{
    int n ;
    cin >> n ;
    string a ;
    cin >> a ;
    a = " " + a;
      
    vector<int>cnt (n + 1);
    for(int i = 1 ; i <= n ; i ++ )
        if(a[i] == '1')
        {
            int j = i + (i & - i);
            if(j <= n)
            {
                cnt[j] ++ ;
            }
        }
    
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(a[i] == '0' && cnt[i] == 1)ans ++ ;
        if(a[i] == '1' && cnt[i] == 0)ans ++ ;
    }
      
    cout << ans << "\n";
    
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
