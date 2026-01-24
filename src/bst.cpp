#include "bst.hpp"

void bst::insertNode(NodeBST* &n, int val) {
    if (n == nullptr) {
        n = new NodeBST(val);
        return;
    }
    
    if (val < n->value) {
        insertNode(n->left, val);
    } else if (val > n->value) {
        insertNode(n->right, val);
    }
}

bool bst::searchNode(NodeBST* n, int numberSearch) {
    if (n == nullptr) 
        return false;

    if (n->value == numberSearch)
        return true;
    else if (numberSearch < n->value)
        return searchNode(n->left, numberSearch);
    else
        return searchNode(n->right, numberSearch);
}