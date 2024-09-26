class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int small=prices[0];
        int maxi=INT_MIN;
        int diff;
        for(int i=0;i<prices.size();i++){
            if(prices[i]>small){
                diff=prices[i]-small;
                maxi=max(maxi,diff);
            }
            else{
                small=prices[i];
            }
        }
        if(maxi==INT_MIN) return 0;
        return maxi;
    }
};
