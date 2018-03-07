#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    Calculator c;
    c.add(4, 10);
    cout << c.getResult() << endl;
    return 0;
}
