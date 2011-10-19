//
//  PluginMaster.h
//  NetworkLocation
//
//  Created by Chris Farber on 1/31/07.
//  Copyright 2007 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface SKPluginMaster : NSObject {

}

+ (id) pluginMaster;
- (void) loadPluginsFromPath: (NSString *)path;
- (void) loadPluginAtPath: (NSString *)path;
- (void) installPluginAtPath: (NSString *)path;
- (void) uninstallPluginAtPath: (NSString *)path;
- (BOOL) isPluginInstalled: (NSString *)path;

- (BOOL) checkPluginAndDisplayErrors: (NSBundle *)plugin;

@end
