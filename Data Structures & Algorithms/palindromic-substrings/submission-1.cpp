class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n==1)return 1;

        int total = 0;

        for(int i = 0; i<n; i++){
            int count = 1;

            //odds
            int left = i;
            int right = i;
            
            while(left!=0 && right!=n-1){
                if(s[left-1] == s[right+1]){
                    count++;
                    left--;
                    right++;
                }
                else break;
            }

            left = i;
            right = i+1;
            if(i!=n-1){
                if(s[left] == s[right]){
                    count++;
                    while(left!=0 && right!=n-1){
                        if(s[left-1] == s[right+1]){
                            count++;
                            left--;
                            right++;
                        }
                        else break;
                    }
                }
            }

            total+=count;
        }

        return total;
    }
};
