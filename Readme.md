# Sidekick Sample Plugin

This is an example project showing you how to create plugins for [Sidekick](http://oomphalot.com/sidekick). It simply speaks the text entered by the user using Mac OS's `say` command.

## Getting started with the SDK

To properly set up your plugin, there are a few settings you'll have to customize. If it helps, you can start using this provided project as a base, but be sure to customize the bundle identifier and class names.

0. Remember that your code is being loaded into Sidekick's global namespace, so make an effort to use unique class names and prefixes. The following prefixes belong to us and should not be used: `SK`, `NL`, `AL`.
1. Add `-undefined dynamic_lookup` to your linker flags.
2. Set the `NLPluginVersion` key in your Info.plist to 1
3. Set garbage collection to required (`GCC_ENABLE_OBJC_GC -fobjc-gc-only`)
4. Subclass SKPlugin and make this subclass your bundle's principal class.
5. Subclass SKAction to create your actions, and update the list returned by your plugin's `-actions` method.
6. If needed, subclass `SKOptionSheetController` to provide more complex interaction in your action's configuration sheet.

##Extra tips

- If you need a user interface, don't forget to disable your window's "Visible At Launch" property. You must also set an outlet for this window on File's Owner (an SKOptionSheetController).
- If you need to access your plugin's bundle, don't use `[NSBundle mainBundle]`, instead use the `-bundle` method on your `SKPlugin` subclass. All `SKAction` objects keep a reference to their plugin instance.

