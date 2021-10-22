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

    EXPECT_EQ(uf.find(0), 0);
    EXPECT_EQ(uf.find(1), 1);
    EXPECT_EQ(uf.find(2), 2);
    EXPECT_EQ(uf.find(3), 3);
    EXPECT_EQ(uf.find(4), 0);

    EXPECT_EQ(uf.numberOfSets(), 4);
}

TEST(UnionFindTest, SimpleMergeTest2)
{
    unionfind::UnionFind uf{5};

    uf.merge(0, 4);
    uf.merge(2, 3);

    EXPECT_EQ(uf.find(0), 0);
    EXPECT_EQ(uf.find(1), 1);
    EXPECT_EQ(uf.find(2), 2);
    EXPECT_EQ(uf.find(3), 2);
    EXPECT_EQ(uf.find(4), 0);

    EXPECT_EQ(uf.numberOfSets(), 3);
}

TEST(UnionFindTest, SimpleMergeTest3)
{
    unionfind::UnionFind uf{5};

    uf.merge(0, 4);
    uf.merge(2, 3);
    uf.merge(0, 1);

    EXPECT_EQ(uf.find(0), 0);
    EXPECT_EQ(uf.find(1), 0);
    EXPECT_EQ(uf.find(2), 2);
    EXPECT_EQ(uf.find(3), 2);
    EXPECT_EQ(uf.find(4), 0);

    EXPECT_EQ(uf.numberOfSets(), 2);
}

TEST(UnionFindTest, SimpleMergeTest4)
{
    unionfind::UnionFind uf{5};

    uf.merge(0, 4);
    uf.merge(2, 3);
    uf.merge(0, 1);
    uf.merge(3, 0);

    EXPECT_EQ(uf.find(0), 0);
    EXPECT_EQ(uf.find(1), 0);
    EXPECT_EQ(uf.find(2), 0);
    EXPECT_EQ(uf.find(3), 0);
    EXPECT_EQ(uf.find(4), 0);

    EXPECT_EQ(uf.numberOfSets(), 1);
}

TEST(UnionFindTest, NumberOfSetsTest)
{
    unionfind::UnionFind uf{5};

    uf.merge(0, 4);
    uf.merge(2, 3);
    uf.merge(0, 1);
    uf.merge(3, 0);

    EXPECT_EQ(uf.find(0), 0);
    EXPECT_EQ(uf.find(1), 0);
    EXPECT_EQ(uf.find(2), 0);
    EXPECT_EQ(uf.find(3), 0);
    EXPECT_EQ(uf.find(4), 0);

    EXPECT_EQ(uf.numberOfSets(), 1);
    uf.merge(0, 3);
    EXPECT_EQ(uf.numberOfSets(), 1);
    uf.merge(1, 3);
    EXPECT_EQ(uf.numberOfSets(), 1);
    uf.merge(3, 4);
    EXPECT_EQ(uf.numberOfSets(), 1);
}

TEST(UnionFindTest, SizeOfSetsTest)
{
    unionfind::UnionFind uf{10};

    uf.merge(0, 4);
    uf.merge(0, 2);
    uf.merge(0, 1);

    EXPECT_EQ(uf.sizeOfSetContaining(0), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(1), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(2), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(3), 1);
    EXPECT_EQ(uf.sizeOfSetContaining(4), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(5), 1);
    EXPECT_EQ(uf.sizeOfSetContaining(6), 1);
    EXPECT_EQ(uf.sizeOfSetContaining(7), 1);
    EXPECT_EQ(uf.sizeOfSetContaining(8), 1);
    EXPECT_EQ(uf.sizeOfSetContaining(9), 1);

    uf.merge(3, 6);
    uf.merge(5, 7);

    EXPECT_EQ(uf.sizeOfSetContaining(0), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(1), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(2), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(3), 2);
    EXPECT_EQ(uf.sizeOfSetContaining(4), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(5), 2);
    EXPECT_EQ(uf.sizeOfSetContaining(6), 2);
    EXPECT_EQ(uf.sizeOfSetContaining(7), 2);
    EXPECT_EQ(uf.sizeOfSetContaining(8), 1);
    EXPECT_EQ(uf.sizeOfSetContaining(9), 1);


    uf.merge(3, 8);

    EXPECT_EQ(uf.sizeOfSetContaining(0), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(1), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(2), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(3), 3);
    EXPECT_EQ(uf.sizeOfSetContaining(4), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(5), 2);
    EXPECT_EQ(uf.sizeOfSetContaining(6), 3);
    EXPECT_EQ(uf.sizeOfSetContaining(7), 2);
    EXPECT_EQ(uf.sizeOfSetContaining(8), 3);
    EXPECT_EQ(uf.sizeOfSetContaining(9), 1);

    uf.merge(3, 5);

    EXPECT_EQ(uf.sizeOfSetContaining(0), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(1), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(2), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(3), 5);
    EXPECT_EQ(uf.sizeOfSetContaining(4), 4);
    EXPECT_EQ(uf.sizeOfSetContaining(5), 5);
    EXPECT_EQ(uf.sizeOfSetContaining(6), 5);
    EXPECT_EQ(uf.sizeOfSetContaining(7), 5);
    EXPECT_EQ(uf.sizeOfSetContaining(8), 5);
    EXPECT_EQ(uf.sizeOfSetContaining(9), 1);

    uf.merge(3, 0);

    EXPECT_EQ(uf.sizeOfSetContaining(0), 9);
    EXPECT_EQ(uf.sizeOfSetContaining(1), 9);
    EXPECT_EQ(uf.sizeOfSetContaining(2), 9);
    EXPECT_EQ(uf.sizeOfSetContaining(3), 9);
    EXPECT_EQ(uf.sizeOfSetContaining(4), 9);
    EXPECT_EQ(uf.sizeOfSetContaining(5), 9);
    EXPECT_EQ(uf.sizeOfSetContaining(6), 9);
    EXPECT_EQ(uf.sizeOfSetContaining(7), 9);
    EXPECT_EQ(uf.sizeOfSetContaining(8), 9);
    EXPECT_EQ(uf.sizeOfSetContaining(9), 1);
}
