/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* findMinNode(TreeNode* root) {
    if (!root || !root->left) return root;
    return findMinNode(root->left);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) 
                root->left = deleteNode(root->left, key);     
            else if(key > root->val) 
                root->right = deleteNode(root->right, key);       
            else{
                if(!root->left && !root->right) 
                    return NULL;          //No child condition
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;    

                int mini = findMinNode(root -> right) -> val;
                root -> val = mini;
                root -> right = deleteNode(root -> right, mini);
            }
        return root;
    }
};
