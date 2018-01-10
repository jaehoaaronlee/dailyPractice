class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> sol = new LinkedList<>();
        if(n == 0) return sol;
        generate(sol, "", n, n);
        return sol;
    }

    void generate(List<String> solution, String parens, int l, int r) {
        if(l == 0 && r == 0) {
            solution.add(parens);
            return;
        }

        if(l > 0)
            generate(solution, parens + "(", l - 1, r);
        if(r > l)
            generate(solution, parens + ")", l, r - 1);
    }
}
