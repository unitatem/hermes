#!/bin/bash

set -e

bin/containers_benchmark/tests/vector_benchmark

cd ./build/tests/
export GTEST_COLOR=1 && ctest --extra-verbose
