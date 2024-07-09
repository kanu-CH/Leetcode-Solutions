class Solution {
public:
    std::string reorganizeString(std::string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> frequency;
        for (char ch : s) {
            frequency[ch]++;
        }
        
        // Step 2: Create a max heap based on the frequency of characters
        priority_queue<pair<int, char>> maxHeap;
        for (auto& [ch, freq] : frequency) {
            maxHeap.push({freq, ch});
        }
        
        // Step 3: Check if rearrangement is possible
        int n = s.length();
        if (maxHeap.top().first > (n + 1) / 2) {
            return "";
        }
        
        // Step 4: Reorganize the string
        string result;
        pair<int, char> prev = {0, '#'};
        
        while (!maxHeap.empty()) {
            auto [freq, ch] = maxHeap.top();
            maxHeap.pop();
            result += ch;
            if (prev.first > 0) {
                maxHeap.push(prev);
            }
            prev = {freq - 1, ch};
        }
        
        return result;
    }
};
