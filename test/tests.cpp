//all the includes you want to use before the gtest include
#include <unionfind/unionfind.hpp>

#include <gtest/gtest.h>

TEST(UnionFindTest, UnmergedTest)
{
    unionfind::UnionFind uf{5};

    EXPECT_EQ(uf.findUnsafe(0), 0);
    EXPECT_EQ(uf.findUnsafe(1), 1);
    EXPECT_EQ(uf.findUnsafe(2), 2);
    EXPECT_EQ(uf.findUnsafe(3), 3);
    EXPECT_EQ(uf.findUnsafe(4), 4);

    EXPECT_EQ(uf.find(0), 0);
    EXPECT_EQ(uf.find(1), 1);
    EXPECT_EQ(uf.find(2), 2);
    EXPECT_EQ(uf.find(3), 3);
    EXPECT_EQ(uf.find(4), 4);

    EXPECT_EQ(uf.numberOfSets(), 5);
}

TEST(UnionFindTest, SimpleMergeTest0)
{
    unionfind::UnionFind uf{5};

    uf.merge(0, 4);

    EXPECT_EQ(uf.find(0), 4);
    EXPECT_EQ(uf.find(1), 1);
    EXPECT_EQ(uf.find(2), 2);
    EXPECT_EQ(uf.find(3), 3);
    EXPECT_EQ(uf.find(4), 4);

    EXPECT_EQ(uf.numberOfSets(), 4);
}

TEST(UnionFindTest, SimpleMergeTest2)
{
    unionfind::UnionFind uf{5};

    uf.merge(0, 4);
    uf.merge(2, 3);

    EXPECT_EQ(uf.find(0), 4);
    EXPECT_EQ(uf.find(1), 1);
    EXPECT_EQ(uf.find(2), 3);
    EXPECT_EQ(uf.find(3), 3);
    EXPECT_EQ(uf.find(4), 4);

    EXPECT_EQ(uf.numberOfSets(), 3);
}

TEST(UnionFindTest, SimpleMergeTest3)
{
    unionfind::UnionFind uf{5};

    uf.merge(0, 4);
    uf.merge(2, 3);
    uf.merge(0, 1);

    EXPECT_EQ(uf.find(0), 4);
    EXPECT_EQ(uf.find(1), 4);
    EXPECT_EQ(uf.find(2), 3);
    EXPECT_EQ(uf.find(3), 3);
    EXPECT_EQ(uf.find(4), 4);

    EXPECT_EQ(uf.numberOfSets(), 2);
}

TEST(UnionFindTest, SimpleMergeTest4)
{
    unionfind::UnionFind uf{5};

    uf.merge(0, 4);
    uf.merge(2, 3);
    uf.merge(0, 1);
    uf.merge(3, 0);

    EXPECT_EQ(uf.find(0), 4);
    EXPECT_EQ(uf.find(1), 4);
    EXPECT_EQ(uf.find(2), 4);
    EXPECT_EQ(uf.find(3), 4);
    EXPECT_EQ(uf.find(4), 4);

    EXPECT_EQ(uf.numberOfSets(), 1);
}
