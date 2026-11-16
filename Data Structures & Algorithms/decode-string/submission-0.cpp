class Solution {
public:
    string decodeString(string s) {
        
        int i;
        string num = "";
        string prev = "";

        for(i = 0; i<s.size(); i++){
            if(isdigit(s[i])){
                num+=s[i];
                i++;
                while(i<s.size() && isdigit(s[i])){
                    num+=s[i];
                    i++;
                }
                break;
            }
            else{
                prev+=s[i];
            }
        }
        i++;
        
        if(num.size()==0){return s;}

        int mult = stoi(num);
        string mid = ""; 
        
        int numOpen = 0;
        
        while(i<s.size()){
            if(s[i] == '['){
                numOpen++;

            }
            else if(s[i] == ']'){
                if(numOpen == 0){
                    string temp = prev;
                    for(int j = 0; j<mult; j++){
                        temp+=mid;
                    }
                    temp+=s.substr(i+1,s.size()-i);
                    return decodeString(temp);
                }
                numOpen--;
            }

            mid+=s[i];


            i++;
        }
        return s;
    }
};