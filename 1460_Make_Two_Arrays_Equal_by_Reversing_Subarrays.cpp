class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Frequency map to count occurrences of elements in target and arr
        unordered_map<int, int> targetCount;
        unordered_map<int, int> arrCount;

        // Count elements in target
        for (int num : target) {
            targetCount[num]++;
        }

        // Count elements in arr
        for (int num : arr) {
            arrCount[num]++;
        }

        // Compare frequency maps
        return targetCount == arrCount;
    }
};
