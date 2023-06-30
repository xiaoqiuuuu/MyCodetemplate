#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

void solve()
{
    int n , x , y ;
    cin >> n >> x >> y;
    
    vector<int>a(n + 1);
    for(int i = 1 ; i <= n ; i ++ )
        cin >> a[i];
    
    vector<vector<LL>> f(n + 1 , vector<LL> (n + 1));
    //f[l][r] 表示把 [l ,r] 区间中 大于 a[l] 的楼房全部摧毁的最小花费
    
    for(int len = 2 ; len <= n + 1 ; len ++ )
        for(int i = 0 ; i + len - 1 <= n  ; i ++ )
        {
            int l = i , r = i + len - 1;
            if(a[r] < a[l])f[l][r] = f[l][r - 1];
            else
            {
                f[l][r] = f[l][r - 1] + x;
                for(int j = l + 1; j < r ; j ++ )
                    if(a[j] <= a[r]) // 能摧毁整个 [l ,r] 区间
                        f[l][r] = min(f[l][r] , y + f[l][j - 1] + f[j][r - 1]);
            }
        }
    
    cout << f[0][n] << "\n";
    
    
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
