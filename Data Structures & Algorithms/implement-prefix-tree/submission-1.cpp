class PrefixTree {
private:
    unordered_map<char, PrefixTree*>children;
    bool isEnd = false;
public:
    PrefixTree(){}
    
    void insert(string word) {
        // PrefixTree* root = this;
        // for(char c : word){
        //     if(!root->children.count(c)){
        //         root->children[c] = new PrefixTree();
        //     }
        //     root = root->children[c];
        // }
        // root->isEnd = true;


        PrefixTree* root = this;
        for(char c : word){
            if(!root->children.count(c)){
                root->children[c] = new PrefixTree();
            }
            root = root->children[c];
        }
        root->isEnd = true;
    }
    
    bool search(string word) {
        PrefixTree* root = this;
        for(char c : word){
            if (!root->children.count(c)){
                return false;
            }
            root = root->children[c];
        }
        return root->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* root = this;
        for(char c : prefix){
            if (!root->children.count(c)){
                return false;
            }
            root = root->children[c];
        }
        return true;
    }
};
