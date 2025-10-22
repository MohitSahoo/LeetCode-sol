class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>mxl(height.size(),-1);
        vector<int>mxr(height.size(),-1);
        vector<int>ans(height.size(),-1);
        mxl[0]=height[0];
        for(int i=1;i<height.size();i++){
            mxl[i]=max(mxl[i-1],height[i]);
        }
        mxr[height.size()-1]=height[height.size()-1];
        for(int i = height.size()-2;i>=0;i--){
            mxr[i]=max(mxr[i+1],height[i]);
        }
        for(int i =0;i<height.size();i++){
            ans[i]=min(mxr[i],mxl[i])-height[i];
        }
        int sum =0;
        for(int i =0;i<height.size();i++){
            sum+=ans[i];
        }
        return sum;


        
    }
};