/*
    author : cuong2905say
    created : 26-09-2022  14:01:12  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
char S[10001];
char T[10001];
int mark[26];
void solve() {
    int n;
    cin >> n;
    int c = 0;
    for (int i = 0; i < 26; i++) {
        mark[i] = 0;
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        cin >> S[i];
        if (mark[S[i] - 'a']) {
            flag = 1;
        }
        mark[S[i] - 'a'] = 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }
    vector<int> pos;
    pos.clear();
    for (int i = 0; i < n; i++) {
        if (c > 2) {
            break;
        }
        if (S[i] - T[i]) {
            c++;
            pos.push_back(i);
        }
    }

    if (c != 0 || c != 2) {
        flag = 0;
    }
    if (c == 2) {
        if (S[pos[0]] == S[pos[1]] && T[pos[0]] == T[pos[1]]) {
            flag = 1;
        } else {
            flag = 0;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
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
