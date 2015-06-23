#include "Playground.hpp"

namespace
{
    //-----------------------------------------------------------------------------
    enum class ShapeType
    {
        Circle,
        Square
    };

    //-----------------------------------------------------------------------------
    enum class Color
    {
        Red,
        Green,
        Blue
    };

    //-----------------------------------------------------------------------------
    class Shape
    {
    public:
        Shape( ShapeType type, Color color )
            : type_( type )
            , color_( color )
        {}

        void Draw() {}

        ShapeType GetType() const { return type_; }
        Color GetColor() const { return color_; }

    private:
        ShapeType type_;
        Color color_;
    };
}

//-----------------------------------------------------------------------------
TEST_CASE( "ConstLiffy", "[auto][lambda]" )
{
    std::vector<Shape> shapes;
    std::vector<bool> shouldDraw;

    shapes.push_back( Shape( ShapeType::Circle, Color::Red   ) );
    shapes.push_back( Shape( ShapeType::Circle, Color::Green ) );
    shapes.push_back( Shape( ShapeType::Circle, Color::Blue  ) );
    shapes.push_back( Shape( ShapeType::Square, Color::Red   ) );
    shapes.push_back( Shape( ShapeType::Square, Color::Green ) );
    shapes.push_back( Shape( ShapeType::Square, Color::Blue  ) );

    for( auto&& shape : shapes )
    {
        const bool draw = [&]{
            switch( shape.GetType() )
            {
            case ShapeType::Circle: return shape.GetColor() == Color::Red;
            case ShapeType::Square: return shape.GetColor() == Color::Blue;
            default: return false;
            }
        }();

        shouldDraw.push_back( draw );
    }

    REQUIRE( shouldDraw.size() == 6 );
    CHECK( shouldDraw[ 0 ] == true  );
    CHECK( shouldDraw[ 1 ] == false );
    CHECK( shouldDraw[ 2 ] == false );
    CHECK( shouldDraw[ 3 ] == false );
    CHECK( shouldDraw[ 4 ] == false );
    CHECK( shouldDraw[ 5 ] == true  );
}
