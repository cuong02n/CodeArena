/*
    author : cuong2905say
    created : 22-09-2022  13:00:25  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

deque<int> A;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        A.clear();
        cin >> n;
        int _max = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            A.push_back(x);
        }
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        _max = A[n - 1] - A[0];
        for (int i = 0; i < n; i++) {
            int x = A.back();
            int y = A.front();
            A.pop_front();
            _max = max(_max, x - y);
            A.push_back(y);
        }

        for (int i = 1; i < n; i++) {
            _max = max(_max, A[i] - A[0]);
        }
        for (int i = 0; i < n - 1; i++) {
            _max = max(_max, A[n - 1] - A[i]);
        }
        cout << _max << endl;
    }
    system("pause");
    return 0;
}
