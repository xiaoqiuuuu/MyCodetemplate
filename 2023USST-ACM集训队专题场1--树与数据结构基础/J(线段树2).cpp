#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 1e5 + 10;

struct Node{
    LL l , r , sum , add , mul;
}tr[4 * N];

int a[N] , n , m , mod ;

void pushup(int u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod ;
}

void build(int u , int l , int r)
{
    if(l == r)tr[u] = {l , r , a[l] , 0 , 1};
    else
    {
        tr[u] = {l , r , 0 , 0 , 1};
        
        int mid = l + r >> 1 ;
        
        build(u << 1 , l , mid) , build(u << 1 | 1 , mid + 1 , r);
        
        pushup(u);
    }
}

void pushdown(Node &u , Node &l , Node &r)
{
    l.sum = l.sum * u.mul % mod + u.add * (l.r - l.l + 1) % mod;
    r.sum = r.sum * u.mul % mod + u.add * (r.r - r.l + 1) % mod;
    l.add = (l.add * u.mul % mod + u.add) % mod;
    r.add = (r.add * u.mul % mod+ u.add) % mod;
    l.mul = l.mul * u.mul % mod;
    r.mul = r.mul * u.mul % mod;
    u.add = 0 ,u.mul = 1;
}

void pushdown(int u)
{
    pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
}

void modify(int u , int l , int r , int x , int op)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        if(op == 1)
        {
            tr[u].sum = x % mod * tr[u].sum % mod;
            tr[u].mul = tr[u].mul * x % mod;
            tr[u].add = tr[u].add * x % mod ;
        }
        else
        {
            tr[u].sum = (tr[u].sum + (tr[u].r - tr[u].l + 1) * x % mod) % mod;
            tr[u].add += x;
        }
    }else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l)modify(u << 1 , l , r , x, op);
        if(r > mid)modify(u << 1 | 1 , l , r , x , op);
        pushup(u);
    }
}

LL query(int u , int l , int r )
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        return tr[u].sum;
    }else
    {
        pushdown(u);
        
        LL res = 0 ;
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l)res = (res + query(u << 1 ,  l , r)) % mod;
        if(r > mid)res = (res + query(u << 1 | 1 , l , r)) % mod;
        
        
        return res;
    }
}





int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> mod;
    
    for(int i = 1 ; i <= n ; i ++ )
        cin >> a[i];
    
    build(1 , 1 , n );
    
    
    while(m -- )
    {
         int op ;
         cin >> op;
         
         if(op == 1)
         {
             int l , r , x ;
             cin >> l >> r >> x; 
             modify(1 , l , r , x, op);
        }else if(op == 2)
        {
            int l , r , x;
            cin >> l >> r >> x ;
            modify(1 , l , r , x, op);
        }
        else
        {
            int l , r ;
            cin >> l >> r ;
            cout << query(1 , l , r) << "\n";
        }
    }
    
    
    return 0 ;
}