// Problem: 
//     P1833 樱花
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1833


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;


int main()
{
    int h1 , m1 , h2 , m2 , n;
    scanf("%d:%d %d:%d %d" , &h1 , &m1 , &h2 , &m2 , &n);    
    int m = (h2 - h1) * 60 + (m2 - m1) % 60;

    vector<int>f(m + 1);
    
    for(int i = 1 ; i <= n ; i ++ )
    {
        int v , w , s;
        scanf("%d %d %d" , &v , &w , &s);
        
        if(!s)
        {
            for(int j = v ; j <= m ; j ++ )
                f[j] = max(f[j] , f[j - v] + w);
        }
        else
        {
            for(int k = 1 ; k <= s ; k *= 2)
            {
                for(int j = m ; j >= k * v ; j -- )
                    f[j] = max(f[j] , f[j - v * k] + w * k);
                s -= k ;
            }
            
            if(s)
            {
                for(int j = m ; j >= s * v ; j -- )
                    f[j] = max(f[j] , f[j - v * s] + w * s);
            }
        }
    }
    
    printf("%d\n" , f[m]);
    
	
	return 0;
}
