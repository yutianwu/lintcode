class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack2.push(element);
        
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
    
    int pop() {
        if (!stack1.empty()) {
            int top = stack1.top();
            stack1.pop();
            return top;
        }
        return -1;
    }

    int top() {
        if (!stack1.empty())
            return stack1.top();
        else 
            return -1;
    }
};

