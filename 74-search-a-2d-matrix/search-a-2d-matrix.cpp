class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
       int row=0;
        int n = arr.size();
        int col = arr[0].size()-1;
        while(row <n && col >=0){
            if(arr[row][col]== target){
                return true;
            }else if ( arr[row][col]<target){
                row++;
            }else{
                col--;
            }

        }
        return false;
    }
};