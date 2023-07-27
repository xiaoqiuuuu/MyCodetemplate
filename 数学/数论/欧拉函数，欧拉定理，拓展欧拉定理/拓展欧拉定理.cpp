// Problem: 
//     P5091 【模板】扩展欧拉定理
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P5091


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

LL get_oula(LL x) {
    LL res = x ;
    for(LL i = 2 ; i <= x / i ; i ++ ) {
        if(x % i == 0) {
            res = res / i * (i - 1);
            while(x % i == 0) {
                x /= i;
            }
        }
    }
    if(x > 1) {
        res = res / x * ( x - 1);
    }
    return res;
}

LL qmi(LL a , LL b , LL p) {
    LL res = 1;
    while(b) {
        if(b & 1) {
            res = res * a % p;
        }
        b >>= 1;
        a = a % p * a % p;
    }
    return res;
}

void solve(){
    LL a , m ;
    cin >> a >> m ;
    string b;
    cin >> b;
    
    LL t = get_oula(m);
    LL res = 0 ,flg = 0 ;
    for(LL i = 0 ; i < b.size() ; i ++ ) {
        res = res * 10 + b[i] - '0';
        if(res >= t) {
            res %= t;
            flg = 1;
        }
    }
    
    if(flg) {
        res += t;
    }
    
    cout << qmi(a , res , m) << "\n";
    
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL tt = 1;
    //cin >> tt ;
    while(tt --> 0){
        solve();
    }
    
    return 0;
}