#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstdio>
#include<stdint.h>

using namespace std;

int main(){
        uint8_t *values;
        values = (uint8_t*) malloc( 2*sizeof(uint8_t) );

        values[0] = 0xda;
        values[1] = 0xaa;

        uintptr_t p =  (uintptr_t) values;


        uint16_t value = *reinterpret_cast<int *>(p);
        uint16_t base = 0xffff;

        printf("%hx 0\n", values[0]);
        printf("%hx 1\n", values[1]);
        printf("%hx 2\n", base);
        printf("%hx 3\n", ( value ) ) ;
        printf("%hx 3\n", ( value&base) ) ;



}
