class Solution {
public:
    char parseBoolOperator(char boolOperator, vector<char>& localExpr) {
        char localExprResult;
        if (boolOperator == '!') {
            localExprResult = localExpr[0] == 't' ? 'f' : 't';
        } else if (boolOperator == '&') {
            localExprResult = 't';
            for (const char& c : localExpr) {
                if (c == 'f') localExprResult = 'f';
            }
        } else {
            localExprResult = 'f';
            for (const char& c : localExpr) {
                if (c == 't') localExprResult = 't';
            }
        }
        return localExprResult;
    }

    void parseLocalExpr(stack<char>& stk) {
        vector<char> localExpr;
        while (stk.top() != '(') {
            localExpr.push_back(stk.top());
            stk.pop();
        }
        stk.pop();
        char boolOperator = stk.top();
        stk.pop();
        stk.push(parseBoolOperator(boolOperator, localExpr));
    }

    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for (char &c : expression) {
            if (c == ',') {
                continue;
            } else if (c != ')') {
                stk.push(c);
            } else {
                parseLocalExpr(stk);
            }
        }
        return stk.top() == 't' ? true : false;
    }
};