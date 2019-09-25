#include <iostream>
#include <map>
#include <fstream>
#include <Windows.h>
#include <string>
#include <io.h>
#include <set>
#include <cctype>
#include <ctime>
using namespace std;

void initMapMono(map<char, double> &Letters, string buffer, set<char> Alphabet, int &LetterAmount) {
	char ch;
	for (int i = 0; i < buffer.length(); i++) {
		if (Alphabet.count(buffer[i])) {

			if (Letters.count(char(tolower(buffer[i])))) {
				Letters[char(tolower(buffer[i]))] += 1;
				LetterAmount++;
			}
			else {
				Letters.emplace(char(tolower(buffer[i])), 1);
				LetterAmount++;
			}
		}
		else continue;
	}
};
void ShowMap(map<char, double>& Letters, int LetterAmount) {
	for (auto it = Letters.cbegin(); it != Letters.cend(); it++) {
		cout << "[ " << (*it).first << " : " << (*it).second*100/LetterAmount << " ]\n";
	}
}
int Count(map<char, double>& Letters) {
	int Amount = 0;
	for (auto it = Letters.cbegin(); it != Letters.cend(); it++) {
		Amount += (*it).second;
	}
	return Amount;
}
int main(){ 
	unsigned int start_time = clock();
	setlocale(LC_ALL, "rus");
	//ifstream fin("D:\\������\\������������\\CP_LAB1\\Crime and Punishment.txt");
	ifstream fin;
	fin.open("D:\\������\\������������\\CP_LAB1\\Document.txt");
	int LetterAmount = 0;
	map<char, double> Letters;
	set<char> Trash{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z', ' ', '	', '\;', '\:', '[', ']', '{', '}', '\"', '\'', '/', '(', ')', '#', '�', '<', '�', 
		'>', '.', '&','1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '!', '?', ',',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	set<char> Alphabet = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
	 '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
	 '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
	 '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
	//Alphabet.insert(' ');
	if (fin.is_open()) {
		string buffer;
		while (fin.peek() != EOF){	//�������������, �� �� ��������� ����������� ������
			getline(fin, buffer);	//������ ����� ���������
			//cout << buffer << endl;	
			fin.seekg(fin.tellg());	// ����������� ������� �� ������� ��������� ����� ����� ������
			initMapMono(Letters, buffer, Alphabet, LetterAmount);
			buffer.clear();
		}
		
	}
	else {
		cout << "Error. File isn't opened" << endl;
	}
	ShowMap(Letters, LetterAmount);
	cout << "LetterAmount: " << LetterAmount << endl;
	cout << Count(Letters) << endl;
	unsigned int end_time = clock();
	double search_time = (end_time - start_time)/1000;
	cout << search_time << endl;
	system("pause");
}