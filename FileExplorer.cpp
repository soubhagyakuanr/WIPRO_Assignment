#include "FileExplorer.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

namespace fs = std::filesystem;

void FileExplorer::listFiles(const std::string &path) {
    try {
        for (const auto &entry : fs::directory_iterator(path))
            std::cout << entry.path().filename().string() << std::endl;
    } catch (const fs::filesystem_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void FileExplorer::changeDirectory(const std::string &path) {
    if (chdir(path.c_str()) == 0)
        std::cout << "Changed directory to " << fs::current_path() << std::endl;
    else
        perror("chdir failed");
}

void FileExplorer::copyFile(const std::string &src, const std::string &dest) {
    try {
        fs::copy(src, dest, fs::copy_options::overwrite_existing);
        std::cout << "File copied successfully!\n";
    } catch (...) {
        std::cerr << "Copy failed.\n";
    }
}

void FileExplorer::moveFile(const std::string &src, const std::string &dest) {
    try {
        fs::rename(src, dest);
        std::cout << "File moved successfully!\n";
    } catch (...) {
        std::cerr << "Move failed.\n";
    }
}

void FileExplorer::deleteFile(const std::string &path) {
    try {
        fs::remove(path);
        std::cout << "File deleted successfully!\n";
    } catch (...) {
        std::cerr << "Delete failed.\n";
    }
}

void FileExplorer::createFile(const std::string &path) {
    std::ofstream file(path);
    if (file) {
        std::cout << "File created successfully!\n";
    } else {
        std::cerr << "Failed to create file.\n";
    }
}

void FileExplorer::searchFile(const std::string &path, const std::string &filename) {
    bool found = false;
    for (auto &p : fs::recursive_directory_iterator(path)) {
        if (p.path().filename() == filename) {
            std::cout << "Found: " << p.path() << std::endl;
            found = true;
        }
    }
    if (!found)
        std::cout << "File not found.\n";
}

void FileExplorer::showPermissions(const std::string &path) {
    struct stat info;
    if (stat(path.c_str(), &info) == 0)
        std::cout << "Permissions: " << std::oct << (info.st_mode & 0777) << std::endl;
    else
        perror("stat failed");
}

void FileExplorer::setPermissions(const std::string &path, const std::string &mode) {
    int perms = std::stoi(mode, nullptr, 8);
    if (chmod(path.c_str(), perms) == 0)
        std::cout << "Permissions updated successfully!\n";
    else
        perror("chmod failed");
}
