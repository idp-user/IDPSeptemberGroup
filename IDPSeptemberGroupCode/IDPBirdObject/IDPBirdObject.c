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

#include "IDPObject.h"


#pragma mark -
#pragma mark Private Declarations



static
IDPBirdObject *IDPBirdObjectPartner(IDPBirdObject *object);

static
void IDPBirdObjectSetPartner(IDPBirdObject *object, IDPBirdObject *parnter);

#pragma mark -
#pragma mark Public Implementations

IDPBirdObject *IDPBirdObjectCreate(void) {
    IDPBirdObject *result = IDPObjectCreateOfType(IDPBirdObject);
//    result->_isAbleToFly = true; /// BAD PRACTICE!!!
    IDPBirdObjectSetAbleToFly(result, true);
    
    return result;
}

void __IDPBirdObjectDeallocate(void *object) {
    IDPBirdObjectSetName(object, NULL);
    IDPBirdObjectSetPartner(object, NULL);
    
    __IDPObjectDeallocate(object);
}

#pragma mark -
#pragma mark Public Implementations

char *IDPBirdObjectName(IDPBirdObject *object) {
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
    if (NULL != object && object->_partner != parnter) {
        IDPObjectRetain(parnter);
        IDPObjectRelease(object->_partner);

        object->_partner = parnter;
    }
}
