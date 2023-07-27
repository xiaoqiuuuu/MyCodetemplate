// Problem: 
//     P3407 散步
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P3407


#include <bits/stdc++.h>

using namespace std;
using LL = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n , t , q;
    cin >> n >> t >> q;
    
    vector<LL> loc(n) , dir(n);
    for(LL i = 0 ; i < n ; i ++ ) {
        cin >> loc[i] >> dir[i];
    }
    
    vector<LL> tmp;
    for(LL i = 1 ; i < n ; i ++ ) {
        if(dir[i - 1] == 1 && dir[i] == 2) {
            tmp.push_back((loc[i - 1] + loc[i]) / 2);
        }
    }
    
    vector<LL> flg(n);
    for(LL i = 0 ; i < n ; i ++ ) {
        if(dir[i] == 1) {
            if(tmp.empty() || loc[i] > tmp.back()) {
                flg[i] = - 1;
                continue;
            }
            auto x = lower_bound(tmp.begin() , tmp.end() , loc[i]);
            if(x == tmp.end()) {
                flg[i] = -1;
            } else {
                flg[i] = (*x) - loc[i];
            }
        } else {
            if(tmp.empty() || loc[i] < tmp[0]) {
                flg[i] = -1;
            }
            auto x = lower_bound(tmp.begin() , tmp.end() , loc[i]);
            
            if(x == tmp.begin()) {
                flg[i] = - 1;
            } else {
                x -- ;
                flg[i] = loc[i] - (*x);
            }
        }
    }
    
    for(LL j = 1 ; j <= q ; j ++ ) {
        LL i = t , x;
        cin >> x;
        x -- ;
        if(flg[x] == -1){
            if(dir[x] == 1) {
                cout << loc[x] + i << "\n";
            } else {
                cout << loc[x] - i << "\n";
            }
        } else {
            if(i > flg[x]) {
                if(dir[x] == 1) {
                    cout << loc[x] + flg[x] << "\n";
                } else {
                    cout << loc[x] - flg[x] << "\n";
                }
            } else {
                 if(dir[x] == 1) {
                    cout << loc[x] + i << "\n";
                } else {
                    cout << loc[x] - i << "\n";
                }
            }
        }
    }


    return 0;
}