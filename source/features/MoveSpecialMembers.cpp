#include "Playground.hpp"

#include <type_traits>

namespace
{
    //-----------------------------------------------------------------------------
    class Empty
    {};

    //-----------------------------------------------------------------------------
    class MoveCtorDeclared
    {
    public:
        MoveCtorDeclared( MoveCtorDeclared&& ) = default;
    };

    //-----------------------------------------------------------------------------
    class MoveAssignmentDeclared
    {
    public:
        MoveAssignmentDeclared& operator=( MoveAssignmentDeclared&& ) = default;
    };

    //-----------------------------------------------------------------------------
    class MoveCtorDeleted
    {
    public:
        MoveCtorDeleted( MoveCtorDeleted&& ) = delete;
    };

    //-----------------------------------------------------------------------------
    class MoveAssignmentDeleted
    {
    public:
        MoveAssignmentDeleted& operator=( MoveAssignmentDeleted&& ) = delete;
    };
}

TEST_CASE( "Auto Generation Behaviors", "[special_member_functions]" )
{
    SECTION( "nothing declared or deleted" )
    {
        // all auto-generated

        CHECK( std::is_default_constructible< Empty >::value );
        CHECK( std::is_destructible< Empty >::value );

        CHECK( std::is_copy_constructible< Empty >::value );
        CHECK( std::is_copy_assignable< Empty >::value );

        CHECK( std::is_move_constructible< Empty >::value );
        CHECK( std::is_move_assignable< Empty >::value );
    }

    SECTION( "move ctor declared" )
    {
        // move ctor explicitely declared
        REQUIRE( std::is_move_constructible< MoveCtorDeclared >::value );

        // dtor still auto-generated
        CHECK( std::is_destructible< MoveCtorDeclared >::value );

        // default ctor requires explicit declaration
        CHECK_FALSE( std::is_default_constructible< MoveCtorDeclared >::value );

        // copying requires explicit delcaration
        CHECK_FALSE( std::is_copy_constructible< MoveCtorDeclared >::value );
        CHECK_FALSE( std::is_copy_assignable< MoveCtorDeclared >::value );

        // move assignment requires explicit declaration
        CHECK_FALSE( std::is_move_assignable< MoveCtorDeclared >::value );
    }

    SECTION( "move assignment declared" )
    {
        // move assignment explicitely declared
        REQUIRE( std::is_move_assignable< MoveAssignmentDeclared >::value );

        // ctor/dtor still auto-generated
        CHECK( std::is_default_constructible< MoveAssignmentDeclared >::value );
        CHECK( std::is_destructible< MoveAssignmentDeclared >::value );

        // copying requires explicit delcaration
        CHECK_FALSE( std::is_copy_constructible< MoveAssignmentDeclared >::value );
        CHECK_FALSE( std::is_copy_assignable< MoveAssignmentDeclared >::value );

        // move construction requires explicit declaration
        CHECK_FALSE( std::is_move_constructible< MoveAssignmentDeclared >::value );
    }

    SECTION( "move ctor deleted" )
    {
        // move ctor explicitely deleted
        REQUIRE_FALSE( std::is_move_constructible< MoveCtorDeleted >::value );

        // dtor still auto-generated
        CHECK( std::is_destructible< MoveCtorDeleted >::value );

        // default ctor requires explicit declaration
        CHECK_FALSE( std::is_default_constructible< MoveCtorDeleted >::value );

        // copying requires explicit delcaration
        CHECK_FALSE( std::is_copy_constructible< MoveCtorDeleted >::value );
        CHECK_FALSE( std::is_copy_assignable< MoveCtorDeleted >::value );

        // move assignment requires explicit declaration
        CHECK_FALSE( std::is_move_assignable< MoveCtorDeleted >::value );
    }

    SECTION( "move assignment deleted" )
    {
        // move assignment explicitely deleted
        REQUIRE_FALSE( std::is_move_assignable< MoveAssignmentDeleted >::value );

        // ctor/dtor still auto-generated
        CHECK( std::is_default_constructible< MoveAssignmentDeleted >::value );
        CHECK( std::is_destructible< MoveAssignmentDeleted >::value );

        // copying requires explicit delcaration
        CHECK_FALSE( std::is_copy_constructible< MoveAssignmentDeleted >::value );
        CHECK_FALSE( std::is_copy_assignable< MoveAssignmentDeleted >::value );

        // move construction requires explicit declaration
        CHECK_FALSE( std::is_move_constructible< MoveAssignmentDeleted >::value );
    }
}
