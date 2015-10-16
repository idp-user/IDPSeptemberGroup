//
//  IDPObjectTests.c
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 10/16/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#include <assert.h>
#include "IDPObjectTests.h"

#include "IDPObject.h"

#include "IDPBirdObject.h"

#pragma mark -
#pragma mark Private Declarations

static
void performIDPObjectTest(void);

static
void performIDPBirdObjectTest(void);

#pragma mark -
#pragma mark Public Implementations

void IDPPerformIDPObjectTests(void) {
    performIDPObjectTest();
    performIDPBirdObjectTest();
}

#pragma mark -
#pragma mark Private Implementations

void performIDPObjectTest(void) {
    IDPObject *object = IDPObjectCreateOfType(IDPObject);
    
    assert(NULL != object);
    assert(1 == IDPObjectRetainCount(object));
    
    IDPObjectRetain(object);
    assert(2 == IDPObjectRetainCount(object));
    
    IDPObjectRelease(object);
    assert(1 == IDPObjectRetainCount(object));
    
    IDPObjectRelease(object);
}

void performIDPBirdObjectTest(void) {
    IDPBirdObject *bird = IDPBirdObjectCreate();
    
    assert(NULL != bird);
    assert(1 == IDPObjectRetainCount(bird));
    
    assert(true == IDPBirdObjectIsAbleToFly(bird));
    
    IDPObjectRelease(bird);
}
