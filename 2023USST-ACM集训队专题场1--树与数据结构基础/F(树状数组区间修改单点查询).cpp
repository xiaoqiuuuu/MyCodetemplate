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
    
    vector<int>a(n + 1);
    for(int i = 1 ; i <= n ; i ++ )
        cin >> a[i];
    
    Fenwick fenwick(n + 1);
    
    for(int i = 1 ; i <= n ; i ++ )
        fenwick.add(i , a[i] - a[i - 1]);
        
    while(m -- )
    {
        int op ;
        cin >> op;
        if(op & 1)
        {
            int x , y , k;
            cin >> x >> y >> k ;
            fenwick.add(x , k);
            fenwick.add(y + 1 , - k);
        }
        else 
        {
            int x;
            cin >> x ;
            cout << fenwick.sum(x) << "\n";
        }
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
