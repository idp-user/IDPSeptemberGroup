//
//  IDPSampleObject.h
//  IDPSeptemberGroupCode
//
//  Created by Alexander Kradenkov on 11/17/15.
//  Copyright (c) 2015 IDAP College. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDPSampleObject : NSObject

+ (id)publicMethod;
- (id)publicMethod;

- (void)say:(NSString *)string;

@end

