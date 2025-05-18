/*
    author : cuong2905say
    created : 26-09-2022  15:13:04  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    stack<char> a;
    string c;
    cin >> c;
    system("pause");

    int level = 0;
    for (int i = 0; i < c.length();) {
        if (c[i + 1] <= 'z' && c[i + 1] >= 'a') {
            // open tag
            a.push(c[i + 1]);
            for (int j = 0; j < 2 * level; j++) {
                cout << " ";
            }
            cout << "<" << c[i + 1] << ">" << endl;
            level++;
            i += 3;
        } else {
            a.pop();
            for (int j = 0; j < 2 * (level - 1); j++) {
                cout << " ";
            }
            cout << "</" << c[i + 2] << ">" << endl;
            level--;
            i += 4;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
