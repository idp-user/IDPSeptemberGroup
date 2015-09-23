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
