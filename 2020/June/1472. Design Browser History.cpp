class BrowserHistory {
public:
    string str [5010];
    int pos = 0, now = 0;
    BrowserHistory(string homepage) {
        now = 1;
        pos = now;
        str[pos]=homepage;
    }

    void visit(string url) {
        now++;
        pos = now;
        str[pos] = url;
        return;
    }

    string back(int steps) {
        if(now-steps>=1)
        {
            now = now-steps;
            return str[now];
        }
        now = 1;
        return str[1];
    }

    string forward(int steps) {
        if(now+steps<=pos)
        {
            now = now+steps;
            return str[now];
        }
        now = pos;
        return str[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
