#include "myfunction.h"
#include "myStack.h"
#include "myPointerList.h"
#include "mybinarytree.h"

void callByValue() {}

void callByReference() {}

void f1(){
    for (int i = 0; i < 10000; i++)
        callByValue();
}
void f2(){
    for (int i = 0; i < 10000; i++)
        callByReference();
}
int main() {
//    time_function(&f1);
//    time_function(&f2);
//    pointerList();
//    startStack();
    startTree();
    return 0;
}