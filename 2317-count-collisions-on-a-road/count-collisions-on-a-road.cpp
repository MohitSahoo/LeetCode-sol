class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        if(n == 1){
            return 0;
        }
        
        int i =0;
        int j = directions.size()-1;
        while(i <n && directions[i]=='L'){
            i++;
        }
        while(j > 0 && directions[j]=='R'){
            j--;
        }
        if(i > j){
            return 0;
        }
        int col=0;
        for(int k = i; k <= j ;k++){
            if(directions[k]!='S'){
                col++;
            }
        }
        return col;
        
    }
};