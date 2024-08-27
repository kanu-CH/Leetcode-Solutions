class Solution {
public:
    bool solve(int total, vector<int> &arr, int N){
        vector<int> curr(total/2 +1);
        vector<int> next(total/2 +1);
            
        curr[0] = 1;
        next[0] = 1;
            
        for(int index = N-1; index >= 0; index--){
            for(int target = 0; target <= (total/2); target++){
                    
                bool include = 0;
                    
                if(target - arr[index] >=0)
                    include = next[target - arr[index]];
                        
                bool exclude = next[target - 0];
                    
                curr[target] = (include or exclude);
            }
                
            next = curr;
        }        
        return next[total/2];
    }
    bool canPartition(vector<int>& nums) {
        int total = 0; 
        int n = nums.size(); 
        for(int i=0; i<n; i++){
            total += nums[i];
        }
            
        if(total & 1)
            return false;
            
        int target = total / 2;
        if(solve(total, nums, n))
            return true;
        else
            return false;
    }
};
