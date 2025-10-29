#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> maxh; // Max heap for lower half
    priority_queue<int, vector<int>, greater<int>> minh; // Min heap for upper half
public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxh.empty() || num <= maxh.top()) {
            maxh.push(num);
        } else {
            minh.push(num);
        }
        // Balance the heaps so their sizes differ by at most 1
        if (maxh.size() > minh.size() + 1) {
            minh.push(maxh.top());
            maxh.pop();
        } else if (minh.size() > maxh.size()) {
            maxh.push(minh.top());
            minh.pop();
        }
    }

    double findMedian() {
        if (maxh.size() == minh.size()) {
            return (maxh.top() + minh.top()) / 2.0;
        }
        return maxh.top();
    }
};
