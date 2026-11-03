class MedianFinder {
private:
    priority_queue<int>left; //maxheap
    priority_queue<int, vector<int>, greater<int>>right; //minheap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        if(left.size()!=0 and right.size()!=0 and left.top() > right.top()){
            right.push(left.top());
            left.pop();
        }
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }
        if(left.size()+1<right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        int n = left.size() + right.size();
        if(n%2==0)return (left.top() + right.top())/2.0;
        if(right.size()>left.size()) return right.top();
        return left.top();
    }
};
