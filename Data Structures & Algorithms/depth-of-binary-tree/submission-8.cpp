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
    int maxDepth(TreeNode* root) {
        if(!root){return 0;}

        stack<pair<TreeNode*,int>>s;
        s.push({root,1});
        int total = 1;
        while(s.size()>0){
            pair<TreeNode*,int>x = s.top();
            TreeNode* node = x.first;
            int depth = x.second;
            s.pop();
            if(node){
                total = max(total,depth);
                s.push({node->right, depth + 1});
                s.push({node->left, depth+1});
            }
        }
        return total;





        // int level = 0;
        // queue<TreeNode*> levels;
        // levels.push(root);
        
        // while(levels.size()>0){
        //     int x = levels.size();
        //     for (int i = 0; i<x; i++){
        //         TreeNode* node = levels.front();
        //         levels.pop();
        //         if(node->left){
        //             levels.push(node->left);
        //         }
        //         if(node->right){
        //             levels.push(node->right);
        //         }
        //     }
        //     level+=1;
        // }
        // return level;
    }
};
