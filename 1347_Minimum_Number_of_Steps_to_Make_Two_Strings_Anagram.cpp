class Solution {
public:
    int minSteps(string s, string t) {
        // Frequency arrays for characters in s and t
        vector<int> countS(26, 0);
        vector<int> countT(26, 0);

        // Count characters in s
        for (char c : s) {
            countS[c - 'a']++;
        }

        // Count characters in t
        for (char c : t) {
            countT[c - 'a']++;
        }

        // Calculate the number of replacements needed
        int steps = 0;
        for (int i = 0; i < 26; i++) {
            if (countT[i] > countS[i]) {
                steps += countT[i] - countS[i];
            }
        }

        return steps;
    }
};
