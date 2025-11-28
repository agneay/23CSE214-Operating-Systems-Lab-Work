#!/bin/bash

# Start an infinite loop to display the menu repeatedly
while true
do
    # Clear the screen for a clean look (optional)
    clear

    echo " "
    echo -e "\t===== SYSTEM UTILITY MENU ====="
    echo -e "\t1. Show current user"
    echo -e "\t2. Display current date and time"
    echo -e "\t3. Show disk usage"
    echo -e "\t4. Show currently logged in users"
    echo -e "\t5. List files in current directory"
    echo -e "\t6. Exit"
    echo " "

    # Read the user input
    read -p "Enter your choice (1-6): " choice
    echo " "

    # Handle the choice using a case statement
    case $choice in
        1)
            echo "--- Current User ---"
            whoami
            ;;
        2)
            echo "--- Current Date and Time ---"
            date
            ;;
        3)
            echo "--- Disk Usage ---"
            df -h
            ;;
        4)
            echo "--- Logged In Users ---"
            who
            ;;
        5)
            echo "--- Files in Current Directory ---"
            ls -l
            ;;
        6)
            echo "Exiting... Goodbye!"
            exit 0
            ;;
        *)
            echo "Invalid option. Please enter a number between 1 and 6."
            ;;
    esac

    # Pause the script so the user can read the output
    echo " "
    read -p "Press Enter to continue..."
done