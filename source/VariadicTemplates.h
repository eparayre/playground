#pragma once

#include <iostream>
#include <string>
#include <sstream>

std::string Anchor( int i )
{
    std::stringstream stream;
    stream << "{" << i << "}";
    return stream.str();
}

std::string Replace( const std::string format, size_t index, const std::string& str )
{
    size_t pos = 0;

    std::string anchor = Anchor( index );
    std::string result = format;

    while( std::string::npos != pos )
    {
        pos = result.find( anchor, pos );

        if( std::string::npos != pos )
        {
            result.replace( pos, anchor.length(), str );
        }
    }

    return result;
}

std::string Format( const std::string& format, size_t index )
{
    return format;
}

template< typename Value, typename... Args >
std::string Format( const std::string& format, size_t index, Value& value, Args&... args )
{
    std::stringstream stream;
    stream << value;

    std::string result = Replace( format, index++, stream.str() );

    return Format( result, index, args... );
}

template< typename... Args >
std::string StringFormat( const std::string& format, Args... args )
{
    return Format( format, 0, args... );
}