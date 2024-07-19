class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int> mini;
        vector<int> maxi(col, INT_MIN);

        // Find the minimum value in each row
        for(int i = 0; i < row; i++) {
            int min_val = INT_MAX;
            for(int j = 0; j < col; j++) {
                min_val = min(min_val, matrix[i][j]);
            }
            mini.push_back(min_val);
        }

        // Find the maximum value in each column
        for(int j = 0; j < col; j++) {
            int max_val = INT_MIN;
            for(int i = 0; i < row; i++) {
                max_val = max(max_val, matrix[i][j]);
            }
            maxi[j] = max_val;
        }

        // Find the lucky numbers
        vector<int> result;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == mini[i] && matrix[i][j] == maxi[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        
        return result;
    }
};
