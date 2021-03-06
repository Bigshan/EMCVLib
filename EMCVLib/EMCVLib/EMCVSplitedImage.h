//
//  EMCVSplitedImage.h
//  EMCVLib
//
//  Created by 郑宇琦 on 2017/4/10.
//  Copyright © 2017年 郑宇琦. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "platform.h"
#import "EMCVImage.h"

@class EMCVImage;

#ifdef __cplusplus
#include "opencv.h"
using namespace std;
using namespace cv;
#endif

@interface EMCVSplitedImage : NSObject

#ifdef __cplusplus
{
@public
    vector<Mat> _mats;
    vector<MatND> _hists;
}
- (instancetype)initWithMats:(vector<Mat>)mats;
- (instancetype)initWithNoCopyMats:(vector<Mat>)mats;
#endif

@property (nonatomic, readonly) int channalCount;

- (instancetype)initWithPath:(NSString *)path;
- (instancetype)initWithCVImage:(EMCVImage *)img;

- (void)threshold:(double)thresh atChannal:(int)channal;
- (void)threshold:(double)thresh maxValue:(double)maxValue type:(int)type atChanal:(int)channal;

- (EMCVImage *)mergeImage;
- (EMCVImage *)imageWithChannal:(int)channal;
- (NSSize)sizeWithChannal:(int)channal;

- (void)flipWithXAxis;
- (void)flipWithYAxis;
- (void)flipWithXAxisAtChannal:(int)channal;
- (void)flipWithYAxisAtChannal:(int)channal;

- (void)setBrightness:(double)brightness;
- (void)setBrightness:(double)brightness atChannal:(int)channal;

- (void)pyrUpWithRatio:(double)ratio;
- (void)pyrDownWithRatio:(double)ratio;
- (void)pyrUpWithRatio:(double)ratio atChannal:(int)channal;
- (void)pyrDownWithRatio:(double)ratio atChannal:(int)channal;

- (void)calHistWithSize:(int)size range:(float *)range;
- (void)calHistWithSizes:(int *)sizes ranges:(float **)ranges;
- (void)calHistWithChannal:(int)channal size:(int)size range:(float *)range;

- (void)normalizeHistWithValue:(double)value;
- (void)normalizeHistWithChanal:(int)channal value:(double)value;

- (void)findMaxValue:(double *)value outPoint:(NSPoint *)point inChannal:(int)channal;
- (void)findMinValue:(double *)value outPoint:(NSPoint *)point inChannal:(int)channal;

- (EMCVImage *)newCannyWithThresh1:(double)thresh1 andThresh2:(double)thresh2 atChannal:(int)channal;
- (void)cannyOnCVImage:(EMCVImage *)img withThresh1:(double)thresh1 andThreash2:(double)thresh2 atChannal:(int)channal;
- (EMCVImage *)newDrawContoursWithMode:(int)mode andMethod:(int)method atChannal:(int)channal;
- (void)drawContoursOnImage:(EMCVImage *)img withMode:(int)mode andMethod:(int)method atChannal:(int)channal;

@end
