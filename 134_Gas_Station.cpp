class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        long long deficit =0 ;
        long long balance =0;
        int start = 0, N = gas.size();
        for(int i=0 ; i<N ; i++){
            balance+=gas[i]-cost[i];
            if(balance<0){
                deficit+=balance;
                start=i+1;
                balance=0;
            }
        }
        if(deficit+balance >=0)
            return start;
        else
            return -1;
    }
};
