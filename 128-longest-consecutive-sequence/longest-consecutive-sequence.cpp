class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s1(nums.begin(),nums.end());
        int maxcount =0;
        for(auto it:s1){
            if(s1.find(it-1)== s1.end()){
                int count =0;
                int x = it;
                while(s1.find(x)!=s1.end()){
                    x= x+1;
                    count++;
                    if(count>maxcount){
                        maxcount = count;
                    }
                }
            }
        }
        return maxcount;

        
    }
};