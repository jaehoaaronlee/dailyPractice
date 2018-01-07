class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        if(nums.length == 0)
            return nums;
        
        int[] solution = new int[2];
        
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }
        
        for(int j = 0; j < nums.length; j++) {
            int remainder = target - nums[j];
            if(map.containsKey(remainder) && map.get(remainder) != j) {
                if(map.get(remainder) > j) {
                    solution[0] = j;
                    solution[1] = map.get(remainder);
                } else {
                    solution[0] = map.get(remainder);
                    solution[1] = j;
                }
                
                return solution;
            }
        }
        
        return solution;
    }
}
