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



	/*���������� ������ �� ����� � ������ � �������*/
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

	 /*�������� ���� � ����������� ������ � ���������*/
	while (flag) {
		flagUnsort = true; flagSort = true; flagTree = true; flagHash = true;
		std::cout << "1 ��������������� ������� | 2 ������������� ������� | 3 �������� ������ | 4 ��� ������� | 0 ���������� ���������: ";
		std::cin >> input;
		std::cout << std::endl;
		switch (input) {
		case 1:
			while (flagUnsort) {
				std::cout << "1 �������� ������ | 2 ������� ������ | 3 ��������� �� ������� ������ � ������� | 4 ����� ������� ������� | 0 ����� � ����: ";
				std::cin >> inputUnsort;
				std::cout << std::endl;
				switch (inputUnsort) {
				case 1:
					std::cout << "������� ��� �������: ";
					std::cin >> tmpKey;
					std::cout << "������� �������� �������: ";
					std::cin >> tmpData;
					UnsortedTable.Push(tmpKey, tmpData);
					std::cout << "���-�� ��������: " << UnsortedTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 2:
					std::cout << "������� ��� �������: ";
					std::cin >> tmpKey;
					UnsortedTable.Del(tmpKey);
					std::cout << "���-�� ��������: " << UnsortedTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 3:
					std::cout << "������� ��� �������: ";
					std::cin >> tmpKey;
					tmpData = UnsortedTable.Search(tmpKey);
					if (tmpData == -1) {
						std::cout << "������� � ����� ������ ��� � �������" << std::endl;
					}
					else {
						std::cout << "������ " << tmpKey << " ������ � ������� ��� ������� " << tmpData + 1 << std::endl;
					}
					std::cout << "���-�� ��������: " << UnsortedTable.GetCountOp();
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
				std::cout << "1 �������� ������ | 2 ������� ������ | 3 ��������� �� ������� ������ � ������� | 4 ����� ������� ������� | 0 ����� � ����: ";
				std::cin >> inputSort;
				std::cout << std::endl;
				switch (inputSort) {
				case 1:
					std::cout << "������� ��� �������: ";
					std::cin >> tmpKey;
					std::cout << "������� �������� �������: ";
					std::cin >> tmpData;
					SortedTable.Push(tmpKey, tmpData);
					std::cout << "���-�� ��������: " << SortedTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 2:
					std::cout << "������� ��� �������: ";
					std::cin >> tmpKey;
					SortedTable.Del(tmpKey);
					std::cout << "���-�� ��������: " << SortedTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 3:
					std::cout << "������� ��� �������: ";
					std::cin >> tmpKey;
					tmpData = SortedTable.Search(tmpKey, &flagSortSerch);
					if (!flagSortSerch) {
						std::cout << "������� � ����� ������ ��� � �������" << std::endl;
					}
					else {
						std::cout << "������ " << tmpKey << " ������ � ������� ��� ������� " << tmpData + 1 << std::endl;
					}
					std::cout << "���-�� ��������: " << SortedTable.GetCountOp();
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
				std::cout << "1 �������� ������ | 2 ������� ������ | 3 ����� ������� ������� | 0 ����� � ����: ";
				std::cin >> inputTree;
				std::cout << std::endl;
				switch (inputTree) {
				case 1:
					std::cout << "������� ��� �������: ";
					std::cin >> tmpKey;
					std::cout << "������� �������� �������: ";
					std::cin >> tmpData;
					BalanceTree.Push(tmpKey, tmpData);
					std::cout << "���-�� ��������: " << BalanceTree.GetCountOp();
					std::cout << std::endl;
					break;
				case 2:
					std::cout << "������� ��� �������: ";
					std::cin >> tmpKey;
					BalanceTree.Del(tmpKey);
					std::cout << "���-�� ��������: " << BalanceTree.GetCountOp();
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
				std::cout << "1 �������� ������ | 2 ������� ������ | 3 ����� ������� ������� | 0 ����� � ����: ";
				std::cin >> inputHash;
				std::cout << std::endl;
				switch (inputHash) {
				case 1:
					std::cout << "������� ��� �������: ";
					std::cin >> tmpKey;
					std::cout << "������� �������� �������: ";
					std::cin >> tmpData;
					HashTable.Push(tmpKey, tmpData);
					std::cout << "���-�� ��������: " << HashTable.GetCountOp();
					std::cout << std::endl;
					break;
				case 2:
					std::cout << "������� ��� �������: ";
					std::cin >> tmpKey;
					HashTable.Del(tmpKey);
					std::cout << "���-�� ��������: " << HashTable.GetCountOp();
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
