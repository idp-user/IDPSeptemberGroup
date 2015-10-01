//
//  IDPBirdObject.c
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 10/1/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include "IDPBirdObject.h"

#include <string.h>

#pragma mark -
#pragma mark Private Declarations

struct IDPBirdObject {
    char *_name;
    bool _isAbleToFly;
};

#pragma mark -
#pragma mark Public Implementations

IDPBirdObject *IDPBirdObjectCreate(void);
void _IDPBirdObjectDeallocate(IDPBirdObject *object);

char *IDPBirdObjectName(IDPBirdObject *object);
void IDPBirdObjectSetName(IDPBirdObject *object, char *name);

bool IDPBirdObjectIsAbleToFly(IDPBirdObject *object);
void IDPBirdObjectSetAbleToFly(IDPBirdObject *object, bool ableToFly);