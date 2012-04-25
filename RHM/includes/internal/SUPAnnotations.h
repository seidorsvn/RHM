#ifndef __has_feature

#define __has_feature(x) 0     // Compatibility with non-clang compilers.

#endif

 

#ifndef NS_RETURNS_RETAINED

#if __has_feature(attribute_ns_returns_retained)

#define NS_RETURNS_RETAINED __attribute__((ns_returns_retained))

#else

#define NS_RETURNS_RETAINED

#endif

#endif


