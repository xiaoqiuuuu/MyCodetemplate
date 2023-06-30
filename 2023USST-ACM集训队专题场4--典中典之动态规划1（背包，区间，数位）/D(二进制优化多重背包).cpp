// Problem: 
//     P1776 宝物筛选
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1776


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//二进制优化的多重背包 , 转换为 01 背包来计算


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
    int n , m;
    cin >> n >> m;
    
    vector<int>v(n + 1) , w(n + 1) , cnt(n + 1);
    for(int i = 1 ; i <= n ; i ++ )
        cin >> w[i] >> v[i] >> cnt[i];
    
    vector<int>V = {0}, W = {0};
    
    for(int i = 1 ; i <= n ; i ++ )
    {
        int sum = cnt[i];
        for(int j = 0 ; ; j ++ )
        {
             if(sum >= (1 << j))   
             {
                 V.push_back(v[i] * (1 << j));
                 W.push_back(w[i] * (1 << j));
                 sum -= (1 << j);   
             }
             else
             {
                 if(sum)
                 {
                     V.push_back(v[i] * sum);
                     W.push_back(w[i] * sum);
                 }
                 break;
             }
        }
    }
    
    n = V.size() - 1;
    
    vector<int>f(m + 1);
    
    for(int i = 1 ; i <= n ; i ++ )
        for(int j = m ; j >= V[i]; j -- )
            f[j] = max(f[j] , f[j - V[i]] + W[i]);
    
    cout << f[m] << "\n";
	
	return 0;
}
