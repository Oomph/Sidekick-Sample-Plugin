//
//  SPSampleActionOptionSheetController.m
//  SamplePlugin
//
//  Created by Chris Farber on 10/18/11.
//  Copyright (c) 2011 Oomph. All rights reserved.
//

#import "SPSampleActionOptionSheetController.h"

@implementation SPSampleActionOptionSheetController

- (IBAction)resetText:(id)sender
{
    NSString *defaultText = [[[self action] optionDefaults] valueForKey:@"text"];
    [self setValue:defaultText forKeyPath:@"options.text"];
}

@end
