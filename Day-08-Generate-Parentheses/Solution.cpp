class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        if(n == 0) return sol;
        generate(sol, "", n, n);
        return sol;
    }

    void generate(vector<string>& solution, string pars, int l, int r) {
        if(l == 0 && r == 0) {
            solution.push_back(pars);
            return;
        }
        if(l > 0)
            generate(solution, pars + "(", l - 1, r);
        if(r > l)
            generate(solution, pars + ")", l, r - 1);
    }
};
