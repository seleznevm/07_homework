#include <iostream>
#include "containerSeq.hpp"
#include <gtest/gtest.h>

TEST(ContainerSeq, PushBack)
{
    //Arrange
    ContainerSeq<int> cont;
    int expected_size = 10;
    //Act
    for(int i{0}; i < 10; i++)
        cont.push_back(i);
    //Assert
    EXPECT_EQ(cont.GetSize(), expected_size);
    for(int i = 0; i < 10; i++)
    {
        EXPECT_EQ(cont[i], i);
    }

}

TEST(ContainerSeq, PushFront)
{
    //Arrange
    ContainerSeq<int> cont;
    int expected_size = 10;
    //Act
    for(int i{9}; i >= 0; i--)
        cont.push_front(i);
    //Assert
    EXPECT_EQ(cont.GetSize(), expected_size);
    for(int i = 0; i < 10; i++)
    {
        EXPECT_EQ(cont[i], i);
    }
}

TEST(ContainerSeq, Insert)
{
    //Arrange
    ContainerSeq<int> cont;
    cont.push_back(0);
    cont.push_back(2);
    //Act
    cont.insert(1, 1);
    //Assert
    for(int i{0}; i < cont.GetSize(); i++)
    {
        EXPECT_EQ(cont[i], i);
    }
}

TEST(ContainerSeq, DeleteFromEnd)
{
    //Arrange
    ContainerSeq<int> cont;
    cont.push_back(0);
    cont.push_back(2);
    //Act
    cont.pop_back();
    //Assert
    for(int i{0}; i < cont.GetSize(); i++)
    {
        EXPECT_EQ(cont[i], i);
    }
}

TEST(ContainerSeq, DeleteFromBeginning)
{
    //Arrange
    ContainerSeq<int> cont;
    cont.push_back(0);
    cont.push_back(1);
    //Act
    cont.pop_front();
    //Assert
    EXPECT_EQ(cont[0], 1);
}

TEST(ContainerSeq, DeleteFromTheMiddle)
{
    //Arrange
    ContainerSeq<int> cont;
    cont.push_back(0);
    cont.push_back(1);
    cont.push_back(2);
    //Act
    cont.erase(1);
    //Assert   
    ASSERT_EQ(cont[0], 0);
    ASSERT_EQ(cont[1], 2);    
}

TEST(ContainerSeq, GetFromContainer)
{
    //Arrange
    ContainerSeq<int> cont;
    cont.push_back(0);
    cont.push_back(1);
    cont.push_back(2);
    int val;
    //Act
    val = cont[1];
    //Assert
    ASSERT_EQ(val, 1);
}

TEST(ContainerSeq, GetSizeOfContainer)
{
    //Arrange
    ContainerSeq<int> cont;
    for(size_t i = 0; i < 50; i++)
        cont.push_back(i);
    size_t size;
    //Act
    size = cont.GetSize();
    //Assert
    ASSERT_EQ(size, 50);
}

TEST(ContainerSeq, EraseAll)
{
    //Arrange
    ContainerSeq<int> cont;
    for(size_t i = 0; i < 50; i++)
        cont.push_back(i);
    //Act
    while (cont.GetSize() != 0)
    {
        int i{0};
        cont.erase(i);
        i++;
    }
    //Assert
    ASSERT_EQ(cont.GetSize(), 0);    
}

TEST(ContainerSeq, IteratorCheck)
{
    //Arrange
    ContainerSeq<int> cont;
    for(size_t i = 0; i < 50; i++)
        cont.push_back(i);
    //Act
    auto it = cont.end();
    //Assert
    ASSERT_EQ(*it, 49);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}