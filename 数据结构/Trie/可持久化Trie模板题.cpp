// Problem: 最大异或和
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/258/


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 6e5 + 10 , M = 6e5 * 25;

int tr[M][2] , idx;
int vis[M] , root[N];
int a[N] , n , m;

void insert(int x , int v) {
    int p = root[v] = ++ idx , pre = root[v - 1];
    for(int i = 24 ; i >= 0 ; i -- ) {
        int u = (x >> i) & 1;
        if(pre) {
            tr[p][u ^ 1] = tr[pre][u ^ 1];
            pre = tr[pre][u];
        }
        tr[p][u] = ++ idx;
        vis[p] = v;
        p = tr[p][u];
    }
    vis[p] = v;
}

int query(int l , int r  , int x) {
    int res = 0 , p = root[r] ;
    for(int i = 24 ; i >= 0 ; i -- ) {
        int u = (x >> i ) & 1;
        if(tr[p][u ^ 1] && vis[tr[p][u ^ 1]] >= l) {
          
            res += (1 << i);
            p = tr[p][u ^ 1];
        } else {
            p = tr[p][u];
        }
    }
    return res;
}

void solve(){
    cin >> n >> m;
    
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i] , a[i] ^= a[i - 1];
        insert(a[i] , i);
    }
    int cnt = n ;
    while(m -- ) {
        string op ;int l , r , x;
        cin >> op ;
        if(op == "A") {
            cin >> x;
            a[++cnt] = x;
            a[cnt] ^= a[cnt - 1];
            insert(a[cnt] , cnt);
        } else {
            cin >> l >> r >> x;
            cout << max( (l == 1 ? (x ^ a[cnt]) : 0) , query(l - 1 , r - 1 , x ^ a[cnt])) << "\n";
        }   
    }
    
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt = 1;
 //   cin >> tt ;
    while(tt --> 0){
        solve();
    }
    
    return 0;
}