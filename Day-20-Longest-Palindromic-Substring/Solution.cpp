class Solution {
public:
    string longestPalindrome(string s) {
        int sz_s = (int) s.length();
        
        /**
         * keep track of max length and start index
         * by using a helper method that expands
         * around an index as a pivot
         */
        int maxLen = 0, start = 0;
        for (int i = 0; i != sz_s; ++i) {
            int odd = expandString(s, i, i);
            int even = expandString(s, i, i + 1);
            int len = (odd > even) ? odd : even;
            
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
    
    /**
     * helper method that expands around a pivot
     * and checks if a substring is palindrome
     */
    int expandString(string s, int left, int right) {
        int l = left, r = right;
        while (l >= 0 && r < (int) s.length() && s[l] == s[r]) {
            --l;
            ++r;
        }
        
        return r - l - 1;
    }
};
