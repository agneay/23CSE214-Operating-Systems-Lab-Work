#!/bin/bash

sum=0
for item in $(seq 1 $1);do
    (( sum+= item ))
done

echo "The sum of first $1 natural numbers is: $sum"