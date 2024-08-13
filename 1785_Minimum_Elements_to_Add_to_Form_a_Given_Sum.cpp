class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = accumulate(nums.begin(), nums.end(), 0L),  diff = abs(goal - sum);
        return (diff + limit - 1) / limit;
    }
};
