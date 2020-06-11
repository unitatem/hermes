#!/bin/bash

test_dir="./bin/tests/"

status=0
for t in `ls $test_dir -1 | grep test`; do
    $test_dir$t
    (( status+=$? ))
done
exit $status
