//
//  YTHFSHeaders.h
//
//  Created by Joshua Seltzer on 12/5/22.
//
//

#import <UIKit/UIKit.h>
#import <rootless.h>

@interface YTDoubleTapToSeekView : UIView

// shows feedback with the given title text and direction
- (void)showCenteredSeekFeedbackWithTitle:(NSString *)title direction:(NSInteger)direction;

@end

@interface YTMainAppVideoPlayerOverlayView : UIView

// the view that is used to display that the double tap to seek gesture was invoked
@property (readonly, nonatomic) YTDoubleTapToSeekView *doubleTapToSeekView;

@end

// the controller responsible for handling changes to the playback speed
@interface YTVarispeedSwitchController : NSObject
@end

@interface YTPlayerView : UIView

// the overlay view which includes the double tap to seek view
@property (retain, nonatomic) UIView *overlayView;

@end

@interface YTPlayerViewController : UIViewController

// the main view for viewing videos
@property (readonly, nonatomic) YTPlayerView *playerView;

// the controller responsible for allowing the user to switch the playback speed
@property (readonly, nonatomic) YTVarispeedSwitchController *varispeedController;

// the overlay controller that will be used to potentially hide the player controls
@property (readonly, nonatomic) UIViewController *contentVideoPlayerOverlay;

// returns whether or not the play controls are currently hidden or visible
- (BOOL)arePlayerControlsHidden;

// returns the current playback speed
- (float)currentPlaybackRateForVarispeedSwitchController:(YTVarispeedSwitchController *)varispeedSwitchController;

// invoked whenever the playback speed selection is changed
- (void)varispeedSwitchController:(YTVarispeedSwitchController *)varispeedSwitchController didSelectRate:(float)rate;

@end

@interface YTMainAppVideoPlayerOverlayViewController : UIViewController

// indicates whether or not the playback speed of the video can be changed
@property (readonly, nonatomic) BOOL isVarispeedAvailable;

// hide the player controls programatically
- (void)hidePlayerControlsAnimated:(BOOL)animated;

@end

// controller which is updated with the launch and dismissal of the player view controller
@interface YTWatchController : NSObject
@end

// manager responsible for handling the app's preferences
@interface YTSettingsSectionItemManager : NSObject

// required when creating setting sections that have user selection
- (id)parentResponder;

@end

// view controller that displays settings information
@interface YTStyledViewController
@end
@interface YTSettingsViewController : YTStyledViewController

// reloads the setting sections in the settings view controller
- (void)reloadData;

// push a new controller on the navigation stack
- (void)pushViewController:(id)viewController;

// sets the array of section items for a given settings category
- (void)setSectionItems:(NSArray *)sectionItems forCategory:(NSInteger)categoryId title:(NSString *)title titleDescription:(NSString *)titleDescription headerHidden:(BOOL)hidden;

@end

// view controller that displays selectable settings
@interface YTSettingsPickerViewController : YTStyledViewController

// initialize a new picker view controller
- (id)initWithNavTitle:(NSString *)navTitle pickerSectionTitle:(NSString *)pickerSectionTitle rows:(NSArray *)rows selectedItemIndex:(NSUInteger)index parentResponder:(id)responder;

@end

// a cell in the settings view controller
@interface YTSettingsCell
@end

// an item which defines a section inside a settings controller
@interface YTSettingsSectionItem : NSObject

// create a new setting item with an on/off switch, title, and optional description
+ (id)switchItemWithTitle:(NSString *)title titleDescription:(NSString *)titleDescription accessibilityIdentifier:(id)identifier switchOn:(BOOL)enabled switchBlock:(id)switchBlock settingItemId:(NSInteger)itemId;

// create a new item with a title, selected detail text, and a selection block which can push another instance of a settings controller
+ (id)itemWithTitle:(NSString *)title titleDescription:(NSString *)titleDescription accessibilityIdentifier:(id)identifier detailTextBlock:(id)detailTextBlock selectBlock:(id)selectBlock;

// create a checkmark item with a title and select block
+ (id)checkmarkItemWithTitle:(NSString *)title selectBlock:(id)selectBlock;

@end
