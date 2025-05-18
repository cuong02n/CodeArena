/*
    author : cuong2905say
    created : 15-09-2022  00:29:22  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;

template <typename T1, typename T2>  // T1 is node(vertex), T2 is valuetype of weight
class un_dir_graph {
   public:
    map<T1, map<T1, T2> > A;  // sorted with dictionary order
    map<T1, bool> visited;
    vector<T1> res;

   private:
    int edge = 0;
    int vertex = 0;

   public:
    int _DFS(T1 x) {
        int c = 0;
        // start from x
        stack<T1> s;
        while (!(s.empty())) {
            s.pop();
        }
        s.push(x);
        while (!(s.empty())) {
            T1 i = s.top();
            s.pop();
            c++;
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
        return c;
    }
    vector<T1> BFS(T1 x) {  // start from x
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
        visited[x] = true;
        while (!(s.empty())) {
            T1 i = s.front();
            s.pop();
            res.push_back(i);
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

    vector<T1> find_path(T1 x, T1 y) {
        // find path from x to y( shortest )
        visited.clear();
        for (auto i : A) {
            visited.insert({i.first, false});
        }
        res.clear();
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
            int z = _DFS(visited.begin()->first);
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

    void erase(T1 x) {
        if (A.find(x) != A.end()) {
            // founded
            for (auto i : A[x]) {
                A[i.first].erase(x);
            }
            A.erase(x);
        }
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    un_dir_graph<int, int> Q;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        Q.add(x, y);
    }
    Q.visited.clear();
    
    system("pause");
    return 0;
}