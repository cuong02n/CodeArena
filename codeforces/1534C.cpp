/*
    author : cuong2905say
    created : 17-09-2022  17:04:31  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <typename T1, typename T2>  // T1 is node(vertex), T2 is valuetype of weight
class un_dir_graph {
   public:
    map<T1, map<T1, T2> > A;  // sorted with dictionary order
    map<T1, bool> visited;
    vector<T1> res;
    map<T1, T1> parent;

   private:
    int edge = 0;
    int vertex = 0;

   public:
    void clear() {
        A.clear();
        visited.clear();
        res.clear();
        parent.clear();
    }
    void _DFS(T1 x) {
        // start from x
        stack<T1> s;
        while (!(s.empty())) {
            s.pop();
        }
        s.push(x);
        while (!(s.empty())) {
            T1 i = s.top();
            s.pop();

            if (visited.find(i) == visited.end()) {
                continue;
            }
            visited.erase(i);
            res.push_back(i);
            for (typename map<T1, T2>::reverse_iterator q = A[i].rbegin(); q != A[i].rend(); q++) {
                T1 p = q->first;
                if (visited.find(p) != visited.end()) {
                    s.push(p);
                }
            }
        }
    }
    vector<T1> _DFS_to_k(T1 x, int k) {
        // start from x
        visited.clear();
        for (auto i : A) {
            visited.insert({i.first, false});
        }
        res.clear();
        stack<T1> s;
        while (!(s.empty())) {
            s.pop();
        }
        s.push(x);
        while (!(s.empty())) {
            if (res.size() == k) {
                return res;
            }
            T1 i = s.top();
            s.pop();

            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            res.push_back(i);

            for (typename map<T1, T2>::reverse_iterator q = A[i].rbegin(); q != A[i].rend(); q++) {
                T1 p = q->first;
                if (!visited[p]) {
                    s.push(p);
                }
            }
        }
        return res;
    }
    vector<T1> BFS(T1 x) {  // start from x
        int c = 0;
        visited.clear();
        for (auto i : A) {
            visited.insert({i.first, false});
        }
        res.clear();
        queue<T1> s;
        while (!(s.empty())) {
            s.pop();
        }
        s.push(x);
        c++;
        visited[x] = true;
        while (!(s.empty())) {
            T1 i = s.front();
            s.pop();
            res.push_back(i);
            c++;
            for (auto q : A[i]) {
                T1 p = q.first;
                if (!visited[p]) {
                    s.push(p);
                    visited[p] = true;
                }
            }
        }
        return res;
    }

    vector<T1> DFS(T1 x) {
        // start from x
        visited.clear();
        for (auto i : A) {
            visited.insert({i.first, false});
        }
        res.clear();
        stack<T1> s;
        while (!(s.empty())) {
            s.pop();
        }
        s.push(x);
        while (!(s.empty())) {
            T1 i = s.top();
            s.pop();

            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            res.push_back(i);
            for (typename map<T1, T2>::reverse_iterator q = A[i].rbegin(); q != A[i].rend(); q++) {
                T1 p = q->first;
                if (!visited[p]) {
                    s.push(p);
                }
            }
        }
        return res;
    }

    vector<T1> find_path(T1 y, T1 x) {
        if (A.find(x) == A.end() || A.find(y) == A.end()) {
            return res;
        }
        res.clear();

        if (x == y) {
            res.push_back(x);
            return res;
        }
        // using BFS.
        //  find path from x to y( shortest )
        visited.clear();
        for (auto i : A) {
            visited.insert({i.first, false});
        }
        parent.clear();
        queue<T1> s;
        while (!(s.empty())) {
            s.pop();
        }
        int flag = 1;
        s.push(x);
        parent.insert({x, x});
        visited[x] = true;
        while (!(s.empty())) {
            T1 i = s.front();
            s.pop();
            for (auto q : A[i]) {
                T1 p = q.first;
                if (!visited[p]) {
                    s.push(p);
                    parent.insert({p, i});
                    if (p == y) {
                        flag = 1;
                        break;
                    }
                    visited[p] = true;
                }
            }
        }
        if (flag) {
            res.push_back(y);
            auto before = y;
            auto i = parent[y];
            while (i != before) {
                res.push_back(i);
                before = i;
                i = parent[i];
            }
        }
        return res;
    }

    void add(T1 x, T1 y, T2 w = 0) {  // O(1);
        // insert with w is weight
        if (A.find(x) == A.end() && A.find(y) == A.end()) {
            map<T1, T2> i1;
            i1.insert(pair<T1, T2>(y, w));
            map<T1, T2> i2;
            i2.insert(pair<T1, T2>(x, w));
            A.insert(pair<T1, map<T1, T2> >(x, i1));
            A.insert(pair<T1, map<T1, T2> >(y, i2));
        } else if (A.find(x) == A.end()) {
            map<T1, T2> i;
            i.insert(pair<T1, T2>(y, w));
            A.insert(pair<T1, map<T1, T2> >(x, i));
            A[y].insert(pair<T1, T2>(x, w));
        } else if (A.find(y) == A.end()) {
            map<T1, T2> i;
            i.insert(pair<T1, T2>(x, w));
            A.insert(pair<T1, map<T1, T2> >(y, i));
            A[x].insert(pair<T1, T2>(y, w));
        } else {
            A[x].insert(pair<T1, T2>(y, w));
            A[y].insert(pair<T1, T2>(x, w));
        }
    }
    void add_vertex_only(T1 x) {
        map<T1, T2> i;
        A.insert({x, i});
    }

    int get_edge() {
        edge = 0;
        for (auto i : A) {
            edge += (i.second).size();
        }
        edge >>= 1;
        return edge;
    }

    int number_Connected_Component() {
        int NBCC = 0;
        visited.clear();
        for (auto i : A) {
            visited.insert({i.first, false});
        }
        while (!(visited.empty())) {
            NBCC++;
            _DFS(visited.begin()->first);
        }
        return NBCC;
    }
    int have_cycle() {
        if (get_edge() > get_vertex() - number_Connected_Component()) {
            return 1;
        }
        return 0;
    }

    int get_vertex() {
        vertex = A.size();
        return vertex;
    }

    T1 get_first() {
        return (A.begin())->first;
    }

    void erase(T1 x) {
        if (A.find(x) != A.end()) {
            // founded
            for (auto i : A[x]) {
                A[i.first].erase(x);
            }
            A.erase(x);
        }
    }
    int min_path(T1 x, T1 y) {
        auto _s = find_path(x, y);
        return _s.size() - 1;
    }

    void display_MAP() {
        for (auto i : A) {
            cout << i.first << " \" ";
            for (auto j : i.second) {
                cout << " " << j.first << " , " << j.second << " ";
            }
            cout << " \" " << endl;
        }
    }

    un_dir_graph(){};
    un_dir_graph(un_dir_graph &&) = default;
    un_dir_graph(const un_dir_graph &) = default;
    un_dir_graph &operator=(un_dir_graph &&) = default;
    un_dir_graph &operator=(const un_dir_graph &) = default;
    ~un_dir_graph(){};

   private:
};
int P = (int)1e9 + 7;
ll pow_mod(ll a, ll k) {
    // a^k;
    if (k == 0) {
        return 1;
    }
    if (k == 1) {
        return a;
    }
    ll u = pow_mod(a, k / 2);
    if (k % 2) {
        return a * u % P * u % P;
    }
    return u * u % P;
}

int A[400001];
int B[400001];
un_dir_graph<int, int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        v.clear();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> B[i];
        }
        for (int i = 1; i <= n; i++) {
            v.add(A[i], B[i]);
        }
        int x = v.number_Connected_Component();
        cout << pow_mod(2, x) << endl;
    }
    system("pause");
    return 0;
}
