class Solution {
public:
    bool isPerfectSquare(int num) {
        int s=1; int e= num;
        int mid= s+(e-s)/2;
        while(s<=e){ 
            if(num%mid==0 && mid==num/mid)return true;
            if (mid > num/mid){  
                e=mid-1;
            }
            else s= mid+1;
            mid= s+(e-s)/2;
        }
        return false;
    }
};
