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
public:
    stack<TreeNode*> left;
    stack<TreeNode*> right;

    void push_left_side(TreeNode* root){
        for(; root != nullptr; root = root->left){
            left.push(root);
        }
    }

    void push_right_side(TreeNode* root){
        for(; root != nullptr; root = root->right){
            right.push(root);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        push_left_side(root);
        push_right_side(root);

        while(!left.empty() || !right.empty()){
            TreeNode* a = left.top();
            TreeNode* b = right.top();

            // If both stacks point to the same node, stop the search
            if (a == b) return false;

            int sum = a->val + b->val;
            if (sum == k) return true;
            else if (sum < k) {
                left.pop();
                push_left_side(a->right);
            } else {
                right.pop();
                push_right_side(b->left);
            }
        }

        return false;
    }
};
