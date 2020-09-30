// 155. Min Stack

// Time: push O(1), pop O(1), top O(1), getMin O(1) Space: O(n)
class MinStack {
    
    private Stack<Integer> S;
    private Stack<Integer> minS;

    /** initialize your data structure here. */
    public MinStack() {
        S = new Stack<Integer>();
        minS = new Stack<Integer>();
    }
    
    public void push(int x) {
        S.push(x);
        if( minS.empty() || x < minS.peek() ){
            minS.push(x);
        }
        else{
            minS.push(minS.peek());
        }
    }
    
    public void pop() {
        S.pop();
        minS.pop();
    }
    
    public int top() {
        return S.peek();
    }
    
    public int getMin() {
        return minS.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
