class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) {
            return ans; 
        }

        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;

        while (left <= right && top <= bottom) {
            // Traverse from left to right
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // Traverse from top to bottom
            for (int j = top; j <= bottom; j++) {
                ans.push_back(matrix[j][right]);
            }
            right--;

            // Traverse from right to left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // Traverse from bottom to top
            if (left <= right) {
                for (int j = bottom; j >=top; j--) {
                    ans.push_back(matrix[j][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
