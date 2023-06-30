#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 5e3 + 10 , M = 2 * N;

int n , m;
int h[N] , e[M] , w[M] , ne[M] , idx ;
int d[N] , cnt[N];
bool st[N];

void add(int a , int b , int c)
{
    e[idx] = b , w[idx] = c , ne[idx] = h[a] , h[a] = idx ++ ;
}

bool spfa(int u)
{
    memset(d , 0x3f , sizeof d);
    queue<int> q;
    q.push(u);d[u] = 0 ;st[0] = true;
    
    while(q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;
        
        for(int i = h[t] ; ~ i ; i = ne[i])
        {
            int j = e[i];
            
            
            if(d[j] > d[t] + w[i])
            {
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n + 1)return false;
                
                d[j] = d[t] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return true;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(h , - 1 ,sizeof h);
	
	cin >> n >> m ;
	while( m -- )
	{
	    int a , b , c;
	    cin >> a >> b >> c ;
	    add(b , a , c);
	}
	
    for(int i = 1 ; i <= n ; i ++ )
        add(0 , i , 0);
    
    int t = spfa(0);
	
	if(!t)cout << "NO";
	else for(int i = 1 ; i <= n ; i ++ )
	    cout << d[i] << " ";
	cout << "\n";
	
	return 0;
}
