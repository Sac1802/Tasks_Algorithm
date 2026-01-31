#include <iostream>
#include <algorithm>
#include <vector>
#include "avl.hpp"

int avl::heigth(Node *n) {
    if (n == nullptr)
        return -1;
    return n->height;
}

int avl::balancerFactor(Node *n) {
    if (n == nullptr)
        return 0;
    return heigth(n->left) - heigth(n->right);
}

void avl::updateHeight(Node *n) {
    if (n == nullptr)
        return;
    n->height = std::max(heigth(n->left), heigth(n->right)) + 1;
}

Node* avl::childTaller(Node *n) {
    if (heigth(n->left) > heigth(n->right))
        return n->left;
    if (heigth(n->left) < heigth(n->right))
        return n->right;

    if (n->parent != nullptr && n == n->parent->left)
        return n->left;
    return n->right;
}

void avl::trasplant(Node *n, Node *y) {
    if (n->parent == nullptr) {
        root = y;
    } else if (n == n->parent->left) {
        n->parent->left = y;
    } else {
        n->parent->right = y;
    }
    if (y != nullptr) {
        y->parent = n->parent;
    }
}

void avl::rotateLeft(Node *n) {
    Node *y = n->right;
    Node *aux = y->left;

    y->left = n;
    n->right = aux;

    if (aux != nullptr)
        aux->parent = n;

    trasplant(n, y);
    n->parent = y;

    updateHeight(n);
    updateHeight(y);
}

void avl::rotateRight(Node *n) {
    Node *y = n->left;
    Node *aux = y->right;

    y->right = n;
    n->left = aux;

    if (aux != nullptr)
        aux->parent = n;

    trasplant(n, y);
    n->parent = y;

    updateHeight(n);
    updateHeight(y);
}

void avl::restructure(Node *n) {
    Node *y = childTaller(n);
    Node *x = childTaller(y);

    if (y == n->left && x == y->left) {
        rotateRight(n);
    } else if (y == n->left && x == y->right) {
        rotateLeft(y);
        rotateRight(n);
    } else if (y == n->right && x == y->right) {
        rotateLeft(n);
    } else {
        rotateRight(y);
        rotateLeft(n);
    }
}

void avl::rebalanceAfterInsertion(Node *n) {
    while (n != nullptr) {
        updateHeight(n);
        int bf = balancerFactor(n);
        if (bf > 1 || bf < -1) {
            Node *parent = n->parent;
            restructure(n);
            n = parent;
        } else {
            n = n->parent;
        }
    }
}

void avl::insert(int value) {
    if (root == nullptr) {
        root = new Node(value, nullptr);
        updateHeight(root);
        return;
    }

    Node *current = root;
    Node *parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    Node *newNode = new Node(value, parent);
    if (value < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    rebalanceAfterInsertion(parent);
}

bool avl::search(int numberSearch) {
    return search(root, numberSearch);
}

bool avl::search(Node* n, int numberSearch) {
    if (!n) return false;

    if (n->value == numberSearch)
        return true;
    else if (numberSearch < n->value)
        return search(n->left, numberSearch);
    else
        return search(n->right, numberSearch);
}