/*
    author : NGUYEN MANH CUONG
    created : 08-09-2022  22:59:35    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case
deque<char> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        A.clear();
        string c;
        cin >> c;
        for (int i = 0; i < c.length(); i++) {
            A.push_back(c[i]);
        }
        
    }
    system("pause");
    return 0;
}