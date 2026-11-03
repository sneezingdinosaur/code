class MedianFinder {
private:
    priority_queue<int> left; //maxheap
    priority_queue<int, vector<int>, greater<int>> right; //minheap

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.size() == 0 || num<left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }
        
        if(right.size()+1 < left.size()){
            right.push(left.top());
            left.pop();
        }
        else if(right.size() > left.size()+1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        int n = left.size() + right.size();
        if(n%2==0){
            return (left.top() + right.top())/2.0;
        }
        else{
            if(right.size()>left.size()) return right.top();
            return left.top();
        }
    }
};
