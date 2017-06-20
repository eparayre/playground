#include "Playground.hpp"

#if defined( __GNUC__ ) && !defined( __clang__ )
    #define EXCLUDE_MISC_HIPPOMOCKS
#elif defined( _MSC_VER )
    #define EXCLUDE_MISC_HIPPOMOCKS
#endif

#if !defined( EXCLUDE_MISC_HIPPOMOCKS )

#include "externs/hippomocks.h"

//-----------------------------------------------------------------------------
TEST_CASE("Test HippoMocks", "[hippomocks]")
{
    using namespace HippoMocks;

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

        MockRepository mocks;
        auto instance = mocks.Mock<Interface>();

        SECTION("Without args")
        {
            mocks.ExpectCall(instance, Interface::TestA);

            instance->TestA();
        }

        SECTION("With 1 arg")
        {
            mocks.ExpectCall(instance, Interface::TestB).With(11);
            mocks.ExpectCall(instance, Interface::TestB).With(22);

            instance->TestB(11);
            instance->TestB(22);
        }

        SECTION("With 2 args")
        {
            mocks.ExpectCall(instance, Interface::TestC).With(11, false);
            mocks.ExpectCall(instance, Interface::TestC).With(22, true);

            instance->TestC(11, false);
            instance->TestC(22, true);
        }

        SECTION("With return value")
        {
            mocks.ExpectCall(instance, Interface::TestD).Return(false);
            mocks.ExpectCall(instance, Interface::TestD).Return(true);

            CHECK(instance->TestD() == false);
            CHECK(instance->TestD() == true);
        }

        SECTION("With arg and return value")
        {
            mocks.ExpectCall(instance, Interface::TestE).With("foo").Return(1.2f);
            mocks.ExpectCall(instance, Interface::TestE).With("bar").Return(3.4f);

            CHECK(instance->TestE("foo") == Approx(1.2f));
            CHECK(instance->TestE("bar") == Approx(3.4f));
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
                std::cerr << "HippoMocks_Test()" << std::endl;
            }
        };

        MockRepository mocks;
        auto fileSystem = mocks.Mock<FakeFileSystem>();

        File fakeFile;
        mocks.ExpectCall(fileSystem, FakeFileSystem::ReadPtr).With("file_A").Return(&fakeFile);
        mocks.ExpectCall(fileSystem, FakeFileSystem::ReadRef).With("file_B").Return(fakeFile);
        //mocks.ExpectCall(fileSystem, FakeFileSystem::Read).Do([]{return nullptr;});
        mocks.ExpectCall(fileSystem, FakeFileSystem::Test).Do([]{std::cerr << "hihi_hippo" << std::endl;});

        auto  fileA = fileSystem->ReadPtr("file_A");
        auto& fileB = fileSystem->ReadRef("file_B");
        //auto  fileC = fileSystem->Read("file_C");
        fileSystem->Test();

        CHECK( fileA == &fakeFile);
        CHECK(&fileB == &fakeFile);
    }
}

#endif
