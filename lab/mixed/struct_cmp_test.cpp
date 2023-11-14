#include <algorithm>
#include <iterator>
#include <ostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector) {
    os << "vector=[";
    std::copy(vector.begin(), vector.end() - 1,
              std::ostream_iterator<T>(os, ", "));
    if (!vector.empty()) os << *(vector.end() - 1);
    os << "]";
    return os;
}

struct Floor {
    int floor;
    std::vector<int> rooms;

    bool operator==(const Floor& rhs) const {
        return (floor == rhs.floor) && (rooms == rhs.rooms);
    }

    friend std::ostream& operator<<(std::ostream& os, const Floor& floor) {
        os << "Floor(floor=" << floor.floor << ", rooms=X" << floor.rooms
           << ")";
        return os;
    }
};

struct Section {
    std::string name;
    Floor floor;

    bool operator==(const Section& rhs) const {
        return (name == rhs.name) && (floor == rhs.floor);
    }

    friend std::ostream& operator<<(std::ostream& os, const Section& section) {
        os << "Section(name=" << section.name << ", floor=" << section.floor
           << ")";
        return os;
    }
};

struct Building {
    std::string name;
    Section section;

    bool operator==(const Building& rhs) const {
        return (name == rhs.name) && (section == rhs.section);
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    const Building& building) {
        os << "Building(name=" << building.name
           << ", section=" << building.section << ")";
        return os;
    }
};

TEST(StructCmpTest, DISABLED_good_weather) {
    // Given
    const Building a = {"B01", {"A", {0, {1, 2, 3, 4, 5}}}};
    const Building b = {"B01", {"B", {0, {1, 2, 3, 4, 6}}}};

    // Then
    EXPECT_EQ(a, b);
}
