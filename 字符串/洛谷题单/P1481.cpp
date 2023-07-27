// Problem: 
//     P1481 魔族密码
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P1481


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

struct Trie {
    vector<int>cnt;
    vector<vector<int>> tr ;
    Trie () : tr(1 , vector<int>(26 , 0)) , cnt(1) {}
    int insert(const string &s) {
        int p = 0 , mx = 0;
        for(int i = 0 ; i < s.size() ; i ++ ) {
            int u = s[i] - 'a';
            if(!tr[p][u]) {
                tr[p][u] = tr.size();
                tr.emplace_back(26);
                cnt.push_back(0);
            }
            p = tr[p][u];
            mx += cnt[p];
        }
        cnt[p] ++ ;
        return mx + 1;
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Trie tr;
    int n;
    cin >> n;
    int ans = 0 ;
    while(n -- ) {
        string s ;
        cin >> s;
        ans = max(ans , tr.insert(s));   
    }
    
    cout << ans << "\n";
    
    return 0;
}