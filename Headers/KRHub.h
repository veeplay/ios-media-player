//
//  APSVAST
//
//  Created by Appscend on 7/17/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRAdapter.h"

/**
 *  A `KRHub` object can easily become a container of references to other objects or classes, organized in groups. To be able to register themselves with a `KRHub`, objects must implement the `KRAdapter` protocol. Within a single group there can not be more objects that declare the same type.
 */
@interface KRHub : NSObject

/**
 *  Returns the list of available registered objects for a specified group.
 *
 *  @param group The required group.
 *
 *  @return A dictionary containing all objects registered for the required group. The dictionary keys are the types, as specified by the objects.
 */
- (NSMutableDictionary*_Nullable)adaptersForGroup:(NSString *_Nonnull)group;

/**
 *  Registers a new adapter to the default group.
 *
 *  @param adapter The adapter to be registered. The object needs to implement `KRAdapter`.
 */
- (void)registerAdapter:(NSObject<KRAdapter> *_Nonnull)adapter;
/**
 *  Returns an object of the specified type, if such an object is currently registered in the default group.
 *
 *  @param type The required object type.
 *
 *  @return An object if any is registered, `nil` otherwise.
 */
- (NSObject<KRAdapter> *_Nullable)adapterForType:(NSString *_Nonnull)type;

/**
 *  Registeres a new adapter to a specific group
 *
 *  @param adapter The adapter to be registered. The object needs to implement `KRAdapter`.
 *  @param group   The group to register the adapter into.
 */
- (void)registerAdapter:(NSObject<KRAdapter> *_Nonnull)adapter inGroup:(NSString *_Nullable)group;
/**
 *  Returns an object of the specified type, if such an object is currently registered in the specified group.
 *
 *  @param type  The required object type.
 *  @param group The required group.
 *
 *  @return An object if any is registered, `nil` otherwise.
 */
- (NSObject<KRAdapter> *_Nullable)adapterForType:(NSString *_Nonnull)type inGroup:(NSString *_Nullable)group;

/**
 *  Registers a class to a specific group and a specific type. Upon requesting a new object from this group and type, a new object of the registered class will be instantiated and returned.
 *
 *  @param cclass The class to register.
 *  @param group  The group to register the call into.
 */
- (void)registerClass:(Class _Nonnull)cclass inGroup:(NSString *_Nullable)group;
/**
 *  Registers a class to the default group, under a specific type. Upon requesting a new object from this type from the default group, a new object of the registered class will be instantiated and returned.
 *
 *  @param cclass The class to register
 */
- (void)registerClass:(Class _Nonnull)cclass;

@end
