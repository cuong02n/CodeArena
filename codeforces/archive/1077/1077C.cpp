/*
    author : cuong2905say
    created : 17-09-2022  17:20:29  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
map<ll, int> B;
vector<int> res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll A[200001];
    B.clear();
    res.clear();
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
        if (B.find(A[i]) != B.end()) {
            B[A[i]]++;
        } else {
            B.insert({A[i], 1});
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((sum - A[i]) % 2) {
            continue;
        }
        ll z = (sum - A[i]) / 2;
        if (B.find(z) != B.end()) {
            if (z == A[i]) {
                if (B[z] >= 2) {
                    res.push_back(i);
                }
            } else {
                res.push_back(i);
            }
        }
    }
    cout << res.size() << endl;
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << endl;

    system("pause");
    return 0;
}
