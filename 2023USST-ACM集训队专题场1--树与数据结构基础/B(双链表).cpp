#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

const int N = 3e5 + 10;

int n , m ;
int e[N] , l[N] , r[N] ,  idx = 1;
bool st[N] ;

//第i个节点的idx 值为 i - 1

// 在节点a的右边插入一个数x
void insert(int a, int x)
{
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx ++ ;
}

void remove(int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

void solve()
{
    cin >> n ;
    
    r[0] = 1 , l[1] = 0;
    idx = 2;
    
    insert(0 , 1);
    for(int i = 2 , k , p; i <= n ; i ++ )
    {
        cin >> k >> p;
        if(p)insert(k + 1 , i);
        else insert(l[k + 1], i);
    }
    
    cin >> m;
    while( m -- )
    {
        int x ;
        cin >> x;
        x ++ ;
        if(!st[x])
        {
            st[x] = true;
            remove(x);
        }
    }
    
    for(int i = r[0] ; i != 1; i = r[i])
        cout << e[i] << " " ;
    cout << "\n";
    
    
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1;
	//cin>>tt;
	while(tt--)
		solve();
	
	return 0;
}
