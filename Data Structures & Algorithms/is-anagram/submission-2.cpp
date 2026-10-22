#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // unordered_map<char, int> dic;
        // unordered_map<char, int> dic1;
        // for(char c : s){
        //     dic[c]++;
        // }
        // for(char c : t){
        //     dic1[c]++;
        // }
        // return dic1==dic;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};
