#!/bin/bash

#define two number to work with
a=10
b=3

echo "---- Working with Numbers: a=$a and b=$b -------"

# 1. Addition (+)
sum=$((a+b))
echo "Addition (a+b) $sum"

# 2. Subtraction (-)
diff=$((a-b))
echo "Difference (a-b): $diff"

# 3. Multiplication (*)
prod=$((a*b))
echo "Product (a*b): $prod"

# 4. Division (/)
div=$((a/b))
echo "Division  (a/b): $div"

# 5. Modulus/Reminder
rem=$((a%b))
echo "Modulus (a%b): $rem"

# 6. Exponentiation
pow=$((a**b))
echo "Exponentiation (a^b): $pow"

# 7. Increment
((a++))
echo "Incrementation (a++): Now a is $a"

# 8. Decrement
((b--))
echo "Decrement (b--): Now b is $b"