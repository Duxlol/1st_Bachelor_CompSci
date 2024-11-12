#!/bin/bash  
#variables from extract_tasks script
student_folder=$1
oplossingen_dir=$2
lastname=$3
firstname=$4

#for each script in the student folder, run and output python scripts to the correct directories
for script in "$student_folder"/*.py; do
        if [[ -f "$script" ]]; then
                scriptname=$(basename "$script" .py)
                output="${lastname}.${firstname}_${scriptname}_output.txt"
                errors="${lastname}.${firstname}_${scriptname}_error.txt"
                python3 "$script" > "${oplossingen_dir}/${output}" 2> "${oplossingen_dir}/${errors}"
        fi
done
