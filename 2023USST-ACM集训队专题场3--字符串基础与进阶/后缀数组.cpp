#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
    static const int N = 1e6 + 10;
    int n, m;
    int sa[N], hgt[N], rk[N], x[N], y[N], p[N + 1], c[N];
    SuffixArray(const string &s) : c{}, p{} {
        n = s.size(), m = 'z' + 1;
        for (int i = 0; i < n; i++) x[i] = s[i], y[i] = i;
        rSort();

        for (int k = 1; k < n; k *= 2) {
            int cur = 0;
            for (int i = n - k; i < n; i++) y[cur++] = i;
            for (int i = 0; i < n; i++) {
                if (sa[i] >= k) y[cur++] = sa[i] - k;
            }
            rSort();

            rk[sa[0]] = cur = 0;
            for (int i = 1; i < n; i++) {
                int a = sa[i], b = sa[i - 1];
                if (a >= n - k || b >= n - k || x[a] != x[b] || x[a + k] != x[b + k]) cur++;
                rk[a] = cur;
            }
            if (cur == n - 1) break;
            for (int i = 0; i < n; i++) x[i] = rk[i];
            m = cur + 1;
        }

        for (int i = 0, k = hgt[0] = 0; i < n; i++) {
            if (rk[i] == 0) continue;
            if (k) k--;
            int j = sa[rk[i] - 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
            hgt[rk[i]] = k;
        }
    }
    void rSort() {
        for (int i = 0; i < n; i++) c[x[i]]++;
        for (int i = 0; i < m; i++) p[i + 1] = c[i] + p[i], c[i] = 0;
        for (int i = 0; i < n; i++) sa[p[x[y[i]]]++] = y[i];
        p[0] = 0;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    SuffixArray sa(s);
    for(int i = 0; i < s.size(); i++)
        cout << sa.sa[i] + 1 << " \n"[i + 1 == s.size()];

    return 0;
}