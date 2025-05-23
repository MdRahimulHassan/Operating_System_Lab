#!/bin/bash
echo "Enter filename:"
read file
if [ -f "$file" ]; then
    wc -w "$file"
else
    echo "File not found!"
fi
