class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string sol;
        for(auto i = S.rbegin(); i < S.rend(); ++i) {
            if(*i != '-') {
                if(sol.size() % (K + 1) == K)
                    sol += '-';
                sol += toupper(*i);
            }
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
