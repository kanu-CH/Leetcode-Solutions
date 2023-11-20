class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        string s="";
        chars.push_back('*'); // for not getting the error as we will check for chars[i+1] in the loop
        int freq=1;
        for(int i=0;i<n;i++){
            char c=chars[i];
            if(chars[i+1]==c){ //checking if current character is equal to the next character
                freq++;
            }
            else{
                s+=c;
                if(freq>1){ //if freq=1 then no need to append the frequency
                    s+=to_string(freq);
                    freq=1;
                }
            }
        }
        for(int i=0;i<s.length();i++){
            chars[i]=s[i]; // for copying back
        }
        return s.length();
    }
};
