#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using std::cout; using std::cin;
using std::string; using std::hex;
using std::stringstream; using std::endl;


//void hexdump()
//{
//	char repTmp;
//	char buffer[MAXBUFLEN]
//
//	while (buffer > 0){
//		std::get(
//		printf("> %08X\n", buffer);
//		
//		if (!isprint(buffer)){
//			repTmp = '.';
//		} else{
//			repTmp = *hTmp;
//		}
//		printf(repTmp);
//}

int ascii_hexdump()
{
	std::ifstream file;
	string filename;
	
	cout << "Enter the file's name > "; cin >> filename;
	file.open(filename, std::ios::in);
	if (file.is_open()) {
		char chara[3];
		while (!file.eof()) {
			for (int i = 0; i < 4; i++) {
				chara[i] = file.get();
				printf("%0X", chara[i]);
			}
			cout << " ";
			//printf(chara);
		}
	}
	else {
		cout << "File couldn't be open or doesn't exist\n";
	}
	return 0;
}

int binary_hexdump()
{
	cout << "modes work!";
//	std::ifstream file;
//	string filename;
//		
//	std::getline(cin, filename);
//	file.open(filename, std::ios::binary);
//	if (file.is_open()) {
//		char tmpRep;
//		while (!file.eof()) {
//			for (int i = 0; i < 4; i++) {
//				chara[i] = file.get();
//				printf("%0lX", chara[i]);
//			}
//			cout << " ";
//			//printf(chara);
//		}
//	}
//	else {
//		cout << "File couldn't be open or doesn't exist\n";
//	}
	return 0;
}

int main()
{
	int mode = 0;

	while (true)
	{
		cout << "(0) ASCII Hexadecimal Dump" <<	"\n"
		 	 << "(1) Binary Hexadecimal Dump" << "\n"
		 	 << "Choose mode > "; cin >> mode;
		
		switch (mode) {
			case 0:
				ascii_hexdump();
				break;

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
