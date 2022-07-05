#include <memory>
#include <iostream>

using namespace std;

int main() {
    // shared_ptr支持动态数组是在C++17后才可以的
    shared_ptr<int[]> pi(new int[10]);
    for (int i = 0; i < 10; ++i) {
        pi[i] = i * 2;
        cout << pi[i] << endl;
    }
    return 0;
}