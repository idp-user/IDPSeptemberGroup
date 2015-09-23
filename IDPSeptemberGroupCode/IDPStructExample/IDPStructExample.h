//
//  IDPStructExample.h
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 9/23/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPSeptemberGroupCode__IDPStructExample__
#define __IDPSeptemberGroupCode__IDPStructExample__

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    float red;
    float green;
    float blue;
    float alpha;
} IDPColor;

typedef struct {
    int serialNumber;
    int count;
    bool isBroken;
    
    IDPColor color;
//    struct {
//        float red;
//        float green;
//        float blue;
//        float alpha;
//    } IDPColor;
    
} IDPPackage;

extern
size_t IDPPackageSizeof(void);

extern
void IDPPackageOutput(IDPPackage package);

#endif /* defined(__IDPSeptemberGroupCode__IDPStructExample__) */
