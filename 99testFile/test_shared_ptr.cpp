#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> pi(new int(10));
    cout << *pi << " " << pi.use_count() << " " << pi.get() << endl;
    int *p = new int;
    *p = 10;
    cout << *p << endl;
    return 0;
}
