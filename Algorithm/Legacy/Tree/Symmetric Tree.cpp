/*
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return subtreeSym(root->left,root->right);
    }
private:
    bool subtreeSym(TreeNode* left,TreeNode* right){
    if(!left&&!right){
        return true;
    }
    else if(!left&&right||left&&!right){
        return false;
    }
    bool cond1 = (left->val==right->val);
    bool cond2 = subtreeSym(left->left,right->right);
    bool cond3 = subtreeSym(left->right,right->left);
    return cond1&&cond2&&cond3;
    }
};