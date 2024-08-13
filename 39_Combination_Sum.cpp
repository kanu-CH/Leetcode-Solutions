class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1])
                continue; // skip duplicates
            if (arr[i] > target)
                break; // no point in exploring further as the array is sorted
            ds.push_back(arr[i]);
            findCombination(i, target - arr[i], arr, ans, ds); // not i + 1 because we can reuse same element
            ds.pop_back(); // backtrack
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
