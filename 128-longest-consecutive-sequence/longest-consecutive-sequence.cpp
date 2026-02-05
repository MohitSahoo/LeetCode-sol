class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return 1;
        }
        unordered_set<int>s1(nums.begin(),nums.end());
        int maxcount = -1;
        for(auto it:s1){
            int count =1;
            if(s1.find(it-1)==s1.end()){
                int x = it;
                while(s1.find(x+1)!=s1.end()){
                    count++;
                    x++;
                    
                }
            }
            if(count>maxcount){
                        maxcount = count;
                    }
        }
        return maxcount;
        
    }
};