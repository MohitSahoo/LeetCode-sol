class Solution {
public:
    void merge(int l,int mid,int r,vector<int>&nums){
        int i=l;
        int j =mid+1;
        vector<int>temp;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i++]);
            }else{
               temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=r){
            temp.push_back(nums[j++]);
        }
        for(int k = l; k <= r; k++) nums[k] = temp[k - l];
        
    }
    void mergesort(int l,int r,vector<int>&nums){
        if(l>=r){
            return;
        }
        int mid = (l+r)/2;
        mergesort(l,mid,nums);
        mergesort(mid+1,r,nums);
        merge(l,mid,r,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(0,nums.size()-1,nums);
        return nums;
    }
};