class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(char c : s){
            if (c == '{' || c == '[' || c == '('){
                brackets.push(c);
            }
            else{
                if(brackets.size()==0 || (c=='}' && brackets.top() != '{') || (c==']' && brackets.top() != '[') || (c==')' && brackets.top() != '(')){return false;}
                brackets.pop();
            }
        }
        return brackets.size()==0;
    }
};
