//
//  IDPObject.c
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 10/16/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>

#include "IDPObject.h"


#pragma mark -
#pragma mark Public Implementations


void *__IDPObjectCreate(size_t size, IDPObjectDeallocator deallocator) {
    assert(0 != size);
    assert(NULL != deallocator);
    
    IDPObject *object = calloc(1, size);

    assert(NULL != object);
    
    object->_retainCount = 1;
    object->_deallocatorFunctionPointer = deallocator;
    
    return object;
}

void __IDPObjectDeallocate(void *object) {
    if (NULL != object) {
        free(object);
    }
}


uint64_t IDPObjectRetainCount(void *object) {
    return object ? ((IDPObject *)object)->_retainCount : 0;
}

void IDPObjectRelease(void *object) {
    if (NULL != object) {
        IDPObject *releasedObject = (IDPObject *)object;
        
        if (0 == --(releasedObject->_retainCount)) {
            IDPObjectDeallocator deallocator = releasedObject->_deallocatorFunctionPointer;

            deallocator(object);
        }
    }
}

void *IDPObjectRetain(void *object) {
    if (NULL != object) {
        ((IDPObject*)object)->_retainCount++;
    }
    
    return object;
}