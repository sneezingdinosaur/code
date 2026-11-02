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

class Codec {
public:
    vector<string>result;
    int i = 0;
    vector<string> vals;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // queue<TreeNode*>q; 
        // q.push(root);
        // string output = "";

        // while(q.size()>0){
        //     int n = q.size();
        //     TreeNode* temp;
        //     for(int i = 0; i<n; i++){
        //         temp = q.front();
        //         q.pop();
        //         if(temp){
        //             output+=to_string(temp->val) + ",";
        //             q.push(temp->left);
        //             q.push(temp->right);
        //         }
        //         else{
        //             output+="n,";
        //         }
                
        //     }
        // }
        // cout<<output;
        // return output;
        dfs(root);
        string output = "";
        for(string s : result){
            output+=s + ",";
        }
        cout<<output;
        return output;
    }
    void dfs (TreeNode* node){
        if(!node){result.push_back("n"); return;}
        result.push_back(to_string(node->val));
        dfs(node->left);
        dfs(node->right);
    }

    


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // stringstream ss(data);
        // string tok;
        // if(!getline(ss, tok , ',') || tok == "n") return nullptr;

        // TreeNode* root = new TreeNode(stoi(tok));
        // queue<TreeNode*>q;
        // q.push(root);

        // while(q.size()>0){
        //     TreeNode* node = q.front();
        //     q.pop();
        //     if(getline(ss, tok, ',') && tok!="n"){
        //         node->left = new TreeNode(stoi(tok));
        //         q.push(node->left);
        //     }
        //     if(getline(ss, tok, ',') && tok!="n"){
        //         node->right = new TreeNode(stoi(tok));
        //         q.push(node->right);
        //     }
        // }
        // return root;
        
        stringstream ss(data);
        string tok;
        while (getline(ss, tok, ',')) {
            vals.push_back(tok);
        }
        return dfsd();
    }
    TreeNode* dfsd(){
        if(vals[i] == "n") {i++; return nullptr;}
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsd();
        node->right = dfsd();
        return node;

    }
    
};
