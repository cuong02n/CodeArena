/*
    author : cuong2905say
    created : 30-09-2022  10:11:09  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
char vowels[] = {'A', 'E', 'Y', 'O', 'U', 'I', 'a', 'e', 'y', 'o', 'u', 'i'};  // size 12
void solve() {
    string c;
    cin >> c;
    for (int i = 0; i < c.length(); i++) {
        for (int j = 0; j < 12; j++) {
            if (c[i] == vowels[j]) {
                c[i] = 0;
            }
            if (c[i] != vowels[j] && c[i] <= 'Z' && c[i] >= 'A') {
                c[i] = (char)(c[i] - 'A' + 'a');
            }
        }
    }
    for (int i = 0; i < c.length(); i++) {
        if (c[i]) {
            cout << "." << c[i];
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    system("pause");
    return 0;
}
