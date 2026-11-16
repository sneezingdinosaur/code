class Solution {
public:
    string decodeString(string s) {
        string out;

        for (char c : s) {
            if (c == ']') {
                string add = "";
                int mult = 0;
                int place = 1;

                while (out.back() != '[') {
                    add += out.back();
                    out.pop_back();
                }

                reverse(add.begin(), add.end());
                out.pop_back();

                while (!out.empty() && isdigit(out.back())) {
                    mult += (out.back() - '0') * place;
                    place *= 10;
                    out.pop_back();
                }

                for (int j = 0; j < mult; j++) {
                    out += add;
                }
            }
            else {
                out.push_back(c);
            }
        }

        return out;
    }
};