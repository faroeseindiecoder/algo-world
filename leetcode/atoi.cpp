#include<iostream>
#include<climits>
#include<cassert>
using namespace std;

int myAtoi(string str) {
	long n = 0, i = 0;
	int sign = 1;
	while (str[i] == ' ') {
		i++;
	}
	if (str[i] == '-') {
		sign = -1;
		i++;
	} else if (str[i] == '+') {
		i++;
	}
	
	for (; i < str.length(); i++) {
		int digit = str[i] - '0';
		if (0 <= digit && digit <= 9) {
			n *= 10;
			n += digit;
			if (n < INT_MIN) {
				if (sign == 1) {
					return INT_MAX;
				}
				else {
					return INT_MIN;
				}
			}
			if (n > INT_MAX) {
				if (sign == 1) {
					return INT_MAX;
				} else {
					return INT_MIN;
				}
			}
		}
		else {
			break;
		}
	}
	
	return n * sign;
}

int main() {
	assert(myAtoi("18446744073709551618") == INT_MAX);
	assert(myAtoi("7877a889") == 7877);
	assert(myAtoi("-00078") == -78);
	assert(myAtoi("    -0001") == -1);
}
