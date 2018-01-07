class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> solution;
        if(!digits.length())
            return vector<string>();
        const vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solution.push_back("");
        for(int i = 0; i != digits.length(); ++i) {
            int digitInt = digits[i] - '0';
            while(solution.front().length() == i) {
                string str = solution.front();
                solution.erase(solution.begin());
                for(int j = 0; j != mapping[digitInt].length(); ++j) {
                    solution.push_back(str + mapping[digitInt][j]);
                }
            }
        }
        return solution;
    }
};
