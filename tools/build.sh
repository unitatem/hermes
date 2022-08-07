#!/bin/bash

targets="//..."

if [ ! -z "$@" ]; then
  targets="$@"
fi

bazel build "$targets"

