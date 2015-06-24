#include "Playground.hpp"

#include <type_traits>

namespace
{
    //-----------------------------------------------------------------------------
    class NoneDeclared
    {
    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class CtorDeclared
    {
    public:
        CtorDeclared() = default;

    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class DtorDeclared
    {
    public:
        ~DtorDeclared() = default;

    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class CopyCtorDeclared
    {
    public:
        CopyCtorDeclared( const CopyCtorDeclared& ) = default;

    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class CopyAssignmentDeclared
    {
    public:
        CopyAssignmentDeclared& operator=( const CopyAssignmentDeclared& ) = default;

    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class MoveCtorDeclared
    {
    public:
        MoveCtorDeclared( MoveCtorDeclared&& ) = default;

    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class MoveAssignmentDeclared
    {
    public:
        MoveAssignmentDeclared& operator=( MoveAssignmentDeclared&& ) = default;

    private:
        int a_;
    };
}

TEST_CASE( "Auto Generation Behaviors", "[special_member_functions]" )
{
    SECTION( "none declared" )
    {
        // all auto-generated

        CHECK( std::is_default_constructible< NoneDeclared >::value );
        CHECK( std::is_destructible< NoneDeclared >::value );

        CHECK( std::is_copy_constructible< NoneDeclared >::value );
        CHECK( std::is_copy_assignable< NoneDeclared >::value );

        CHECK( std::is_move_constructible< NoneDeclared >::value );
        CHECK( std::is_move_assignable< NoneDeclared >::value );
    }

    SECTION( "ctor declared" )
    {
        // ctor explicitely declared
        REQUIRE( std::is_default_constructible< CtorDeclared >::value );

        // dtor still auto-generated
        CHECK( std::is_destructible< CtorDeclared >::value );

        // copying still auto-generated
        CHECK( std::is_copy_constructible< CtorDeclared >::value );
        CHECK( std::is_copy_assignable< CtorDeclared >::value );

        // moving still auto-generated
        CHECK( std::is_move_constructible< CtorDeclared >::value );
        CHECK( std::is_move_assignable< CtorDeclared >::value );
    }

    SECTION( "dtor declared" )
    {
        // dtor explicitely declared
        REQUIRE( std::is_destructible< DtorDeclared >::value );

        // ctor still auto-generated
        CHECK( std::is_default_constructible< DtorDeclared >::value );

        // copying still auto-generated
        CHECK( std::is_copy_constructible< DtorDeclared >::value );
        CHECK( std::is_copy_assignable< DtorDeclared >::value );

        // moving still auto-generated
        CHECK( std::is_move_constructible< DtorDeclared >::value );
        CHECK( std::is_move_assignable< DtorDeclared >::value );
    }

    SECTION( "copy ctor declared" )
    {
        // copy ctor explicitely declared
        REQUIRE( std::is_copy_constructible< CopyCtorDeclared >::value );

        // default ctor requires explicit declaration
        CHECK_FALSE( std::is_default_constructible< CopyCtorDeclared >::value );

        // dtor still auto-generated
        CHECK( std::is_destructible< CopyCtorDeclared >::value );

        // copy assignment still auto-generated
        CHECK( std::is_copy_assignable< CopyCtorDeclared >::value );

        // moving still auto-generated
        CHECK( std::is_move_constructible< CopyCtorDeclared >::value );
        CHECK( std::is_move_assignable< CopyCtorDeclared >::value );
    }

    SECTION( "copy assignment declared" )
    {
        // copy assignment explicitely declared
        REQUIRE( std::is_copy_assignable< CopyAssignmentDeclared >::value );

        // ctor/dtor still auto-generated
        CHECK( std::is_default_constructible< CopyAssignmentDeclared >::value );
        CHECK( std::is_destructible< CopyAssignmentDeclared >::value );

        // copy ctor still auto-generated
        CHECK( std::is_copy_constructible< CopyAssignmentDeclared >::value );

        // moving still auto-generated
        CHECK( std::is_move_constructible< CopyAssignmentDeclared >::value );
        CHECK( std::is_move_assignable< CopyAssignmentDeclared >::value );
    }

    SECTION( "move ctor declared" )
    {
        // move ctor explicitely declared
        REQUIRE( std::is_move_constructible< MoveCtorDeclared >::value );

        // default ctor requires explicit declaration
        CHECK_FALSE( std::is_default_constructible< MoveCtorDeclared >::value );

        // dtor still auto-generated
        CHECK( std::is_destructible< MoveCtorDeclared >::value );

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
}

namespace
{
    //-----------------------------------------------------------------------------
    class NoneDeleted
    {
    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class CtorDeleted
    {
    public:
        CtorDeleted() = delete;

    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class DtorDeleted
    {
    public:
        ~DtorDeleted() = delete;

    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class CopyCtorDeleted
    {
    public:
        CopyCtorDeleted( const CopyCtorDeleted& ) = delete;

    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class CopyAssignmentDeleted
    {
    public:
        CopyAssignmentDeleted& operator=( const CopyAssignmentDeleted& ) = delete;

    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class MoveCtorDeleted
    {
    public:
        MoveCtorDeleted( MoveCtorDeleted&& ) = delete;

    private:
        int a_;
    };

    //-----------------------------------------------------------------------------
    class MoveAssignmentDeleted
    {
    public:
        MoveAssignmentDeleted& operator=( MoveAssignmentDeleted&& ) = delete;

    private:
        int a_;
    };
}

TEST_CASE( "Auto Generation Behaviors with Deletes", "[special_member_functions]" )
{
    SECTION( "none deleted" )
    {
        // all auto-generated

        CHECK( std::is_default_constructible< NoneDeleted >::value );
        CHECK( std::is_destructible< NoneDeleted >::value );

        CHECK( std::is_copy_constructible< NoneDeleted >::value );
        CHECK( std::is_copy_assignable< NoneDeleted >::value );

        CHECK( std::is_move_constructible< NoneDeleted >::value );
        CHECK( std::is_move_assignable< NoneDeleted >::value );
    }

    SECTION( "ctor deleted" )
    {
        // ctor explicitely deleted
        REQUIRE_FALSE( std::is_default_constructible< CtorDeleted >::value );

        // dtor still auto-generated
        CHECK( std::is_destructible< CtorDeleted >::value );

        // copying still auto-generated
        CHECK( std::is_copy_constructible< CtorDeleted >::value );
        CHECK( std::is_copy_assignable< CtorDeleted >::value );

        // moving still auto-generated
        CHECK( std::is_move_constructible< CtorDeleted >::value );
        CHECK( std::is_move_assignable< CtorDeleted >::value );
    }

    SECTION( "dtor deleted" )
    {
        // dtor explicitely deleted
        REQUIRE_FALSE( std::is_destructible< DtorDeleted >::value );

        // ctor still auto-generated
        CHECK( std::is_default_constructible< DtorDeleted >::value );

        // copying still auto-generated
        CHECK( std::is_copy_constructible< DtorDeleted >::value );
        CHECK( std::is_copy_assignable< DtorDeleted >::value );

        // moving still auto-generated
        CHECK( std::is_move_constructible< DtorDeleted >::value );
        CHECK( std::is_move_assignable< DtorDeleted >::value );
    }

    SECTION( "copy ctor deleted" )
    {
        // copy ctor explicitely deleted
        REQUIRE_FALSE( std::is_copy_constructible< CopyCtorDeleted >::value );

        // default/move ctors auto-deleted
        CHECK_FALSE( std::is_default_constructible< CopyCtorDeleted >::value );
        CHECK_FALSE( std::is_move_constructible< CopyCtorDeleted >::value );

        // dtor still auto-generated
        CHECK( std::is_destructible< CopyCtorDeleted >::value );

        // copy/move assignment still auto-generated
        CHECK( std::is_copy_assignable< CopyCtorDeleted >::value );
        CHECK( std::is_move_assignable< CopyCtorDeleted >::value );
    }

    SECTION( "copy assignment deleted" )
    {
        // copy assignment explicitely deleted
        REQUIRE_FALSE( std::is_copy_assignable< CopyAssignmentDeleted >::value );

        // ctor/dtor still auto-generated
        CHECK( std::is_default_constructible< CopyAssignmentDeleted >::value );
        CHECK( std::is_destructible< CopyAssignmentDeleted >::value );

        // copy ctor still auto-generated
        CHECK( std::is_copy_constructible< CopyAssignmentDeleted >::value );

        // moving still auto-generated
        CHECK( std::is_move_constructible< CopyAssignmentDeleted >::value );
        CHECK( std::is_move_assignable< CopyAssignmentDeleted >::value );
    }

    SECTION( "move ctor deleted" )
    {
        // move ctor explicitely deleted
        REQUIRE_FALSE( std::is_move_constructible< MoveCtorDeleted >::value );

        // default ctor requires explicit declaration
        CHECK_FALSE( std::is_default_constructible< MoveCtorDeleted >::value );

        // dtor still auto-generated
        CHECK( std::is_destructible< MoveCtorDeleted >::value );

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
