class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // int max = 0;
        // if(arr.size() >= 3){
        //     for(int i =0 ; i<arr.size(); i++){
        //         if (arr[i]>arr[max]){
        //             max=i;
        //         }
        //     }
        // }
        //return max;

        //another approach

        int s = 0, e= arr.size()-1;
        int mid= s+(e-s)/2;
        while(s<e){
            if(arr[mid]<arr[mid+1]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
            mid= s+(e-s)/2;
        }
        return s;  
    }
};
