class Solution {
public:
    void dfs(int start, vector<vector<int>>& adjLS, vector<int>& vis) {
        vis[start] = 1;
        for (auto it : adjLS[start]) {
            if (!vis[it]) {
                dfs(it, adjLS, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();
        vector<vector<int>> adjLS(m); 
        
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(isConnected[i][j]==1 && i != j){
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
        }
        int count =0;
        vector<int>vis(m,0);
        for(int i =0;i<m;i++){
            if(!vis[i]){
                count++;
                dfs(i,adjLS,vis);
            }
        }
        return count;
        
    }
};