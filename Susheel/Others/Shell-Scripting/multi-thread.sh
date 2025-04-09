```
Method-1 : wait - &
```
#!/bin/bash

# List of files to process
files=("file1.txt" "file2.txt" "file3.txt")

# Function to process a file (simulating with sleep for simplicity)
process_file() {
    echo "Processing $1..."
    sleep 2  # Simulate work
    echo "Done with $1."
}

# Loop through files and process them in parallel
for file in "${files[@]}"; do
    process_file "$file" &  # Start each process in the background
done

# Wait for all background processes to complete
wait

echo "All files processed!"

```
Method-2 : xargs
```
#!/bin/bash

# File containing URLs (one per line)
urls=("http://example.com/file1" "http://example.com/file2" "http://example.com/file3")

# Function to download a URL (using curl or wget)
download_url() {
    echo "Downloading $1..."
    curl -O "$1"  # Download the file
    echo "Done with $1."
}

# Export the function so xargs can use it
export -f download_url

# Use xargs to execute in parallel (2 processes at a time)
printf "%s\n" "${urls[@]}" | xargs -n 1 -P 2 bash -c 'download_url "$@"' _

```
Method-3 : GNU parllel
```

#!/bin/bash

# List of files to compress
files=("file1.log" "file2.log" "file3.log")

# Export function for parallel
compress_file() {
    echo "Compressing $1..."
    gzip "$1"
    echo "Done compressing $1."
}

export -f compress_file

# Use GNU parallel
parallel compress_file ::: "${files[@]}"
