class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        int LSum = 0, RSum = 0, tmp = 0;
        for(auto x : nums) RSum += x;
        for(int i = 0; i < nums.size(); i++){
            RSum -= nums[i];
            tmp = abs(LSum - RSum);
            ans.push_back(tmp);
            LSum += nums[i];
        }
        return ans;
    }
};
