#include <bits/stdc++.h>

using namespace std;

const string IN = "in";
const string OUT = "out";

struct myListNode {
    string mes;
    int type;
    myListNode* next = nullptr;
};

int main() {
    int N;
    cin >> N;
    string s = "";
    getline(cin, s);
    myListNode* head = nullptr;
    myListNode* tail = nullptr;
    for (int i = 0; i < N; ++i) {
        getline(cin, s);
        stringstream ss(s);
        string op, mes;
        int t;
        ss >> op;
        if (op == IN) {
            ss >> t >> mes;
            if (head == nullptr) {
                head = new myListNode;
                head->type = t;
                head->mes = mes;
                tail = head;
            }
            else {
                tail->next = new myListNode;
                tail = tail->next;
                tail->type = t;
                tail->mes = mes;
            }
        }
        else if (op == OUT) {
            if (head == nullptr) {
                cout << "-1" << endl;
                continue;
            }
            ss >> t;
            if (t == 0) {
               myListNode* tmp = head->next;
                cout << head->mes;
                delete head;
                head = tmp;
            }
            else {
                myListNode* tmp = head;
                myListNode* pre = tmp;
                while (tmp->type != t && tmp != nullptr) {
                    pre = tmp;
                    tmp = tmp->next;
                }
                if (tmp == nullptr) {
                    cout << "-1" << endl;
                }
                else {
                    cout << tmp->mes;
                    pre->next = tmp->next;
                    delete tmp;
                }
            }
        }
    }
    return 0;
}