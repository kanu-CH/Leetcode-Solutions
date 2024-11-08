class KthLargest {
public:
    // Taking a min Heap to track the largest 'k' element
    priority_queue<int, vector<int>, greater<int>> pq;
    int curr_size;
    KthLargest(int k, vector<int>& nums) {
        curr_size = k;
        for (auto& x : nums) {
            pq.push(x);
            if (pq.size() > curr_size) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > curr_size) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
