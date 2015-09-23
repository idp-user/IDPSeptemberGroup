//
//  main.c
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 9/14/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <stdio.h>

#include "IDPMacros.h"
#include "IDPMacros.h"

#define IDPSayHello printf("Hello, World!\n")
#define IDPSay(string) printf(string)

#define IDPPrintSizeof(type, value) \
    printf("sizeof("#type") = %lu\n", sizeof(type)); \
    printf("sizeof("#value") = %lu\n", sizeof(value));


int main(int argc, const char * argv[]) {
    // insert code here...

    IDPSayHello;
    
    IDPSay("wheeee!");
    
    
    
    printf("Hello, World!\n");

    int a = 0;
    char b;
    
    IDPPrintSizeof(char, b);
    IDPPrintSizeof(int, a);
    
//    printf("sizeof(char) = %lu\n", sizeof(char));
//    printf("sizeof(char) = %lu\n", sizeof(b));
//
//    printf("sizeof(int) = %lu\n", sizeof(int));
//    printf("sizeof(int) = %lu\n", sizeof(a));
    
    uint16_t c;
    
        printf("max uint16_t = %lu", UINT16_MAX);
    
    printf("current a = %d\t b = %d", a, b);
    
    a = 2;
    printf("current a = %d\n", a);
    
    a = 56;
    printf("current a = %d\n", a);
    
    {
//        int a = 0;
        a = 1234;
        printf("current a = %d\n", a);
    }
    
    printf("\n");
    
    for (a = 0; a <= 15; a++) {
        printf("%d ",a);
        
//        switch (a) {
//            case 15:
//                printf("current a == 15\n");
//                break;
//            case 5:
//                printf("current a == 5\n");
//                break;
//            case 3:
//                printf(" is A 3 ");
//            case 0:
//                printf("current a = %d\n", a);
//                break;
//                
//            default:
//                printf("NOT FOUND\n");
//                break;
//        }
        
        if (15 == a) {
            printf("current a == 15\n");
        } else if (5 == a) {
            printf("current a == 5\n");
        } else if (3 == a) {
            printf(" is A 3 ");
            printf("current a = %d\n", a);
        } else if (0 == a) {
            printf("current a = %d\n", a);
        } else {
            printf("NOT FOUND\n");
        }
    }
    
    return 0;
}
