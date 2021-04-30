#include "FileList.h"

#include <iostream>
#include <fstream>
#include <iomanip>



FileListTXT::FileListTXT() {
	outFileName = "fileList.txt";
}

void FileListTXT::makeList(const std::vector<FileInfo>& fi) const {
	using namespace std;
	try {
		ofstream outf(outFileName);
		outf << setiosflags(ios::left) << setw(30) << "File Name" << setw(10) << "Size" << setw(15) <<
			"Creation time" << setw(15) << "Last modified" << setw(15) << "Readonly";
		outf << endl;

		for (const FileInfo& f : fi) {
			outf << setw(30) << f.fileName << setw(10) << f.size << setw(15)
				<< f.crTime << setw(15) << f.modTime << setw(15) << f.readonly << "\n";
		}
		outf.close();
	}
	catch (const ifstream::failure& e) {
		cerr << e.what();
	}
}


FileListCSV::FileListCSV() {
	outFileName = "fileList.csv";
}

void FileListCSV::makeList(const std::vector<FileInfo>& fi) const {
	using namespace std;
	try {
		std::ofstream outf(outFileName);
		outf << "File Name,Size,Creation time,Last modified,Readonly\n";

		for (const FileInfo& f : fi) {
			outf << f.fileName << "," << f.size << ","
				<< f.crTime << "," << f.modTime << "," << f.readonly << "\n";
		}
		outf.close();
	}
	catch (const ifstream::failure& e) {
		cerr << e.what();
	}
}

