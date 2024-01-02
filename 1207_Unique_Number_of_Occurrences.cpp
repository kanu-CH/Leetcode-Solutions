class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> uniqueArr;
        vector<int> countArr;
        sort(arr.begin(), arr.end());

        // Add unique elements to the new vector
        for (int i = 0; i < arr.size(); ++i) {
            // Check if the current element is not equal to the next element (avoid duplicates)
            if (i == arr.size() - 1 || arr[i] != arr[i + 1]) {
                uniqueArr.push_back(arr[i]);
            }
        }
        for(int i = 0; i< uniqueArr.size(); i++){
            countArr.push_back(count(arr.begin(), arr.end(), uniqueArr[i]));
        }

        for(int i=0;i<countArr.size();i++){
            if(count(countArr.begin(), countArr.end(), countArr[i])!=1){
                return false;
            }
        }
        return true;
    }
}; 
