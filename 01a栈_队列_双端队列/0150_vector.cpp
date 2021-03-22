class Solution {
public:
    bool isNumber(string& s)
    {
        return s != "+" && s != "-" && s != "*" && s != "/";
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        vector<int> stk((n + 1) / 2);
        int top = -1;
        for (auto& token : tokens) {
            if (isNumber(token)) {
                stk[++top] = atoi(token.c_str());
            }
            else {
                int num2 = stk[top--];
                int num1 = stk[top--];
                switch(token[0]) {
                    case '+':
                        stk[++top] = num1 + num2;
                        break;
                    case '-':
                        stk[++top] = num1 - num2;
                        break;
                    case '*':
                        stk[++top] = num1 * num2;
                        break;
                    case '/':
                        stk[++top] = num1 / num2;
                        break;
                }
            }
        }//for
        return stk[top];
    }
};