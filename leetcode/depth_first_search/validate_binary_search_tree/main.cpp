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

// Time Complexity: O(n)
// Space Complexity: O(n)
bool isValidBST(TreeNode *root)
{
    return validate(root, nullptr, nullptr);
}

// Traverse left subtree, check if each node is valid
// traverse right subtree, check if each node is valid
// if everything's valid then BST is valid, else not BST
bool validate(TreeNode *root, int *max, int *min)
{
    // base case: if successfully reached the end (it's valid)
    if (root == nullptr)
        return true;
    // check if the node is valid by seeing if its value stays within the range
    else if (max && root->val >= *max || min && root->val <= *min)
        return false;
    // traverse the left subtree and the right subtree
    else
        return validate(root->left, &(root->val), min) && validate(root->right, max, &(root->val));
}

int main()
{
    TreeNode left = TreeNode(4);
    TreeNode right2 = TreeNode(7);
    TreeNode left2 = TreeNode(3);
    TreeNode right = TreeNode(6, &left2, &right2);
    TreeNode root = TreeNode(5, &left, &right);

    std::cout << isValidBST(&root) << std::endl;
}

