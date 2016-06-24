#include <iostream>
#include <string>
#include <conio.h>
#include "log.h"
#include <thread> 
#include <sstream>

using namespace std;

void foo(int y, int x) {
    for (int i = 0; i < y; ++i) {
        char *str = " <string> ";
        outlog("thread: ", x, " iteration: ", i, ' ', str, 1234112312*i*x, " bool: ", (bool)((i*x)%2), "  ", 24.234234*x*i);
    }
}

int main() {

    int cout = 10000;
    thread th1(foo, cout, 1);
    thread th2(foo, cout, 2);
    thread th3(foo, cout, 3);
    thread th4(foo, cout, 4);
    thread th5(foo, cout, 5);
    foo(cout, 0);

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();

    return 0;
}