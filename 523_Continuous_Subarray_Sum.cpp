class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int Sum = 0;
        mp[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            Sum += nums[i];
            if (k != 0) Sum %= k;
            
            // Check if the remainder has been seen before
            if (mp.find(Sum) != mp.end()) {
                if (i - mp[Sum] > 1)   // If subarray length is greater than 1, return true
                return true;
            } 
            else {            // Store the index of the first occurrence of the remainder
                mp[Sum] = i;
            }
        }
        // If no valid subarray is found, return false
        return false;
    }
};
