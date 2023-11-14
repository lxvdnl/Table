#include"../headers/TUnsortedTable.h"

int TUnsortedTable::Search(std::string _key, bool* flag) {
	count_op = 0;
	for (int i = 0; i < cur_size; i++) {
		count_op++;
		if (arr[i].key == _key) return i;
	}
	return -1;
}

void TUnsortedTable::Push(std::string _key, int _data) {
	int indx;
	indx = Search(_key);
	if (indx >= 0) arr[indx].data += _data;
	else {
		arr[cur_size].data = _data;
		arr[cur_size].key = _key;
		cur_size++;
	}
}

void TUnsortedTable::Del(std::string _key) {
	int indx;
	indx = Search(_key);
	if (indx >= 0) {
		arr[indx] = arr[cur_size - 1];
		cur_size--;
	}
}