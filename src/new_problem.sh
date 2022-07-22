#!/usr/bin/env bash

prob_name=$1

cp -r template "${prob_name}" || exit 1
sed -i "s/CMAKE_TARGET_NAME/${prob_name}/g" "${prob_name}/CMakeLists.txt" || exit 1
echo "add_subdirectory(${prob_name})" >>CMakeLists.txt
