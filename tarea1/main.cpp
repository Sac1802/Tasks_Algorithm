#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool validate(TreeNode *root, TreeNode *&prev)
{
    if (!root)
        return true;
    if (!validate(root->left, prev))
        return false;
    if (prev && root->val <= prev->val)
        return false;
    prev = root;
    return validate(root->right, prev);
}

bool isValidBST(TreeNode *root)
{
    TreeNode* prev = nullptr;
    return validate(root, prev);
}

int main(void)
{
    TreeNode root(5);
    root.left = new TreeNode(1);
    root.right = new TreeNode(4);
    root.left->left = new TreeNode(0);
    root.left->right = new TreeNode(0);
    root.right->left = new TreeNode(3);
    root.right->right = new TreeNode(6);
    bool result = isValidBST(&root);

    TreeNode root1(2);
    root1.left = new TreeNode(1);
    root1.right = new TreeNode(3);
    bool result1 = isValidBST(&root1);
    std::cout << "The test 1 is: " << result1 << std::endl;
    std::cout << "The test 2 is: " << result << std::endl;
    return 0;
}
