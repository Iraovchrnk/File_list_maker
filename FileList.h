#pragma once


#include<vector>
#include<string>
#include"FileInfo.h"

class FileList {
public:
	std::string outFileName;
	virtual void makeList(const std::vector<FileInfo>& fi) const = 0;

	virtual ~FileList() {}
};

class FileListTXT : public FileList {
public:
	FileListTXT();

	void makeList(const std::vector<FileInfo>& fi) const override;
};

class FileListCSV : public FileList {
public:
	FileListCSV();

	void makeList(const std::vector<FileInfo>& fi) const override;
};



