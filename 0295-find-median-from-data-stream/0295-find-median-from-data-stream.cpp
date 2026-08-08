class MedianFinder {
public:
    double median;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    int signum(int maxsize, int minsize) {
        if (maxsize == minsize) {
            return 0; // both heap size equal
        } else if (maxsize > minsize) {
            return 1; // maxheap size greater
        } else {
            return -1; // minheap size greater
        }
    }

    MedianFinder() { median = 0; }

    void addNum(int num) {
        switch (signum(maxheap.size(), minheap.size())) {
        case 0: { // leftsize == rightsize
            if (num > median) {
                minheap.push(num);
                median = minheap.top();
            } else {
                maxheap.push(num);
                median = maxheap.top();
            }
            break;
        }
        case 1: { // leftsize > rightsize
            if (num > median) {
                minheap.push(num);
                median = (maxheap.top() + minheap.top()) / 2.0;
            } else {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
                median = (maxheap.top() + minheap.top()) / 2.0;
            }
            break;
        }
        case -1: { // leftsize < rightsize
            if (num > median) {
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(num);
                median = (maxheap.top() + minheap.top()) / 2.0;
            } else {
                maxheap.push(num);
                median = (maxheap.top() + minheap.top()) / 2.0;
            }
            break;
        }
        }
    }

    double findMedian() { return median; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */