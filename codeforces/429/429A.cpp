/*
    author : cuong2905say
    created : 15-09-2022  14:49:13  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Tree {
   public:
    struct node {
        T value;
        node *right;
        node *left_child;
    };
    vector<T> res;

   private:
    node *_find(T x, node *r) {
        if (r == NULL) {
            return r;
        }
        if (r->value == x) {
            return r;
        }
        node *it = r->left_child;
        while (it != NULL) {
            node *f = find(x, it);
            if (f != NULL) {
                return f;
            }
            it = it->right;
        }
        return NULL;
    }

   public:
    node *root = NULL;
    node *new_node(T x) {
        node *q = (node *)malloc(sizeof(node));
        q->value = x;
        q->left_child = NULL;
        q->right = NULL;
    }

    node *find(T x) {
        return _find(x, root);
    }
    void add(T x, T y) {
        // assert y is exist in this tree
        // add x to y
        node *p = find(y);
        node *q = new_node(x);
        if (p->left_child == NULL) {
            p->left_child = q;
            return;
        }
        p = p->left_child;
        while (p->right != NULL) {
            p = p->right;
        }
        p->right = q;
    }

   public:
    Tree(){};
    Tree(T x) {
        root = new_root(x);
    }
    Tree(Tree &&) = default;
    Tree(const Tree &) = default;
    Tree &operator=(Tree &&) = default;
    Tree &operator=(const Tree &) = default;
    ~Tree(){};

   private:
};
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Tree<pair<int, int> > v({ 1, 1});

    cin >> n;
    
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        node *q = v.find(y)
    }
    system("pause");
    return 0;
}