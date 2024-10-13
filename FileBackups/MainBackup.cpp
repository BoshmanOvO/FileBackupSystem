#include<iostream>
#include <map>
#include <ctime>
#include <string>
#include <vector>
#include "MainBackup.h"


void MainBackup::fullBackup(const time_t timestamp, const string &filename, const string &content) {
    vector<string> block;
    for (int i = 0; i < content.size(); i += 8) {
        string b = content.substr(i, 8);
        if (b.size() < 8) {
            b.append(8 - b.size(), '0');
        }
        block.push_back(b);
    }
    if(globalBackup.find(filename) != globalBackup.end()) {
        FileBackup *f = globalBackup[filename];
        f->blocks[timestamp] = block;
        f->lastUpdated = timestamp;
    }
    else {
        auto *f = new FileBackup(filename);
        f->blocks[timestamp] = block;
        f->lastUpdated = timestamp;
        globalBackup[filename] = f;
    }
}

void MainBackup::incrementalBackup(time_t timestamp, const string &filename, const BlockInfo *blockInfo) {
    MainBackup mb = *this;
    if (globalBackup.find(filename) != globalBackup.end()) {
        FileBackup *f = mb.getGlobalBackup()[filename];
        if(blockInfo->operationType == 0) {
            time_t lastUpdated = f->lastUpdated;
            vector<string> latestImage = f->blocks[lastUpdated];
            int blockIndex = blockInfo->blockNumber;
            string content = blockInfo->content;
            f->updateNewImage(f, blockIndex, timestamp, latestImage, content);
        }
        else {
            time_t lastUpdated = f->lastUpdated;
            vector<string> latestImage = f->blocks[lastUpdated];
            auto blockIndex = blockInfo->blockNumber;
            f->deleteBlock(f, blockIndex, timestamp, latestImage);
        }
    }
    else {
        cout << "File not found" << '\n';
    }
}

void MainBackup::readFile(time_t timestamp, const string &filename) {
    MainBackup mb = *this;
    if(globalBackup.find(filename) != globalBackup.end()) {
        FileBackup *f = mb.getGlobalBackup()[filename];
        if (f->blocks.find(timestamp) == f->blocks.end()) {
            const auto index = --f->blocks.lower_bound(timestamp);
            f->print(index->second);
        }
        else {
            f->print(f->blocks[timestamp]);
        }
    }
    else {
        cout << "File not found" << '\n';
    }
}