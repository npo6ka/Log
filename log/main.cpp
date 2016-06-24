#include <iostream>
#include <string>
#include <conio.h>
#include "log.h"
#include <thread> 
#include <sstream>

using namespace std;

void foo(int x) {
    for (int i = 0; i < x; ++i) {
        outlog("f2: ", i, "    ", "more text");
        //_sleep(5);
    }
}

int main() {

    int cout = 100;
    //thread first(foo, cout);
    outlog("SDf");
    for (int i = 0; i < cout; ++i) {
        outlog("f1: ", i , "    ", "more text");
        //_sleep(5);
    }
    /*first.join();*/

    //_getch();
    return 0;
}