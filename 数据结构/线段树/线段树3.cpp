#include<bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 1e5 + 10;

int n , m ,  p;
struct Node{
    LL l , r , sum , add , mul;
}tr[N * 4];
int a[N];

void pushup(int u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void pushdown(Node &u , Node &l , Node &r)
{
    l.sum = (l.sum * u.mul % p + (l.r - l.l + 1) * u.add % p) % p;
    l.mul = l.mul * u.mul % p ;
    l.add = (l.add * u.mul % p + u.add) % p;
    
    r.sum = ((r.sum * u.mul) % p + (r.r - r.l + 1) * u.add % p )% p;
    r.mul = r.mul * u.mul % p;
    r.add = ((r.add * u.mul) % p + u.add) % p;
    
    u.add = 0 ,u.mul = 1;
}

void build(int u , int l ,int r)
{
    if(l == r)tr[u] = {l , r , a[l] , 0, 1};
    else
    {
        tr[u] = {l , r , 0 , 0 , 1};
        int mid = l + r >> 1 ;
        build(u << 1 , l , mid) , build(u << 1 | 1 , mid + 1 , r);
        pushup(u);
    }
}

void modify(int u ,int l , int r , int x , int op)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        if(op == 1)
        {
            tr[u].sum = tr[u].sum * x % p;
            tr[u].mul = tr[u].mul * x % p;
            tr[u].add = tr[u].add * x % p;
        }
        else
        {
            tr[u].sum = (tr[u].sum + (tr[u].r - tr[u].l + 1) * x % p) % p;
            tr[u].add += x;
        }
    }
    else
    {
        pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l)modify(u << 1 , l , r , x , op);
        if(r > mid)modify(u << 1 | 1 , l , r , x , op);
        pushup(u);
    }
}

LL query(int u , int l , int r)
{
    if(tr[u].l >= l && tr[u].r <= r)return tr[u].sum;
    else
    {
        pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
        
        LL res = 0 ;
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l)res = query(u << 1 , l , r) % p;
        if(r > mid)res = (res + query(u << 1 | 1 , l , r)) % p;
        return res;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> p;
    
    for(int i = 1 ; i <= n ; i ++ )
        cin >> a[i];
    
    build(1 , 1 , n );
    
    cin >> m ;
    while (m -- )
    {
        int op , l , r , x ;
        cin >> op ;
        
        if(op == 1 || op == 2)
        {
            cin >> l >> r >> x ;
            modify(1 , l , r , x , op);
        }else
        {
            cin >> l >> r ;
            cout << query(1 , l , r) << "\n";
        }
    }    
    return 0 ;
}