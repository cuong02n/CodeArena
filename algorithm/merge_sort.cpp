#include <bits/stdc++.h>
using namespace std;
int inv = 0;
void merge(int A[], int l, int m, int r, int tmp[]) {
    for (int k = l, i = l, j = m + 1; k <= r; k++) {
        if (i > m) {
            tmp[k] = A[j++];
        } else if (j > r || A[i] <= A[j]) {
            tmp[k] = A[i++];
        } else {
            inv += m - i + 1;
            tmp[k] = A[j++];
        }
    }
    for (int i = l; i <= r; i++) {
        A[i] = tmp[i];
    }
}
void merge_sort(int A[], int l, int r, int tmp[]) {
    if (l < r) {
        int m = l + r >> 1;
        merge_sort(A, l, m, tmp);
        merge_sort(A, m + 1, r, tmp);
        merge(A, l, m, r, tmp);
    }
}
template <class it>
void _print(it begin, it end) {
    for (it i = begin; i != end; i++) {
        cout << *i << " ";
    }
}
int main() {
    freopen("output.txt", "w", stdout);
    int A[] = {1, 5, 2, 7, 4, 4, 9, 8, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int tmp[n];
    merge_sort(A, 0, n - 1, tmp);
    _print(A, A + n);
    cout << "inv : " << inv << endl;
    return 0;
}