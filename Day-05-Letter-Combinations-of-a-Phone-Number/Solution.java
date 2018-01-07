class Solution {
    public List<String> letterCombinations(String digits) {
        LinkedList<String> solution = new LinkedList<>();
        String[] mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.length() == 0) {
            return solution;
        }
        
        solution.add("");
        for(int i = 0; i < digits.length(); i++) {
            int digitInt = digits.charAt(i) - '0';
            while(solution.peek().length() == i) {
                String str = solution.remove();
                for(char s: mapping[digitInt].toCharArray()) {
                    solution.add(str + s);
                }
            }
        }
        return solution;        
    }
}
