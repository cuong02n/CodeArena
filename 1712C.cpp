/*
    author : cuong2905say
    created : 20-09-2022  19:56:47  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int A[100005];
<<<<<<< HEAD
=======
int used[100005];
>>>>>>> 862498337086e8054b8109c8e09ab740b32b735d
int last[100005];
int used[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
<<<<<<< HEAD
        for (int i = 1; i <= n; i++) {
            used[i] = 0;
=======
        for (int i = 0; i < n; i++) {
>>>>>>> 862498337086e8054b8109c8e09ab740b32b735d
            last[i] = -1;
            used[i + 1] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            last[A[i]] = i;
        }
<<<<<<< HEAD
        int res = 0;
        int L = 0;
        for (int i = n; i > 1; i--) {
            if (A[i - 1] > A[i]) {
                L = i - 1;
            } 
        }

        for (int i = 1; i <= L; i++) {
            L = max(L, last[i]);
        }

        for (int i = 1; i <= L; i++) {
            if (!used[A[i]]) {
                used[A[i]] = 1;
=======
        int L = -1;
        for (int i = 0; i < n - 1; i++) {
            if (A[i] > A[i + 1]) {
                L = i;
            }
        }
        int res = 0;
        for (int i = 0; i <= L; i++) {
            if (!used[A[i]]) {
>>>>>>> 862498337086e8054b8109c8e09ab740b32b735d
                res++;
                used[A[i]] = 1;
            }
            L = max(L, last[A[i]]);
        }
        cout << res << endl;
    }
    system("pause");
    return 0;
}
