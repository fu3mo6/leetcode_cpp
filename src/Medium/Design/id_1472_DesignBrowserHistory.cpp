class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        prev.push(homepage);
    }
    
    void visit(string url) {
        prev.push(url);
        next = stack<string>();
    }
    
    string back(int steps) {
        string tmp;
        while(prev.size() > 1 && steps > 0)
        {
            tmp = prev.top();
            prev.pop();
            next.push(tmp);
            steps--;
        }
        return prev.top();
    }
    
    string forward(int steps) {
        string tmp;
        while(next.size() > 0 && steps > 0)
        {
            tmp = next.top();
            next.pop();
            prev.push(tmp);
            steps--;
        }
        return prev.top();
    }
private:
    stack<string> prev, next;
};

// https://leetcode.com/problems/design-browser-history/description/