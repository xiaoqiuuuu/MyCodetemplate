// Problem: 
//     P1816 忠诚
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1816


#include <bits/stdc++.h>

using namespace std;
using LL = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n , m;
    cin >> n >> m;
    vector<int>a(n + 1);
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
    }    
    
    vector<vector<int>>f(n + 1 , vector<int>(16 , 0));

    for(int j = 0 ; j < 16 ; j ++ ) {
        for(int i = 1 ; i + (1 << j) - 1 <= n ; i ++ ) {
            if(!j) {
                f[i][j] = a[i];
            } else {
                f[i][j] = min(f[i + (1 << j - 1)][j - 1] , f[i][j - 1]);
            }
        }
    }
    
    while( m -- ) {
        int a , b;
        cin >> a >> b;
        int len = b - a + 1;
        int k = log2(len);
        cout << min(f[a][k] , f[b - (1 << k) + 1][k]) << " ";
    }
    
    
    return 0;
}