// Problem: 区间最大公约数
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/247/


#include<bits/stdc++.h>
#define __gcd gcd

using namespace std;
using LL = long long;

const LL N = 500010;

struct Node{
    LL l , r , sum , v;
}tr[4 * N];

LL n , m ;
LL a[N];

void pushup(LL u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].v = gcd(tr[u << 1].v , tr[u << 1 | 1].v);
}

void build(LL u ,LL l ,LL r)
{
     if(l == r)tr[u] = {l , r , a[l] - a[l - 1], a[l] - a[l - 1]};
     else
     {
         tr[u] = {l , r , 0 , 0};
         LL mid = l + r >> 1; 
         build(u << 1 , l , mid) , build(u << 1 | 1 , mid + 1 , r);
         pushup(u);
     }
}

void modify(LL u ,LL x , LL k)
{
     if(tr[u].l == tr[u].r && tr[u].l == x)
     {
         tr[u].sum += k ;
         tr[u].v = tr[u].sum;
     }
     else
     {
         LL mid = tr[u].l + tr[u].r >> 1;
         if(x <= mid)modify(u << 1 , x , k);
         else modify(u << 1 | 1 , x , k);
         pushup(u);
     }
}
LL query(LL u , LL l , LL r)
{
    if(tr[u].l >= l && tr[u].r <= r)return tr[u].v;
    else
    {
        LL res = 0;
        LL mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid)res = gcd(res , query(u << 1 , l , r));
        if(r > mid)res = gcd(res , query(u << 1 | 1 , l , r));
        return res;
    }
}

LL query(LL u ,LL x)
{
    if(tr[u].l >= 1 && tr[u].r <= x)return tr[u].sum;
    else
    {
        LL res = 0 ;
        LL mid = tr[u].l + tr[u].r >> 1;
        if(mid >= 1)res += query(u << 1 , x);
        if(x > mid)res += query(u << 1 | 1 , x);
        return res;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m ;
    
    for(LL i = 1 ; i <= n ; i ++ )
        cin >> a[i];
    
    build(1 , 1 , n );
    
    while(m -- )
    {
        string op ;cin >> op;
        LL l , r , x ;
        if(op == "Q")
        {
           cin >> l >> r ;
           cout << gcd(query(1 , l) , query(1 , l + 1 , r)) << "\n"; 
        }
        else
        {
            cin >> l >> r >> x ;
            modify(1 , l , x);
            if(r + 1 <= n)modify(1 , r + 1 , -x);
        }
    }

    
    return 0 ;
}
