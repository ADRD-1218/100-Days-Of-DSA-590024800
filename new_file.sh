#!/bin/bash

echo "Enter day number:"
read day

filename="Day-$day.c"

touch "$filename"

echo "Created $filename"
