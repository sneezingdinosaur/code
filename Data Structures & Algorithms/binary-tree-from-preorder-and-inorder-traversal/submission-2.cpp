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
    // TreeNode* build (int preIdx, int begin, int end, vector<int>& preorder, vector<int>& inorder){
    //     if(begin>=end){return nullptr;}
    //     TreeNode* root = new TreeNode(preorder[preIdx]);
    //     int mid = begin;
    //     while(root->val != inorder[mid]){
    //         mid++;
    //     }

    //     root->right = build(preIdx+1 + (mid-begin), mid+1, end, preorder, inorder);
    //     root->left = build(preIdx+1, begin, mid, preorder, inorder);

    //     return root;
    // }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // TreeNode* root = build(0, 0, inorder.size(), preorder, inorder);
        // return root;

        if (preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int mid = 0;
        while(preorder[0]!=inorder[mid]){mid++;}

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;

        

         



    }
};
