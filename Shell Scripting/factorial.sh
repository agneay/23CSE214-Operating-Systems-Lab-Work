#!/bin/bash

read -p "Enter a number: " num
fact=1
while [ $num -ge 0 ];do
    ((fact = fact*$num))
    ((num--))
done

echo "The factorial of $num is $fact"