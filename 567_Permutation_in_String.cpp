class Solution {
    public:
     bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
        return false;
        int arr[26] = {0};
        for(int ch=0; ch< s1.length(); ch++)
            arr[s1[ch]-'a']++;
        int arr1[26] = {0};
        int i=0,j=0;
        while(j<s2.length()){
            arr1[s2[j]-'a']++;
            if(j-i+1==s1.length()){
                if(areEqual(arr, arr1))
                    return true;
            }
            if(j-i+1<s1.length())
            j++;
            else
            {
                arr1[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }

 bool areEqual(int s[] , int t[])
    {
        for(int i=0;i<26;i++)
            if(s[i]!=t[i])
                return false;
        return true;
    }
};
