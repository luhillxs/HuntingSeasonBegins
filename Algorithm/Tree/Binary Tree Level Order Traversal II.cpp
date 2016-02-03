/*
    Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

    For example:
    Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
        /  \
       15   7
    return its bottom-up level order traversal as:
    [
      [15,7],
      [9,20],
      [3]
    ]
    confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int level = depth(root);
        vector<vector<int>> levelOrder(level);
        if(level==0){
            return levelOrder;
        }
        order(root,levelOrder,levelOrder.size()-1);
        return levelOrder;
        
    }

private:
    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        return left_depth>right_depth? left_depth+1:right_depth+1;
    }
    
    void order(TreeNode* root, vector<vector<int>> &levelOrder,int level){
        if(!root){
            return;
        }
        levelOrder[level].push_back(root->val);
        order(root->left,levelOrder,level-1);
        order(root->right,levelOrder,level-1);
    }
};