//
//  SKActionContext.h
//  SideKick
//
//  Created by Rick Fillion on 11-09-17.
//  Copyright (c) 2011 Oomph. All rights reserved.
//

#import <Foundation/Foundation.h>


__attribute__((visibility("default")))
@interface SKActionContext : NSObject
{
    NSString *locationName;
}

@property (readonly) NSString *locationName;

- (id)initWithLocationName:(NSString *)name;

@end
