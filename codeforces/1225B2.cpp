/*
    author : cuong2905say
    created : 26-09-2022  18:09:57  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int A[200001];
map<int, int> num;
void solve() {
    int n, k, d;
    num.clear();
    cin >> n >> k >> d;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int val = 0;
    for (int i = 0; i < d; i++) {
        if (num.find(A[i]) == num.end()) {
            num.insert({A[i], 1});
            val++;
        } else {
            num[A[i]]++;
        }
    }
    int res = val;
    
    for (int i = d; i < n; i++) {
        if (num[A[i - d]] == 1) {
            num.erase(A[i - d]);
            val--;
        } else {
            num[A[i - d]]--;
        }
        if (num.find(A[i]) == num.end()) {
            val++;
            num.insert({A[i], 1});
        } else {
            num[A[i]]++;
        }
        res = min(res, val);
    }
    cout << res << endl;
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
