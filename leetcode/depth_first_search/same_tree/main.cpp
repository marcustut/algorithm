#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
  // when p is null and q is null
  if (!p && !q) return true;

  // when either one of p or q is null
  if (!p || !q) return false;

  // when value of p and q is not same
  if (p->val != q->val) return false;

  // recursively call children
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
}
