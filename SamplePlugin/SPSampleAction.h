//
//  SPSampleAction.h
//  SamplePlugin
//
//  Created by Chris Farber on 10/18/11.
//  Copyright (c) 2011 Oomph. All rights reserved.
//


#import "SKAction.h"

@interface SPSampleAction : SKAction

// Have the computer speak some text using `say`
- (void)say:(NSString *)text;

@end
