#!/bin/bash
echo "Enter two numbers:"
read a b
while [ $b -ne 0 ]
do
    temp=$b
    b=$((a % b))
    a=$temp
done
echo "GCD is $a"
