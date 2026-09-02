//
//  POPPath.h
//  PullOver X
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Resolves a canonical rootful path inside the standard /var/jb rootless.
NS_INLINE NSString *POPPath(NSString *path) {
#if defined(POP_PACKAGE_SCHEME_ROOTLESS)
    if ([path hasPrefix:@"/var/jb/"] || [path isEqualToString:@"/var/jb"]) {
        return path;
    }
    if ([path hasPrefix:@"/"]) {
        return [@"/var/jb" stringByAppendingString:path];
    }
#endif
    return path;
}

NS_ASSUME_NONNULL_END
