//
//  SPSampleAction.m
//  SamplePlugin
//
//  Created by Chris Farber on 10/18/11.
//  Copyright (c) 2011 Oomph. All rights reserved.
//

#import "SPSampleAction.h"
#import "SPSampleActionOptionSheetController.h"

@implementation SPSampleAction

+ (NSString *)actionID
{
    return @"SampleAction";
}

+ (NSString *)title
{
    return @"Say something";
}

- (NSString *)title
{
    return [NSString stringWithFormat:@"Say: \"%@\"", [[self options] valueForKey:@"text"]];
}

+ (NSImage *)icon
{
    return [NSImage imageNamed:NSImageNameGoRightTemplate];
}

- (Class)optionSheetControllerClass
{
    return [SPSampleActionOptionSheetController class];
}

- (void)performActionWithContext:(SKActionContext *)actionContext
{
    NSString *text = [[self options] valueForKey:@"text"];
    [self say:text];
}

- (NSDictionary *)optionDefaults
{
    return [NSDictionary dictionaryWithObjectsAndKeys:
            @"Hello, there", @"text",
            nil];
}

- (void)say:(NSString *)text
{
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSString *text = [[self options] valueForKey:@"text"];
        NSTask *sayTask = [NSTask launchedTaskWithLaunchPath:@"/usr/bin/say" arguments:[NSArray arrayWithObject:text]];
        [sayTask waitUntilExit];
        int status = [sayTask terminationStatus];
        if (status) {
            //You should probably do something better than this...
            NSLog(@"say failed");
        }
    });
}

@end
