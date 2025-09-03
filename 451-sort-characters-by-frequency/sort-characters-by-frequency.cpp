class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto &it:mpp){
            pq.push({it.second,it.first});
        }
        string res="";
        while(pq.size()!=0){
           int count = pq.top().first;
           char ch = pq.top().second;
           while(count!=0){
            res.push_back(ch);
            count--;
           }
           pq.pop();
        }
        return res;
        
    }
};