class Solution {
public:
    string decodeString(string s) {
        vector<string> stack;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                stack.push_back(string(1, s[i]));
            } else {
                string substr = "";

                while (stack.back() != "[") {
                    substr = stack.back() + substr;
                    stack.pop_back();
                }
                stack.pop_back(); // remove '['

                string k = "";
                while (!stack.empty() && isdigit(stack.back()[0])) {
                    k = stack.back() + k;
                    stack.pop_back();
                }

                int num = stoi(k);
                string decoded = "";

                while (num--) {
                    decoded += substr;
                }

                stack.push_back(decoded);
            }
        }

        string result = "";
        for (string &str : stack) {
            result += str;
        }

        return result;
    }
};
