class Solution {
public:
    string reverseWords(string s) {
        // Trim leading and trailing spaces
    int start = 0, end = s.size() - 1;
    while (start <= end && s[start] == ' ') start++;
    while (end >= start && s[end] == ' ') end--;
    
    if (start > end) return ""; // If the string is empty or contains only spaces

    // Extract words into a vector
    vector<string> words;
    string word;
    for (int i = start; i <= end; ++i) {
        if (s[i] != ' ') {
            word += s[i];
        } else if (!word.empty()) {
            words.push_back(word);
            word = "";
        }
    }
    if (!word.empty()) words.push_back(word);

    // Reverse the words vector
    reverse(words.begin(), words.end());

    // Join the reversed words with a single space
    string result;
    for (int i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i != words.size() - 1) {
            result += ' ';
        }
    }

    return result;	
    }
};
