// Problem: 
//     P1507 NASA的食物计划
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1507


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int m1 ,m2 , n;
	cin >> m1 >> m2 >> n;
	
	vector f(m1 + 1 , vector<int>(m2 + 1));
	for(int i = 1 ; i <= n ; i ++ )
	{
	    int v1 , v2 , w;
	    cin >> v1 >> v2 >> w;
	    for(int j = m1 ; j >= v1 ; j -- )
	        for(int k = m2 ; k >= v2 ; k -- )
	            f[j][k] = max(f[j][k] , f[j - v1][k - v2] + w);    
	}
	
	cout << f[m1][m2] << "\n";
	
	
	return 0;
}
