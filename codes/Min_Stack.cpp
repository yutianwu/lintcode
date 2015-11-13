class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        dataStack.push(number);
        if (minStack.empty()) {
            minStack.push(number);
        } else {
            int minVal = minStack.top();
            minVal = (minVal <= number) ? minVal : number;
            minStack.push(minVal);
        }
    }

    int pop() {
        int top = dataStack.top();
        dataStack.pop();
        minStack.pop();
        return top;
    }

    int min() {
        int minVal = minStack.top();
        return minVal;
    }
};

