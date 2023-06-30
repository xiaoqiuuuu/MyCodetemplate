#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;


int n ;
int h[N] , e[M] , ne[M] , idx;
int v[N] , mx = 0x3f3f3f3f;
bool st[N];

void add(int a , int b)
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

int dfs(int u)
{
    st[u] = true;
    int sum = 1 , res = 0;
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        if(st[j])continue;
        int sz = dfs(j);
        res = max(res , sz);
        sum += sz; 
    }
    v[u] = max( n - sum , res);
    
    mx = min(mx , v[u]);
    
    return sum;
}

void solve()
{
    memset(h , - 1, sizeof h);
    memset(st , 0 , sizeof st);
    //memset(v , 0 , sizeof v);
    idx = 0 , mx = 0x3f3f3f3f;
    
    cin >> n ;
    
    for(int i = 2 ; i <= n ; i ++ )
    {
        int a , b ;
        cin >> a >> b ;
        add(a , b) , add(b , a);
    }
    
    dfs(1);
    
    
    int cnt = 0 , pos1 , pos2;
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(v[i] == mx)
        {
            if(cnt == 0)pos1 = i ,cnt ++ ;
            else if(cnt == 1)
            {
                pos2 = i;
                cnt ++ ;
                break;
            }        
        }
    }
    
    if(cnt == 1)
    {
        cout << 1 << " " << e[h[1]] << "\n";
        cout << 1 << " " << e[h[1]] << "\n";
    }
    else
    {
        int j = 0 ;
        for(int i = h[pos2] ; ~ i ; i = ne[i])
        {
            j = e[i];
            if(j != pos1)
            {
                break;
            }
        }
        
        
        cout << pos2 << " " << j << "\n";
        cout << pos1 << " " << j << "\n";
    }
    
    
    
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt;
    cin >> tt;
    while(tt --)
        solve();
    
    return 0;
}