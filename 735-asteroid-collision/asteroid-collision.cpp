class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>sol;
        for(int i =0;i<asteroids.size();i++){
            if(asteroids[i]<0){
                while(st.size()!=0 && st.top()>0 && st.top() < abs(asteroids[i])){
                    st.pop();
                }
                if(st.size()!=0 && st.top() == abs(asteroids[i])){
                    st.pop();
                }
                else if(st.size()== 0 || st.top() <0){
                    st.push(asteroids[i]);
                }
            }else{
                st.push(asteroids[i]);
            }
        }
        while(st.size()!=0){
            sol.push_back(st.top());
            st.pop();
        }
        reverse(sol.begin(),sol.end());
        return sol;
    }
};