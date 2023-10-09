#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;


void tobase64(string* input, vector <char>* base64list) {

	string base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int size = (input->size() * 8);
	int base64lenght = (int)(size / 6);
	int padding = size %3;

	vector <int>  all_byte_list;

	int counter = 0;
	bitset <6> temp;
	for (int i = 0; i < input->size(); i++) {
		bitset<8> byte_list = (input->c_str()[i]);

		for (int j = 7; j >= 0; j--) {

			temp.set( (5-counter), (int)(byte_list[j]));
			counter++;

			if (counter == 6) {
				base64list->push_back(base64Chars[int(temp.to_ulong())]);
				temp.reset();
				counter = 0;
			}
		}
	}
	if (counter) {

		base64list->push_back(base64Chars[int(temp.to_ulong())]);
		for (int i = 0; i < padding; i++) {
			base64list->push_back('=');
		}
	}
}

int main() {

	string* input = new string;

	while (true) {


		cout << "Enter text :" << endl;
		cin >> *input;

		if (*input == "exit") {
			break;
		}

		vector<char> output; 
		tobase64(input, &output);


		for (int i=0; i < output.size(); i++) {
			cout << output[i];
		}
		cout << endl << endl;

	}
	delete input;
	return 0;
}