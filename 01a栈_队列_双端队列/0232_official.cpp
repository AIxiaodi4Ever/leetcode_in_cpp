// 学习下官方的命名
class MyQueue {
private:
    stack<int> inStk, onStk;
    void in2on()
    {
        while (!inStk.empty())
        {
            onStk.push(inStk.top());
            inStk.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        inStk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        if (onStk.empty())
        {
            in2on();
        }
        int ret = onStk.top();
        onStk.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() 
    {
        if (onStk.empty())
        {
            in2on();
        }
        return onStk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return inStk.empty() && onStk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */