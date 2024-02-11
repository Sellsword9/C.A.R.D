#!/bin/bash
file_size_bytes=$(stat -c "%s" "$file_path")
file_size_mb=$(echo "scale=2; $file_size_bytes / (1024 * 1024)" | bc)
echo "$file_size_mb MB."
