class Solution {
public:
    bool isNumber(string& s)
    {
        return s != "+" && s != "-" && s != "*" && s != "/";
    }

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        vector<int> stk((n + 1) / 2);
        int top = -1;
        for (auto& token : tokens) {
            if (isNumber(token)) {
                stk[++top] = atoi(token.c_str());
            }
            else {
                switch(token[0]) {
                    case '+':
                        --top;
                        stk[top] += stk[top + 1];
                        break;
                    case '-':
                        --top;
                        stk[top] -= stk[top + 1];
                        break;
                    case '*':
                        --top;
                        stk[top] *= stk[top + 1];
                        break;
                    case '/':
                        --top;
                        stk[top] /= stk[top + 1];
                        break;
                }
            }
        }//for
        return stk[top];
    }
};