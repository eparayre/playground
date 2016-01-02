#pragma once

//-----------------------------------------------------------------------------
// common

#if defined( __has_attribute )
    #define CXX_HAS_ATTRIBUTE
#endif

#if defined( __has_cpp_attribute )
    #define CXX_HAS_ATTRIBUTE_CPP
#endif

#if defined( __has_declspec_attribute )
    #define CXX_HAS_ATTRIBUTE_DECLSPEC
#endif

#if defined( __has_builtin )
    #define CXX_HAS_BUILTIN
#endif

#if defined( __has_extension )
    #define CXX_HAS_EXTENSION
#endif

#if defined( __has_feature )
    #define CXX_HAS_FEATURE
#endif

#if defined( __has_include )
    #define CXX_HAS_INCLUDE
#endif

#if defined( __has_include_next )
    #define CXX_HAS_INCLUDE_NEXT
#endif

#if defined( __has_warning )
    #define CXX_HAS_WARNING
#endif
