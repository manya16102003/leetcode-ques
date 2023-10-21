class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>t(matrix[0].size(),vector<int>(n));
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[i].size();++j)
            {
                t[j][i]=matrix[i][j];
            }
        }
        return t;
    }
};