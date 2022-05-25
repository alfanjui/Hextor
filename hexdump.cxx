#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <bitset>

using std::cout; using std::cin;
using std::string; using std::hex;
using std::stringstream; using std::endl;
using std::bitset;

int binary_hexdump()
{
	std::ifstream file;
	string filename;
	string binRep;

	cout << "Enter the file's name > "; cin >> filename;
	file.open(filename, std::ios::in);
	if (file.is_open()) {
		char chara[3];
		char tmpRep;
		while (!file.eof()) {
			for (int i = 0; i < 4; i++) {
				chara[i] = file.get();
				bitset<8>(chara[i]).to_string(); 
				printf("%0X", chara[i]);
			}
			cout << " ";
			//printf(chara);
		}
	}
	else {
		cout << "File couldn't be open or doesn't exist\n";
	}
	return EXIT_SUCCESS;
}

int main()
{
	int mode = 0;

	while (true)
	{
		 	 << "(1) Binary Hexadecimal Dump" << "\n"
		 	 << "Choose mode > "; cin >> mode;
		
		switch (mode) {
			case 1:
				binary_hexdump();
				break;

			default:
				cout << "Mode doesn't exist" << endl;
		}
	cout << "Exit with success!" << endl;
	return 0;
	}
}
