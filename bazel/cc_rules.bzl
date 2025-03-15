"""
"""

COMMON_CXXOPTS = [
    "-pedantic",
    "-Wuninitialized",
    "-Wshadow",
    "-Wnon-virtual-dtor",
    "-Wall",
    "-Wextra",
    "-Werror",
]

def hermes_cc_binary(**kwargs):
    native.cc_binary(
        cxxopts = COMMON_CXXOPTS,
        **kwargs
    )

def hermes_cc_library(**kwargs):
    native.cc_library(
        cxxopts = COMMON_CXXOPTS,
        **kwargs
    )

def hermes_cc_test(**kwargs):
    native.cc_test(
        cxxopts = COMMON_CXXOPTS,
        **kwargs
    )
