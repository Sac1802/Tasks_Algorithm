#ifndef AVL_HPP
#define AVL_HPP

class Node
{
public:
    int value;
    int height;
    Node *left, *right, *parent;

    Node(int value, Node *parent)
    {
        this->value = value;
        this->parent = parent;
        this->height = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class avl
{
private:
    Node *root;
    bool search(Node* n, int numberSearch);

public:
    avl() : root(nullptr) {}

    int heigth(Node *n);
    int balancerFactor(Node *n);
    void updateHeight(Node *n);
    Node *childTaller(Node *n);
    void trasplant(Node *n, Node *y);
    void rotateLeft(Node *n);
    void rotateRight(Node *n);
    void restructure(Node *n);
    void rebalanceAfterInsertion(Node *n);
    void insert(int value);
    bool search(int numberSearch);
};

#endif
