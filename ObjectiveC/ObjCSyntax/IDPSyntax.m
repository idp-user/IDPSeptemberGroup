//
//  IDPSyntax.m
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 11/16/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import <objc/message.h>

#import "IDPSyntax.h"
#import "IDPSampleObject.h"


#pragma mark -
#pragma mark Private Declarations

static
void IDPSyntaxObjectCreationTest(void);

static
void IDPSyntaxExplicitNSAutoreleasePool(void);

static
void IDPSyntaxTollFreeBridging(void);

static
void IDPSyntaxLiterals(void);

static
void IDPSyntaxMessagingSamples(void);

static
void IDPSyntaxMessagingWithSampleObject(void);

static
void IDPSyntaxNil(void);

#pragma mark -
#pragma mark Public Implementationsw

void IDPSyntaxPerformDemo() {
    IDPSyntaxExplicitNSAutoreleasePool();
    IDPSyntaxObjectCreationTest();
    IDPSyntaxTollFreeBridging();
    IDPSyntaxLiterals();
    IDPSyntaxMessagingSamples();
    IDPSyntaxMessagingWithSampleObject();
    IDPSyntaxNil();
}

#pragma mark -
#pragma mark Private Implementations

void IDPSyntaxObjectCreationTest(void) {
    @autoreleasepool {
        NSObject *object = [[NSObject alloc] init];
        
        [object autorelease];
        
        int value = 123;
        
        NSLog(@"%i %@", value, [object description]);
        NSLog(@"%@", object);
        
//        [object release];
    }
}

void IDPSyntaxExplicitNSAutoreleasePool() {
    {
        id pool = [[NSAutoreleasePool alloc] init];
        
        NSObject *object = [[NSObject alloc] init];
        
        [object autorelease];
        
        int value = 123;
        
        NSLog(@"%i %@", value, [object description]);
        NSLog(@"%@", object);
        
//        [object release];
        
        [pool drain];
    }
}

void IDPSyntaxTollFreeBridging(void) {
    
    NSString *string = @"asd";
    
    CFStringRef cfString = (__bridge CFStringRef)string;
    
    CFIndex retainCount = CFGetRetainCount(cfString);
    CFRetain(cfString);
    NSLog(@"%lu == %lu", string.length, CFStringGetLength(cfString));
    retainCount = CFGetRetainCount(cfString);
    
    CFRelease(cfString);
    
    retainCount = CFGetRetainCount(cfString);
}


void IDPSyntaxLiterals(void) {
    @autoreleasepool {
        NSString *literalString = @"string";
        
        NSNumber *literalNumber = @(1234);
        
        NSArray *literalArray = @[literalString, literalNumber]; // [NSArray arrayWithObjects:literalString, nil];
        
        id object = [[NSObject alloc] init];
        
        NSDictionary *literalDictionary = @{literalString : object,
                                            literalString : object,
                                            literalNumber : object}; // [NSDictionary dictionaryWithObjectsAndKeys:literalString, object, nil];
        
        NSObject *objectInDictionary = literalDictionary[literalString];  // [literalDictionary objectForKeyedSubscript:literalString];
        NSObject *objectInArray = literalArray[0]; // [literalArray objectAtIndexedSubscript:0];
    
        
        [object release];
        
        object = literalDictionary[@"string"];
        
        [literalArray objectAtIndex:0];
        
        NSUInteger obj = literalArray.count;
        NSUInteger obj2 = [literalArray count];
        
        NSUInteger index = [literalArray indexOfObject:literalNumber
                                               inRange:NSMakeRange(0, literalArray.count)];
        
        NSLog(@"INDEX = %lu", index);
    }
}

void IDPSyntaxMessagingSamples() {
    NSArray *array = @[@(23), @(24), @(25), @(26)];
    
    // send message without parameters
    [array count];
    
    
    // send message with one parameter
    [array indexOfObject:@(23)];
    
    
    // send message with two parameters
    [array indexOfObject:@(23) inRange:NSMakeRange(0, array.count)];
    
    NSUInteger index1 = [array indexOfObject:@(23)];
    NSUInteger index2 = [array indexOfObject:@(23) inRange:NSMakeRange(0, [array count])];

    assert(index1 == index2);

    id object1 = [array firstObject];
    
    SEL oneParameterMethod = @selector(firstObject);
    id object2 = [array performSelector:oneParameterMethod];

    assert(object2 == object1);
    
    id (*sendMethod)(id,SEL) = objc_msgSend;
    
    id object3 = sendMethod(array, oneParameterMethod);
    
    assert(object3 == object1);
}


void IDPSyntaxMessagingWithSampleObject(void) {
    IDPSampleObject *object = [[IDPSampleObject alloc] init];

    assert([object isKindOfClass:[NSObject class]]);
    assert([object isMemberOfClass:[IDPSampleObject class]]);
    
    id result = [object privateMethod];
    
    
    if (YES == [object respondsToSelector:@selector(privateMethod2)]) {
            id result2 = [object privateMethod2];
    }

    
    NSLog(@"%@", result);
    
    NSLog(@"%@", [object publicMethod]);
    
    [object say:@"WAZZUUUP!"];
    [object say:@[@(1), @(3)]];
    
    NSLog(@"%@", [IDPSampleObject publicMethod]);
    
    [object release];
}

void IDPSyntaxNil(void) {
    Class class = Nil;
    NSObject *object = nil;
    
    void *pointer = NULL;
    
    id nullObject = [NSNull null];
    
    
    id object2 = [[NSObject alloc] init];
    
    [object2 release];
    
    NSLog(@"Nil class  = %@,  nil object = %@, NULL pointer = %p, NSNull object = %@", NSStringFromClass(class), object, pointer, nullObject);
}