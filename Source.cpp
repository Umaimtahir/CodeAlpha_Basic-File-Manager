#include<iostream>
#include<filesystem>
#include<fstream>
#include<string>
using namespace std;
namespace fs = std::filesystem;

void listFiles(const string& path) {
    try {
        for (const auto& entry : fs::directory_iterator(path))
            cout << entry.path() << endl;
    }
    catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void changeDirectory(string& path) {
    string newPath;
    cout << "Enter new directory path: ";
    getline(cin.ignore(), newPath);
    if (fs::exists(newPath) && fs::is_directory(newPath)) {
        path = newPath;
        cout << "Current directory changed to: " << path << endl;
    }
    else 
        cout << "Invalid directory!" << endl;
    
}

void viewFile(const string& path) {
    string fileName;
    cout << "Enter file name to view: ";
    cin >> fileName;

    ifstream file(path + "/" + fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "Error opening file!" << endl;
    }
}

void createDirectory(const string& path) {
    string dirName;
    cout << "Enter new directory name: ";
    cin >> dirName;

    if (fs::create_directory(path + "/" + dirName)) {
        cout << "Directory created successfully!" << endl;
    }
    else {
        cout << "Error creating directory!" << endl;
    }
}

void copyFile(const string& path) {
    string src, dest;
    cout << "Enter source file name: ";
    cin.ignore();  
    getline(cin, src);
    cout << "Enter destination file name: ";
    getline(cin, dest);

    try {
        fs::copy_file(path + "/" + src, path + "/" + dest, fs::copy_options::overwrite_existing);
        cout << "File copied successfully!" << endl;
    }
    catch (const filesystem::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

int main() {
    string currentPath = fs::current_path().string();
    int choice;

    do {
        cout << "\nFile Manager Menu:\n";
        cout << "1. List files\n";
        cout << "2. Change directory\n";
        cout << "3. View file contents\n";
        cout << "4. Create directory\n";
        cout << "5. Copy file\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        if (choice == 1) 
            listFiles(currentPath);
 
        else if (choice == 2) 
            changeDirectory(currentPath);
        
        else if (choice == 3) 
            viewFile(currentPath);
        
        else if (choice == 4) 
            createDirectory(currentPath);
        
        else if (choice == 5) 
            copyFile(currentPath);
        
        else if (choice == 6) 
            cout << "Exiting..." << endl;
        
        else 
            cout << "Invalid choice! Please select a valid option." << endl;
        
    } while (choice != 6);

}
