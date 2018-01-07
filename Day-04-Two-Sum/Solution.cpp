class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        if(nums.empty())
            return nums;
        
        // hashMap[value] = index
        unordered_map<int, int> hashMap;
        vector<int> solution;
        for(int i = 0; i != nums.size(); ++i) {
            hashMap.insert(make_pair(nums[i], i));
        }
        
        for(int j = 0; j != nums.size(); ++j) {
            int remainder = target - nums[j];
            unordered_map<int, int>::iterator it = hashMap.find(remainder);
            if(it != hashMap.end() && it->second != j) {
                if(j > it->second) {
                    solution.push_back(it->second);
                    solution.push_back(j);
                } else {
                    solution.push_back(j);
                    solution.push_back(it->second);
                }                    
                return solution;
            }
        }
        return solution;
    }
};
