class Solution {
public:
    int func(vector<int>&bloomDay,int mid,int k){
        int total=0;
        int count =0;
        for(int i =0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }else{
                total += count / k;
                count = 0;
            }  
        }
        total += count / k;
        return total;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *std::min_element(bloomDay.begin(),bloomDay.end());
        int high = *std::max_element(bloomDay.begin(),bloomDay.end());
        int ans =-1;

        while(low <= high){
            int mid =  (low + high)/2;
            if(func(bloomDay,mid,k)>=m){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};