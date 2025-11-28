#!/bin/bash

read -p "Enter a number: " num

if [ $num -ge -9 ] && [ $num -le 9 ];then
    echo "$num is a one digit number"
elif [ $num -ge -99 ] && [ $num -le 99 ];then
    echo "$num is a two digit number"
else
    echo "$num is a three (or more) digit number"
fi