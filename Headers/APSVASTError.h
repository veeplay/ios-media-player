//
//  APSVASTError.h
//  Veeplay
//
//  Created by Ovidiu Nitan on 15/03/2019.
//  Copyright © 2019 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef APSVASTError_h
#define APSVASTError_h

#define kAPSVASTErrorXMLParsingError 100
#define kAPSVASTErrorSchemaValidation 101
#define kAPSVASTErrorVersionNotSupported 102

#define kAPSVASTTraffickingError 200
#define kAPSVASTLinearityError 201
#define kAPSVASTDurationError 202
#define kAPSVASTSizeError 203
#define kAPSVASTAdCategoryRequiredError 204
#define kAPSVASTAdCategoryBlockedError 205

#define kAPSVASTGeneralWrapperError 300
#define kAPSVASTURITimeoutError 301
#define kAPSVASTWrapperLimitError 302
#define kAPSVASTNoVASTResponseError 303
#define kAPSVASTAdUnitTooLongError 304

#define kAPSVASTLinearAdGeneralError 400
#define kAPSVASTFileNotFoundError 401
#define kAPSVASTMediaFileURITimeoutError 402
#define kAPSVASTMediaFileNotSupportedError 403
#define kAPSVASTMediaFileDisplayError 405
#define kAPSVASTMezzanineNotFoundError 406
#define kAPSVASTMezzanineIsBeingDownloadedError 407
#define kAPSVASTConditionalAdRejectedError 408
#define kAPSVASTInteractiveUnitNotExecutedError 409
#define kAPSVASTVerificationNotExecutedError 410
#define kAPSVASTInvalidMezzanineError 411

#define kAPSVASTNonLinearAdsGeneralError 500
#define kAPSVASTNonLinearInvalidSizeError 501
#define kAPSVASTNonLinearResourceFetchError 502
#define kAPSVASTNoSupportedNonLinearFoundError 503

#define kAPSVASTCompanionAdsGeneralError 600
#define kAPSVASTCompanionInvalidSizeError 601
#define kAPSVASTCompanionDisplayError 602
#define kAPSVASTCompanionResourceFetchError 603
#define kAPSVASTNoSupportedCompanionFoundError 604

#define kAPSVASTUndefinedError 900
#define kAPSVASTGeneralVPAIDError 901

static inline NSString *descriptionForVASTError(int err) {
    if (err == kAPSVASTErrorXMLParsingError) return @"XML parsing error";
    else if (err == kAPSVASTErrorSchemaValidation) return @"VAST schema validation error";
    else if (err == kAPSVASTErrorVersionNotSupported) return @"VAST version of response not supported";
    else if (err == kAPSVASTTraffickingError) return @"Trafficking error. Media player received an Ad type that it was not expecting and/or cannot play";
    else if (err == kAPSVASTLinearityError) return @"Media player expecting different linearity";
    else if (err == kAPSVASTDurationError) return @"Media player expecting different duration";
    else if (err == kAPSVASTSizeError) return @"Media player expecting different size";
    else if (err == kAPSVASTAdCategoryRequiredError) return @"Ad category was required but not provided";
    else if (err == kAPSVASTAdCategoryBlockedError) return @"Inline Category violates Wrapper BlockedAdCategories";
    else if (err == kAPSVASTGeneralWrapperError) return @"General Wrapper error";
    else if (err == kAPSVASTURITimeoutError) return @"Timeout of VAST URI provided in Wrapper element, or of VAST URI provided in a subsequent Wrapper element";
    else if (err == kAPSVASTWrapperLimitError) return @"Wrapper limit reached. Too many Wrapper responses have been received with no InLine response";
    else if (err == kAPSVASTNoVASTResponseError) return @"No VAST response after one or more Wrappers";
    else if (err == kAPSVASTAdUnitTooLongError) return @"InLine response returned ad unit that failed to result in ad display within defined time limit";
    else if (err == kAPSVASTLinearAdGeneralError) return @"General Linear error. Media player is unable to display the Linear Ad";
    else if (err == kAPSVASTFileNotFoundError) return @"File not found. Unable to find Linear/MediaFile from URI";
    else if (err == kAPSVASTMediaFileURITimeoutError) return @"Timeout of MediaFile URI";
    else if (err == kAPSVASTMediaFileNotSupportedError) return @"Couldn’t find MediaFile that is supported by this media player, based on the attributes of the MediaFile element";
    else if (err == kAPSVASTMediaFileDisplayError) return @"Problem displaying MediaFile. Media player found a MediaFile with supported type but couldn’t display it";
    else if (err == kAPSVASTMezzanineNotFoundError) return @"Mezzanine was required but not provided";
    else if (err == kAPSVASTMezzanineIsBeingDownloadedError) return @"Mezzanine is in the process of being downloaded for the first time";
    else if (err == kAPSVASTConditionalAdRejectedError) return @"Conditional ad rejected";
    else if (err == kAPSVASTInteractiveUnitNotExecutedError) return @"Interactive unit in the InteractiveCreativeFile node was not executed";
    else if (err == kAPSVASTVerificationNotExecutedError) return @"Verification unit in the Verification node was not executed";
    else if (err == kAPSVASTInvalidMezzanineError) return @"Mezzanine was provided as required, but file did not meet required specification";
    else if (err == kAPSVASTNonLinearAdsGeneralError) return @"General NonLinearAds error";
    else if (err == kAPSVASTNonLinearInvalidSizeError) return @"Unable to display NonLinearAd because creative dimensions do not align with creative display area";
    else if (err == kAPSVASTNonLinearResourceFetchError) return @"Unable to fetch NonLinearAds/NonLinear resource";
    else if (err == kAPSVASTNoSupportedNonLinearFoundError) return @"Couldn’t find NonLinear resource with supported type";
    else if (err == kAPSVASTCompanionAdsGeneralError) return @"General CompanionAds error";
    else if (err == kAPSVASTCompanionInvalidSizeError) return @"Unable to display Companion because creative dimensions do not fit within Companion display area";
    else if (err == kAPSVASTCompanionDisplayError) return @"Unable to display required Companion";
    else if (err == kAPSVASTCompanionResourceFetchError) return @"Unable to fetch CompanionAds/Companion resource";
    else if (err == kAPSVASTNoSupportedCompanionFoundError) return @"Couldn’t find Companion resource with supported type";
    else if (err == kAPSVASTUndefinedError) return @"Undefined Error";
    else if (err == kAPSVASTGeneralVPAIDError) return @"General VPAID error";
    return @"Unknown error";
}

#endif /* APSVASTError_h */
