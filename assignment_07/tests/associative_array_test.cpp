#include <gtest/gtest.h>
#include "AssociativeArray.hpp"
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

TEST(AssociativeArrayTest, InsertUpdateAndGet) {
    AssociativeArray<int, std::string> map;
    EXPECT_EQ(map.size(), 0);
    EXPECT_EQ(map.get(1), std::nullopt);
    EXPECT_FALSE(map.contains(1));

    map.set(1, "Apple");
    map.set(2, "Banana");
    EXPECT_EQ(map.size(), 2);
    EXPECT_TRUE(map.contains(1));
    EXPECT_EQ(map.get(1).value(), "Apple");

    map.set(1, "Orange");
    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(map.get(1).value(), "Orange");
    EXPECT_EQ(map.get(2).value(), "Banana");
}

TEST(AssociativeArrayTest, CollisionsAndRemoval) {
    AssociativeArray<int, int> map;
    map.set(1, 100);
    map.set(12, 200);
    map.set(23, 300);

    EXPECT_EQ(map.size(), 3);
    EXPECT_EQ(map.get(12).value(), 200);
    EXPECT_TRUE(map.remove(12));
    EXPECT_FALSE(map.contains(12));
    EXPECT_EQ(map.get(12), std::nullopt);
    EXPECT_EQ(map.get(1).value(), 100);
    EXPECT_EQ(map.get(23).value(), 300);
    EXPECT_FALSE(map.remove(12));
    EXPECT_EQ(map.size(), 2);

    map.set(12, 400);
    EXPECT_EQ(map.get(12).value(), 400);
    EXPECT_EQ(map.size(), 3);
}

TEST(AssociativeArrayTest, Rehashing) {
    AssociativeArray<int, int> map;
    for (int i = 0; i < 200; i++) {
        map.set(i, i * 10);
    }

    EXPECT_EQ(map.size(), 200);
    for (int i = 0; i < 200; i++) {
        ASSERT_TRUE(map.get(i).has_value());
        EXPECT_EQ(map.get(i).value(), i * 10);
    }
}

TEST(AssociativeArrayTest, KeyValuePairs) {
    AssociativeArray<int, std::string> map;
    map.set(3, "Cherry");
    map.set(1, "Apple");
    map.set(2, "Banana");

    auto result = map.keyValuePairs();
    std::sort(result.begin(), result.end());

    std::vector<std::pair<int, std::string>> expected = {
        {1, "Apple"}, {2, "Banana"}, {3, "Cherry"}
    };
    EXPECT_EQ(result, expected);
}

TEST(AssociativeArrayTest, StringKeys) {
    AssociativeArray<std::string, int> map;
    map.set("Apple", 10);
    map.set("Banana", 20);

    EXPECT_EQ(map.get("Apple").value(), 10);
    EXPECT_EQ(map.get("Banana").value(), 20);
    EXPECT_EQ(map.size(), 2);

    EXPECT_TRUE(map.remove("Apple"));
    EXPECT_FALSE(map.contains("Apple"));
    EXPECT_EQ(map.get("Apple"), std::nullopt);
    EXPECT_EQ(map.size(), 1);
}
