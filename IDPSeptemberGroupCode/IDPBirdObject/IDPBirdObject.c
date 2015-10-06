//
//  IDPBirdObject.c
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 10/1/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPBirdObject.h"

#include <string.h>
#include <stdlib.h>
#include <assert.h>


#pragma mark -
#pragma mark Private Declarations

struct IDPBirdObject {
    char *_name;
    IDPBirdObject *_partner;
    bool _isAbleToFly;
    
    uint64_t _referenceCount;
};

static
IDPBirdObject *IDPBirdObjectPartner(IDPBirdObject *object);

static
void IDPBirdObjectSetPartner(IDPBirdObject *object, IDPBirdObject *parnter);


void IDPObjectRetain(IDPBirdObject *object) {
    if (object) {
        object->_referenceCount++;
    }
}

void IDPObjectRelease(IDPBirdObject *object) {
    if (NULL != object) {
        if (0 == --(object->_referenceCount)) {
            _IDPBirdObjectDeallocate(object);
        }
    }
}


#pragma mark -
#pragma mark Public Implementations

IDPBirdObject *IDPBirdObjectCreate(void) {
    IDPBirdObject *result = calloc(1, sizeof(IDPBirdObject));
    
    assert(NULL != result);
    
//    result->_isAbleToFly = true; /// BAD PRACTICE!!!
    IDPBirdObjectSetAbleToFly(result, true);
    
    return result;
}

void _IDPBirdObjectDeallocate(IDPBirdObject *object) {
    IDPBirdObjectSetName(object, NULL);
    
    IDPBirdObjectSetPartner(object, NULL);
    
    free(object);
}

#pragma mark -
#pragma mark Public Implementations

char *IDPBirdObjectName(IDPBirdObject *object) {
//    if (NULL == object) {
//        return NULL;
//    }
//    
//    return object->_name;
    return NULL != object ? object->_name : NULL;
}

void IDPBirdObjectSetName(IDPBirdObject *object, char *name) {
    if (NULL != object) {
        if (NULL != object->_name) {
            free(object->_name);
            object->_name = NULL;
        }
        
        if (name) {
            object->_name = strdup(name);
        }
    }
}

bool IDPBirdObjectIsAbleToFly(IDPBirdObject *object) {
    return NULL != object && object->_isAbleToFly;
}

void IDPBirdObjectSetAbleToFly(IDPBirdObject *object, bool ableToFly) {
    if (NULL != object) {
        object->_isAbleToFly = ableToFly;
    }
    
//    object->_isAbleToFly = NULL == object ? : ableToFly;
}


#pragma mark -
#pragma mark Private Implementations

IDPBirdObject *IDPBirdObjectPartner(IDPBirdObject *object) {
    return NULL != object ? object->_partner : NULL;
}

void IDPBirdObjectSetPartner(IDPBirdObject *object, IDPBirdObject *parnter) {
    if (NULL != object) {
//        if (object->_partner) {
            IDPObjectRelease(object->_partner);
            
//            _IDPBirdObjectDeallocate(object->_partner); // BAD
//            object->_partner = NULL;
//        }
        
        object->_partner = parnter;
        IDPObjectRetain(parnter);
    }
}
