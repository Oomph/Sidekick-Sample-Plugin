//
//  SPSamplePlugin.m
//  SamplePlugin
//
//  Created by Chris Farber on 10/18/11.
//  Copyright (c) 2011 Oomph. All rights reserved.
//

#import "SPSamplePlugin.h"
#import "SPSampleAction.h"

@implementation SPSamplePlugin

- (NSArray *)actions
{
    return [NSArray arrayWithObjects:
            [SPSampleAction class],
            nil];
}

@end
