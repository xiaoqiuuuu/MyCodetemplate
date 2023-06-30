#include<bits/stdc++.h>

using namespace std;

const int N = 40010 , M = 2 * N ;

int n ,m;
int d[N] , depth[N];
int h[N] , e[M] ,w[M] , ne[M] , idx;
int fa[N][20];


void add(int a , int b , int c)
{
    e[idx] = b , w[idx] = c , ne[idx] = h[a] , h[a] = idx ++ ;
}

void bfs(int u)
{
    memset(depth , 0x3f , sizeof depth);
    memset(d , 0x3f, sizeof d);
    depth[0] = 0 , depth[u] = 1;
    d[0] = 0 , d[u] = 0 ;
    queue<int> q;
    q.push(u);
    
    while(q.size())
    {
        auto t = q.front();q.pop();
        
        for(int i = h[t] ; ~ i ; i = ne[i])
        {
            int j = e[i];
            d[j] = min(d[j] , d[t] + w[i]);
            if(depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                q.push(j);fa[j][0] = t;
                for(int k = 1 ; k <= 18 ; k ++ )
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a , int b)
{
    if(depth[a] < depth[b])
        swap(a , b);
    
    for(int k = 18 ; k >= 0 ; k -- )
        if(depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if(a == b)return a;
    
    for(int k = 18 ; k >= 0 ; k -- )
        if(fa[a][k] != fa[b][k])
            a = fa[a][k] , b = fa[b][k];
    return fa[a][0];
}



void solve()
{
    memset(h , - 1 , sizeof h);
    idx = 0 ;
    
    cin >> n >> m ;
    for(int i = 2 , a , b , c; i <= n ; i ++ )
    {
        cin >> a >> b >> c;
        add(a , b , c) , add(b , a , c);
    }
    
    bfs(1);
    
    while(m -- )
    {
        int a , b ;
        cin >> a >> b ;
        int t = lca(a , b);
        cout << d[a] + d[b] - 2 * d[t] << "\n"; 
    }
    
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
   
    solve();

    return 0;
}