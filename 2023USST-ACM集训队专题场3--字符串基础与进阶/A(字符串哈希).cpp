#include<bits/stdc++.h>

using namespace std;
using LL = unsigned long long ;

//const int N = 1e5 + 10;

const int mod = 1e10 + 93;

set<LL>S;

LL p[1510];

void insert(string s)
{
    LL res = 0;
 
    s = " " + s;
       
    for(int i = 1 ; i < s.size() ; i ++ )
        res = (res + p[i] * s[i] % mod) % mod;
    
    S.insert(res);
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	p[0] = 1;
	for(LL i = 1 ; i <= 1500 ; i ++ )
	{
	    p[i] = i * p[i - 1] * 13331ll % mod;
	}
	

    int n;
    cin >> n;
    
    while(n --)
    {
        string str;
        cin >> str;
        insert(str);
    }
  
    cout << S.size() << "\n";
  
	
	return 0;
}
