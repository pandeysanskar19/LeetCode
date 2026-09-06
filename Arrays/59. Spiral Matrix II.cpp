class Solution {
public:
// TIME COMPLEXITY:O(N^2)   , SPACE COMPLEXITY:O(N^2).
    vector<vector<int>> generateMatrix(int n) {
        int total_el = n*n;
        vector<vector<int>> matrix(n,vector<int>(n));
        int left =0;int right=n-1;
        int top=0;int bottom=n-1;
        int cnt =1;
        while(left<=right && top<=bottom){
                // left to right: top row
            for(int j=left;j<=right;j++){
                matrix[top][j] = cnt++;
            }
            top++;
            // top to bottom : right column
            for(int i=top;i<=bottom;i++){
                matrix[i][right]=cnt++;
            }
            right--;
            // right to left : bottom row
            for(int i=right;i>=left;i--){
                matrix[bottom][i]= cnt++;
            }
            bottom--;
            // bottom to top : left columns
            for(int i=bottom;i>=top;i--){
                matrix[i][left]= cnt++;
            }
            left++;
        }
        return matrix;
    }
};
