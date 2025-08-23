class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        set<int> s1;
        for(int i =0;i<nums.size();i++){
            s1.insert(nums[i]);
        }
        int maxcount =1;
        
        for(auto it:s1 ){
            if(s1.find(it-1)==s1.end()){
                int x = it;
                int count =1;
                while(s1.find(x+1)!=s1.end()){
                    x++;
                    count++;
                    if(count>maxcount){
                        maxcount =count;
                    }
                }
            }
        }
        return maxcount;
        
    }
};