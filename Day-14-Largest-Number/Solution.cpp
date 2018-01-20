class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        
        for(auto i: nums)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](string& s1, string& s2){ return s1+s2 > s2+s1; });
        
        string sol;
        for(auto s: arr)
            sol += s;
        
        while(sol[0] =='0' && sol.length() > 1)
            sol.erase(0, 1);
        
        return sol;
    }
};
