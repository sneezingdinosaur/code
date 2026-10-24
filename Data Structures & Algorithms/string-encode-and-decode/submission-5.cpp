class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";
        for(int i = 0; i<strs.size(); i++){
            output += to_string(strs[i].size()) + "#" + strs[i];
        }
        return output;
    }

    vector<string> decode(string s) {
        int before = 0;
        vector<string>output;

        for(int i = 0; i<s.size(); i++){
            if (s[i] == '#'){
                string num = "";
                for(int j = before; j<i; j++){
                    num += s[j];
                }
                int n = stoi(num);
                if(n == 0){
                    output.push_back("");
                }
                else{
                    output.push_back(s.substr(i+1,n));
                    i+=n;
                }
                before = i+1;
            }
        }
        return output;
    }
};
