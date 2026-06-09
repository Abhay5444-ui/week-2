class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();

        unordered_map<char, int> map1;
        for (char c : p) {
            map1[c]++;
        }

        unordered_map<char, int> map2;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            map2[s[i]]++;

            if (i >= m) {
                map2[s[i - m]]--;

                if (map2[s[i - m]] == 0) {
                    map2.erase(s[i - m]);
                }
            }

            if (map1 == map2) {
                result.push_back(i - m + 1);
            }
        }

        return result;
    }
};
