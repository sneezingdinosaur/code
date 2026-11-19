class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char op = '+';
        int i = 0;

        while(i<s.size()){
            if (s[i] == ' ') {
                i++;
            }
            else if(isdigit(s[i])){
                int num = 0;
                while(i<s.size() && isdigit(s[i])){
                    num = num*10 + (s[i]-'0');
                    i++;
                }

                if(op == '+') st.push(num);
                else if (op == '-') st.push(-num);
                else if (op == '*') {int t = st.top(); st.pop(); st.push(t*num);}
                else if (op == '/') {int t = st.top(); st.pop(); st.push(t/num);}
            }
            else{
                op = s[i];
                i++;
            }
        }

        int ret = 0;
        while(!st.empty()){
            ret+=st.top();
            st.pop();
        }
        return ret;
    }
};