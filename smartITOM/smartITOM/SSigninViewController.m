//
//  SSigninViewController.m
//  smartITOM
//
//  Created by 朱国强 on 14-3-6.
//  Copyright (c) 2014年 Apple002. All rights reserved.
//

#import "SSigninViewController.h"

@interface SSigninViewController ()
{
    NSString *userName;
    NSString *password;
    
    
}

@end

@implementation SSigninViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    if (textField.tag == 100)
    {
        userName = textField.text;
    }
    else if (textField.tag == 101)
    {
        password = textField.text;
    }
    
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    
    return YES;
}


- (IBAction)signinBtnAction:(id)sender
{
    if ([userName isEqualToString:@"admin"])
    {
        //通过验证
        [self performSegueWithIdentifier:@"signin" sender:self];
    }
    else
    {
        //验证失败
        
    }
}

@end
