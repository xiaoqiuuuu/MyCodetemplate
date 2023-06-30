// Problem: 数字游戏
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1084/


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

int f[35][12];

int count(int x)
{
    if(!x)return 1;
    
    vector<int>a ;
    
    int c = x;
    while(c)
    {
        a.push_back(c % 10);
        c /= 10;
    }
    
    int ans = 0 , last = 0;
    for(int i = a.size() - 1 ; ~ i ; i -- )
    {    
        if(a[i] < last)break;
        if(a[i])
        {
            for(int j = last ; j < a[i] ; j ++ )
                ans += f[i + 1][j];
                
            last = a[i];
        }
        else if(last)break;
        
        if(!i)ans ++ ;
    }
    
                  
    return ans;
    
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
    for(int i = 0 ; i <= 9 ; i ++ )
        f[1][i] = 1;

	for(int i = 2 ; i <= 20 ; i ++ )
	    for( int j = 0 ; j <= 9 ; j ++ )
	        for(int k = j ; k <= 9 ; k ++ )
	            f[i][j] += f[i - 1][k];
	
	int l , r;
	while(cin >> l >> r )
	{
	    if(l > r)swap(l , r);
	        cout << count(r) - count(l - 1) << "\n";
	}

	
	return 0;
}
