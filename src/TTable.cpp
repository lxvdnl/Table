#include"../headers/TTable.h"

bool TTable::IsEmpty() {
	return cur_size == 0;
}

bool TTable::IsFull() {
	return cur_size == MAX;
}

std::ostream& operator <<(std::ostream& os, const TTable& Table) {
	for (int i = 0; i < Table.cur_size; i++) {
		os << i + 1 << "  " << Table.arr[i].key << " (" << Table.arr[i].data << ")" << std::endl;
	}
	return os;
}

int TTable::GetCountOp() {
	return count_op;
}