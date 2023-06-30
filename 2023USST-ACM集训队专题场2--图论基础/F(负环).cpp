#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 2010  , M = 6020;

int n , m ;
int h[N] , e[M] , w[M] , ne[M] , idx;
int cnt[N] ,d[N];
bool st[N];

void add(int a , int b , int c)
{
    e[idx] = b , w[idx] = c , ne[idx] = h[a] , h[a] = idx ++ ;
}

bool spfa()
{
    for(int i = 1 ; i <= n ; i ++ )
        cnt[i] = st[i] = 0 , d[i] = 0x3f3f3f3f;
    
    queue<int>q;
    q.push(1);d[1] = 0;
    st[1] = true;
    
  while(q.size())
    {
        int t = q.front();
        q.pop();
        
        st[t] = false; 
        for(int i = h[t] ; ~ i  ; i = ne[i])
        {
            int j = e[i];
            if(d[j] > d[t] + w[i])
            {
                d[j] = d[t] + w[i];

                if(!st[j])
                {
                    if(++ cnt[t] >= n)return true;             
                    q.push(j);
                    st[j] = true;
                }
            }
        }
        
    }
    
    return false;
}

void solve()
{
    memset(h , -1 ,sizeof h);
    idx = 0 ;
    
    cin >> n >> m ;
    while(m -- )
    {
        int a , b , c;
        cin >> a >> b >> c ;
        add(a , b , c);
        if(c >= 0)add(b , a , c);
    }
    
    int t = spfa();
    
    cout << (t ? "YES\n" : "NO\n");
    
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin >> tt;
	while(tt -- )
	    solve();
	
	
	return 0;
}
