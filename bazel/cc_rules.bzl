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

def hermes_cc_binary(cxxopts = [], **kwargs):
    native.cc_binary(
        cxxopts = COMMON_CXXOPTS + cxxopts,
        **kwargs
    )

def hermes_cc_library(cxxopts = [], **kwargs):
    native.cc_library(
        cxxopts = COMMON_CXXOPTS + cxxopts,
        **kwargs
    )

def hermes_cc_test(cxxopts = [], **kwargs):
    native.cc_test(
        cxxopts = COMMON_CXXOPTS + cxxopts,
        **kwargs
    )
