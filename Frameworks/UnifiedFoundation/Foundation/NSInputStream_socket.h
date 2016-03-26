//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#pragma once

@class NSSocket;
@class NSSelectInputSource;

@interface NSInputStream_socket : NSStream {
@public
    id _delegate;
    id _error;
    NSSocket* _socket;
    NSSelectInputSource* _inputSource;
}
- (int)read:(uint8_t*)buffer maxLength:(DWORD)maxLength;
- (BOOL)hasBytesAvailable;
- (void)dealloc;
- (instancetype)initWithSocket:(NSSocket*)socket streamStatus:(DWORD)status;
- (void)setDelegate:(id)delegate;
- (id)open;
- (id)close;
- (id)scheduleInRunLoop:(id)runLoop forMode:(id)mode;
- (id)removeFromRunLoop:(id)runLoop forMode:(id)mode;
- (id)selectInputSource:(id)inputSource selectEvent:(DWORD)selectEvent;
- (BOOL)setProperty:(id)prop forKey:(id)key;
@end
