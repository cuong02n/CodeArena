/*
    author : cuong2905say
    created : 11-09-2022  11:26:41    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case
int A[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {   
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    int good_pos = 0;
    for (int i = 0; i < n; i++) {
        int have_actor = 0;
        for (int j = 0; j < m; j++) {
            if (A[i][j]) {
                have_actor = 1;
            } else {
                if (have_actor) {
                    good_pos++;
                    // cout << i << ' ' << j << ' ' << "left" << endl;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int have_actor = 0;
        for (int j = m - 1; j >= 0; j--) {
            if (A[i][j]) {
                have_actor = 1;
            } else {
                if (have_actor) {
                    good_pos++;
                    // cout << i << ' ' << j << ' ' << "right" << endl;
                }
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int have_actor = 0;
        for (int i = 0; i < n; i++) {
            if (A[i][j]) {
                have_actor = 1;
            } else {
                if (have_actor) {
                    good_pos++;
                    // cout << i << ' ' << j << ' ' << "up" << endl;
                }
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int have_actor = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (A[i][j]) {
                have_actor = 1;
            } else {
                if (have_actor) {
                    good_pos++;
                    // cout << i << ' ' << j << ' ' << "down" << endl;
                }
            }
        }
    }
    cout << good_pos << endl;
    system("pause");
    return 0;
}