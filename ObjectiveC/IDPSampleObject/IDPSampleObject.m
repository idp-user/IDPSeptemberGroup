//
//  IDPSampleObject.m
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 11/17/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import "IDPSampleObject.h"

@implementation IDPSampleObject

#pragma mark -
#pragma mark Class Methods

+ (id)publicMethod {
    return @"I'm CLASS public";
}

#pragma mark -
#pragma mark Public

- (id)publicMethod {
    return @"I'm INSTANCE public";
}

- (void)say:(NSString *)string {
    NSLog(@"%@", string);
}
#pragma mark -
#pragma mark Private

- (id)privateMethod {
    return @"I'm private";
}

@end