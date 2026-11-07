class Solution {
public:

    bool isPalindrome(){

    }



    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1){return s;}

        int maxi = 1;
        int begin = 0; int end = 0;


        for(int i = 1; i<n-1; i++){
            int right = i;
            int left = i;
            int count = 1;

            while(left!=0 && right!=n-1){
                if(s[left-1] == s[right+1]){
                    left--;
                    right++;
                    count+=2;
                }
                else break;
            }


            if(count>=maxi){
                cout<<count;
                cout<<left;
                cout<<right;
                maxi = count;
                begin = left;
                end = right;
            }
        }



        for(int i = 0; i<n-1; i++){
            if(s[i] == s[i+1]){
                int left = i;
                int right = i+1;
                
                int count = 2;

                while(left!=0 && right!=n-1){
                    if(s[left-1] == s[right+1]){
                        left--;
                        right++;
                        count+=2;
                    } 
                    else break;
                }

                if(count>=maxi){
                    cout<<count;
                    cout<<left;
                    cout<<right;
                    maxi = count;
                    begin = left;
                    end = right;
                }
            }
        }


        // cout<<begin;
        // cout<<end;

        return s.substr(begin,end-begin+1);
        
    }
};
