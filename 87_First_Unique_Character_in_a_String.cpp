class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>arr(26,0);
        int ans = -1;
        for(int i = 0;i < s.size();i++)
        {
            arr[s[i] - 'a']++;
        }
        for(int i = 0;i < s.size();i++)
        {
            if(arr[s[i]- 'a'] == 1)
            {
               return i ; 
            }
        }
        return -1 ;
    }
};
