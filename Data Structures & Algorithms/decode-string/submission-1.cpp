class Solution {
public:
    string decodeString(string s) {
        string ret = "";
        stack<char>out;
        

        for(int i = 0; i<s.size(); i++){
            if(s[i] == ']'){
                string add = "";
                string integer = "";

                while(out.top()!='['){
                    add = out.top() + add;
                    out.pop();
                }

                out.pop();

                while(out.size()>0 && isdigit(out.top())){
                    integer = out.top() + integer;
                    out.pop();
                }

                int mult = stoi(integer);

                for(int j = 0; j<mult; j++){
                    for(char c : add){
                        out.push(c);
                    }
                }
            }
            else{
                out.push(s[i]);
            }
        }

        while(!out.empty()){
            ret = out.top() + ret;
            out.pop();
        }

        return ret;
    }
};