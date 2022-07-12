#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <bitset>

int hexdump(std::ifstream &file, std::string &filename)
{
	string binRep;

	//file.open(filename, std::ios::in);
	if (file.is_open()) {
		char chara[3];
		char tmpRep;
		while (!file.eof()) {
			for (int i = 0; i < 4; i++) {
				chara[i] = file.get();
				std::bitset<8>(chara[i]).to_string();
				printf("%0X", chara[i]);
			}
			cout << " ";
		}
	}
	else {
		cout << "File couldn't be open or doesn't exist\n";
	}
	return EXIT_SUCCESS;
}





//int main()
//{
//	int mode = 0;
//
//	while (true)
//	{
//		 	 cout << "(1) Binary Hexadecimal Dump" << "\n"
//				  << "Choose mode > "; cin >> mode;
//		switch (mode) {
//			case 1:
//				binary_hexdump();
//				break;
//
//			default:
//				cout << "Mode doesn't exist" << endl;
//		}
//	cout << "Exit with success!" << endl;
//	return 0;
//	}
//}
