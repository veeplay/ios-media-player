//
//  APSAdapterManager.h
//  Dolphin
//
//  Created by gabi on 09.07.2013.
//
//

#import <Foundation/Foundation.h>
#import "KRAdapter.h"

typedef NSString KRAdapterGroup;

@interface KRHub : NSObject {
    NSMutableDictionary *adapters;
}

- (NSMutableDictionary*)adaptersForGroup:(KRAdapterGroup*)group;

- (void)registerAdapter:(NSObject<KRAdapter>*)adapter;
- (NSObject<KRAdapter>*)adapterForType:(KRAdapterType*)type;

- (void)registerAdapter:(NSObject<KRAdapter>*)adapter inGroup:(KRAdapterGroup*)group;
- (NSObject<KRAdapter>*)adapterForType:(KRAdapterType*)type inGroup:(KRAdapterGroup*)group;

- (void)registerClass:(Class)cclass inGroup:(KRAdapterGroup*)group type:(KRAdapterType*)type;
- (void)registerClass:(Class)cclass type:(KRAdapterType*)type;

@end