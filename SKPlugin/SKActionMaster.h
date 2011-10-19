//
//  ActionMaster.h
//  NetworkLocation
//
//  Created by Chris Farber on 9/21/06.
//  Copyright 2006 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class SKAction;

@interface SKActionMaster : NSObject {
    NSMutableDictionary * actionsByPlugin;
    NSMutableArray * actions;
    NSMutableDictionary * plugins;
}

+ (void) initialize;
+ (id) actionMaster;

- (void) loadActionsFromPlugin:(NSBundle *)pluginBundle;

- (SKAction *) actionFromPlistItem:(NSMutableDictionary *)plistItem;

- (NSDictionary *) actionsByPlugin;
- (NSArray *)actions;
- (NSArray *)snapshot;

@end
