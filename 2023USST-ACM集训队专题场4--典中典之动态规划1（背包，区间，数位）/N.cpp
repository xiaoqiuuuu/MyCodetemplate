// Problem: 
//     P8764 [蓝桥杯 2021 国 BC] 二进制问题
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P8764


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;





int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    vector<vector<LL>>f(70 , vector<LL>(70 , 0));
    for(int i = 0; i < 66; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) f[i][j] = 1;
            else f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]);
 

 
   
    LL n , k ;
    cin >> n >> k;
    vector<int>a ;
    while(n)
    {
        a.push_back(n % 2);
        n /= 2;
    }
    
    LL ans = f[a.size() - 1][k], res = 1 ;//res 表示前面用了多少个1
    
    //cout << ans << "\n";
    


    for(int i = a.size() - 2 ; i >= 0 ; i -- )
    {
        if(a[i])
        {
            ans += f[i][k - res];           
            res ++ ;
            if(res == k)
            {
                ans ++ ;
                break;
            }
        }else
        {
         //   ans
        }

    }
    
    
    // 1011
// 
    // 1001
    // 1010
    // 0101
    // 0011
    

    
    cout << ans << "\n";
    
	
	return 0;
}
