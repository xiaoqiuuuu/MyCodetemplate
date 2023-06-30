#include<bits/stdc++.h>

using namespace std;

map<char , int> mp;


int tr[3000010][65];
map<int,int>cnt;
int idx = 0;

void insert(string s){
    int p = 0 ;
    for(int i = 0 ; i < s.size() ; i ++ )
    {
      int u = mp[s[i]];
     
      if(!tr[p][u])tr[p][u] = ++ idx;
      p = tr[p][u];
      cnt[p] ++ ;
    }
       
}
int query(string s)
{
    int res = 0 , p = 0;
    for(int i = 0 ; i < s.size() ; i ++ )
    {
      int u = mp[s[i]];
      if(!tr[p][u])return res;
      p = tr[p][u];
    }
    return cnt[p];
}



void solve()
{
    for(int i = 0 ; i <= idx ; i ++ )
        for(int j = 0 ; j <= 64 ; j ++ )
            tr[i][j] = 0;
    cnt.clear();
    idx = 0;
    
    int n , m;
    cin >> n >> m;
    
    while( n -- )
    {
        string x;
        cin >> x;
        
        insert(x);
    }
    
    while(m -- )
    {
        string x;
        cin >> x;
        
        cout << query(x) << "\n";
    }
    
    
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int id = 1;
    for(char i = 'A' ; i <= 'Z' ; i ++ )
        mp[i] = id ++ ;
    for(char i = 'a' ; i <= 'z' ; i ++ )
        mp[i] = id ++ ;
    for(int i = '0' ; i <= '9' ; i ++ )
        mp[i] = id ++ ;
    
    int tt;
    cin >> tt;
    while(tt -- )
        solve();
    
    return 0 ;
}