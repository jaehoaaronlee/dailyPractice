class Solution {
public:
    string convert(string s, int numRows) {
        int len = (int)s.length();
        if (len < 2 || len <= numRows || numRows < 2)
            return s;
        
        string sol;
        int maxOff = 2 * (numRows - 1), offset;
        for (int i = 0; i < numRows; ++i) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < len; j += maxOff)
                    sol += s[j];
            }
            else {
                offset = 2 * i;
                for (int k = i; k < len; offset = maxOff - offset, k += offset)
                    sol += s[k];
            }
        }
        
        return sol;
    }
};
