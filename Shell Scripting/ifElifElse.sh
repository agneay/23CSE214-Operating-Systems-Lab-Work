#!/bin/bash

if [ "${1,,}" == "agneay" ];then
    echo "You are my boss"
elif [ "${1,,}" == "help" ];then
    echo "Just Type in your username, duh!"
else
    echo "You are not my boss, just get Lost!"
fi