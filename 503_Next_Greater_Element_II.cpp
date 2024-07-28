class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n,-1);

        stack<int>st;
        for(int i = 2*n - 1; i >= 0; i--)
        {
            // we pop out all elements smaller than current element
            while(!st.empty() && (nums[i%n] >= st.top()))
            {
                st.pop();
            }

            // if stack is empty means no greater element is there
            // if not empty we make answer at that index equal to top element
            if(!st.empty() && (i < n))
            {
                v[i] = st.top();
            }

            st.push(nums[i%n]);
        }

        return v;
    }
};
