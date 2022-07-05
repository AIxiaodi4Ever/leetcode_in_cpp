#include <iostream>

using namespace std;

enum color
{
    red,
    green,
    blue
};

enum animal
{
    dog,
    fish,
    cat
};

enum class human
{
    women,
    man,
    child
};

int main() {
    color c1 = (color)0;
    int n1 = c1;
    animal a1 = (animal)c1;
    int n2 = a1;

    human h = human::women;
    int n2 = (int)h;
    human h2 = (human)n2;
    human h3 = static_cast<human>(n2);

    cout << c1 << " " << n1 << " " << a1 << " " << n2 << endl;

    return 0;
}