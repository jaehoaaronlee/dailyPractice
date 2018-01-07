class Solution {
    public boolean wordPattern(String pattern, String str) {
        Map<String, String> hashMap = new HashMap<>();

        String[] strArr = str.split(" ");
        if(pattern.length() != strArr.length)
            return false;
        
        for(int i = 0; i < pattern.length(); i++) {
            String s = String.valueOf(pattern.charAt(i));
            if( hashMap.containsKey(s) && !hashMap.get(s).equals(strArr[i]) ) {
                    return false;
            } else {
                hashMap.put(s, strArr[i]);
            }
            
            if(i > 0) {
                String st = String.valueOf(pattern.charAt(i - 1));
                if( !st.equals(s) && hashMap.get(s).equals(hashMap.get(st)) )
                    return false;
            }
        }
        
        return true;
    }
}
