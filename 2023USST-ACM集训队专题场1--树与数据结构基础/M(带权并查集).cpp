#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
using LL = long long ;

const int N = 5010;

int n , m;
int p[N] , d[N];

int find(int x)
{
    if(p[x] != x)
    {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    } 
    return p[x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    	cin >> n >> m;
    	
    	for(int i = 1 ; i <= n ; i ++ )
    	    p[i] = i;
    	
    	int res = 0 ;
	while(m -- )
	{
	    int op , x , y ;
	    cin >> op >> x >> y ;
	    if (x > n || y > n) res ++ ;
        else
        {
            int px = find(x), py = find(y);
            if(px == py)
            {
                if(op == 1)
                {
                    if((d[x] - d[y]) % 3)res ++ ;
                }
                else
                {
                    if((d[x] - 1 - d[y]) % 3) res ++ ;
                }
            }
            else
            {
                if(op == 1)
                {
                    d[px] = d[y] - d[x];
                    
                }
                else
                {
                    d[px] = d[y] - d[x] + 1;
                }
                p[px] = py;
            }
        }
	   
	}
	
	cout << res << "\n";
	
	
	return 0;
}
