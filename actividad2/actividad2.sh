#!/bin/bash

# Variable to save the first param
GITHUB_USER=$1

# Concatenates the GITHUB_USER to query the URL
response=$(curl -s https://api.github.com/users/$GITHUB_USER)

# Extract information from JSON
# Install jq using: sudo apt-get install jq
user_id=$(echo $response | jq -r '.id')
created_at=$(echo $response | jq -r '.created_at')

# Print the message
message="Hello $GITHUB_USER. User ID: $user_id. Account was created at: $created_at."
echo $message

# Create the log file
date_log=$(date +%Y-%m-%d)
# echo $date_log
#log_dir="./tmp/$date_log"
log_dir="/tmp/$date_log"

mkdir -p $log_dir
echo $message >> "$log_dir/saludos.log"

# Cronjob used:
# */5 * * * * /home/luis/Escritorio/Semestre-2024/SegundoSemestre/SistemasOperativos/Actividades/actividad2/actividad2.sh LuisduPacheco