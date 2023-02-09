#include <CoreFoundation/CoreFoundation.h>
#include <objc/objc-runtime.h>

int main(int argc, char** argv) {
    Class bundle = objc_getClass("NSBundle");
    class_replaceMethod(bundle,
                        sel_registerName("bundleIdentifier"),
                        method_getImplementation((Method)^{return CFSTR("com.apple.systempreferences");}),
                        nullptr);
    id notificationCenter = ((id (*) (id, SEL))objc_msgSend)((id)objc_getClass("NSUserNotificationCenter"),
                                  sel_registerName("defaultUserNotificationCenter"));
    id notification = ((id (*) (id, SEL, SEL))objc_msgSend)((id)objc_getClass("NSUserNotification"),
                            sel_registerName("alloc"),
                            sel_registerName("init"));
    ((id (*) (id, SEL, CFStringRef))objc_msgSend)(notification, sel_registerName("setTitle:"), CFSTR("Hi"));
    ((id (*) (id, SEL, CFStringRef))objc_msgSend)(notification, sel_registerName("setSubtitle:"), CFSTR("Notification"));
    ((id (*) (id, SEL, CFStringRef))objc_msgSend)(notification, sel_registerName("setInformativeText:"), CFSTR("From System Settings!"));
    ((id (*) (id, SEL, id))objc_msgSend)(notificationCenter, sel_registerName("deliverNotification:"), notification);
    sleep(1);
    return 0;
}
