#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode* node, int curSum, int targetSum)
{
  // base case: sum are not equal
  if (!node) return false;

  curSum += node->val;
  // check sum at leaf node
  if (!node->left && !node->right) return curSum == targetSum;

  // recursively do it on both side of the tree
  return dfs(node->left, curSum, targetSum) || dfs(node->right, curSum, targetSum);
}


bool hasPathSum(TreeNode* root, int targetSum)
{
  return dfs(root, 0, targetSum);
}

int main()
{
    TreeNode seven = TreeNode(7);
    TreeNode two = TreeNode(2);
    TreeNode eleven = TreeNode(11, &seven, &two);
    TreeNode four = TreeNode(4, &eleven, nullptr);

    TreeNode one = TreeNode(1);
    TreeNode four2 = TreeNode(4, nullptr, &one);
    TreeNode thirteen = TreeNode(13);
    TreeNode eight = TreeNode(8, &thirteen, &four2);

    TreeNode root = TreeNode(5, &four, &eight);

    if (hasPathSum(&root, 22)) cout << "PASSED\n";
    else cout << "FAILED\n";
}
