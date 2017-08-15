#include<iostream>
#include<vector>
#include<bitset>
#include<cassert> 

using namespace std;

bool validUtf8(vector<int>& data) {
	vector<string> binaryRepresentation;
	for (int i = 0; i < data.size(); i++) {
		binaryRepresentation.push_back(bitset<8>(data[i]).to_string());
	}
	
	for (int i = 0; i < binaryRepresentation.size(); i++) {
		string firstChar = binaryRepresentation[i];
		int nrOnes = 0, j = 0;
		if (firstChar[0] == '1') {
			nrOnes++;
			j++;
			while (firstChar[j] == '1') {
				nrOnes++;
				j++;
			}
		}
		if (nrOnes == 0) {
			continue;
		}
		
		if (nrOnes > 1 && nrOnes <= 4) {
			if (i + nrOnes - 1 <= binaryRepresentation.size() - 1) {
				for (int j = i + 1; j <= i + nrOnes - 1; j++) {
					if (!(binaryRepresentation[j].substr(0, 2) == "10")) {
						return false;
					} 
				}
				i += nrOnes - 1;
			} else {
				return false;
			}
		} else {
			return false;
		} 
	}
	return true;
}

int main() {
	vector<int> data = {235, 140, 4};
	assert(validUtf8(data) == false);
	data = {197, 130, 1};
	assert(validUtf8(data) == true);
	data = {255};
	assert(validUtf8(data) == false);
}
