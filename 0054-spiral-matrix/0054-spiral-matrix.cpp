class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int r=matrix.size();
        int c=matrix[0].size();
        int total=r*c;
        int start_row=0;
        int start_col=0;
        int end_row=r-1;
        int end_col=c-1;
        int count=0;
        vector<int>ans;
        while(count<total)
        {
            for(int i=start_col;i<=end_col&& count<total;i++)
            {
                ans.push_back(matrix[start_row][i]);
                count++;
            }
            start_row++;
            for(int i=start_row;i<=end_row && count<total;i++)
            {
                ans.push_back(matrix[i][end_col]);
                count++;   
            }
            end_col--;
            
            for(int i=end_col;i>=start_col && count<total;i--)
            {
                ans.push_back(matrix[end_row][i]);
                count++;
            }
            end_row--;
            for(int i=end_row;i>=start_row && count<total;i--)
            {
                ans.push_back(matrix[i][start_col]);
                count++;
            }
            start_col++;
        }
        return ans;
    }
};