#include <bits/stdc++.h>
using namespace std;

// @leet start
#if 1
// 代码随想录 时间短，代码支持复用
// stack_in 和 stack_out 均用于存储
// stack_in 中元素是后来添加的，当 out 为空时将 in 中元素加入 out
// stack_out 中元素是已经调换顺序的，可以直接弹出
class MyQueue {
public:
    MyQueue() {}

    void push(int x) {
        stack_in.push(x);
    }

    int pop() {
        // 如果 stack_out 为空，则将 in 中元素加入 out
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        // 否则直接弹出 stack_out 中元素
        int top = stack_out.top();
        stack_out.pop();
        return top;
    }

    int peek() {
        // 复用 pop() 代码
        int top = this->pop();  // this 指针妙用
        stack_out.push(top);
        return top;
    }

    bool empty() {
        return stack_in.empty() && stack_out.empty();
    }

private:
    stack<int> stack_in;
    stack<int> stack_out;
};

#else
// 原思路：时间长，代码重复
// stack_in 存储所有元素
// stack_out 用于取出队首元素，再放回 stack_in
class MyQueue {
public:
    MyQueue() {}

    void push(int x) {
        stack_in.push(x);
    }

    int pop() {
        while (!stack_in.empty()) {
            stack_out.push(stack_in.top());
            stack_in.pop();
        }
        int top = stack_out.top();
        stack_out.pop();
        while (!stack_out.empty()) {
            stack_in.push(stack_out.top());
            stack_out.pop();
        }
        return top;
    }

    int peek() {
        // 功能相近的代码但无法抽象复用
        while (!stack_in.empty()) {
            stack_out.push(stack_in.top());
            stack_in.pop();
        }
        int top = stack_out.top();
        while (!stack_out.empty()) {
            stack_in.push(stack_out.top());
            stack_out.pop();
        }
        return top;
    }

    bool empty() {
        return stack_in.empty();
    }

private:
    stack<int> stack_in;
    stack<int> stack_out;
};

#endif
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @leet end
