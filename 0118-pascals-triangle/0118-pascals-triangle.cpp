class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result(numRows);
        for(int i=0;i<numRows;i++)
        {
            //1st and 2nd row will always have 1 
            result[i]=vector<int>(i+1, 1);
            //as 1st and last column is always 1
            for(int j=1;j<i;j++)
            {
                result[i][j]=result[i-1][j-1] + result[i-1][j];
            }
        }
        return result;
    }
};