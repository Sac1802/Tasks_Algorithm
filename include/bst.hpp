#ifndef BST_HPP
#define BST_HPP

class NodeBST {
public:
    int value;
    NodeBST *left, *right;

    NodeBST(int val) : value(val), left(nullptr), right(nullptr) {}
};

class bst {
private:
    NodeBST *root;
    void insertNode(NodeBST* &n, int val);
    bool searchNode(NodeBST* n, int numberSearch);

public:
    bst() : root(nullptr) {}
    void insert(int val) { insertNode(root, val); }
    bool search(int val) { return searchNode(root, val); }
    NodeBST* getRoot() { return root; }
};

#endif