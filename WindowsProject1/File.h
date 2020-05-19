#pragma once

#include<fstream>
#include<string>

#define MAX_PATH 100

struct File {


	fstream file;

	bool Close() {
		file.close();
	}

	bool isFile(string fileName) {
		//converting string to char pointer.
		const char* fileNamePtr = fileName.c_str();

		file.open(fileNamePtr, ios_base::in);
		if (!file) return false;

		return true;
	}

	bool createFile(string fileName) {
		//converting string to char pointer.
		const char* fileNamePtr = fileName.c_str();

		file.open(fileNamePtr, ios_base::out);

		if (!file) return false;

		return true;
	}


	bool writeFile(string fileName, string text) {

		const char* fileNamePtr = fileName.c_str();

		fstream new_file;
		new_file.open(fileNamePtr, ios_base::out);

		if (!new_file) { cout << "file couldn't open." << endl;return ""; }
		string msg = (string)"New file created named " + fileName;
		cout << msg << endl;

		new_file << "this text has been generated from c++ programming language.\nAnd this is new the new line.\n\tThis is new line and tab space." << endl;
		new_file.close();

		return "";
	}

	string readFile(string fileName) {

		const char* fileNamePtr = fileName.c_str();
	
		

		fstream file;
		file.open("C:/Users/Subhan/Desktop/temp.txt", ios_base::in);

		string msg = "No such file exists named " + (string)fileName;
		if (!file) { cout << msg << endl;return "ERROR::NOT FOUND."; }

		string lineText;
		string wholeText;

		while (getline(file, lineText)) { wholeText += lineText + '\n'; }

		return wholeText;
	}


};


/*

int main(int argc, char* argv[]) {

	//createAndWriteFile((char*)"sample.txt");
	//cout<<readFile("sample.txt")<<endl;


	/*
	char *ptr = (char*)"abc";
	cout<<(&ptr)<<endl;
	int address = 0x22fe48;
	cout<<address<<endl;
	*/

/*

	File file;



	///if(file.isFile("sample.txt")) cout<<"true"<<endl;
	//else cout<<"false"<<endl;

	cout << file.readFile("C:/Users/Subhan/OneDrive/C++/fileHandling/sample.txt") << endl;

	file.Close();



	//system("sample.txt");

	return 0;
}




*/






/*
string writeFile(string fileName, string text) {

	const char* fileNamePtr = fileName.c_str();

	fstream new_file;
	new_file.open(fileNamePtr, ios_base::out);

	if(!new_file) {cout<<"file couldn't open."<<endl;return "";}
	string msg = (string)"New file created named "+fileName;
	cout<<msg<<endl;

	new_file<<"this text has been generated from c++ programming language.\nAnd this is new the new line.\n\tThis is new line and tab space."<<endl;
	new_file.close();

	return "";
}

*/
