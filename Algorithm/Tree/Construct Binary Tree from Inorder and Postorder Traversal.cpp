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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()){
            return NULL;
        }
        else{
            for(int i=0;i<inorder.size();i++){
                m[inorder[i]] = i;
            }
            build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
        }
    }
private:
    unordered_map<int, int> m;
    TreeNode* build(vector<int>& inorder, int si, int ei, vector<int>& postorder, int sp, int ep) {
        if(si>ei||sp>ep){
           return NULL; 
        }
        else{
            TreeNode* root = new TreeNode(postorder[ep]);
            int mid = m[postorder[ep]];
            int left_length = mid-si;
            root->left = build(inorder,si,mid-1,postorder,sp,sp+left_length-1);
            root->right = build(inorder,mid+1,ei,postorder,sp+left_length,ep-1);
            return root;
        }
    }
};