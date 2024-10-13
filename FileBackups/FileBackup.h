#ifndef FILEBACKUP_H
#define FILEBACKUP_H

#include <vector>
#include <ctime>
#include <string>
#include "BlockInfo.h"
using namespace std;

class FileBackup {
    // string filename;
    // time_t lastUpdated;
    // map<time_t, vector<string>> blocks;
public:
    string filename;
    time_t lastUpdated;
    map<time_t, vector<string>> blocks;

    FileBackup(const string &filename);
    static void deleteBlock(FileBackup* f, int blockIndex, time_t timestamp, const vector<string> &latestImage);
    static void updateNewImage(FileBackup* f, int blockIndex, time_t timestamp, const vector<string> &latestImage, const string &content);
    static void print(const vector<string> &block);
};

#endif // FILEBACKUP_H