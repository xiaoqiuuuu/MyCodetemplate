#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
//using LL = long long ;

typedef pair<int,int> PII;

const int N = 50010;

struct Node {
    int l , r , sum;
}tr[N * 4];
int n , a[N];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum ;
}

void build(int u , int l , int r)
{
    if(l == r)
    {
        tr[u] = {l , r , a[l]};
    }
    else
    {
        tr[u] = {l , r , 0};
        int mid = l + r >> 1 ;
        build(u << 1 , l , mid) , build(u << 1 | 1 , mid + 1 , r);
        pushup(u);
    }
}

void modify(int u , int l , int r , int x)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum += (tr[u].r - tr[u].l + 1) * x;
       // cout << tr[u].sum << " " << l << "\n";
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= l)modify(u << 1 , l , r , x);
        if(mid < r)modify(u << 1 | 1 , l , r , x);
        pushup(u);
    }
}

int query(int u , int l , int r)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        return tr[u].sum;
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        int res = 0;
        if(mid >= l)res += query(u << 1 , l , r);
        if(r > mid)res += query(u << 1 | 1 , l , r);
        
        return res;
    }
}


void solve()
{
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++ )
        cin >> a[i];
        
    build(1 , 1 , n);
    
    string op;
    while(cin >> op && op != "End")
    {
        if(op == "Query")
        {
            int l , r;
            cin >> l >> r ;
            cout << query(1 , l , r) << "\n";
        }
        else if(op == "Add")
        {
            int l , x;
            cin >> l >> x ;
            modify(1 , l , l , x);
        }
        else
        {
            int l , x;
            cin >> l >> x ;
            modify(1 , l , l , - x);
        }
    }
    
    
    
    
	return ;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tt = 1;
	cin>>tt;
	for(int i = 1 ; i <= tt ; i ++ )
	{
	    cout << "Case " << i << ":\n";
	    solve();
	}
	return 0;
}
