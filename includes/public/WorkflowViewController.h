/*
 Copyright (c) Sybase, Inc. 2011 All rights reserved. 
 
 In addition to the license terms set out in the Sybase License Agreement for 
 the Sybase Unwired Platform ("Program"), the following additional or different 
 rights and accompanying obligations and restrictions shall apply to the source 
 code in this file ("Code"). Sybase grants you a limited, non-exclusive, 
 non-transferable, revocable license to use, reproduce, and modify the Code 
 solely for purposes of (i) maintaining the Code as reference material to better 
 understand the operation of the Program, and (ii) development and testing of 
 applications created in connection with your licensed use of the Program. 
 The Code may not be transferred, sold, assigned, sublicensed or otherwise 
 conveyed (whether by operation of law or otherwise) to another party without 
 Sybase's prior written consent. The following provisions shall apply to any 
 modifications you make to the Code: (i) Sybase will not provide any maintenance 
 or support for modified Code or problems that result from use of modified Code; 
 (ii) Sybase expressly disclaims any warranties and conditions, express or 
 implied, relating to modified Code or any problems that result from use of the 
 modified Code; (iii) SYBASE SHALL NOT BE LIABLE FOR ANY LOSS OR DAMAGE RELATING 
 TO MODIFICATIONS MADE TO THE CODE OR FOR ANY DAMAGES RESULTING FROM USE OF THE 
 MODIFIED CODE, INCLUDING, WITHOUT LIMITATION, ANY INACCURACY OF DATA, LOSS OF 
 PROFITS OR DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES, EVEN 
 IF SYBASE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; (iv) you agree 
 to indemnify, hold harmless, and defend Sybase from and against any claims or 
 lawsuits, including attorney's fees, that arise from or are related to the 
 modified Code or from use of the modified Code.
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Workflow priorities
#define IMPORTANCE_LOW                 0
#define IMPORTANCE_NORMAL              1
#define IMPORTANCE_HIGH                2

#define WORKFLOW_CHANGED_NOTIFICATION  @"WorkflowChanged"

// The class describing a Workflow that can be opened
@interface Workflow : NSObject {
   NSInteger moduleId;       // A unique number assigned to the Workflow by the server
   NSInteger moduleVersion;  // A number identifying the version of the module as specified in the manifest
   NSInteger msgId;          // For Workflows accessed from the inbox, a unique ID associated with the message
                             // For Workflows accessed from the Workflows folder this will be -1
   NSString* moduleName;     // The Workflow name from the manifest
   BOOL isProcessed;         // Indicates whether Workflow has been processed or not.  Needed internally by the class.
   NSInteger iconIndex;      // Used to determine icon to return from getImage.  Needed internally by the class.
   NSString* from;           // Who workflow is from, only applies to workflow messages
   NSString* subject;        // Subject of workflow, only applies to workflow messages
   NSDate* date;             // Received date, only applies to workflow messages
   BOOL readFlag;            // Indicates whether or not workflow has been read, only applies to workflow messages
   NSInteger priority;       // Indicates workflow priorities (see above),  only applies to workflow messages
}

@property(nonatomic, assign) NSInteger moduleId;
@property(nonatomic, assign) NSInteger moduleVersion;
@property(nonatomic, assign) NSInteger msgId;
@property(nonatomic, assign) NSString* moduleName;
@property(nonatomic, assign) BOOL isProcessed;
@property(nonatomic, assign) NSInteger iconIndex;
@property(nonatomic, assign) NSString* from;
@property(nonatomic, assign) NSString* subject;
@property(nonatomic, assign) NSDate* date;
@property(nonatomic, assign) BOOL readFlag;
@property(nonatomic, assign) NSInteger priority;
       
// Used to sort Workflows in the Workflows folder       
- (NSComparisonResult)compareByName:(Workflow*)workflow;

// Returns an image to display that is associated with the Workflow
// The image may change after the Workflow is processed
// The files contained within WorkflowImages.zip must be added to the applications project in order for this
// routine to operate properly, otherwise nil will be returned.
- (UIImage*)getImage;

// The image that indicates the read flag and priority of the message
// The files contained within WorkflowImages.zip must be added to the applications project in order for this
// routine to operate properly, otherwise nil will be returned.
- (UIImage*)getReadFlagImage;

// Internal class level function used internally
+ (Workflow*)workflowWithModuleId:(NSUInteger)moduleId withModuleVersion:(NSUInteger)moduleVersion;

@end

typedef enum {
   UnknownFolder,
   WorkflowFolder,
   MessageFolder
} WorkflowFolderType;

typedef enum {
   WORKFLOW_OPERATION_NEW = 1,
   WORKFLOW_OPERATION_MOD = 2,
   WORKFLOW_OPERATION_DELETE = 3,
   WORKFLOW_OPERATION_DELETE_ALL = 4
} WorkflowOperation;

// Each folder of Workflows should maintain a collection
// This collection can be populated via loadFromWorkflowFolder or loadFromInbox depending upon the folder in use
// For Workflow folders the collection should be accessed via workflowAtIndexFromWorkflowFolder
// For Inbox folders the collection should be accessed via workflowFromMsgId
@interface WorkflowCollection : NSObject {
   NSMutableArray* workflows;
   WorkflowFolderType folderType;
}

@property (nonatomic, readonly) NSUInteger count;

- (void)loadForFolder:(WorkflowFolderType)folderTypeToLoad;

- (WorkflowFolderType)getFolderType;

- (Workflow*)workflowAtIndex:(NSUInteger)index;

- (Workflow*)workflowFromMsgId:(NSUInteger)msgId;

+ (NSInteger)unreadCount;

- (void)deleteWorkflowAtIndex:(NSUInteger)index;

@end


@class WorkflowViewController;

@protocol WorkflowViewControllerDelegate

// A delegate should be implemented for each folder
// It will be caled after a Workflow submission occurs
// Depending upon the Workflow definition, some Workflows need to be immediately reopened after a
// submission occurs.  If the workflowToReopen parameter is not nil this workflow should be opened by
// the calling view and the it is up to the caller to release this parameter.
// Whether the workflowToReopen is nil or not, typically the delegate should reload its collection
// when called.  
- (void)workflowViewController:(WorkflowViewController*)controller workflowToReopen:(Workflow*)workflow;
            
- (void)workflowDidStartLoad:(NSInteger)msgId withModuleId:(NSInteger)moduleId withModuleVersion:(NSInteger)moduleVersion;
- (void)workflowDidFinishLoad:(NSInteger)msgId withModuleId:(NSInteger)moduleId withModuleVersion:(NSInteger)moduleVersion;
            
@end

// The controller that provides the ability to open a Workflow
@interface WorkflowViewController : UIViewController 
+ (NSInteger)openWithWorkflow:(Workflow*)workflow
               fromController:(UIViewController*)viewController
                     delegate:(id <WorkflowViewControllerDelegate>)delegate;

+ (void)deleteWorkFlowMsg:(NSUInteger)msgId;

+ (void)closeCurrentWorkFlowMsg;

@end

// Used whenever the collection changes
// folderType specifies which folder was changed
// operation indicates new, modifify, or delete
// msgId only applies to MessageFolder
@interface WorkflowChangeNotification: NSObject
{
   WorkflowFolderType folderType;
   WorkflowOperation operation;
   NSInteger msgId;
}

@property (nonatomic, readonly) WorkflowFolderType folderType;
@property (nonatomic, readonly) NSInteger msgId;
@property (nonatomic, readonly) WorkflowOperation operation;

// Internal API used for object creation by internal code
- (id)initWithType:(WorkflowFolderType)type withOperation:(WorkflowOperation)op withMsgId:(NSInteger)id;

@end

