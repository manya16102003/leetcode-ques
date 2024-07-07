class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        //transpose of matrix;
        for(int i=0;i<row;i++)
        {
            for(int j=i;j<col ;j++)
            {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        
        
        //reverse the starting columns with last columns
        for(int k=0;k<row;k++)
        {
           reverse(matrix[k].begin(), matrix[k].end());
        }
    }
};