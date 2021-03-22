class Solution {
public:
    bool isNumber(string& s)
    {
        return s != "+" && s != "-" && s != "*" && s != "/";
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto& token : tokens) {
            if (isNumber(token)) {
                stk.push(atoi(token.c_str()));
            }
            else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch(token[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }//for
        return stk.top();
    }
};