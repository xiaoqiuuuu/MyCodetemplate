// Problem: Windy数
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1085/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

int f[30][30]; // f[i][j] 表示前 i 位 ， 第一位为 j 的 windy 数量


int count(int x)
{
    if(!x)return 0;
    
    vector<int>a;
    while(x)
    {
        a.push_back(x % 10);
        x /= 10;
    }    
    
    int ans = 0 , last = -12 ;
    for(int i = a.size() - 1 ; ~ i ; i -- )
    {
        for(int j = (i == a.size() - 1); j <= a[i] - 1 ; j ++ )
            if(abs(j - last) >= 2)
                ans += f[i + 1][j];
        
        if(abs(a[i] - last) < 2)break;
        last = a[i];
        if(!i)ans ++ ;
    }
    
    for(int i = 1 ; i < a.size() ; i ++ )
        for(int j = 1 ; j <= 9 ; j ++ )
            ans += f[a.size() - i ][j];
    
    return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for(int i = 0 ; i <= 9 ; i ++ )
	    f[1][i] = 1;
	for(int i = 2 ; i <= 25 ; i ++ )
	    for(int j = 0 ; j <= 9 ; j ++ )
	        for(int k = 0 ; k <= 9 ; k ++ )
	            if(abs(j - k) >= 2)
	                f[i][j] += f[i - 1][k];
	

	int l ,r ;
	cin >> l >> r ;
	if(l > r)swap(l ,r);
	
	
	cout << count(r) - count(l - 1) << "\n";
	
	return 0;
}
