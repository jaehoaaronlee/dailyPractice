class Solution {
public:
    typedef vector<int>::size_type size;
    void nextPermutation(vector<int>& nums) {
        size len = nums.size();
        size left;
        if(len == 0 || len == 1) return;

        // find the first occurance of non-descending element
        size i = len - 1;
        for( ; i != 0; --i) {
            if(nums[i - 1] < nums[i]) {
                left = i - 1;
                break;
            }
        }
        
        // all elements are in descending order
        if(i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // find an element to swap
        for(size j = len - 1; j != left; --j) {
            if(nums[j] > nums[left]) {
                swap(nums[left], nums[j]);
                break;
            }
        }
        
        reverse(nums.begin() + left + 1, nums.end());
    }
};
