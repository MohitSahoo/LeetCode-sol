class Solution {
public:
    bool canRun(long long T, int n, vector<int>& batteries) {
        long long total = 0;
        for (int b : batteries) {
            total += min(1LL * b, T);
            if (total >= T * n) return true; // early exit
        }
        return total >= T * n;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (int b : batteries) sum += b;

        long long low = 0;
        long long high = sum / n;  // upper bound on answer
        long long ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canRun(mid, n, batteries)) {
                ans = mid;          // mid is possible, try bigger
                low = mid + 1;
            } else {
                high = mid - 1;     // mid not possible, go smaller
            }
        }
        
        return ans;
    }
};
