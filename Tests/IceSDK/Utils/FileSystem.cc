#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Utils/FileSystem.h"

TEST(FileSystem, MkDir)
{
    IceSDK::FileSystem::MkDir("./TestDir");

    ASSERT_TRUE(IceSDK::FileSystem::Exists("./TestDir"));
    ASSERT_FALSE(IceSDK::FileSystem::Exists("./TestDir2"));
}

TEST(FileSystem, Exists)
{
    IceSDK::FileSystem::MkDir("./TestDir");

    ASSERT_TRUE(IceSDK::FileSystem::Exists("./TestDir"));
    ASSERT_FALSE(IceSDK::FileSystem::Exists("./TestDir2"));
}

TEST(FileSystem, JoinPath)
{
    ASSERT_EQ("./test/dir", IceSDK::FileSystem::JoinPath("./test/", "dir"));
}

TEST(FileSystem, IsDirectory)
{
    IceSDK::FileSystem::MkDir("./TestDir");
    IceSDK::FileSystem::Touch("./TestFile");

    ASSERT_TRUE(IceSDK::FileSystem::IsDirectory("./TestDir"));
    ASSERT_FALSE(IceSDK::FileSystem::IsDirectory("./TestDir2"));
    ASSERT_FALSE(IceSDK::FileSystem::IsDirectory("./TestFile"));
}

TEST(FileSystem, ReadDirectory)
{
    IceSDK::FileSystem::MkDir("./TestDir");
    IceSDK::FileSystem::MkDir("./TestDir/Dir");
    IceSDK::FileSystem::Touch("./TestDir/File");

    auto dir_info = IceSDK::FileSystem::ReadDirectory("./TestDir");

    ASSERT_THAT(dir_info, testing::ElementsAre("./TestDir/Dir", "./TestDir/File"));
}

TEST(FileSystem, ResolveFullPath)
{
    ASSERT_NE(IceSDK::FileSystem::ResolveFullPath("."), ""); // there is no real way we could test it, other than it's not being empty
}

TEST(FileSystem, ReadBinaryFile)
{
    std::vector<uint8_t> data = {'M', 'e', 'm', 'p', 'l', 'e', 'r', 17};

    IceSDK::FileSystem::WriteBinaryFile("./TestFile", data);

    ASSERT_THAT(IceSDK::FileSystem::ReadBinaryFile("./TestFile"), testing::ElementsAre('M', 'e', 'm', 'p', 'l', 'e', 'r', 17));
}

TEST(FileSystem, WriteBinaryFile)
{
    std::vector<uint8_t> data = {'M', 'e', 'm', 'p', 'l', 'e', 'r', 17};

    IceSDK::FileSystem::WriteBinaryFile("./TestFile", data);

    ASSERT_THAT(IceSDK::FileSystem::ReadBinaryFile("./TestFile"), testing::ElementsAre('M', 'e', 'm', 'p', 'l', 'e', 'r', 17));
}

TEST(FileSystem, HasExtension)
{
    IceSDK::FileSystem::Touch("./TestFile.test");

    ASSERT_TRUE(IceSDK::FileSystem::HasExtension("./TestFile.test", ".test"));
    ASSERT_FALSE(IceSDK::FileSystem::HasExtension("./TestFile.test", ".est"));
}

TEST(FileSystem, GetFileName)
{
    IceSDK::FileSystem::Touch("./TestFile");

    ASSERT_EQ(IceSDK::FileSystem::GetFileName("TestFile"), "TestFile");
    ASSERT_EQ(IceSDK::FileSystem::GetFileName("./TestFile"), "TestFile");
    ASSERT_EQ(IceSDK::FileSystem::GetFileName("./test/TestFile"), "TestFile");
}

TEST(FileSystem, Touch)
{
    IceSDK::FileSystem::Touch("./TestFile");

    ASSERT_TRUE(IceSDK::FileSystem::Exists("./TestFile"));
    ASSERT_FALSE(IceSDK::FileSystem::Exists("./TestFile2"));
}
