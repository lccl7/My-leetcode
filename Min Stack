class MinStack {
    stack<int> minstack;
    stack<int> stackint;
public:
    void push(int x) {
        stackint.push(x);
        if(minstack.empty() || x <= minstack.top())
        {
            minstack.push(x);
        }
    }

    void pop() {
        if(stackint.empty()) return;
        int n = stackint.top();
        stackint.pop();
        if(n == minstack.top())
            minstack.pop();
    }

    int top() {
        if(!stackint.empty())
            return stackint.top();
        return 0;
    }

    int getMin() {
        if(!minstack.empty())
            return minstack.top();
        return 0;
    }
};
