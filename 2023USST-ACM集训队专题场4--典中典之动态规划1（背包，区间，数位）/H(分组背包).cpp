#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n , m ;
    cin >> m >> n ;
    
    vector<vector<int>>vis(n + 1) ;
    vector<int>w(n + 1) , c(n + 1) , tmp(n + 1);
    
    
    for(int i = 1 ; i <= n ; i ++ )
    {
        int v , p , q;
        cin >> v >> p >> q;
        w[i] = v * p;
        c[i] = v;
        if(q)vis[q].push_back(i) ;
        else tmp[i] ++ ;
    }
   
    
    vector<int>a = {0} , b = {0};
    
    vector<int>f(m + 1);
    
    for(int i = 1 ; i <= n ; i ++ )
        if(tmp[i])
        {
            vector<int>a , b;
            a.push_back(c[i]) , b.push_back(w[i]);
            if(vis[i].size())
            {
                a.push_back(c[vis[i][0]] + c[i]) , b.push_back(w[vis[i][0]] + w[i]);
                if(vis[i].size() >= 2)
                {
                    a.push_back(c[vis[i][1]] + c[i]) , b.push_back(w[vis[i][1]] + w[i]);
                    a.push_back(c[vis[i][1]] + c[i] + c[vis[i][0]]) , b.push_back(w[vis[i][1]] + w[vis[i][0]] + w[i]);     
                } 
            }
            for(int j = m ; j > 0 ; j -- )
                for(int k = 0 ; k < a.size() ; k ++ )
                    if(j >= a[k])
                        f[j] = max(f[j] , f[j - a[k]] + b[k]);  

        }
        
    
    cout << f[m] << "\n";
    
    
    return 0;
}