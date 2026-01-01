class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        for(int i =0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }else{
                pos.push_back(nums[i]);
            }
        }
        reverse(neg.begin(),neg.end());
        int i =0;
        int j =0;
        int k =0;
        while(i < neg.size() && j <pos.size()){
            if(neg[i]*neg[i] < pos[j]*pos[j]){
                nums[k]=neg[i]*neg[i];
                i++;
                k++;
            }else if(neg[i]*neg[i] > pos[j]*pos[j]){
                nums[k]=pos[j]*pos[j];
                j++;
                k++;
            }else{
                nums[k]=neg[i]*neg[i];
                i++;
                k++;
                nums[k]=pos[j]*pos[j];
                j++;
                k++;
            }
        }
        while(i<neg.size()){
            nums[k]=neg[i]*neg[i];
            i++;
            k++;
        }
        while(j<pos.size()){
            nums[k]=pos[j]*pos[j];
            j++;
            k++;
        }
        return nums;
        
    }
};