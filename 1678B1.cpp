/*
  author : NGUYEN MANH CUONG
  created : 05-09-22 13:47
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case
char c[200001];
vector<int> A;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<int> A;

    cin >> t;
    while (t--) {
        A.clear();
        int n;
        cin >> n;
        char last = 'z';
        int now = 0;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < n; i++) {
            if (last == 'z') {
                now = 1;
                last = c[i];
            } else {
                if (c[i] == last) {
                    now++;
                } else {
                    A.push_back(now);
                    now = 1;
                    last = c[i];
                }
            }
        }
        A.push_back(now);
        int last_odd = -1;
        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2) {
                if (last_odd == -1) {
                    last_odd = i;
                } else {
                    sum += i - last_odd;
                    last_odd = -1;
                }
            }
        }
        cout << sum;
        cout << endl;
    }
    return 0;
}
