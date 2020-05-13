#!/bin/bash

test_dir="./build/tests/"
for t in `ls $test_dir -1 | grep test`; do
    $test_dir$t
done
