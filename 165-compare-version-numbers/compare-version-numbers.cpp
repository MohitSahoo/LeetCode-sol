class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i =0;
        int j =0;
        while(i<version1.size() || j <version2.size()){
            int start1=i;
            while(i < version1.size() && version1[i] != '.'){
                i++;
            }
            int num1 = 0;
           if( start1 < version1.size()){
                num1 = stoi(version1.substr(start1,i-start1));
            }
            int start2=j;
            while(j < version2.size() && version2[j] != '.'){
                j++;
            }
            int num2 = 0;
            if( start2 < version2.size()){
                num2 = stoi(version2.substr(start2,j-start2));
            }
            if(num1 <num2){
                return -1;
            }
            if(num2 < num1){
                return 1;
            }
           i++;
           j++;

        }
        return 0;
        
    }
};