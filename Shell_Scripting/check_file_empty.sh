#!/bin/bash
echo "Enter filename:"
read file
if [ ! -s "$file" ]; then
    echo "File is empty."
else
    echo "File is not empty."
fi
