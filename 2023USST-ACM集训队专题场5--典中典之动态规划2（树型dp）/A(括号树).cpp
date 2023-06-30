// Problem: 
//     P5658 [CSP-S2019] 括号树
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P5658

#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 5e5 + 10 , M = 2 * N;

int h[N] , e[M] , ne[M]  , idx;
string s;
int n ;
int stk[N] , tt;
int f[N] ,p[N];
LL sum[N];

void add(int a , int b) {
    e[idx] = b , ne[idx] = h[a] , h[a] = idx ++ ;
}

void dfs(int u , int fa) {
    p[u] = fa;
    int flg = 0 ;
    if(s[u] == ')') {
        if(tt){
            flg = stk[tt -- ];
            f[u] = f[p[flg]] + 1;
        }
    } else stk[++tt] = u;

    sum[u] = sum[fa] + f[u];

    for(int i = h[u] ; ~ i ; i = ne[i]) {
        int j = e[i];
        if(j == fa) {
            continue;
        }
        dfs(j , u);
    }
    
    if(flg) {
         stk[++tt] = flg;
    } else if(s[u] == '(') {
        stk[tt -- ];
    }
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(h , - 1 , sizeof h);    
    
    cin >> n >> s ;
    s = " " + s;
    
    for(int i = 2 ; i <= n ; i ++ ) {
        int x ;cin >> x;
        add(x , i) ;
    }
    
    dfs(1 , 1);
 
    LL res = 0;
 
    for(int i = 1 ; i <= n ; i ++ ) {
        //cout << f[i] << " ";
        res ^= 1ll * sum[i] * i;
    }
    
   // cout << "\n";
    cout << res << "\n";
    return 0;
}