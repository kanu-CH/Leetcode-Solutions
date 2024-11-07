class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals based on the starting value
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;  // Step 2: To store merged intervals

        for (const auto& interval : intervals) {
            // Step 3: If merged list is empty or there is no overlap
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);  // Add current interval
            } else {
                // Overlapping intervals, merge them
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;  // Step 4: Return merged intervals
    }
};
