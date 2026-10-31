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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // if(!root) return {};
        // queue<TreeNode*> q;
        // vector<vector<int>> result;

        // q.push(root);

        // while(q.size()>0){
        //     int n = q.size();
        //     vector<int>layer;
        //     for(int i = 0; i<n; i++){
        //         TreeNode* temp = q.front();
        //         q.pop();
        //         if(temp){
        //             if(temp->left){
        //                 q.push(temp->left);
        //             }
                    
        //             if(temp->right){
        //                 q.push(temp->right);
        //             }

        //             layer.push_back(temp->val);
        //         }
                
        //     }
        //     result.push_back(layer);        
        // }
        // return result;

        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            vector<int>level;
            for(int i = 0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if (temp){
                    level.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                }   
            }
            if(level.size()>0){
                result.push_back(level);
            }
        }
        return result;
    }
};
