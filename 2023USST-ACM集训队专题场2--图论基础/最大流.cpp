// Problem: 
//     P3376 【模板】网络最大流
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P3376


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 210 , M = 10010;
const int INF = 2e9 + 7    ;

int n , m , s , T;
LL h[N] , e[M] , f[M] , ne[M] , idx;
LL q[N] , d[N] , pre[N];
bool st[N];

void add(int a , int b , int c)
{
    e[idx] = b , f[idx] = c , ne[idx] = h[a] , h[a] = idx ++ ;
    e[idx] = a , f[idx] = 0 , ne[idx] = h[b] , h[b] = idx ++ ;
}

bool bfs()
{
    memset(st , 0 , sizeof st);
    
    int hh = 0 , tt = 0 ;
    q[0] = s , st[s] = true , d[s] = INF;
    
    while(hh <= tt)
    {
        int t = q[hh ++ ];
        for(int i = h[t] ; ~ i ; i = ne[i])
        {
            int j = e[i];
            if(!st[j] && f[i])
            {
                st[j] = true;
                d[j] = min(d[t] , f[i]);
                pre[j] = i;
                if(j == T)return true;
                q[ ++ tt] = j;
            }
        } 
    }
    
    return false;
}

LL EK()
{
    LL r = 0;
    while (bfs())
    {
        r += d[T];
        for (int i = T; i != s; i = e[pre[i] ^ 1])
            f[pre[i]] -= d[T], f[pre[i] ^ 1] += d[T];
    }
    return r;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	memset(h , -1 , sizeof h);

	cin >> n >> m >> s >> T;
	while(m -- )
	{
	    int a , b , c ;
	    cin >> a >> b >> c ;
	    add(a , b , c) ;
	}
	
	cout << EK() << "\n";
	
	return 0;
}
