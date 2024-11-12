#!/bin/bash
set -x
archive=$1 #gets the tgz archive as first argument
extension=$2 #gets extension as 2nd argument, puts * if none is given as failsafe

file=$(basename "$archive" .tgz)
file_date=$(echo "$file" | cut -d'_' -f5 | sed 's/\.tgz$//') #extract deadline

#get subject and title out of title, while also replacing ' ' with '_'
subject=$(echo "$file" | cut -d'_' -f3 | sed 's/ /_/g')
task_title=$(echo "$file" | cut -d'_' -f4 | sed 's/ /_/g')
rmdir "$subject/$task_title/$file"

#creates directory tree and extracts files to correct location
mkdir -p "$subject/$task_title"
tar -xzf "$archive" --strip-components=1 -C "$subject/$task_title"



#for each studentarchive in the task, create folder with their name and extract into said folder
for studentfile in "$subject/$task_title"/*; do
	upload_date=$(basename "$studentfile" | cut -d'_' -f4 | sed 's/\.tgz$//') #extract student upload date
	name=$(basename "$studentfile" | cut -d'_' -f2)
        firstname=$(echo "$name" | cut -d'.' -f1 | sed 's/ //g')
        lastname=$(echo "$name" | cut -d'.' -f2 | sed 's/ //g')
	mkdir -p "$subject/$task_title/$lastname.$firstname"
	if [[ "$upload_date" > "$file_date" ]]; then #logic when deadline exceeded, create late_inzending file
		touch "$subject/$task_title/$lastname.$firstname/late_inzending"
	fi
        
        tar -xzf "$studentfile" --strip-components=1 -C "$subject/$task_title/$lastname.$firstname"
	rm "$studentfile"

	#find "$subject/$task_title/$lastname.$firstname" -type f -name "*$extension" -exec mv {} "$subject/$task_title/$lastname.$firstname" \;
	#find "$subject/$task_title/$lastname.$firstname" -type f ! -name "*$extension" -delete
	#find "$subject/$task_title/$lastname.$firstname" -type d -empty -delete
done
