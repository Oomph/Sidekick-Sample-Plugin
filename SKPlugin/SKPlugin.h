//
//  SKPlugin.h
//  NetworkLocation
//
//  Created by Chris Farber on 2/7/07.
//  Copyright 2007 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

/**
 * There should be one subclass of SKPlugin in your plugin bundle. This subclass
 * should be your bundle's principal class. SKPlugin serves two purposes, the first
 * of which is managing certain responsibilites. The second purpose is to inform
 * NetworkLocation what actions are provided by the plugin, and hold any common code
 * useful to other classes (such as SKAction subclasses).
 */
@class SKAction;

__attribute__((visibility("default")))
@interface SKPlugin : NSObject {
    @private
    NSBundle * pluginBundle;
    NSDictionary * actionsByID;
}

+ (id)pluginForClass:(Class)aClass;

- (id)initInBundle:(NSBundle *)bundle;

- (SKAction *)actionForID:(NSString *)actionID;
- (NSBundle *)bundle;

//Must be overriden
//Return an array of the classes of SKAction in your plugin.
/**
 * This is the only method you must implement in your subclass. Since there's no
 * good way to autodetect the SKAction subclasses within the bundle, or at least I
 * haven't found a suitable way yet, you have to implement this method to let
 * NetworkLocation know.
 * Here's an example implementation:
 *
 * - (NSArray *)actions
 * {
 *   return [NSArray arrayWithObject:[MySuperCoolSKActionSubclass class]];
 * }
 *
 * Note that you can use this method 
 */
- (NSArray *)actions;

@end
