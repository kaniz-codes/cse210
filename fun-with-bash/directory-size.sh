#!/bin/bash

echo -n "Enter your directory: "
read -r x
du -sh "$x" # Shows total size of the directory in readable format
