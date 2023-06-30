// Problem: D. Iahub and Xors
// Author : Weiqt
// URL: https://codeforces.com/contest/341/problem/D


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 1010 ;

struct Two_Fenwick{
int n , m;
LL tr1[N][N] , tr2[N][N] , tr3[N][N] , tr4[N][N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x , int y , int c)
{
    for(int i = x ; i <= n ; i += lowbit(i))
        for(int j = y ; j <= n ; j += lowbit(j))
        {
            tr1[i][j] ^= c;
            if(x & 1)tr2[i][j] ^= c;
            if(y & 1)tr3[i][j] ^= c;
            if((1ll * y * x) & 1)tr4[i][j] ^= c;
        }
}

LL sum(int x ,int y)
{
    LL res = 0 ;
    for(int i = x ; i ; i -= lowbit(i))
        for(int j = y ; j ; j -= lowbit(j))
        {
            
            if(1ll * (x + 1) * (y + 1) & 1)res ^= tr1[i][j];
            if((y + 1) & 1)res ^= tr2[i][j];
            if((x + 1) & 1)res ^= tr3[i][j];
            res ^= tr4[i][j];
        }   
     
    return res;
}
LL query(int x1 , int y1 , int x2 , int y2)
{
    return sum(x2 , y2) ^ sum(x2 , y1 - 1) ^ sum(x1 - 1 , y2) ^ sum(x1 - 1, y1 - 1);
}
void modify(int x1 , int y1 , int x2 , int y2 , int d)
{
    add(x1 , y1 , d);
    add(x1 , y2 + 1 , d);
    add(x2 + 1 , y1 , d);
    add(x2 + 1 , y2 + 1 , d);
}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	while(m -- )
	{
	    int op , x1 , y1 , x2 , y2 ;
	    cin >> op >> x1 >> y1 >> x2 >> y2 ;
	    if(op == 1)
	        cout << query(x1 , y1 , x2 , y2) << "\n";
	    else
	    {
	        LL d;cin >> d;
	        modify(x1 , y1 , x2 , y2 , d);
	    }
	}
	
	
	return 0;
}
