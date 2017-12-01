class Solution {
    public static final String operators = "+-/*";
    
    public boolean isOperator(String str) {
        return operators.indexOf(str) != -1;
    }
    
    public int calculate(String operator, int lval, int rval) {
        if(operators.indexOf(operator) == 0) {
            return lval + rval;
        } else if(operators.indexOf(operator) == 1) {
            return lval - rval;
        } else if(operators.indexOf(operator) == 2) {
            return lval / rval;
        } else {
            return lval * rval;
        }
    }
    
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < tokens.length; i++) {
            if(!isOperator(tokens[i])) {
                stack.push(Integer.parseInt(tokens[i]));
            } else {
                int rVal = stack.pop();
                int lVal = stack.pop();
                stack.push(calculate(tokens[i], lVal, rVal));
            }
        }    
        return stack.pop();
    }
}
