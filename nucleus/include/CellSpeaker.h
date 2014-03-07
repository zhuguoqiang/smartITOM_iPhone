/*
 ------------------------------------------------------------------------------
 This source file is part of Cell Cloud.
 
 Copyright (c) 2009-2012 Cell Cloud Team - cellcloudproject@gmail.com
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ------------------------------------------------------------------------------
 */

#include "CellPrerequisites.h"
#import "CellMessageService.h"

/** 对话者状态。
 */
typedef enum _CCSpeakerState
{
    /// 无对话
    CCSpeakerStateHangUp = 1,

    /// 正在请求服务
    CCSpeakerStateCalling,

    /// 已经请求服务
    CCSpeakerStateCalled,

    /// 挂起状态
    CCSpeakerStateSuspended

} CCSpeakerState;

/** 对话者描述类。
 * @author Jiangwei Xu
 */
@interface CCSpeaker : NSObject <CCMessageHandler>

@property (nonatomic, strong, readonly) NSString *identifier;
@property (nonatomic, strong, readonly) CCInetAddress *address;
@property (nonatomic, strong, readonly) CCNucleusTag *remoteTag;
@property (nonatomic, strong) CCTalkCapacity *capacity;
@property (nonatomic, assign) NSTimeInterval timestamp;
@property (atomic, assign) CCSpeakerState state;

/** 初始化。 */
- (id)initWithIdentifier:(NSString *)identifier;
/** 初始化。 */
- (id)initWithCapacity:(NSString *)identifier capacity:(CCTalkCapacity*)capacity;

/** 向指定地址请求 Cellet 服务。 */
- (BOOL)call:(CCInetAddress *)address;

/** 中断与 Cellet 服务。 */
- (void)hangUp;

/** 挂起与 Cellet 服务。 */
- (void)suspend:(NSTimeInterval)duration;

/** 恢复与 Cellet 服务。 */
- (void)resume:(NSTimeInterval)startTime;

/** 是否已经调用了 Cellet 。 */
- (BOOL)isCalled;

/** 是否已挂起 Cellet 会话。 */
- (BOOL)isSuspended;

/** 向 Cellet 发送原语。 */
- (BOOL)speak:(CCPrimitive *)primitive;

/** 心跳。 */
- (void)heartbeat;

@end
