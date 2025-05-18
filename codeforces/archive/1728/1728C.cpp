/*
    author : NGUYEN MANH CUONG
    created : 08-09-2022  22:00:47    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

template <typename T>
int integer_part_of_log(T a, T b) {
    // log_a(b);
    // a>=1;
    T _a = a;
    for (int i = 1; i < 1000; i++) {
        if (a == b) {
            return i;
        }
        if (a > b) {
            return i - 1;
        }
        a *= _a;
    }
    return -1;
}
int _A[10];  // 1->9;
int _B[10];  // 1->9
multiset<int> A;
multiset<int> B;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        A.clear();
        B.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            A.insert(a);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            auto it = A.find(b);
            if (it == A.end()) {
                // k tim thay
                B.insert(b);
            } else {
                // neu tim thay , thi bo
                A.erase(it);
            }
        }

        for (multiset<int>::iterator it = A.begin(); it != A.end();) {
            auto it1 = B.find((*it));
            int x = *it;
            if (it1 != B.end()) {
                // tim thay
                A.erase(it++);
                B.erase(it1);
            } else if (x >= 10) {
                A.erase(it++);
                A.insert(integer_part_of_log(10, x) + 1);
                res++;
            } else {
                it++;
            }
        }
        int i = 1;
        for (multiset<int>::iterator it = B.begin(); it != B.end();) {
            int x = *it;
            auto it1 = A.find(x);
            if (it1 != A.end()) {//tim thay x trong A
                B.erase(it++);
                A.erase(it1);
            } else if (x >= 10) {
                B.erase(it++);
                B.insert(integer_part_of_log(10, x) + 1);
                res++;
            } else {
                it++;
            }
        }
        for(int i = 0; i < 10; i++){
            _A[i] = 0;
            _B[i] = 0;
        }
        // now ,arr contains 1-->9
        for (auto x : A) {
            _A[x]++;
        }

        for (auto x : B) {
            _B[x]++;
        }
        for(int i = 2; i < 10; i++){
            res += abs(_A[i] - _B[i]);
        }
        cout << res << endl;
    }
    system("pause");
    return 0;
}