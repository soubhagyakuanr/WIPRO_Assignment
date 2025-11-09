#ifndef FILE_EXPLORER_H
#define FILE_EXPLORER_H

#include <string>
#include <vector>

class FileExplorer {
public:
    void listFiles(const std::string &path);
    void changeDirectory(const std::string &path);
    void copyFile(const std::string &src, const std::string &dest);
    void moveFile(const std::string &src, const std::string &dest);
    void deleteFile(const std::string &path);
    void createFile(const std::string &path);
    void searchFile(const std::string &path, const std::string &filename);
    void showPermissions(const std::string &path);
    void setPermissions(const std::string &path, const std::string &mode);
};

#endif
