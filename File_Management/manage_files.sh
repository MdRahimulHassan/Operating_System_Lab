#!/bin/bash

filename="file.txt"
copyname="file_copy.txt"
movedname="file_moved.txt"

echo "This is a test file." > "$filename"
echo "File created: $filename"

cp "$filename" "$copyname"
echo "File copied to: $copyname"

mv "$copyname" "$movedname"
echo "File moved/renamed to: $movedname"

rm "$filename"
echo "Original file deleted: $filename"
