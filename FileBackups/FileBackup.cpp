#include "FileBackup.h"
#include <iostream>
using namespace std;

FileBackup::FileBackup(const string &filename) {
    this->filename = filename;
}

void FileBackup::deleteBlock(FileBackup* f, int blockIndex, const time_t timestamp, const vector<string> &latestImage) {
    f->blocks[timestamp] = latestImage;
    f->blocks[timestamp].erase(f->blocks[timestamp].begin() + blockIndex);
    f->lastUpdated = timestamp;
}

void FileBackup::updateNewImage(FileBackup* f, const int blockIndex, const time_t timestamp, const vector<string> &latestImage, const string &content) {
    f->blocks[timestamp] = latestImage;
    f->blocks[timestamp][blockIndex] = content;
    f->lastUpdated = timestamp;
}

void FileBackup::print(const vector<string> &block) {
    string content = "";
    for(const auto& block : block) {
        content += block;
    }
    int i = content.size() - 1;
    while (i >= 0 && content[i] == '0') {
        i--;
    }
    content = content.substr(0, i + 1);
    cout << content << '\n';
}