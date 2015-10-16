//
//  IDPObject.h
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 10/16/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPSeptemberGroupCode__IDPObject__
#define __IDPSeptemberGroupCode__IDPObject__

#include <stdlib.h>

typedef void (*IDPObjectDeallocator)(void *object);

typedef struct {
    uint64_t _retainCount;
    IDPObjectDeallocator _deallocatorFunctionPointer;
    
} IDPObject;

#define IDPObjectCreateOfType(type) __IDPObjectCreate(sizeof(type), __ ##type ##Deallocate)

extern
void *__IDPObjectCreate(size_t size, IDPObjectDeallocator deallocator);

extern
void __IDPObjectDeallocate(void *object);

extern
uint64_t IDPObjectRetainCount(void *object);

extern
void IDPObjectRelease(void *object);

extern
void *IDPObjectRetain(void *object);



#endif /* defined(__IDPSeptemberGroupCode__IDPObject__) */
