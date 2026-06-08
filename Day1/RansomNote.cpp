class Solution {
public:
    bool canConstruct(string r, string s) {
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }

        for (int i = 0; i < r.size(); i++) {
            if (m[r[i]] > 0) {
                m[r[i]]--;
            }
            else {
                return false;
            }
        }

        return true;
    }
};
