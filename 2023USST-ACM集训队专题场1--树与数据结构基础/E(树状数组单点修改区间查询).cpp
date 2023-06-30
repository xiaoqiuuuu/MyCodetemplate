#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

struct Fenwick{
    int n;
    vector<int>tr;
    
    Fenwick(int n) : n(n) ,  tr(n + 1) {}
    
    void add(int x , int c){
        for(int i = x ; i <= n ; i += lowbit(i))
            tr[i] += c;
    }
    int sum(int x){
        int res = 0;
        for(int i = x ; i ; i -= lowbit(i))
            res += tr[i];
        return res;
    }
    
    int lowbit(int x){
        return x & - x;
    }
};




void solve()
{
    int n , m;
    cin >> n >> m ;
    Fenwick fenwick(n);
    for(int i = 1 , x ; i <= n ; i ++ )
    {
        cin >> x;
        fenwick.add(i , x);
    }
    
    while(m -- )
    {
        int op , l , r ;
        cin >> op >> l >> r ;
        
        if(op == 1)fenwick.add(l , r);
        else cout << fenwick.sum(r) - fenwick.sum(l - 1) << "\n";
    }
    
    
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
