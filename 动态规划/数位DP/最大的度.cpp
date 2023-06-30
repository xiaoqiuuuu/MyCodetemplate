#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

LL f[35][35] , dp[35][35];
int l , r , b , k;
vector<int>a;

LL dfs(int p , int res)
{
    if(p < 0){
        return (res == 0);
    }
    if(res == - 1)return 0;
    
    if(~ dp[p][res])return dp[p][res];
    
    int sum = 0 ;
    
    if(a[p])
    {
        sum += f[p][res];
        if(a[p] != 1){
            if(res)sum += f[p][res - 1];
        }
        else sum += dfs(p - 1 , res - 1);
    }
    else sum += dfs(p - 1 , res);
    
    return dp[p][res] = sum;
}


LL count(int x)
{
    if(x == 0)return 0;

    memset(dp , - 1 , sizeof dp);

    int c = x;
    a.clear();
    while(c)
    {
        a.push_back(c % b);
        c /= b;
    }
    
    return dfs(a.size() - 1 , k );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0 ; i <= 32 ; i ++ )
        f[i][0] = 1;
    for(int i = 1 ; i <= 32 ; i ++ )
        for(int j = 1 ; j <= i ; j ++ )
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
    
    cin >> l >> r >> k >> b ;
     
    cout << count(r) - count(l - 1) << "\n";
    
    return 0 ;
}