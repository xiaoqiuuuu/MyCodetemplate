// Problem: 
//     P2574 XOR的艺术
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P2574


#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 2e5 + 10;

struct Node{
    int l , r , d , lazy;
}tr[4 * N];
string a ;
int n , m ;

void pushup(int u)
{
    tr[u].d = tr[u << 1].d + tr[u << 1 | 1].d;
}

void build(int u , int l ,int r)
{
    if(l == r)tr[u] = {l , r , a[l] - '0'};
    else
    {
        tr[u] = {l , r};
        int mid = l + r >> 1 ;
        build(u << 1 , l , mid ) , build(u << 1 | 1 , mid + 1 , r);
        pushup(u);
    }
}

void pushdown(Node &u , Node &l , Node &r)
{
    l.lazy ^= u.lazy;
    r.lazy ^= u.lazy;
    
    if(u.lazy)
    {
        l.d = l.r - l.l + 1 - l.d;
        r.d = r.r - r.l + 1 - r.d;
    }
    
    u.lazy = 0 ;
}

void modify(int u , int l , int r )
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].d = tr[u].r - tr[u].l + 1 - tr[u].d;
        tr[u].lazy ^= 1;
    }
    else
    {
        pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
        
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l)modify(u << 1 , l , r);
        if(r > mid)modify(u << 1 | 1 , l , r);
        pushup(u);
    }
}

int query(int u , int l , int r)
{
    if(tr[u].l >= l && tr[u].r <= r)return tr[u].d;
    else
    {
        pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
        int res = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l)res = query(u << 1 , l , r);
        if(r > mid)res += query(u << 1 | 1 , l , r);
        return res;
    }
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> a;
	
	a = " " + a;
	build(1 , 1 , n);
	
	while(m -- )
	{
	    int op , l , r ;
	    cin >> op >> l >> r ;
	    if(op == 0)modify(1 , l , r);
	    else cout << query(1 , l , r) << "\n";
	}
	
	return 0;
}
