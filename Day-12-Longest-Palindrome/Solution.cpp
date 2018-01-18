class Solution {
public:
    int longestPalindrome(string s) {
        int sol = 0;
        unordered_map<char, int> pairs;
        for (int i = 0; i < s.length(); ++i) {
            unordered_map<char, int>::iterator tmp = pairs.find(s[i]);
            if (tmp == pairs.end()) {
                pairs.insert(make_pair(s[i], 1));
            } else {
                ++(tmp->second);
            }
        }
        
        for (unordered_map<char, int>::iterator it = pairs.begin(); it != pairs.end(); ++it) {
            int times = it->second;
            sol += times / 2 * 2;
            if (times % 2 != 0 && sol % 2 == 0) {
                ++sol;
            }
        }
        
        return sol;
    }
};
