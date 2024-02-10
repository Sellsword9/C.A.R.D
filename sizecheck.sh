#!/bin/bash
if [ $# -ne 1 ]; then
  echo "Usage: $0 <file>"
  exit 1
fi
file_path="$1"
if [ ! -f "$file_path" ]; then
  echo "Error: File '$file_path' not found."
  exit 1
fi
file_size_bytes=$(stat -c "%s" "$file_path")
file_size_mb=$(echo "scale=2; $file_size_bytes / (1024 * 1024)" | bc)

echo "$file_size_mb MB."
