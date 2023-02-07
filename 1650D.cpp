/*
    author : cuong2905say
    created : 19-09-2022  12:18:36  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int A[2001];
int B[2001];
int n;
int left(int i, int k, int max) {
    if (i - k < 1) {
        return i + max - k;
    }
    return i - k;
}

void cycle_left(int k, int max) {
    // left k operator
    for (int i = 1; i <= max; i++) {
        B[left(i, k, max)] = A[i];
    }
    for (int i = 1; i <= max; i++) {
        A[i] = B[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int res[2001];

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < n + 1; i++) {
            cin >> A[i];
        }
        for (int i = n; i >= 2; i--) {
            int pos = 0;
            for (int j = 1; j <= i; j++) {
                if (A[j] == i) {
                    pos = j;
                    break;
                }
            }
            res[i] = pos % i;
            cycle_left(pos % i, i);
        }
        for (int i = 1; i < n + 1; i++) {
            cout << res[i] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
