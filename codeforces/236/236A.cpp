/*
    author : cuong2905say
    created : 30-09-2022  10:06:50  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
char a[26];
void solve() {
    string c;
    cin >> c;
    for (int i = 0; i < 26; i++) {
        a[i] = 0;
    }
    for (char i : c) {
        a[i - 'a'] = 1;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        res += a[i];
    }
    if (res % 2) {
        cout << "IGNORE HIM!";
    } else {
        cout << "CHAT WITH HER!";
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
