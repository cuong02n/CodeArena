/*
    author : cuong2905say
    created : 13-09-2022  17:18:57    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;

int t = 0;  // test case

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    set<int> r;
    while (t--) {
        r.clear();
        string c;
        cin >> c;
        if (c.length() >= 4) {
            for (int i = 0; i < c.length() - 4; i++) {
                if (c[i] == 't' && c[i + 1] == 'w' && c[i + 2] == 'o' && c[i + 3] == 'n' && c[i + 4] == 'e') {
                    r.insert(i + 2);
                }
            }
        }
        if (c.length() >= 2) {
            for (int i = 0; i < c.length() - 2; i++) {
                if (c[i] == 't' && c[i + 1] == 'w' && c[i + 2] == 'o') {
                    if (r.find(i + 2) == r.end()) {
                        r.insert(i + 1);
                    }
                }
                if (c[i] == 'o' && c[i + 1] == 'n' && c[i + 2] == 'e') {
                    if (r.find(i) == r.end()) {
                        r.insert(i + 1);
                    }
                }
            }
        }
        cout << r.size() << endl;
        for (auto x : r) {
            cout << x + 1 << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}