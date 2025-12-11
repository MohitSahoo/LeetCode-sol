class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low =0;
        int high = letters.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(letters[mid] <= target){
                low = mid+1;
            }else if(letters[mid]>target){
                ans = mid;
                high= mid-1;
            }
        }
        if(ans != -1){
            return letters[ans];
        }else{
            return letters[0];
        }
        
    }
};