class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ls =0;
        int rs =0;
        int maxsum = 0;
        for(int i =0;i<k;i++){
            ls +=cardPoints[i];
        }
        maxsum = ls;
        int rindex = cardPoints.size()-1;
        for(int i =k-1;i>=0;i--){
            ls= ls-cardPoints[i];
            rs = rs+cardPoints[rindex];
            rindex--;
            maxsum = max(ls+rs,maxsum);
        }
        return maxsum;
    }

};