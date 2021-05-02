//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>

#include "Tree.h"

class TreeTestCase : public ::testing::Test {
public:
    void SetUp() override;
    void TearDown() override;
    FileNode TestEmpty();
    FileNode TestFile();
    FileNode TestIncorrectPath();
    FileNode TestCorrect();
    FileNode TestDirsOnly();
    FileNode TestFilterEmpty();
    FileNode TestEqFileNode();
};
