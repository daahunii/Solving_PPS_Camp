/*
Leet Code
<232. Implement Queue using Stacks>

Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
- void push(int x) Pushes element x to the back of the queue.
- int pop() Removes the element from the front of the queue and returns it.
- int peek() Returns the element at the front of the queue.
- boolean empty() Returns true if the queue is empty, false otherwise.
=======================================================================================================
Example 1:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
=======================================================================================================
*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> input; // 하노이의 탑 원반옮기는 느낌으로 2개 이용
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x){
        input.push(x);
    }
    
    int pop() {
        if(input.size() == 0 && output.size() == 0) return -1;
        if(output.size() == 0){
            while(input.size() != 0){
                output.push(input.top());
                input.pop();
            }
        }
        int n = output.top();
        output.pop();
        return n;
    }
    
    int peek() {
        if(input.size() == 0 && output.size() == 0) return -1;
        if(output.size() == 0){
            while(input.size() != 0){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty(){
        return (input.size() == 0 && output.size() == 0);
    }
};

int main()
{
    MyQueue myQueue = new MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek(); // return 1 (peek = front)
    myQueue.pop(); // return 1, queue is [2]
    myQueue.empty(); // return false
    return 0;
}