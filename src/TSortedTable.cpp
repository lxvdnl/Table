#include"../headers/TSortedTable.h"

int TSortedTable::Search(std::string _key, bool* flag) {
	int l = 0, r = cur_size - 1, mid = 0; count_op = 0;
	if (IsEmpty()) { count_op++; *flag = false; return 0; }
	do {
		count_op++;
		mid = (l + r) / 2;
		if (arr[mid].key == _key) { *flag = true;  return mid; }
		else if (arr[mid].key > _key) r = mid - 1;
		else l = mid + 1;
	}while (l <= r);
	*flag = false;
	return l;
}

void TSortedTable::Push(std::string _key, int _data) {
	bool flag;
	int indx = Search(_key, &flag);
	if (flag) arr[indx].data += _data;
	else {
		if (IsFull()) return;
		for (int i = cur_size; i >= indx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[indx].key = _key;
		arr[indx].data = _data;
		cur_size++;
	}
}

void TSortedTable::Del(std::string _key) {
	bool flag;
	int indx = Search(_key, &flag);
	if (flag) {
		for (int i = indx + 1; i < cur_size; i++) {
			arr[i - 1] = arr[i];
		}
		cur_size--;
	}
	else { std::cout << "There is no object with this key" << std::endl; return; }
}
