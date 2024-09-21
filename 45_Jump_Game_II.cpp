class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        if(nums[0]==0) return -1;

        int jumps=0, farthest=0, curr_end=0;

        for(int i=0; i<n-1; i++){
            farthest = max(farthest, i+nums[i]);
            if(i==curr_end){
                jumps++;
                curr_end = farthest;
                if(curr_end >= n-1) return jumps;
            }
        }
        return -1;
    }
};
