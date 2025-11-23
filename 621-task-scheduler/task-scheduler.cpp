class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char t:tasks){
            freq[t-'A']++;
        }
        sort(freq.begin(),freq.end());
        int max_freq = freq[25];
        int count_max_freq =1;
        for(int i =24;i>=0;i--){
            if(freq[i]==max_freq){
                count_max_freq++;
            }else{
                break;
            }
        }
        return max(((max_freq-1)*(n+1)+count_max_freq) ,(int)tasks.size());
    }
};