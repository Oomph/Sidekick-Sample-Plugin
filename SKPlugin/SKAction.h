//
//  SKAction.h
//  Sidekick
//
//  Created by Chris Farber on 2/7/07.
//  Copyright 2007-2011 Oomph. All rights reserved.
//

#import <Cocoa/Cocoa.h>


enum {
	SKPluginCategoryPlugin = 0,
	SKPluginCategorySystem = 1,
	SKPluginCategoryApplication = 2
};
typedef NSUInteger SKPluginCategory;

extern NSString * SKPluginCategoryName(SKPluginCategory category);

@class SKPlugin, SKOptionSheetController, SKActionContext;

/**
 * Every action must be a subclass of SKAction.
 * Methods you will need to implement:
 *      +actionID, +category, +title, -performAction, -cleanupAction
 * Usually, you will also want to override:
 *      -title, -optionDefaults, +icon, -icon
 */
__attribute__((visibility("default")))
@interface SKAction : NSObject {
    @private
    SKPlugin * plugin;
    NSMutableDictionary * plist;
}

/**
 * Returns the ID of the action.
 * The ID must be a string, and must be unique within your plugin. If your action
 * has options, then the ID is also assumed to be the filename of the nib containing
 * your options. MUST BE OVERRIDEN.
 * @see optionSheetController
 */
+ (NSString *) actionID;

/**
 * Returns the name of the category the action will appear under.
 * You shouldn't override this without good reason; the default implementation
 * returns SKPluginCategoryPlugin
 */
+ (SKPluginCategory) category;

/**
 * Returns the description the user will see when adding an action.
 * MUST BE OVERRIDEN.
 * Example: "Change the volume"
 */
+ (NSString *) title;

/**
 * If your action should logically only have one instance per location (for
 * example, you are modifying a system setting that there is no reason to set
 * twice), then override this method to return NO. The default implementation
 * returns YES.
 */
+ (BOOL) allowsMultipleInstances;

/**
 * If your action should only be addable by the user if certain conditions
 * have been met, you may use this method to hide it. This method is invoked
 * frequently, so it must be efficient. The default implementation returns NO.
 */
+ (BOOL) invisible;

/**
 * Let Sidekick know if this action should be included in new new locations
 * that are created as a snapshot of the user machine's current state.
 * The default implementation returns NO.  
 */
+ (BOOL) snapshotable;

/**
 * Returns an icon that will be displayed to the user in the list of available
 * actions. The default is [NSImage imageNamed: @"NSAdvanced"]
 */
+ (NSImage *) icon;

+ (id)actionWithPlist: (NSMutableDictionary *)entry;

- (id)initWithPlist: (NSMutableDictionary *)entry;

- (NSMutableDictionary *) plist;

/**
 * Gets the NSMutableDictionary of options
 */
- (NSMutableDictionary *) options;

- (NSNumber *) enabled;
- (void) setEnabled: (NSNumber *)enabled;

/**
 * Returns the parent instance of SKPlugin.
 */
- (SKPlugin *) plugin;
- (NSString * )pluginID;

- (void) triggerTitleUpdate;

/**
 * Let Sidekick know if this action has options.
 * The default implementation searches for a nib file matching the action's ID,
 * and returns an NSNumber containing YES if found. You only need to override this
 * method if your nib's filename does not match +(NSString *)actionID
 * @see actionID
 */
- (NSNumber *) hasOptions;

/**
 * In special cases, when bindings prove inadequate, you will need
 * to provide controller code for your option interface. To do this, you should
 * subclass OptionSheetController and override this method to return your subclass's
 * class. The default implementation of this method returns the class
 * OptionSheetController. The class returned by this method is instantiated and used
 * as the nib's owner.
 */
- (Class) optionSheetControllerClass;

/**
 * Instantiate and return an OptionSheetController. The default implementation of this
 * method uses the class returned by optionSheetControllerClass and instantiates it
 * using +(NSString)actionID as the nib name.
 * @see optionSheetControllerClass
 * @see actionID
 */
- (SKOptionSheetController *) optionSheetController;

/**
 * Return an NSDictionary containing default options. When the action is instantiated
 * as a new action, this method is invoked to get the defaults
 */
- (NSDictionary *) optionDefaults;

/**
 * This method returns a string describing the action for the user. It is displayed
 * in the list of actions in a location in the preferences. The default implementation
 * simply invokes +title
 */
- (NSString *) title;

/**
 * Returns an NSImage containing an icon to display to the user in the list of
 * actions for a location. If possible, this should be more specific than the
 * icon returned by +icon; for example, an action that opens a URL may want to
 * fetch the site's favicon and return it.
 */
- (NSImage *) icon;


/**
 * performAction is invoked by Sidekick when it wants the action to do its
 * stuff.
 * MUST BE OVERRIDEN (or use performActionWithContext).
 */
- (void) performAction;

/*
 * performActionWithContext calls performAction by default
 */
- (void) performActionWithContext:(SKActionContext *)actionContext;


/**
 * cleanupAction is invoked by Sidekick when it wants the action to clean up
 * after itself. In other words, if you want to undo anything done by your action,
 * such as set the system volume back to the value it was before performAction
 * changed it, this is the place to do it.
 * MUST BE OVERRIDEN.
 */
- (void) cleanupAction;

/*
 * cleanupActionWithContext calls cleanupAction by default
 */
- (void) cleanupActionWithContext:(SKActionContext *)actionContext;

@end
