#include <stdio.h>
#include <stdint.h>

int main() {

    // Definimos nuestras variables:
    
    // hice el casteo en uint8 y 16 porque me tiraba este error:

    //sizeof_stdint.c: In function ‘main’:
    //sizeof_stdint.c:8:18: warning: overflow in conversion from ‘int’ to ‘int8_t’ {aka ‘signed char’} changes value from ‘255’ to ‘-1’ [-Woverflow]
    //    8 |     int8_t i_8 = 0xff;
    //      |                  ^~~~


    int8_t i_8 = (int8_t) 0xff;
    uint8_t ui_8 = 0xff;
    
    int16_t i_16 = (int16_t) 0xffff;
    uint16_t ui_16 = 0xffff;
    
    int32_t i_32 = 0xffffffff;
    uint32_t ui_32 = 0xffffffff;
    
    int64_t i_64 = 0xffffffffffffffff;
    uint64_t ui_64 = 0xffffffffffffffff;
    
    // Devolvemos sus tamaños:
    
    printf("* 8 bits/1 byte: \n");
    printf("\n");
    
    printf("int8_t(%lu): %i \n", sizeof(i_8), i_8);
    printf("uint8_t(%lu): %u \n", sizeof(ui_8), ui_8);
    printf("\n");
    
    printf("* 16 bits/2 bytes: \n");
    printf("\n");
    
    printf("int16_t(%lu): %i \n", sizeof(i_16), i_16);
    printf("uint16_t(%lu): %u \n", sizeof(ui_16), ui_16);
    printf("\n");
    
    printf("* 32 bits/4 bytes: \n");
    printf("\n");
    
    printf("int32_t(%lu): %i \n", sizeof(i_32), i_32);
    printf("uint32_t(%lu): %u \n", sizeof(ui_32), ui_32);
    printf("\n");
    
    printf("* 64 bits/8 bytes: \n");
    printf("\n");
    
    printf("int64_t(%lu): %li \n", sizeof(i_64), i_64);
    printf("uint64_t(%lu): %lu \n", sizeof(ui_64), ui_64);

    return 0;
}
