/*
    author : cuong2905say
    created : 12-09-2022  22:26:22    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case
int X[200001];
int Y[200001];
vector<int> A;  // positive
vector<int> B;  // negative
deque<int> C;   // all
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        A.clear();
        B.clear();
        C.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> X[i];
        }
        int zero = 0;
        for (int i = 0; i < n; i++) {
            cin >> Y[i];
            Y[i] -= X[i];
        }

        for (int i = 0; i < n; i++) {
            if (Y[i] > 0) {
                A.push_back(Y[i]);
            } else {
                B.push_back(Y[i]);
            }
        }
        int res = 0;
        std::sort(A.begin(), A.end(), greater<int>());
        std::sort(B.begin(), B.end());
        // for (auto x : A) {
        //     cout << x << ' ';
        // }
        // cout << endl;

        // for (auto x : B) {
        //     cout << x << ' ';
        // }
        // cout << endl;

        while (!(A.empty() && B.empty())) {
            if (A.empty()) {
                int b = B.back();
                B.pop_back();
                C.push_back(b);
            } else if (B.empty()) {
                int a = A.back();
                A.pop_back();
                C.push_back(a);
            } else {
                int a = A.back();
                int b = B.back();
                if (abs(a) < abs(b)) {
                    C.push_back(a);
                    A.pop_back();
                } else if (abs(b) < abs(a)) {
                    C.push_back(b);
                    B.pop_back();
                } else {
                    C.push_back(b);
                    C.push_back(a);
                    A.pop_back();
                    B.pop_back();
                }
            }
            if (C.empty()) {
                break;
            }
            int z = C.back();
            if (z > 0) {
                if (C.size() >= 2) {
                    C.pop_back();
                    C.pop_back();
                    res++;
                }
            } else if (z == 0) {
                if (C.size() >= 2) {
                    C.pop_back();
                    C.pop_back();
                    res++;
                }
            } else {
                // z<0;
            }
        }
        // for (auto x : C) {
        //     cout << x << ' ';
        // }
        // cout << endl;
        cout << res << endl;
    }
    system("pause");
    return 0;
}