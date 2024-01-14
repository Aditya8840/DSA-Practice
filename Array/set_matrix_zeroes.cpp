/*
Using space of m*n
*/
class Solution {
public:
    void helper(vector<pair<int, int>>& v, int n, int m, vector<vector<int>>& matrix){
        for(auto i: v){
            // cout<<i.first<<" "<<i.second<<endl;
            for(int k = 0; k < m; k++){
                matrix[i.first][k] = 0;
                // cout<<i.first<<" "<<k<<endl;
            }
            for(int k = 0; k < n; k++){
                matrix[k][i.second] = 0;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> v;
        int n = matrix.size();
        int m = matrix[0].size();


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    v.push_back({i,j});
                }
            }
        }

        helper(v, n, m, matrix);
    }
};


/*
Constant Space and Optimised Time complexity of O(m*n)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> v;
        int n = matrix.size();
        int m = matrix[0].size();

        cout<<n<<" "<<m<<endl;

        int count = matrix[0][0];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    // v.push_back({i,j});
                    matrix[i][0] = 0;
                    if(j == 0){
                        count = 0;
                    }else{
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }

        for(int j = 1; j < m; j++){
            // cout<<j<<" "<<matrix[0][j]<<endl;
            if(matrix[0][j] == 0){
                // cout<<j<<endl;
                for(int i = 0; i < n; i++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < m; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        if(count == 0){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};