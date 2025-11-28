#!/bin/bash

case "${1,,}" in
    "agneay" | "administrator")
    echo "You are my Boss :)"
    ;;
    help)
    echo "Just, Type your username, duh!"
    ;;
    *)
    echo "You are not my boss"
    ;;
esac