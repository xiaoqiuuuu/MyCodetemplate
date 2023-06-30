#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    string s , p;
    cin >> s >> p ;
    
    int m = p.size() ,n = s.size() ;
    s = " " + s;
    p = " " + p;	
    
    
    vector<int>ne(m + 1 , 0);
    for(int i = 2 , j = 0 ; i <= m ; i ++ )
    {
        while(j && p[i] != p[j + 1])j = ne[j];
        if(p[i] == p[j + 1]) j ++ ;
        ne[i] = j;
    }
    
    for(int i = 1 , j = 0 ; i <= n ; i ++ )
    {
        while(j && s[i] != p[j + 1])j = ne[j];
        if(s[i] == p[j + 1]) j ++ ;
        if(j == m)
        {
            cout << i - m + 1 << "\n";
            j = ne[j];
        }
    }
    
    
    for(int i = 1 ; i <= m ; i ++ )
        cout << ne[i] << " ";
    cout << "\n";
	
	
	return 0;
}
