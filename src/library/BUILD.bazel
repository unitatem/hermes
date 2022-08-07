cc_binary(
    name = "library",
    srcs = ["main.cpp"],
    deps = [":book"],
)

cc_library(
    name = "book",
    srcs = [
        "book.cpp",
        "book.hpp",
    ],
    visibility = [":__subpackages__"],
    deps = [":page"],
)

cc_library(
    name = "page",
    srcs = [
        "page.cpp",
    ],
    hdrs = ["page.hpp"],
    visibility = [":__subpackages__"],
)
