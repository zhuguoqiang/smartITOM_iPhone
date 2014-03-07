//
//  SAppDelegate.m
//  smartITOM
//
//  Created by 朱国强 on 14-3-6.
//  Copyright (c) 2014年 Apple002. All rights reserved.
//


#import "SAppDelegate.h"


@implementation SAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    NSString *path = [[NSBundle mainBundle] pathForResource:@"currentUser" ofType:@"json"];
  
    NSString *json = [[NSString alloc] initWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
    
    NSDictionary *dic = [json objectFromJSONString];
    
    //json解析出错，
    
    NSDictionary *currentDic  = [dic objectForKey:@"currentUser"];
    NSString *username = [dic objectForKey:@"userName"];
    NSLog(@"%@",username);
    BOOL status = [[currentDic objectForKey:@"siginStatus"] boolValue];
    if (status)
    {
        NSLog(@"当前用户已登录");
    }
    else {
        NSLog(@"用户已注销");
    }

    // Override point for customization after application launch.
    return YES;
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
