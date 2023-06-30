// Problem: 字串变换
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/description/192/

#include<bits/stdc++.h>

using namespace std;


string be , ed;
 
int extend(queue<string> &q , unordered_map<string , int> &da , unordered_map<string , int> &db , vector<string> &a, vector<string> &b)
{
    int d = da[q.front()];
    while(q.size() && d == da[q.front()])
    {
        auto t = q.front();
        q.pop();
        
        for(int i = 0 ; i < a.size() ; i ++ )
            for(int j = 0 ; j < t.size() ; j ++ )
                if(t.substr(j , a[i].size()) == a[i])
                {
                    string s = t.substr(0 , j) + b[i] + t.substr(j + a[i].size());
                    if(db.count(s))return da[t] + 1 + db[s];
                    if(da.count(s))continue;
                    
                    da[s] = da[t] + 1;
                    q.push(s);
                }
    }
    
    return 11;
}
    
    
int bfs(vector<string>&a , vector<string> & b){     
    
    queue<string> qa , qb;
    unordered_map<string ,int> da , db;
    qa.push(be) , qb.push(ed);
    da[be] = db[ed] = 0;
    
    int t = 0 , cnt = 0;
    while(qa.size() && qb.size())
    {
        if(qa.size() < qb.size()) t = extend(qa , da , db , a , b);
        else t = extend(qb , db , da , b , a);
        
        if(t <= 10)return t;
        
        if(++ cnt == 10)break;
    }
    return 11;
};
    


int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> be >> ed;
    
    vector<string>a , b ;
    
    string x;
    while(cin >> x)
    {
        a.push_back(x);
        cin >> x;
        b.push_back(x);
    }    
    
    int t ;
    if(be == ed ) t = 0;
    else t =  bfs(a , b);

    
    if(t > 10)cout << "NO ANSWER!\n";
    else cout << t << "\n";
    
    return 0 ;
}
