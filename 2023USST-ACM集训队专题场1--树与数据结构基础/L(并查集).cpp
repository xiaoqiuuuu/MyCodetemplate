#include<bits/stdc++.h>

using namespace std;
using LL = long long ;

//const int N = 1e5 + 10;

struct DSU{
    int n ;
    vector<int> p;
    DSU (int n) :n(n) , p(n + 1){iota(p.begin() + 1 , p.end() , 1);}
    
    int find(int x){
        if(p[x] != x)p[x] = find(p[x]);
        return p[x];
    }
    
    bool merge(int x , int y){
        int px = find(x) , py = find(y);
        if(px == py)return false;
        p[px] = py;
        return true;
    }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n , m;
	cin >> n >> m;
	
	DSU dsu(n);
	
	while(m -- )
    {
        int op , x , y;
        cin >> op >> x >> y;
        if(op == 1)dsu.merge(x , y);
        else cout << (dsu.find(x) == dsu.find(y) ? "Y\n" : "N\n");
    }
	
	
	return 0;
}
