#pragma once

//-----------------------------------------------------------------------------
// visual c++

#if defined( _MSC_VER )

//  c++11

#   if ( _MSC_VER >= 1600 )
#       define CPP11_NULLPTR
#   endif

#   if ( _MSC_VER >= 1900 )
#       define CPP11_NOEXCEPT
#   endif

#   if ( _MSC_VER > 1400 )
#       define CPP11_VARIADICS
#   endif

#endif

//-----------------------------------------------------------------------------
// gcc

#if defined( __GNUC__ )

//  c++11

#   if ( __GNUC__ > 4 || ( __GNUC__ == 4 && __GNUC_MINOR__ >= 6 && defined( __GXX_EXPERIMENTAL_CXX0X ) ) )
#       define CPP11_NULLPTR
#   endif

#   if ( __GNUC__ >= 3 )
#       define CPP11_VARIADICS
#   endif

#endif

//-----------------------------------------------------------------------------
// clang

#if defined( __clang__ )

//  c++11

#   if __has_feature( cxx_nullptr )
#       define CPP11_NULLPTR
#   endif

#   if __has_feature( cxx_noexcept )
#       define CPP11_NOEXCEPT
#   endif

#   if __has_feature( cxx_constexpr )
#       define CPP11_CONSTEXPR
#   endif

//  c++14

#   if __has_feature( cxx_relaxed_constexpr )
#       define CPP14_CONSTEXPR
#   endif

#endif
