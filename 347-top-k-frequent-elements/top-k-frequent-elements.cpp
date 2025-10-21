class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mpp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        vector<int>ans;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            minheap.push({it.second,it.first});
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        
        while(minheap.size()!=0){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }
        return ans;
        
    }
};