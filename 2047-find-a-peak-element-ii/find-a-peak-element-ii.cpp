class Solution {
public:
    int findMaxInd(vector<vector<int>>&mat,int m,int n,int mid){
        int index = -1;
        int maxele = -1;
        for(int i=0;i<m;i++){
            if(mat[i][mid]>maxele){
                maxele=mat[i][mid];
                index = i;
            }

        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low =0;
        int high = n-1;
        while(low <= high){
        int mid =(low + high)/2;

        int index = findMaxInd(mat,m,n,mid);
        int left =-1;
        if(mid -1 >=0){
            left = mat[index][mid-1];
        }
        int right = -1;   
        if(mid+1 <n){
            right = mat[index][mid+1];
        }
        if(mat[index][mid]>left && mat[index][mid]>right){
            return {index,mid};
        }
        else if(mat[index][mid]<left){
            high = mid-1;
        }else{
            low = mid+1;
        }
        }
        return {-1,-1};  
      
    }

};