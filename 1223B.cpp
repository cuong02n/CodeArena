/*
    author : cuong2905say
    created : 26-09-2022  20:41:35  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int m[26];
void solve() {
    for (int i = 0; i < 26; i++) {
        m[i] = 0;
    }
    string s;
    string t;
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) {
        m[s[i] - 'a'] = 1;
    }
    for (int i = 0; i < t.length(); i++) {
        if (m[t[i] - 'a']) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
