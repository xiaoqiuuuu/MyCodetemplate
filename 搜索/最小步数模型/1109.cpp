// Problem: 魔板
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1109/


#include<bits/stdc++.h>

using namespace std;

unordered_map<string ,int> mp;
unordered_map<string,pair<string,char>> pre;


string ed = "";

string A(string s)
{
    reverse(s.begin() , s.end() );
    return s;
}
string B(string a)
{
    swap(a[0] , a[1]);
    swap(a[7] , a[6]);
    
    swap(a[3] , a[0]);
    swap(a[4] , a[7]);
    
    swap(a[2] , a[3]);
    swap(a[5] , a[4]);
    
    return a;
}
string C(string s)
{
    swap(s[1] , s[2]);
    swap(s[1] , s[5]);
    swap(s[1] , s[6]);
    
    return s;
}

pair<int,string> bfs()
{
    queue<string> q;
    q.push("12345678");
    mp["12345678"] ++ ;
    pre["12345678"] = {"12345678" , '1'};
    
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        
        auto a = A(t) , b = B(t) , c = C(t);
        if(!mp.count(a))mp[a] ++ , q.push(a) , pre[a] = {t , 'A'};
        if(!mp.count(b))mp[b] ++ , q.push(b) , pre[b] = {t , 'B'};
        if(!mp.count(c))mp[c] ++ , q.push(c) , pre[c] = {t , 'C'};
    }

    string last = ed , ans = "";
    while(last != pre[last].first)
    {
        ans = pre[last].second + ans ;
        last = pre[last].first;
    }
    
    return {ans.size() , ans};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0 ; i < 8 ; i ++ )
    {
        int x ;cin >> x;
        ed = ed + to_string(x);
    }
    
    auto t = bfs();
    
    cout << t.first << "\n" << t.second;
    
    return 0 ;
}