#!/usr/bin/env bash

rev=$(git rev-parse HEAD)
git archive -o libcul-$rev.zip HEAD


./build.sh

#binary release/debug static/dynamic
7z a -mx=9 libcul-bin-$rev.7z lib include
