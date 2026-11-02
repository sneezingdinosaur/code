class WordDictionary {
private:
    unordered_map<char, WordDictionary*> children;
    bool isDone = false;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        WordDictionary* root = this;
        for(char c : word){
            if(!root->children.count(c)){root->children[c] = new WordDictionary();}
            root = root->children[c];
        }
        root->isDone = true;
    }

    bool help (string word, WordDictionary*root){
        for(int i = 0; i<word.size(); i++){
            char c = word[i];
            if(c != '.'){
                if(!root->children.count(c)){
                    return false;
                }
                root = root-> children[c];
            }
            else{
                for (auto& [letter, child] : root->children){
                    if(help(word.substr(i+1), child)){
                        return true;
                    }
                }
                return false;
            }
        }
        
        return root->isDone;
    }
    
    bool search(string word) {
        WordDictionary* root = this;
        return help(word, root);
    }
    
};
