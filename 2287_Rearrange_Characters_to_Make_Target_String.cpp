class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        // Create frequency counters for s and target
        unordered_map<char, int> s_count, target_count;
        
        // Count frequencies of characters in s
        for (char ch : s) {
            s_count[ch]++;
        }
        
        // Count frequencies of characters in target
        for (char ch : target) {
            target_count[ch]++;
        }
        
        // Find the maximum number of copies of target that can be formed
        int max_copies = INT_MAX;
        for (char ch : target) {
            if (target_count[ch] > 0) {
                max_copies = min(max_copies, s_count[ch] / target_count[ch]);
            }
        }
        
        return max_copies;
    }
};
