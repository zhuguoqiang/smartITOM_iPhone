//
//  SSigninViewController.h
//  smartITOM
//
//  Created by 朱国强 on 14-3-6.
//  Copyright (c) 2014年 Apple002. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SSigninViewController : UIViewController<UITextFieldDelegate>

@property (strong, nonatomic) IBOutlet UIImageView *signinBgImageV;
@property (strong, nonatomic) IBOutlet UIImageView *logoImageV;
@property (strong, nonatomic) IBOutlet UIView *signinView;
@property (strong, nonatomic) IBOutlet UITextField *userNameTf;
@property (strong, nonatomic) IBOutlet UITextField *pswTf;
@property (strong, nonatomic) IBOutlet UIButton *settingBtn;
@property (strong, nonatomic) IBOutlet UIButton *signinBtn;

@end
