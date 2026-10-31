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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* root1 = root;
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;

        while(p->val != root->val){
            path1.push_back(root);
            if(p->val>root->val){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        path1.push_back(p);

        while(q->val != root1->val){
            path2.push_back(root1);
            if(q->val>root1->val){
                root1 = root1->right;
            }
            else{
                root1 = root1->left;
            }
        }
        path2.push_back(q);

        TreeNode* lowest = path1[0];
        int i = 1;
        while(i<path1.size() && i<path2.size() && path1[i]->val == path2[i]->val){
            lowest = path1[i];
            i++;
        }
        return lowest;
    }
};
