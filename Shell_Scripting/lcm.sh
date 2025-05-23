#!/bin/bash
echo "Enter two numbers:"
read a b
x=$a
y=$b
# Find GCD
while [ $b -ne 0 ]
do
    temp=$b
    b=$((a % b))
    a=$temp
done
gcd=$a
lcm=$(( (x * y) / gcd ))
echo "LCM is $lcm"
