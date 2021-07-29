//
//  APSVASTRegulationInformation.h
//  Veeplay
//
//  Created by Ovidiu Nitan on 30/05/2019.
//  Copyright © 2019 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APSVASTRegulationInformation : NSObject

/**
 * The limit ad tracking setting of a device-specific advertising ID scheme. This value
 * is a boolean, with `true` indicating that a user has opted for limited ad tracking, and
 * `false` indicating that they have not
 */
@property (nonatomic) BOOL limitAdTracking;

/**
 * List of applicable regulations. Possible values:
 * - coppa
 * - gdpr
 */
@property (nonatomic, nonnull) NSArray<NSString*>* applicableRegulations;

/**
 * Base64-encoded Cookie Value of IAB GDPR consent info
 */
@property (nonatomic, nonnull) NSString *gdprConsentCookie;

+ (APSVASTRegulationInformation * _Nonnull)regulationInformationWithLimitAdTracking:(BOOL)limitAdTracking applicableRegulations:(NSArray<NSString*>*_Nullable)applicableRegulations gdprConsentCookie:(NSString *_Nullable)gdprConsentCookie;

@end
