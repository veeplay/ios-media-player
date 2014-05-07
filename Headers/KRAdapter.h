//
//  APSAdapter.h
//  Dolphin
//
//  Created by gabi on 10.07.2013.
//
//

#import <Foundation/Foundation.h>
typedef NSString KRAdapterType;

@protocol KRAdapter <NSObject>
- (KRAdapterType*)type;
@end
