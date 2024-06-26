class Solution {    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Using Breadth First Search (BFS)
        queue<TreeNode *> q1;
        vector<vector<int>> res;
        bool flagRev = false;
        
        if(!root) return res;
        
        q1.push(root);
        
        while(!q1.empty()){
            int size = q1.size();
            vector<int> lvl;
            
            while(size--){
                TreeNode *curr = q1.front();
                q1.pop();
                
                if(curr->left) q1.push(curr->left);
                if(curr->right) q1.push(curr->right);
                
                lvl.push_back(curr->val);
            }
            
            if(flagRev) reverse(begin(lvl), end(lvl));
            flagRev = !flagRev;
            res.push_back(lvl);
        }
        
        return res;
    }
};
