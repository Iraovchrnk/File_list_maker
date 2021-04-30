#include"FileList.h"
#include"FileListCreator.h"
#include <iostream>
#include <string>

using namespace std;

void MakeFileList(FileListCreator& f, const string& path) {
	f.ListMaker(path);
}

int main() {
	cout << "Enter path to make list of files: ";
	string path;
	cin >> path;
	// to do : chek path existance;
	unique_ptr<FileListCreator> ft = make_unique<FileListTXTCreator>();
	unique_ptr<FileListCreator> fc = make_unique<FileListCSVCreator>();
	MakeFileList(*ft, path);
	MakeFileList(*fc, path);

	return 0;

}