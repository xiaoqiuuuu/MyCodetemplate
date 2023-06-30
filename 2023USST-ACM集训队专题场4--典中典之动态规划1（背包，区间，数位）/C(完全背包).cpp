// Problem: 
//     P1853 投资的最大效益
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1853


#include<bits/stdc++.h>

using namespace std;
using LL = long long;


//当先年份的钱是上一年的最大值， 相当于背包容量在变化的完全背包 ，每一年都计算一次即可

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s , n , d;
    cin >> s >> n >> d;
    
    vector<int>v(d + 1) , w(d + 1);
    for(int i = 1 ; i <= d ; i ++ )
        cin >> v[i] >> w[i] ,  v[i] /= 1000;
    
    LL ans = s;
    for(int year = 1 ; year <= n ; year ++ )
    {
        int m = ans / 1000;    
        vector<LL>f(m + 1);
        for(int i = 1 ; i <= d ; i ++ )
            for(int j = v[i] ; j <= m ; j ++ )
                f[j] = max(f[j] , f[j - v[i]] + w[i]);
        ans += f[m];       
    }
    
    cout << ans << "\n";
    
    return 0 ;
}
