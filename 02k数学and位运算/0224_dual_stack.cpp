#define ll long long        //采用long long数据类型，如果有题目有小数可以改为double
class Solution {
public:
    stack<ll> num;          //运算数栈与运算符栈
    stack<char> op;
    string str;

    ll cal() {              //封装好的计算原子型操作，功能为弹出num栈顶2个元素与op栈顶1个元素执行运算,可拓展至多种运算
        ll b = num.top();
        num.pop();
        ll a = num.top();       //注意栈LIFO特性，先出为b，后出为a
        num.pop();
        char c = op.top();
        op.pop();

        switch(c){                     //在switch语句中加入* 、/、%等相应语句即可拓展运算功能
            case '+': return a + b;
            case '-': return a - b;
            default: break;
        }
        return 0;
    }
    ll getNum(int& i) {                //若str[i]为数字则连续读取一个数，若有小数则加入小数点.的判断，该题暂不需要
        ll ret = str[i] - '0';          
        while (i + 1 <= str.size() && isdigit(str[i + 1])) {    //注意主函数for循环中有i++，故该处while循环应对str[i+1]进行判断
            ret = ret * 10 + str[i + 1] - '0';
            i++;                        //i为引用，可改变主函数i指针位置
        }
        return ret;
    }
    int calculate(string s) {
        unordered_map<char, int> pri;       //运算符优先级，其中'('优先级最高，遇到则压入op栈，')'优先级默认为0，这里默认括号匹配无误
        pri['+'] = (pri['-'] = 1);          //可同样扩展至乘除法
        pri['('] = 2;

        op.push('(');                   
        str = s + ")";                      //哨兵处理，等效于用一对括号把式子包起来，这样一遍for循环刚好可以计算完毕
        int n = str.size();
        for (int i = 0; i < n; i++) {
            if (str[i] == ' ') continue;        //空格跳过
            if (isdigit(str[i]))   num.push(getNum(i));     //若str[i]为数字则读数，i调用形式为引用
            else {
                if((i == 0 || str[i - 1] == '(') && str[i] == '-'){     //处理负数问题， -1 或者(-1)可以等效为'-'前加个0
                    num.push(0);
                    op.push('-');
                    continue;
                }
                if ((i == 0 || str[i - 1] == '(') && str[i] == '+')
                {
                    continue;
                }
                while (op.top() != '(' && pri[op.top()] >= pri[str[i]]) {   //当str[i]不为'('且优先级更低时，代表之前的运算符已可以计算
                    num.push(cal());                            //由于式子末尾有')'哨兵, 优先级为0，故遍历到末尾')'能将所有运算符计算完毕
                }
                if (op.top() == '(' && str[i] == ')') op.pop();         //消去括号
                else    op.push(str[i]);
            }
        }
        return num.top();               //由于此前的哨兵处理，最后num栈中只有唯一一个数，即最后结果
    }
};