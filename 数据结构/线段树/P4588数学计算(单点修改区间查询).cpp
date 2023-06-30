// Problem: 
//     P4588 [TJOI2018]数学计算
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P4588


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 1e5 + 10;


LL n , p , x;
pair<int,LL> a[N];

struct Node{
    int l , r ;
    LL v ;
}tr[N << 2];

void pushup(int u)
{
   tr[u].v = tr[u << 1].v * tr[u << 1 | 1].v % p;
}

void build(int u , int l , int r)
{
    if(l == r)tr[u] = {l , r , 1};
    else
    {
        int mid = l + r >> 1;
        tr[u] = { l , r , 1};
        build(u << 1 , l , mid) , build(u << 1 | 1 , mid + 1 , r);
    }
}

void modify(int u , int l , int r , LL x)
{
    if(tr[u].l >= l && tr[u].r <= r)tr[u].v = x;
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l)modify(u << 1 , l , r , x);
        if(r > mid)modify(u << 1 | 1 , l , r , x);
        pushup(u);
    }
}

LL query(int u ,int l , int r)
{
    if(tr[u].l >= l && tr[u].r <= r)return tr[u].v;
    else
    {
        LL res = 1 ;
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l)res = query(u << 1 , l , r) % p;
        if(r > mid)res = res * query(u << 1 | 1 , l , r) % p;
        return res;
    }
    
}

void solve()
{
   cin >> n >> p ;
   for(int i = 1 ; i <= n ; i ++ )
       cin >> a[i].first >> a[i].second ;
   
   build(1 , 1 , n );
   
   for(int i = 1 ; i <= n ; i ++ )
   {
       auto &[op , y] = a[i];
       if(op == 1)
       {
            modify(1 , i , i , y);
       }
       else
       {
            modify(1 , y , y , 1);
       }     
       cout << query(1 , 1 , i) << "\n";
   }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt;
	cin >> tt ;
	while(tt -- )
	    solve();
	
	return 0;
}
