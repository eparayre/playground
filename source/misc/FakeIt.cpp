#include "Playground.hpp"

#if defined( __GNUC__ ) && !defined( __clang__ )
    #if ( GCC_VERSION <= 40900 )
        #define EXCLUDE_MISC_FAKEIT
    #endif
#endif

#if !defined( EXCLUDE_MISC_FAKEIT )

#include "externs/fakeit.hpp"

//-----------------------------------------------------------------------------
TEST_CASE("Test FakeIt", "[fakeit]")
{
    using namespace fakeit;

    SECTION("Simple Method")
    {
        struct Interface
        {
            virtual void TestA() = 0;
            virtual void TestB(int arg) = 0;
            virtual void TestC(int arg1, bool arg2) = 0;
            virtual bool TestD() = 0;
            virtual float TestE(const std::string& arg) = 0;
        };

        Mock<Interface> mock;
        auto& instance = mock.get();

        SECTION("Without args")
        {
            When(Method(mock, TestA)).Return();

            instance.TestA();

            Verify(Method(mock, TestA));
        }

        SECTION("With 1 arg")
        {
            When(Method(mock, TestB)).Return();
            instance.TestB(11);

            When(Method(mock, TestB)).Return();
            instance.TestB(22);

            Verify(Method(mock, TestB).Using(11));
            Verify(Method(mock, TestB).Using(22));
        }

        SECTION("With 2 args")
        {
            When(Method(mock, TestC)).Return();
            instance.TestC(11, false);

            When(Method(mock, TestC)).Return();
            instance.TestC(22, true);

            Verify(Method(mock, TestC).Using(11, false));
            Verify(Method(mock, TestC).Using(22, true));
        }

        SECTION("With return value")
        {
            When(Method(mock, TestD)).Return(false);
            CHECK(instance.TestD() == false);

            When(Method(mock, TestD)).Return(true);
            CHECK(instance.TestD() == true);

            Verify(Method(mock, TestD));
            Verify(Method(mock, TestD));
        }

        SECTION("With arg and return value")
        {
            When(Method(mock, TestE)).Return(1.2f);
            CHECK(instance.TestE("foo") == Approx(1.2f));

            When(Method(mock, TestE)).Return(3.4f);
            CHECK(instance.TestE("bar") == Approx(3.4f));

            Verify(Method(mock, TestE));
            Verify(Method(mock, TestE));
        }
    }

    SECTION("Unique Pointer")
    {
        struct File
        {
            int value{0};
        };

        struct FileSystem
        {
            virtual std::unique_ptr<File> Read(const std::string& filename) const = 0;
            virtual File* ReadPtr(const std::string& filename) const = 0;
            virtual File& ReadRef(const std::string& filename) const = 0;
        };

        struct FakeFileSystem : public FileSystem
        {
            virtual void Test() const
            {
                std::cerr << "FakeIt_Test()" << std::endl;
            }
        };

        Mock<FakeFileSystem> mockFileSystem;
        auto& fileSystem = mockFileSystem.get();

        //auto lambda = []{return std::make_unique<File>();};

        //When(Method(mockFileSystem, Read).Do(lambda));
        //When(Method(mockFileSystem, Read)).Do([]{return std::make_unique<File>();});

        File fakeFile;
        When(Method(mockFileSystem, ReadPtr)).Return(&fakeFile);
        When(Method(mockFileSystem, ReadRef)).Return(fakeFile);
        //When(Method(mockFileSystem, Read)).Do([]{return std::make_unique<File>();});
        When(Method(mockFileSystem, Test)).Do([]{std::cerr << "hihi_fakeit" << std::endl;});

        auto  fileA = fileSystem.ReadPtr("file_A");
        auto& fileB = fileSystem.ReadRef("file_B");
        //auto  fileC = fileSystem.Read("file_C");
        fileSystem.Test();

        CHECK( fileA == &fakeFile);
        CHECK(&fileB == &fakeFile);

        //Verify(Method(mockFileSystem, Read).Using("file_B"));
    }
}

#endif
