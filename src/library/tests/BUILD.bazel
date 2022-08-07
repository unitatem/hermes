cc_test(
    name = "book_test",
    srcs = ["book_test.cpp"],
    deps = [
        "//src/library:book",
        "//src/library/tests:page_mock",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "matcher_test",
    srcs = ["matcher_test.cpp"],
    deps = [
        "//src/library:book",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "page_mock",
    srcs = [
        "page_mock.cpp",
    ],
    hdrs = ["page_mock.hpp"],
    deps = [
        "//src/library:page",
        "@googletest//:gtest",
    ],
)

cc_library(
    name = "page_fake",
    srcs = [
        "page_fake.cpp",
    ],
    deps = [
        "//src/library:page",
        "@googletest//:gtest",
    ],
)
