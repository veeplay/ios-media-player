//
//  APSVAST
//
//  Created by Appscend on 7/17/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The `KRAdapter` protocol allows an object to declare itself as being of a certain type.
 */
@protocol KRAdapter <NSObject>
/**
 *  Returns the adapter type.
 *
 *  @return An adapter type in string format.
 */
- (NSString *_Nonnull)type;
@end
