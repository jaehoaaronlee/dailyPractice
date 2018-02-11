class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int sol = 0;
        
        int start, end;
        for (int i = 0; i != len; ++i) {
            // odd length
            start = i - 1, end = i + 1;
            while (start >= 0 && end < len && s[start] == s[end]) {
                ++sol;
                --start;
                ++end;
            }
            
            // even length
            start = i, end = i + 1;
            while (start >= 0 && end < len && s[start] == s[end]) {
                ++sol;
                --start;
                ++end;
            }
            
            // single character
            ++sol;
        }
        
        return sol;  
    }
};
