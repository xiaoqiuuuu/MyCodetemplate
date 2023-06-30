#include<bits/stdc++.h>

using namespace std;


using LL = long long ;

const int mod = 10007;

char s[1010];
int f[1010][1010];

void solve()
{
    cin >> s;
    
    memset(f , 0 , sizeof f);
    int n = strlen(s);
   
    for(int i = 0 ; i < n ; i ++ )
        f[i][i] = 1;
    
    for(int len = 2 ; len <= n ; len ++ )
        for(int i = 0 ; i + len - 1 < n ; i ++ )
        {
            int l = i , r = i + len - 1;
            
            f[l][r] += ((f[l + 1][r] + f[l][r - 1] - f[l + 1][r - 1]) % mod + mod ) % mod;
            
            if(s[l] == s[r])
            {
                f[l][r] += f[l + 1][r - 1] + 1;
            }         
            f[l][r] %= mod;
        }
   
    cout << f[0][n - 1] % mod << "\n";
    
	return ;
}

int main()
{
    
    

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1;
	cin>>tt;
	for(int i = 1 ; i <= tt ; i ++ )
	{
	    cout << "Case " << i << ": ";
	    solve();
	}
	
	return 0;
}
