#include <iostream>

using namespace std;

int main() {
    char *b = "123";
    cout << b << endl;
    b[1] = '3';
    cout << b[1] << endl;
    return 0;
}