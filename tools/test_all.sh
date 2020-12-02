#!/bin/bash

set -e

#cd ./build/tests/
# export GTEST_COLOR=1 && ctest --extra-verbose

bin/library/tests/book_test
bin/visitor/tests/visitor_test

