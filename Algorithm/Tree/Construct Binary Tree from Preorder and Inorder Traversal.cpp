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
    unordered_map<int,int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        int root_idx = 0;
        build(preorder,0,preorder.size()-1,inorder,0,preorder.size()-1);
    }
    
private:
    TreeNode* build(vector<int>& preorder,int sp,int ep, vector<int>& inorder,int si, int ei){
        if(sp>ep||si>ei){
            return NULL;
        }
        int mid = m[preorder[sp]];
        int num = mid-si;
        TreeNode* root = new TreeNode(preorder[sp]);
        root->left = build(preorder,sp+1,sp+num,inorder,si,mid-1);
        root->right = build(preorder,sp+num+1,ep,inorder,mid+1,ei);
        return root;
        
    }
};