#!/bin/bash
echo -e "Executing Backup \"workspace\" directory..."


destination_folder="$HOME/Backup_Ihm/"
actual_date=`date`
actual_date=${actual_date// /-}

destination_folder="${destination_folder}${actual_date}"
mkdir -p -v "$destination_folder"
echo -e "Destination Folder: $destination_folder"

cp -r "workspace" "$destination_folder/workspace"
echo -e "...OK"
echo -e
