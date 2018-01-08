class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        vector<string> strArr{istream_iterator<string>{iss},
                             istream_iterator<string>{}};
        
        if(pattern.length() != strArr.size())
            return false;
        
        unordered_map<char, string> mapOne;
        unordered_map<string, char> mapTwo;
        
        for(int i = 0; i != pattern.length(); ++i) {
            unordered_map<char, string>::const_iterator one = mapOne.find(pattern[i]);
            unordered_map<string, char>::const_iterator two = mapTwo.find(strArr[i]);
            
            if( one == mapOne.end() && two == mapTwo.end() ) {
                mapOne[pattern[i]] = strArr[i];
                mapTwo[strArr[i]] = pattern[i];
                continue;
            } 
            
            if( mapOne[pattern[i]] != strArr[i] )
                return false;
            
        }
        return true;
    }
};
