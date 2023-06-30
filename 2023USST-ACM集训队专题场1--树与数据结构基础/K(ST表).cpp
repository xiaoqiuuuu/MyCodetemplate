#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

void solve()
{
    int n , m ;
    cin >> n >> m ;
    
    vector<int>a(n + 1);
    for(int i = 1 ; i <= n ; i ++ )
        cin >> a[i];
    
    
    vector f(n + 1 , vector<int> (30 , 0));
    
    for(int i = 1 ; i <= n ; i ++ )
        f[i][0] = a[i];
        
    for(int j = 1 ; j <= log2(n) ; j ++ )
        for(int i = 1 ; i + (1 << (j - 1))<= n ; i ++ )
        {
            f[i][j] = max(f[i][j - 1] , f[i + (1 << (j - 1))][j - 1]);
        }
    
    while(m -- )
    {
        int l , r;
        cin >> l >> r ;
        
        int len = log2(r - l + 1);
        
        cout << max(f[l][len] , f[r - (1 << (len)) + 1][len]) << "\n";
        
    }
    
    
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1;
	//cin>>tt;
	while(tt--)
		solve();
	
	return 0;
}
