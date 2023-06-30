#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010 , M = 2 * N;

int n , m ;
int h[N] , e[M] , ne[M] , idx;
int tr[N] , sz[N] , vis[N] , id;

int lowbit(int x)
{
    return x & - x;
}

void add(int x , int c)
{
    for(int i = x ; i <= n ; i += lowbit(i))
        tr[i] += c;
}

int sum(int x )
{
    int res = 0;
    for(int i = x ; i ; i -= lowbit(i))
        res += tr[i];
    return res; 
}

void Add(int a , int b )
{
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

int dfs(int u , int fa)
{
    vis[u] = ++ id;
    
    int sum = 1;
    for(int i = h[u] ; ~ i ; i = ne[i])
    {
        int j = e[i];
        if(j == fa)continue;
        sum += dfs(j , u); 
    }
    sz[u] = sum;
    return sum;
}
 
void modify(int x)
{
    if(sum(vis[x]) - sum(vis[x] - 1) == 1)add(vis[x] , -1 );
    else add(vis[x] , 1);

    return ;
}

int query(int x)
{
    return sum(vis[x] + sz[x] - 1) - sum(vis[x] - 1);
}

int main()
{
    memset(h , - 1, sizeof h);
    
    scanf("%d" , &n);
    for(int i = 2 , a , b ; i <= n ; i ++ )
    {
        scanf("%d %d" , &a , &b);
        Add(a , b ) , Add(b , a);
    }
    
    dfs(1 ,1);   
    for(int i = 1 ; i <= n ; i ++ )
    {
        tr[i] += 1;
        int j = i + lowbit(i);
        if(j <= n)
            tr[j] += tr[i];
    }
    
    
    scanf("%d" , &m);
    char op[2] ;int x ;
    while(m -- )
    {
        scanf("%s %d" , op , &x );
        if(*op == 'Q')
        {
            printf("%d\n" , query(x));
        }
        else modify(x);
    }
    
    return 0 ;
}