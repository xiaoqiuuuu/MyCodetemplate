#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 1e5 + 10;

struct Node{
   LL l , r ;
   LL sum;
   LL lazy;
}tr[4 * N];

int n , m ;
int a[N] ;


void pushup(int u)
{    
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(Node &u , Node &l , Node &r)
{
    l.sum += (l.r - l.l + 1) * u.lazy;
    r.sum += (r.r - r.l + 1) * u.lazy;
    l.lazy += u.lazy , r.lazy += u.lazy;
    u.lazy = 0 ;
}

void pushdown(int u)
{
    pushdown(tr[u] , tr[u << 1] , tr[u << 1 | 1]);
}

void build(int u , int l , int r)
{
    if(l == r)
    {
        tr[u] = {l , r , a[l] , 0};
        return ;
    }
    tr[u] = {l , r};
    int mid = l + r  >> 1;
    build(u << 1, l , mid) , build(u << 1 | 1 , mid + 1 , r);
    
    pushup(u);
}

void modify(int u , int l , int r , int x)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum += (tr[u].r - tr[u].l + 1) * x;
        tr[u].lazy += x;
    }
    else
    {
        pushdown(u); 
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l)modify(u << 1 , l , r , x);
        if(r > mid)modify(u << 1 | 1 , l , r , x);
        pushup(u); 
    }
}

LL query(int u ,int l , int r)
{
    if(tr[u].l >= l && tr[u].r <= r)return tr[u].sum;
    
    pushdown(u);
    
    LL res = 0 ;
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l)res += query(u << 1 , l , r);
    if(r > mid)res += query(u << 1 | 1 , l , r);
    
    return res;
    
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++ )
	    cin >> a[i];
	
	build(1 , 1 , n);
	
	while(m -- )
	{
	    int op , x , y , k;
	    cin >> op >> x >> y;
	    
	    if(op & 1)cin >> k , modify(1 , x , y , k);
	    else cout << query(1 , x , y) << "\n";
	}
	
	
	return 0;
}
