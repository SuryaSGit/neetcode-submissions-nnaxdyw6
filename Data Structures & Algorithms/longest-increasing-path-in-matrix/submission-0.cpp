class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> in_degree(matrix.size(), vector<int>(matrix[0].size()));
        queue<pair<int,int>> top_sort;
        int num_layers = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(i > 0 && matrix[i-1][j] < matrix[i][j]){
                    in_degree[i][j]++;
                }
                if(j > 0 && matrix[i][j-1] < matrix[i][j]){
                    in_degree[i][j]++;
                }
                if(i < matrix.size() - 1 && matrix[i+1][j] < matrix[i][j]){
                    in_degree[i][j]++;
                }
                if(j < matrix[0].size() - 1 && matrix[i][j+1] < matrix[i][j]){
                    in_degree[i][j]++;
                }
                if(in_degree[i][j] == 0){
                    top_sort.push({i,j});
                }
            }
        }
        while(!top_sort.empty()){
            int temp = top_sort.size();
            for(int i = 0; i < temp; i++){
                pair<int,int> cur_ind = top_sort.front();
                int cur_i = cur_ind.first;
                int cur_j = cur_ind.second;
                top_sort.pop();
                if(cur_i > 0 && matrix[cur_i-1][cur_j] > matrix[cur_i][cur_j]){
                    in_degree[cur_i-1][cur_j]--;
                    if(in_degree[cur_i-1][cur_j] == 0){
                        top_sort.push({cur_i-1,cur_j});
                    }
                }
                if(cur_j > 0 && matrix[cur_i][cur_j-1] > matrix[cur_i][cur_j]){
                    in_degree[cur_i][cur_j-1]--;
                    if(in_degree[cur_i][cur_j-1] == 0){
                        top_sort.push({cur_i,cur_j-1});
                    }
                }
                if(cur_i < matrix.size() - 1 && matrix[cur_i+1][cur_j] > matrix[cur_i][cur_j]){
                    in_degree[cur_i+1][cur_j]--;
                    if(in_degree[cur_i+1][cur_j] == 0){
                        top_sort.push({cur_i+1,cur_j});
                    }
                }
                if(cur_j < matrix[0].size() - 1 && matrix[cur_i][cur_j+1] > matrix[cur_i][cur_j]){
                    in_degree[cur_i][cur_j+1]--;
                    if(in_degree[cur_i][cur_j+1] == 0){
                        top_sort.push({cur_i,cur_j+1});
                    }
                }
                in_degree[cur_i][cur_j] = -1;
            }
            num_layers++;
        }
        return num_layers;
    }
};
