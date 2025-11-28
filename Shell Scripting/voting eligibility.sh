#!/bin/bash

echo "Enter your age: "
read AGE
if [ $AGE -ge 18 ];then
    echo "Eligible to vote"
else
    echo "Not Eligible to vote"
fi