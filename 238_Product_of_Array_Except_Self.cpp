class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);

        // Calculate prefix products
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            output[i] = prefix;
            prefix *= nums[i];
        }

        // Calculate suffix products and final result
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            output[i] *= suffix;
            suffix *= nums[i];
        }

        return output;
    }
};
