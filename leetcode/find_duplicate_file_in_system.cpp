#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;

vector<vector<string>> findDuplicate(vector<string>& paths) {
	vector<vector<string>> duplicatePaths;
	unordered_map<string, vector<string>> contentToFilePaths;

	for (int i = 0; i < paths.size(); i++) {
		string path = paths[i];
		istringstream iss(path);
		string token;
		getline(iss, token, ' ');
		string dirPath = token;
		while (getline(iss, token, ' ')) {
			size_t contentStart = token.find('(');
			string fileName = token.substr(0, contentStart);
			string content = token.substr(contentStart + 1);
			content.pop_back();
			string fullPath = dirPath + '/' + fileName;
			if (contentToFilePaths.find(content) == contentToFilePaths.end()) {
				vector<string> filePaths;
				filePaths.push_back(fullPath);
				contentToFilePaths[content] =  filePaths;
			} else {
				contentToFilePaths[content].push_back(fullPath);
			}
		}
	}

	for (auto &pair : contentToFilePaths) {
		if (pair.second.size() >= 2)
			duplicatePaths.push_back(pair.second);
	}

	return duplicatePaths;
}

int main() {
	vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
	vector<vector<string>> duplicatePaths = findDuplicate(paths);
	for (int i = 0; i < duplicatePaths.size(); i++) {
		vector<string> filePaths = duplicatePaths[i];
		for (int j = 0; j < filePaths.size(); j++) {
			cout << filePaths[j] << " ";
		}
		cout << endl;
	}
}
