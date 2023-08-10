/*
    author : cuong2905say
    created : 15-09-2022  23:21:03  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

int A[200001];
set<int> place_0;
set<int> place_1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        place_0.clear();
        place_1.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            A[i] = c - '0';
            if (A[i]) {
                place_1.insert(i);
            } else {
                place_0.insert(i);
            }
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (A[i]) {
                // 1
                auto it = place_0.upper_bound(i);
                if (it != place_0.end()) {
                    res += 1LL * (n - (*it));
                }
            } else {
                auto it = place_1.upper_bound(i);
                if (it != place_1.end()) {
                    res += 1LL * (n - (*it));
                }
            }
        }
        cout << "res" << res + n << endl;
    }
    system("pause");
    return 0;
}