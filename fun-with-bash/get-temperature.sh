#!/usr/bin/env bash

TEMP_FILE=/sys/class/thermal/thermal_zone0/temp

# Reading raw temperature value
ORIGINAL_TEMP=$(cat "$TEMP_FILE")

# Convert to celsius
TEMP_C=$((ORIGINAL_TEMP / 1000))

echo "$TEMP_C °C"