#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 2050 , M = 2050 ;

int n , m ;
int tr1[N][M] ;
LL tr2[N][M] , tr3[N][M] , tr4[N][M];

int lowbit(int x)
{
    return x & -x;
}

void add(int x ,int y ,int c)
{
   for(int i = x ; i <= n ; i += lowbit(i))
       for(int j = y ; j <= m ; j += lowbit(j))
       {
            tr1[i][j] += c;
            tr2[i][j] += 1ll * x * c;
            tr3[i][j] += 1ll * y * c;
            tr4[i][j] += 1ll * x * y * c;
        }
}
LL sum(int x , int y)
{
    LL res = 0;
    for(int i = x ; i ; i -= lowbit(i))
        for(int j = y ; j ; j -= lowbit(j))
         {
             res += 1ll * (x + 1) * (y + 1) * tr1[i][j];
             res -= 1ll * (y + 1) * tr2[i][j];
             res -= 1ll * (x + 1) * tr3[i][j];
             res += 1ll * tr4[i][j];
         } 
    return res;
}

void modify(int x1 , int y1 , int x2 ,int y2 , int d)
{
    add(x1 , y1 , d);
    add(x1 , y2 + 1 , -d);
    add(x2 + 1, y1 , -d);
    add(x2 + 1 , y2 + 1 , d);
}


LL query(int x1 , int y1 , int x2 , int y2)
{
    return sum(x2 , y2) - sum(x1 - 1 , y2) - sum(x2 , y1 - 1) + sum(x1 - 1 , y1 - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    char x;
    cin >> x >> n >> m;
    
    string op;
    while(cin >> op)
    {
        int x1 , y1 , x2 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(op == "L")
        {
            int d;cin >> d;
            modify(x1 , y1 , x2 , y2 , d);
        }
        else
        {
            cout << query(x1 , y1 , x2 , y2) << "\n";
        }
    }
    
    return 0 ;
}