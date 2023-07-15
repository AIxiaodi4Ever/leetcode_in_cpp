class Solution {
public:
    char parseBoolOperator(char boolOperator, int trueNum, int falseNum) {
        char localExprResult;
        switch (boolOperator) {
            case '!' : 
                localExprResult = falseNum == 1 ? 't' : 'f';
                break;
            case '&' :
                localExprResult = falseNum == 0 ? 't' : 'f';
                break;
            case '|' :
                localExprResult = trueNum > 0 ? 't' : 'f';
                break;
            default:
                break;
        }
        return localExprResult;
    }

    void parseLocalExpr(stack<char>& stk) {
        int t = 0, f = 0;
        while (stk.top() != '(') {
            if (stk.top() == 't') { ++t; }
            else { ++f; }
            stk.pop();
        }
        stk.pop();
        char boolOperator = stk.top();
        stk.pop();
        stk.push(parseBoolOperator(boolOperator, t, f));
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