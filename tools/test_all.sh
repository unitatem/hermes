#!/bin/bash

test_dir="./bin/tests/"
for t in `ls $test_dir -1 | grep test`; do
    $test_dir$t
done
