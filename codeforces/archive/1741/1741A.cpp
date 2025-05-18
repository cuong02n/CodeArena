/*
    author : cuong2905say
    created : 12-10-2022  16:00:51  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int n = 0;
map<char, int> A;
void solve() {
    string a, b;
    cin >> a >> b;
    char l_a = a[a.length() - 1];
    char l_b = b[b.length() - 1];
    if (A[l_a] > A[l_b]) {
        cout << ">" << endl;
    } else if (A[l_a] < A[l_b]) {
        cout << "<" << endl;
    } else if (l_a == 'S') {
        if (a.length() > b.length()) {
            cout << "<" << endl;
        } else if (a.length() < b.length()) {
            cout << ">" << endl;
        } else {
            cout << "=" << endl;
        }
    } else {
        if (a.length() > b.length()) {
            cout << ">" << endl;
        } else if (a.length() < b.length()) {
            cout << "<" << endl;
        } else {
            cout << "=" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    A.insert({'S', 1});
    A.insert({'M', 2});
    A.insert({'L', 3});
    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}
