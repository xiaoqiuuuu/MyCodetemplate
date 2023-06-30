// Problem: 
//     P3796 【模板】AC 自动机（加强版）
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P3796


#include<bits/stdc++.h>

using namespace std;

struct AC {
    int idx ,hh , tt;
    vector<vector<int>> tr;
    vector<int> fail , f , q , id;
    vector<string> a;
    
    AC() : tr(1 , vector<int>(26 , 0)) , fail(1) , f(1) , idx(0) {}
    void insert(string &s , int x) {
        int n = s.size() , p = 0;
        for(int i = 0 ; i < n ; i ++ ) {
            int u = s[i] - 'a';
            if(!tr[p][u]) {
                tr[p][u] = ++ idx;
                tr.emplace_back(26);
                fail.push_back(0);
                f.push_back(0);
            }
            p = tr[p][u];
        }
        a.emplace_back(s);
        id.push_back(p);
    }
    
    void build() {
        q.resize(idx);
        hh = 0 , tt = -1;
        for(int i = 0 ; i < 26 ; i ++ ) {
            if(tr[0][i]) {
                q[++ tt] = tr[0][i];
            }
        }
        while(hh <= tt) {
            int t = q[hh ++ ];
            for(int i = 0 ; i < 26 ; i ++ ) {
                int c = tr[t][i];
                if(c) {
                    fail[c] = tr[fail[t]][i];
                    q[++ tt ] = c;
                } else {
                    tr[t][i] = tr[fail[t]][i];
                }
            }
        }
    }
    
    void query(string &s) {
        
        int n = s.size() ; 
        for(int i = 0 , j = 0; i < n ; i ++ ) {
            int u = s[i] - 'a';
            j = tr[j][u];       
            f[j] ++ ;
        }
        
        for(int i = idx - 1 ; i >= 0 ; i -- ) {
            f[fail[q[i]]] += f[q[i]];
        }
        
        n = id.size();
        int mx = id[0];
        for(int i = 1 ; i < n ; i ++ ) {
            if(f[id[i]] > f[mx]) {
                mx = id[i];
            }
        }
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n ;
    while(cin >> n && n) {
        AC ac ;string s;
        for(int i = 0 ; i < n ; i ++ ) {
            cin >> s;
            ac.insert(s , i); 
        }

        ac.build() ;       
        cin >> s;
        ac.query(s);
    }
    
    return 0;
}