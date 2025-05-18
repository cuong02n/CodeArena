/*
    author : NGUYEN MANH CUONG
    created : 08-09-2022  00:55:36  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

class DSU {
   public:
    int size = 0;
    vector<int> arr_Par;
    vector<int> arr_size;
    DSU(int n) {
        size = n;
        make_set(n);
    }
    ~DSU() {
        arr_Par.clear();
        arr_size.clear();
    }
    void make_set(int n) {
        arr_Par.clear();
        arr_size.clear();
        size = n;
        for (int i = 0; i < size; i++) {
            arr_Par.push_back(i);
            arr_size.push_back(1);
        }
    }
    void merge(int t1, int t2) {
        t1 = find(t1);
        t2 = find(t2);
        if (t1 != t2) {
            // 2 tap hop khac nhau ;
            arr_Par[t2] = arr_Par[t1];
            arr_size[t2] += arr_size[t1];
            arr_size[t1] = arr_size[t2];
        }
    }
    int find(int t) {
        if (t == arr_Par[t]) {
            return t;
        }
        return find(arr_Par[t]);
    }
    int get_size(int t) {
        return arr_size[find(t)];
    }

   private:
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        DSU A(n + 1);
        for (int i = 1; i < n + 1; i++) {
            int x;
            cin >> x;
            A.merge(i, x);
        }
        
        for (int i = 1; i < n + 1; i++) {
            cout << A.get_size(i) << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}