# CodeAlpha_Basic-File-Manager

📄 Overview
The Basic File Manager is a simple, menu-driven command-line tool written in C++. It provides basic file management functionalities like listing files, changing directories, viewing file contents, creating directories, and copying files. This project leverages the C++ <filesystem> library for directory and file operations.

✨ Features
List Files: Display all files and directories in the current directory.
Change Directory: Change the working directory to a specified path.
View File Contents: Read and display the contents of a specified file.
Create Directory: Create a new directory within the current path.
Copy File: Copy a file to a specified destination within the current path.
Error Handling: Manages invalid inputs and file system errors gracefully.

📋 Requirements
C++17 or later: This project uses the C++ <filesystem> library, available from C++17 onwards.
C++ Compiler: Ensure your compiler supports C++17 or later.
Standard Library Headers: Includes <iostream>, <filesystem>, <fstream>, and <string>.
🚀 Getting Started
Clone or download the repository.
Compile the program using a C++ compiler with C++17 support:
g++ -std=c++17 -o file_manager file_manager.cpp
./file_manager


🛠️ Usage
Upon running, the program presents a menu with options to perform various file operations:

List Files: Lists all files and directories in the current working directory.
Change Directory: Prompts for a new directory path and switches to it if valid.
View File Contents: Asks for a file name and displays its contents.
Create Directory: Prompts for a new directory name and creates it in the current path.
Copy File: Asks for a source and destination file name. The copyFile function uses getline for input to handle spaces in file names.
Exit: Exits the program.

📂 Code Structure
listFiles: Lists all files and directories in the current path.
changeDirectory: Changes the working directory to a user-specified path.
viewFile: Reads and displays the contents of a file.
createDirectory: Creates a new directory at the current path.
copyFile: Copies a specified file to a new destination using getline for input to support spaces.
Error Handling: Checks for invalid paths and non-existent files, displaying appropriate error messages.

🔍 Notes
Ensure you have permission to create directories and copy files in the working directory.
The copyFile function uses getline to read input, allowing for file names with spaces.

📜 License
This project is open-source and free to use. No specific license is applied.
