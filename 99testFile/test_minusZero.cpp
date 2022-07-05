#include <iostream>
#include <memory>
using namespace std;

int main() {
    // 对于int型数据，-0，+0都会被看作0
    float p = -0.0;
    float q = 1 / p;

    cout << p << " " << q << endl;

    if (p >= 0) {
        cout << "yeah" << endl;
    }
    else {
        cout << "no" << endl;
    }

    cout << (q >= 0 ? "yeah" : "no") << endl;
    return 0;
}