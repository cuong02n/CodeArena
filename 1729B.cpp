/*
    author : cuong2905say
    created : 12-09-2022  21:41:42    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

stack<int> A;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--) {
        while (!(A.empty())) {
            A.pop();
        }
        int n;
        cin >> n;
        int val = 0;
        for (int i = 0; i < n; i++) {
            char x;
            cin >> x;
            A.push(x - '0');
        }
        string c = "";
        while (!(A.empty())) {
            if (A.top() == 0) {
                A.pop();
                int a1 = A.top();
                A.pop();
                int a2 = A.top();
                A.pop();
                int val = a2 * 10 + a1;
                char c1 = (char)(val + (int)'a' - 1);
                c = c1 + c;
            } else {
                int a1 = A.top();
                A.pop();
                int val = a1;
                char c1 = (char)(val + (int)'a' - 1);
                c = c1 + c;
            }
        }
        cout << c << endl;
    }

    system("pause");
    return 0;
}