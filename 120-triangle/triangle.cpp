class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int>front(m,0);
        for(int j = 0;j<m;j++){
            front[j]=triangle[m-1][j];
        }
        for(int i =m-2;i>=0;i--){
            vector<int>temp(m,0);
            for(int j =i;j>=0;j--){
                int d = front[j]+triangle[i][j];
                int dg = front[j+1]+triangle[i][j];
                temp[j]=min(d,dg);
            }
            front =temp;
        }
        return front[0];
        
    }
};