class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==0 || num<left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }

        if(right.size()+1<left.size()){
            int temp = left.top();
            left.pop();
            right.push(temp);
        }
        if(left.size()+1<right.size()){
            int temp = right.top();
            right.pop();
            left.push(temp);
        }
    }
    
    double findMedian() {
        if(left.size()>right.size()){
            return left.top();
        }
        else if(right.size()>left.size()){
            return right.top();
        }
        else{
            return (left.top() + right.top())/2.0;
        }
    }
};
