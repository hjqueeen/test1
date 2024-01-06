#include "myfunction.h"
#include "myPointerList.h"
#include <stdio.h>
#include <time.h>
#include <stdint.h>

struct d {
    long long a;
    long long b;
    long long c;
    long long d;
    long long e;
    long long f;
    long long g;
    long long h;
    long long j;
    long long i;
    long long k;
    long long l;
    long long m;
    long long n;
    long long o;
    long long p;
};
struct d lingd;

void callByValue(struct d d) {}

void callByReference(struct d *d) {}

void f1(){
    for (int i = 0; i < 10000; i++)
        callByValue(lingd);
}
void f2(){
    for (int i = 0; i < 10000; i++)
        callByReference(&lingd);
}
int main() {
    lingd.a = 1;
    lingd.b = 1;
    lingd.c = 1;
    lingd.d = 1;
    lingd.e = 1;
    lingd.f = 1;
    lingd.g = 1;
    lingd.h = 1;
    lingd.j = 1;
    lingd.i = 1;
    lingd.k = 1;
    lingd.l = 1;
    lingd.m = 1;
    lingd.n = 1;
    lingd.o = 1;
    lingd.p = 1;

    time_function(&f1);
    time_function(&f2);
    List *myList = initList();
    pointerList();
    return 0;
}