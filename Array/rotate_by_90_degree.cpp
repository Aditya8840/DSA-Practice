/*
for clockwise reverse top to down
for anticlock wise reverse left to right

then

swap elements by symmertically
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        reverse(matrix.begin(), matrix.end());

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};