/*
    author : cuong2905say
    created : 25-09-2022  21:43:25  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

pair<int, int> A[100001];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> A[i].second;
    }
    int _min = INT_MAX;
    int _max = INT_MIN;
    for (int i = 0; i < n; i++) {
        _min = min(_min, A[i].first - A[i].second);
        _max = max(_max, A[i].first + A[i].second);
    }
    cout << (_min + _max) / 2 << ((_min + _max) % 2 ? ".5" : "") << endl;
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
