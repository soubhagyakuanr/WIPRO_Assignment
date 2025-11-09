#include "FileExplorer.h"
#include <iostream>
using namespace std;

int main() {
    FileExplorer fe;
    int choice;
    string path, src, dest, filename, mode;

    while (true) {
        cout << "\n=== File Explorer Menu ===\n";
        cout << "1. List files\n2. Change directory\n3. Copy file\n4. Move file\n";
        cout << "5. Delete file\n6. Create file\n7. Search file\n8. Show permissions\n9. Set permissions\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter path: "; cin >> path;
            fe.listFiles(path); break;
        case 2:
            cout << "Enter directory: "; cin >> path;
            fe.changeDirectory(path); break;
        case 3:
            cout << "Source file: "; cin >> src;
            cout << "Destination: "; cin >> dest;
            fe.copyFile(src, dest); break;
        case 4:
            cout << "Source file: "; cin >> src;
            cout << "Destination: "; cin >> dest;
            fe.moveFile(src, dest); break;
        case 5:
            cout << "Enter file to delete: "; cin >> path;
            fe.deleteFile(path); break;
        case 6:
            cout << "Enter file name to create: "; cin >> path;
            fe.createFile(path); break;
        case 7:
            cout << "Enter directory: "; cin >> path;
            cout << "Enter filename: "; cin >> filename;
            fe.searchFile(path, filename); break;
        case 8:
            cout << "Enter file path: "; cin >> path;
            fe.showPermissions(path); break;
        case 9:
            cout << "Enter file path: "; cin >> path;
            cout << "Enter new permissions (e.g., 755): "; cin >> mode;
            fe.setPermissions(path, mode); break;
        case 0:
            cout << "Exiting...\n"; return 0;
        default:
            cout << "Invalid option.\n";
        }
    }
}
