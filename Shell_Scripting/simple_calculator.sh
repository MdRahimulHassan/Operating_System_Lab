#!/bin/bash
echo "Enter first number:"
read a
echo "Enter second number:"
read b
echo "Choose operation (+ - * /):"
read op
if [ "$op" = "+" ]; then
    echo "Result: $((a + b))"
elif [ "$op" = "-" ]; then
    echo "Result: $((a - b))"
elif [ "$op" = "*" ]; then
    echo "Result: $((a * b))"
elif [ "$op" = "/" ]; then
    if [ "$b" -eq 0 ]; then
        echo "Error: Division by zero"
    else
        echo "Result: $((a / b))"
    fi
else
    echo "Invalid operation"
fi
