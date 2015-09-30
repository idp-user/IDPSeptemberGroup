//
//  IDPStructExample.c
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 9/23/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <stdio.h>

#include "IDPStructExample.h"

#pragma mark -
#pragma mark Private Declarations

struct {
    int value1;
} SomeGlobalStruct;


struct SomeKindOfStruct {
    int value2;
};

struct SomeOtherKindOfGlobalStruct {
    int value3;
} SomeOtherGlobalStruct;


typedef struct {
    int value4;
} SomeStructType;

typedef struct SomeKindOfStruct SomeProposedStructType;

typedef struct SomeOtherKindOfStruct {
    int value5;
} SomeOtherStructType;

#pragma mark -
#pragma mark Public Implementations

size_t IDPPackageSizeof(void) {
    return sizeof(IDPPackage);
}

void IDPPackageOutput(IDPPackage package) {
    printf("sizeof:%lu, serialNumber: %d, count: %d color:{%f, %f, %f, %f}",
           IDPPackageSizeof(),
           package.serialNumber,
           package.count,
           package.color.red,
           package.color.green,
           package.color.blue,
           package.color.alpha);
}


void IDPStructExampleUsage(void) {
    //
    struct {
        int value0;
    } someLocalStruct;
    someLocalStruct.value0 = 6;
    
    //
    struct SomeKindOfStruct myValue;
    myValue.value2 = 7;
    
    //
    SomeOtherGlobalStruct.value3 = 8;
    
    //    SomeOtherKindOfGlobalStruct struct1;  - compiler error
    struct SomeOtherKindOfGlobalStruct struct1;
    struct1.value3 = 9;
    
    SomeGlobalStruct.value1 = 10;
    
    struct SomeKindOfStruct myStruct;
    myStruct.value2 = 11;
    
    SomeStructType myTypedStruct;
    myTypedStruct.value4 = 12;
    
    SomeProposedStructType myProposedStruct;
    myProposedStruct.value2 = 13;
    
    struct SomeOtherKindOfStruct kindOfStructValue;
    kindOfStructValue.value5 = 14;
    
    
    SomeOtherStructType myOtherTypedStruct;
    myOtherTypedStruct.value5 = 15;
}
