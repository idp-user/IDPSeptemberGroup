//
//  IDPBirdObject.h
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 10/1/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#ifndef __IDPSeptemberGroupCode__IDPBirdObject__
#define __IDPSeptemberGroupCode__IDPBirdObject__

#include <stdbool.h>

typedef struct IDPBirdObject IDPBirdObject;

IDPBirdObject *IDPBirdObjectCreate(void);
void _IDPBirdObjectDeallocate(IDPBirdObject *object);

char *IDPBirdObjectName(IDPBirdObject *object);
void IDPBirdObjectSetName(IDPBirdObject *object, char *name);

bool IDPBirdObjectIsAbleToFly(IDPBirdObject *object);
void IDPBirdObjectSetAbleToFly(IDPBirdObject *object, bool ableToFly);

#endif /* defined(__IDPSeptemberGroupCode__IDPBirdObject__) */
