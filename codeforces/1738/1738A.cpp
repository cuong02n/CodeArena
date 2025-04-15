/*
    author : cuong2905say
    created : 30-09-2022  21:39:51  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int A[100001];
int B[100001];
vector<int> frost;  // 0
vector<int> fire;   // 1
void solve() {
    int n;
    cin >> n;
    frost.clear();
    fire.clear();
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        if (A[i]) {
            fire.push_back(B[i]);
        } else {
            frost.push_back(B[i]);
        }
    }
    sort(frost.begin(), frost.end());
    sort(fire.begin(), fire.end());
    int i1 = frost.size();
    int i2 = fire.size();
    if (i1 == i2) {
        ll m = 0;
        for (int i = 0; i < i1; i++) {
            m += 2LL * fire[i];
            m += 2LL * frost[i];
        }
        m -= min(frost[0], fire[0]);
        cout << m << endl;
        return;
    }

    if (i1 > i2) {
        int d = i1 - i2;
        ll m = 0;
        for (int i = 0; i < d; i++) {
            m += frost[i];
        }
        for (int i = d; i < i1; i++) {
            m += 2LL * frost[i];
        }
        for (int i = 0; i < i2; i++) {
            m += 2LL * fire[i];
        }
        cout << m << endl;
        return;
    }
    if (i2 > i1) {
        int d = i2 - i1;
        ll m = 0;
        for (int i = 0; i < d; i++) {
            m += fire[i];
        }
        for (int i = d; i < i2; i++) {
            m += 2LL * fire[i];
        }
        for (int i = 0; i < i1; i++) {
            m += 2LL * frost[i];
        }
        cout << m << endl;
        return;
    }
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
