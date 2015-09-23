//
//  main.c
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 9/14/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <stdio.h>

#include "IDPMacros.h"
#include "IDPStructExample.h"

typedef struct {
    bool bool1;
    //
    short int shortNumber;
    
    bool bool2;
    bool bool3;
    
    bool bool4;
    //
} IDPBooleanStruct;


typedef union {
    bool bool1;
    int intValue;
    char someCharacter;
} IDPUnionExampleType;

typedef union {
    int16_t intValue;
    uint8_t bytes[2];
} IDPShortIntUnion;


int main(int argc, const char * argv[]) {
    // insert code here...
    IDPPackage package = {1, 2, true, {0.0, 1.0, 0.0, 1.0}};
    
    IDPPackageOutput(package);
    
    printf("\n");
    printf("IDPBooleanStruct: %lu", sizeof(IDPBooleanStruct));

    IDPShortIntUnion unionValue;

    printf("\n");
    printf("%d %d %d",
           unionValue.intValue,
           unionValue.bytes[0],
           unionValue.bytes[1]);
    
    unionValue.intValue = 2;
    
    
    printf("\n");
    printf("%d %d %d",
           unionValue.intValue,
           unionValue.bytes[0],
           unionValue.bytes[1]);
    
    unionValue.intValue = -1;
    
    
    return 0;
}
