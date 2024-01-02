class Solution{
public:
    void reverse(vector<char> &s,int x, int y) {
        while(x<y){
            swap(s[x++],s[y--]);
        }
    }
    void reverseWords(vector<char> &s)
    {
        int x = 0, y = 0;
        reverse(s, x, s.size() - 1);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                y = i - 1;
                reverse(s, x, y);
                x = y + 2;
            }
        }
        reverse(s, x, s.size() - 1);
    }
}
