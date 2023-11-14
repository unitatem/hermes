#include <iostream>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "lab/protobuf/person.pb.h"

TEST(CodecTest, encode_decode) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    Person in;
    in.set_name("Name");
    in.set_surname("Surname");
    std::cout << in.DebugString();

    std::string wire;
    in.SerializeToString(&wire);

    Person out;
    out.ParseFromString(wire);

    EXPECT_EQ(in.name(), out.name());
    EXPECT_EQ(in.surname(), out.surname());
}
