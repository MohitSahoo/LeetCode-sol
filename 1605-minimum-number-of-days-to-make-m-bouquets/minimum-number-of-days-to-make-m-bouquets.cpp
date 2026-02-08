#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to calculate the number of bouquets that can be made
    int nob(vector<int>& bloomDay, int k, int mid) {
        int count = 0;   // Count the number of flowers in a bouquet
        int bouquets = 0; // Total bouquets formed
        for (int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i]<=mid){
                count++;
                if(count ==k){
                    bouquets++;
                    count=0;
                }
            }else{
                count =0;
            }
            
        }
        return bouquets;
    }

    // Function to find the minimum day to make 'm' bouquets of 'k' flowers
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1; // Initialize the answer to -1, in case no solution is found

        while (low <= high) {
            int mid = (low + high) / 2;
            int bouquets = nob(bloomDay, k, mid); // Get the number of bouquets for the current day 'mid'

            if (bouquets >= m) {
                ans = mid;  // If we can form 'm' or more bouquets, try for a smaller day
                high = mid - 1;
            } else {
                low = mid + 1;  // If not enough bouquets, try a larger day
            }
        }

        return ans; // Return the minimum day if a solution exists, otherwise -1
    }
};


