//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

#include <iostream>
#include <boost/filesystem.hpp>

using boost::filesystem::create_directories;

void TreeTestCase::SetUp() { // create file system
    create_directories("tmp");
}

void TreeTestCase::TearDown() {
    remove("tmp");
}

FileNode TreeTestCase::TestEmpty() {
    create_directories("tmp/test_empty");
    auto res = GetTree("tmp/test_empty", false);
    return res;
}

FileNode TreeTestCase::TestFile() {
    boost::filesystem::ofstream( "tmp/test_file" );
    auto res = GetTree("tmp/test_file", false);
    return res;
}

FileNode TreeTestCase::TestIncorrectPath() {
    auto res = GetTree("tmp/not_exist", false);
    return res;
}

FileNode TreeTestCase::TestCorrect() {
    create_directories("tmp/correct");
    create_directories("tmp/correct/folder");    
    boost::filesystem::ofstream( "tmp/correct/test_file" );
    auto res = GetTree("tmp/correct", false);
    return res;
}

FileNode TreeTestCase::TestDirsOnly() {
    create_directories("tmp/dirsonly");
    create_directories("tmp/dirsonly/folder");    
    boost::filesystem::ofstream( "tmp/dirsonly/test_file" );
    auto res = GetTree("tmp/dirsonly", true);
    return res;
}

FileNode TreeTestCase::TestFilterEmpty() {
    create_directories("tmp/filter");
    create_directories("tmp/filter/folder");    
    boost::filesystem::ofstream( "tmp/filter/test_file" );
    FileNode res = GetTree("tmp/filter", false);
    FilterEmptyNodes(res, "tmp/filter");
    res = GetTree("tmp/filter", false);
    return res;
}

FileNode TreeTestCase::TestEqFileNode() {
    create_directories("tmp/single");
    create_directories("tmp/single/folder");    
    boost::filesystem::ofstream( "tmp/single/test_file" );
    FileNode res = GetTree("tmp/single", false);
    return res;
}

TEST_F(TreeTestCase, TestEmpty) {
    auto res = TreeTestCase::TestEmpty();
    ASSERT_EQ(res.name, "test_empty");
    ASSERT_EQ(res.children.size(), 0);
}

TEST_F(TreeTestCase, TestFile) {
    EXPECT_THROW(TreeTestCase::TestFile(), std::invalid_argument);
}

TEST_F(TreeTestCase, TestIncorrectPath) {
    EXPECT_THROW(TreeTestCase::TestIncorrectPath(), std::invalid_argument);
}

TEST_F(TreeTestCase, TestCorrect) {
    auto res = TreeTestCase::TestCorrect();
    ASSERT_EQ(res.name, "correct");
    ASSERT_EQ(res.children.size(), 2);

    ASSERT_EQ(res.children[0].name, "folder");
    ASSERT_EQ(res.children[1].name, "test_file");
}

TEST_F(TreeTestCase, TestDirsOnly) {
    auto res = TreeTestCase::TestDirsOnly();
    ASSERT_EQ(res.name, "dirsonly");
    ASSERT_EQ(res.children.size(), 1);
    ASSERT_EQ(res.children[0].name, "folder");
}

TEST_F(TreeTestCase, TestFilterEmpty) {
    auto res = TreeTestCase::TestFilterEmpty();
    ASSERT_EQ(res.name, "filter");
    ASSERT_EQ(res.children.size(), 1);
    ASSERT_EQ(res.children[0].name, "test_file");
}

TEST_F(TreeTestCase, TestEqFileNode) {
    auto res = TreeTestCase::TestEqFileNode();
    ASSERT_EQ(res == res, true);
}
