#pragma once
#include"FileList.h"
#include<string>
#include<vector>

//struct FileInfo;

class FileListCreator {
public:
	virtual std::unique_ptr<FileList> FactoryMethod() const = 0;
	virtual ~FileListCreator() {};

	std::vector<FileInfo> filesInfo;

	void ListMaker(const std::string& path);
};

class FileListTXTCreator : public FileListCreator {
public:
	std::unique_ptr<FileList> FactoryMethod() const override;
};

class FileListCSVCreator : public FileListCreator {
public:
	std::unique_ptr<FileList> FactoryMethod() const override;
};

void collectInfo(const std::string& path, std::vector<FileInfo>& fInfos);