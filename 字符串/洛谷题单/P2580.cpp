// Problem: 
//     P2580 于是他错误的点名开始了
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P2580


#include <bits/stdc++.h>

using namespace std;
using LL = long long;


struct Trie {
    vector<vector<int>> tr;
    vector<int> cnt;
    
    Trie () : tr(1 , vector<int> (26 , 0)) , cnt(1) {}
    
    void insert(const string & s) {
        int p = 0 ;
        for(int i = 0 ; i < s.size() ; i ++ ) {
            int u = s[i] - 'a';
            if(!tr[p][u]) {
                tr[p][u] = tr.size();
                tr.emplace_back(26);
                cnt.push_back(0);
            }
            p = tr[p][u];
        }
        cnt[p] ++ ;
    }  
    
    int query(const string &s) {
        int p = 0 ;
        for(int i = 0 ; i < s.size() ; i ++ ) {
            int u = s[i] - 'a';
            if(!tr[p][u]) {
                return -1;
            }
            p = tr[p][u];
        }
        return ++ cnt[p];
    }
    
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie tr;
    
    int n ;
    cin >> n;
    while(n -- ) {
        string s;
        cin >> s;
        tr.insert(s);
    }
    
    cin >> n;
    while(n -- ) {
        string s ;
        cin >> s;
        int t = tr.query(s);
        if(t <= 1) {
            cout << "WRONG\n";
        } else if(t == 2) {
            cout << "OK\n";
        } else {
            cout << "REPEAT\n";
        }
    }
    
    return 0;
}