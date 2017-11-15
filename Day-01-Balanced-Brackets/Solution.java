import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    public static boolean isOpener(char c) {
        if(c == '[' || c == '{' || c== '(') {
            return true;
        }
        return false;
    }
    
    public static Character partner(char c) {
        if(c == '}') {
            return '{';
        } else if (c == ')') {
            return '(';
        } else {
            return '[';
        }
    }
    
    public static boolean isBalanced(String expression) {
        LinkedList<Character> stack = new LinkedList<>();
        char[] arr = expression.toCharArray();
        
        for(int i = 0; i < arr.length; i++) {
            if(isOpener(arr[i])) {
                stack.addFirst(arr[i]);
            } else {
                if( partner(arr[i]) == stack.peek() ) {
                    stack.remove();
                } else {
                    return false;
                }
            }
        }
        
        if(stack.isEmpty()) {
            return true;
        } else {
            return false;
        }
    }
  
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int a0 = 0; a0 < t; a0++) {
            String expression = in.next();
            System.out.println( (isBalanced(expression)) ? "YES" : "NO" );
        }
    }
}
