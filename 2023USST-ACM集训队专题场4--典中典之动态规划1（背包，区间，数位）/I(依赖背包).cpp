#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n , m;
    while(cin >> n >> m)
    {
       
        vector<int>f(m + 1);
        // f[i][j] 表示 前 i 组物品中选 ， 总体积不超过 j 的方案数
        // 对于第 i 组物品 ，        
        for(int i = 1 ; i <= n ; i ++ )
        {
            auto g = f;
            int boxm , boxn;
            cin >> boxm >> boxn;
            for(int j = 1 ; j <= boxn ; j ++ )
            { 
                int v , w;
                cin >> v >> w;
               for(int k = m ; k >= v ; k -- )
                 g[k] = max(g[k] ,  g[k - v] + w);
             }   
           
            for(int j = boxm ; j <= m ; j ++ )
                f[j] = max(f[j]  , g[j - boxm]);
        }
        cout << f[m] << "\n";
    }

    return 0 ;
}