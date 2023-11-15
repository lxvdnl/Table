#include<iostream>
#include<string>
#include<fstream>
#include"../headers/TSortedTable.h"
#include"../headers/TUnsortedTable.h"
#include"../headers/TBalanceTree.h"
#include"../headers/THashTable.h"

int main() {
	setlocale(LC_ALL, "rus");
	std::string path = "../tableExamples/Table.txt";
	std::ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		std::cout << "Error open file" << std::endl;
		return 0;
	}
	short int input, inputUnsort, inputSort, inputTree , inputHash;
	bool flag = true, flagUnsort, flagSort, flagTree, flagSortSerch, flagHash;
	std::string tmpKey, tmp;
	int tmpData, MAX = 100;



	/*Reading data from a file and writing to tables*/
	TUnsortedTable UnsortedTable(MAX);
	TSortedTable SortedTable(MAX);
	TBalanceTree BalanceTree;
	THashTable HashTable(5);
	while (!fin.eof()) {
		tmpKey = "";
		tmp = "";
		fin >> tmpKey;
		fin >> tmp;
		tmpData = stoi(tmp);
		UnsortedTable.Push(tmpKey, tmpData);
		SortedTable.Push(tmpKey, tmpData);
		BalanceTree.Push(tmpKey, tmpData);
		HashTable.Push(tmpKey, tmpData);
	}

	 /*The main cycle with the implementation of working with tables*/
	while (flag) {
		flagUnsort = true; flagSort = true; flagTree = true; flagHash = true;
		std::cout << "1 unsorted table | 2 sorted table | 3 binary tree | 4 hash table | 0 end program: ";
		std::cin >> input;
		std::cout << std::endl;
		switch (input) {
		case 1:
			while (flagUnsort) {
				std::cout << "1 add object | 2 delete object | 3 check for table entry | 4 output current table | 0 exit to menu: ";
				std::cin >> inputUnsort;
				std::cout << std::endl;
				switch (inputUnsort) {
				case 1:
					std::cout << "Enter object name: ";
					std::cin >> tmpKey;
					std::cout << "Enter object value: ";
					std::cin >> tmpData;
					UnsortedTable.Push(tmpKey, tmpData);
					std::cout << "Number of operations: " << UnsortedTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 2:
					std::cout << "Enter object name: ";
					std::cin >> tmpKey;
					UnsortedTable.Del(tmpKey);
					std::cout << "Number of operations: " << UnsortedTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 3:
					std::cout << "Enter object name: ";
					std::cin >> tmpKey;
					tmpData = UnsortedTable.Search(tmpKey);
					if (tmpData == -1) {
						std::cout << "There is no object with this name in the table" << std::endl;
					}
					else {
						std::cout << "Object " << tmpKey << " found in the table under number " << tmpData + 1 << std::endl;
					}
					std::cout << "Number of operations: " << UnsortedTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 4:
					std::cout << UnsortedTable << std::endl;
					std::cout << std::endl;
					break;
				default:
					flagUnsort = false;
				}
			}
			break;
		case 2:
			while (flagSort) {
				std::cout << "1 add object | 2 delete object | 3 check for table entry | 4 output current table | 0 exit to menu: ";
				std::cin >> inputSort;
				std::cout << std::endl;
				switch (inputSort) {
				case 1:
					std::cout << "Enter object name: ";
					std::cin >> tmpKey;
					std::cout << "Enter object value: ";
					std::cin >> tmpData;
					SortedTable.Push(tmpKey, tmpData);
					std::cout << "Number of operations: " << SortedTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 2:
					std::cout << "Enter object name: ";
					std::cin >> tmpKey;
					SortedTable.Del(tmpKey);
					std::cout << "Number of operations: " << SortedTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 3:
					std::cout << "Enter object name: ";
					std::cin >> tmpKey;
					tmpData = SortedTable.Search(tmpKey, &flagSortSerch);
					if (!flagSortSerch) {
						std::cout << "There is no object with this name in the table" << std::endl;
					}
					else {
						std::cout << "Object " << tmpKey << " found in the table under number " << tmpData + 1 << std::endl;
					}
					std::cout << "Number of operations: " << SortedTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 4:
					std::cout << SortedTable << std::endl;
					std::cout << std::endl;
					break;
				default:
					flagSort = false;
				}
			}
			break;
		case 3:
			while (flagTree) {
				std::cout << "1 add object | 2 delete object | 3 output current table | 0 exit to menu: ";
				std::cin >> inputTree;
				std::cout << std::endl;
				switch (inputTree) {
				case 1:
					std::cout << "Enter object name: ";
					std::cin >> tmpKey;
					std::cout << "Enter object value: ";
					std::cin >> tmpData;
					BalanceTree.Push(tmpKey, tmpData);
					std::cout << "Number of operations: " << BalanceTree.GetCountOp();
					std::cout << std::endl;
					break;
				case 2:
					std::cout << "Enter object name: ";
					std::cin >> tmpKey;
					BalanceTree.Del(tmpKey);
					std::cout << "Number of operations: " << BalanceTree.GetCountOp();
					std::cout << std::endl;
					break;
				case 3:
					BalanceTree.Print();
					std::cout << std::endl;
					break;
				default:
					flagTree = false;
				}
			}
			break;
		case 4:
			while (flagHash) {
				std::cout << "1 add object | 2 delete object | 3 output current table | 0 exit to menu: ";
				std::cin >> inputHash;
				std::cout << std::endl;
				switch (inputHash) {
				case 1:
					std::cout << "Enter object name: ";
					std::cin >> tmpKey;
					std::cout << "Enter object value: ";
					std::cin >> tmpData;
					HashTable.Push(tmpKey, tmpData);
					std::cout << "Number of operations: " << HashTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 2:
					std::cout << "Enter object name: ";
					std::cin >> tmpKey;
					HashTable.Del(tmpKey);
					std::cout << "Number of operations: " << HashTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 3:
					HashTable.Print();
					std::cout << std::endl;
					break;
				default:
					flagHash = false;
				}
			}
			break;
		default:
			flag = false;
		}
	}

	fin.close();
	return 0;
}
