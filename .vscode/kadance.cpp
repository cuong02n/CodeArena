/*
    author : cuong2905say
    created : 25-07-2023  19:33:18  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int MOD = 1e9 + 7;
int n = 0;

template <class T>
T kadane(T A[], int size) {
    T max_ending_here = 0;
    T MAX = 0;
    for (int i = 0; i < size; i++) {
        max_ending_here += A[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;
        } else if (max_ending_here > MAX) {
            MAX = max_ending_here;
        }
    }
    if (MAX == 0) {
        MAX = LLONG_MIN;
        for (int i = 0; i < size; i++) {
            MAX = max(MAX, A[i]);
        }
    }
    return MAX;
}

template <class T>
T kadane(T A[], int size, int& result_begin, int& result_end) {
    T max_ending_here = 0;
    T MAX = 0;
    int result_begin_tmp = -1;
    int result_end_tmp = -1;
    for (int i = 0; i < size; i++) {
        max_ending_here += A[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;
            result_begin_tmp = -1;
        } else {
            if (result_begin == -1) {
                result_begin_tmp = i;
            }
            if (max_ending_here > MAX) {
                MAX = max_ending_here;
                result_begin = result_begin_tmp;
                result_end = i;
            }
        }
    }
    if (MAX == 0) {
        MAX = LLONG_MIN;
        for (int i = 0; i < size; i++) {
            if (MAX < A[i]) {
                result_begin = i;
                result_end = i;
                MAX = A[i];
            }
        }
    }
    return MAX;
}

void solve() {
    int A[] = {-2,
               1,
               2,
               4,
               -1,
               2,
               1,
               -5,
               4};
    int a, b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
    return 0;
}
