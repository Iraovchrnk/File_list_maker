#include "FileListCreator.h"
#include "FileList.h"
#include <iostream>
#include <Windows.h>
#include <filesystem>


namespace fs = std::experimental::filesystem;
using namespace std;


void FileListCreator::ListMaker(const string& path) {
	collectInfo(path, filesInfo);
	auto fileList = this->FactoryMethod();
	fileList->makeList(filesInfo);
}

unique_ptr<FileList> FileListTXTCreator::FactoryMethod() const {
	return make_unique<FileListTXT>();
}


unique_ptr<FileList> FileListCSVCreator::FactoryMethod() const {
	return make_unique<FileListCSV>();
}


void collectInfo(const string& path, vector<FileInfo>& fInfos) {
	try {
		for (auto & entry : fs::directory_iterator(path)) {
			if (!fs::is_regular_file(entry.path())) {
				continue;
			}
			FileInfo f;
			WIN32_FILE_ATTRIBUTE_DATA finf;

			if (!GetFileAttributesEx(entry.path().wstring().c_str(), GetFileExInfoStandard, &finf)) {
				throw(fs::filesystem_error("GetFileAttributesEx failed"));
			}
			if (finf.dwFileAttributes == INVALID_FILE_ATTRIBUTES) {
				throw(fs::filesystem_error("INVALID_FILE_ATTRIBUTES"));
			}

			SYSTEMTIME   time, time1;
			FileTimeToSystemTime(&finf.ftCreationTime, &time);
			FileTimeToSystemTime(&finf.ftLastWriteTime, &time1);

			string t = to_string(time.wDay) + "-" + to_string(time.wMonth) + " " + to_string(time.wHour) + ":" + to_string(time.wMinute);
			string t1 = to_string(time1.wDay) + "-" + to_string(time1.wMonth) + " " + to_string(time1.wHour) + ":" + to_string(time1.wMinute);

			f.fileName = entry.path().filename().string();
			f.crTime = t;
			f.modTime = t1;
			f.size = finf.nFileSizeLow;
			f.readonly = finf.dwFileAttributes & FILE_ATTRIBUTE_READONLY;
			fInfos.push_back(f);
		}
	}
	catch (fs::filesystem_error& ex) {
		cerr << ex.what();
		cout << "dsdsdsds";
	}
}

