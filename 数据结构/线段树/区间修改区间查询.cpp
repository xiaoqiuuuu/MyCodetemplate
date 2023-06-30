// Problem: 一个简单的整数问题2
// Author : xiaoqiuuuu
// URL: https://www.acwing.com/problem/content/244/

#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 1e5 + 10;

int n , m;
struct Node{
	int l , r ;
	LL sum , add;
}tr[N * 4];
int w[N];

void pushup(int u)
{
	tr[u].sum = tr[u << 1].sum +  tr[u << 1 | 1].sum;
}
void pushdown(Node &u , Node &l , Node &r)
{
	l.sum += (l.r - l.l + 1ll) * u.add;
	r.sum += (r.r - r.l + 1ll) * u.add;
	l.add  += u.add , r.add += u.add;
	u.add = 0;
}

void pushdown(int u)
{
	pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
}


void build(int u , int l , int r)
{
	tr[u] = {l , r};
	if(l == r)tr[u] = { l , r , w[r] , 0};
	else
	{
		int mid = l + r >> 1 ;
		build(u << 1 , l , mid) , build(u << 1 | 1 , mid + 1 , r);
		pushup(u);
	}
}

void modify(int u , int l , int r , int x)
{
	if(tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].add += x;
		tr[u].sum += (tr[u].r - tr[u].l + 1ll) * x ;
	}
	else
	{
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1 ;
		if(l <= mid)modify(u << 1 , l , r ,  x );
		if(r > mid)modify(u << 1 | 1 , l , r , x);
		pushup(u);
	}
}

LL query(int u , int l , int r )
{
	if(tr[u].l >= l && tr[u].r <= r)return tr[u].sum ; 
	
	pushdown(u);
	
	int mid = tr[u].l + tr[u]. r >> 1 ;
	LL res = 0 ;
	if(l <= mid)res = query(u << 1 , l , r);
	if(r > mid )res += query(u << 1 | 1 , l , r);
	
	return res;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m ;
	for(int i =1 ; i <= n ; i ++ )
		cin >> w[i];
	build(1 , 1 , n );
	
	while(m --)
	{
		string op ;int l , r ;
		cin >> op >> l >> r ;
		if(op == "Q")cout << query(1 , l , r )<< "\n";
		else 
		{
			int x ; cin >> x ;
			modify(1 , l , r , x );
		}
	}
	
	
	
	return 0 ;
}