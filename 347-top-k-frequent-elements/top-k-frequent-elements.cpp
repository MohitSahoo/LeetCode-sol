class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int,int> mpp;
        vector<int>v1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;

       for(int i =0;i<nums.size();i++){
        mpp[nums[i]]++;
       }
       for(auto i =mpp.begin();i!=mpp.end();i++){
        minh.push({i->second,i->first});
        if(minh.size()>k){
            minh.pop();
        }
       }
       while(minh.size()!=0){
        
        v1.push_back(minh.top().second);
        minh.pop();
       }
       return v1;


        
    }
};