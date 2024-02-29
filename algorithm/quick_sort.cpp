#include <bits/stdc++.h>
using namespace std;

void swap(int A[], int x, int y) {
    int tmp = A[x];
    A[x] = A[y];
    A[y] = tmp;
}
int partition(int A[], int l, int r, int p) {
    swap(A, p, r);
    int i = l;
    int k = l;
    for (int i = l; i < r; i++) {
        if (A[i] <= A[r]) {
            swap(A, k++, i);
        }
    }
    swap(A, k, r);
    return k;
}
void quick_sort(int A[], int l, int r) {
    if (l < r) {
        int m = partition(A, l, r, l + r >> 1);
        quick_sort(A, 1, m - 1);
        quick_sort(A, m + 1, r);
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
    int A[] = {8, 2, 1, 5, 4, 2, 1, 4, 6, 7, 1, 5, 6, 12};
    int n = sizeof(A) / sizeof(A[0]);
    quick_sort(A, 0, n - 1);
    _print(A, A + n);
    return 0;
}