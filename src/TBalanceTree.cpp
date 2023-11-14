#include"../headers/TBalanceTree.h"

bool TBalanceTree::IsFull()
{
	try {
		TNode* tmp = new TNode("", 0);
		delete tmp;
	}
	catch (...) {
		return true;
	}
	return false;
}

bool TBalanceTree::IsEmpty()
{
	return pRoot == nullptr;
}

TBalanceTree::TNode* TBalanceTree:: Search(std::string _key, bool& isFound) {
	count_op = 1;
	if (IsEmpty()) return nullptr;
	if (pRoot->data.key == _key) { isFound = true; return pRoot; }
	else if ((pRoot->pLeft == nullptr) && (pRoot->data.key > _key) || (pRoot->pRight == nullptr) && (pRoot->data.key < _key)) { isFound = false; return pRoot; }
	TNode* tmp = pRoot;
	while (true) {
		if (tmp->data.key == _key) { isFound = true; return tmp; }
		else if ((tmp->pLeft == nullptr) && (tmp->data.key > _key) || (tmp->pRight == nullptr) && (tmp->data.key < _key)) { isFound = false; return tmp; }
		else if (tmp->data.key > _key) tmp = tmp->pLeft;
		else if (tmp->data.key < _key) tmp = tmp->pRight;
		count_op++;
	}
}

void TBalanceTree::Push(std::string _key, int _data) {
	bool isFound;
	TNode* tmp = Search(_key, isFound);
	TNode* node = new TNode(_key, _data);
	if (tmp == nullptr) pRoot = node;
	else if (isFound) {
		tmp->data.data += _data;
	}
	else {
		if (tmp->data.key > _key) tmp->pLeft = node;
		else if (tmp->data.key < _key) tmp->pRight = node;
	}
}

void TBalanceTree::Del(std::string _key) {
	bool isFound;
	TNode* tmp = Search(_key, isFound);
	if (!isFound) return;
	else {
		if ((tmp->pLeft == nullptr) && (tmp->pRight == nullptr)) {
			TNode* tmpPrev = GetPrevNode(tmp);
			if (tmpPrev == nullptr) pRoot = nullptr;
			else if (tmpPrev->data.key > tmp->data.key) tmpPrev->pLeft = nullptr;
			else if (tmpPrev->data.key < tmp->data.key) tmpPrev->pRight = nullptr;
			delete tmp;
		}
		else if (tmp->pLeft == nullptr) {
			TNode* tmpPrev = GetPrevNode(tmp);
			if (tmpPrev == nullptr) pRoot = tmp->pRight;
			else if (tmpPrev->data.key > tmp->data.key) tmpPrev->pLeft = tmp->pRight;
			else if (tmpPrev->data.key < tmp->data.key) tmpPrev->pRight = tmp->pRight;
			delete tmp;
		}
		else if (tmp->pRight == nullptr) {
			TNode* tmpPrev = GetPrevNode(tmp);
			if (tmpPrev == nullptr) pRoot = tmp->pLeft;
			else if (tmpPrev->data.key > tmp->data.key) tmpPrev->pLeft = tmp->pLeft;
			else if (tmpPrev->data.key < tmp->data.key) tmpPrev->pRight = tmp->pLeft;
			delete tmp;
		}
		else {
			TNode* tmpSheet = tmp;
			tmpSheet = tmpSheet->pLeft;
			while (tmpSheet->pRight != nullptr) tmpSheet = tmpSheet->pRight;
			TNode* tmpPrevSheet = GetPrevNode(tmpSheet);
			if (tmpPrevSheet == tmp) {
				TNode* tmpPrev = GetPrevNode(tmp);
				if (tmpPrev == nullptr) pRoot = tmpSheet;
				else if (tmpPrev->data.key > tmp->data.key) tmpPrev->pLeft = tmpSheet;
				else if (tmpPrev->data.key < tmp->data.key) tmpPrev->pRight = tmpSheet;
				tmpSheet->pRight = tmp->pRight;
				delete tmp;
				return;
			}
			tmpPrevSheet->pRight = tmpSheet->pLeft;
			TNode* tmpPrev = GetPrevNode(tmp);
			if (tmpPrev == nullptr) pRoot = tmpSheet;
			else if (tmpPrev->data.key > tmp->data.key) tmpPrev->pLeft = tmpSheet;
			else if (tmpPrev->data.key < tmp->data.key) tmpPrev->pRight = tmpSheet;
			if (tmp->pLeft != tmpSheet) tmpSheet->pLeft = tmp->pLeft;
			tmpSheet->pRight = tmp->pRight;
			delete tmp;
		}
	}
}

void TBalanceTree::PrintLTR(const TBalanceTree::TNode* _node) {
	if (_node == nullptr) return;
	PrintLTR(_node->pLeft);
	std::cout << _node->data.key << " (" << _node->data.data << ")" << std::endl;
	PrintLTR(_node->pRight);
}

void TBalanceTree::Print() {
	PrintLTR(pRoot);
}

TBalanceTree::TNode* TBalanceTree::GetPrevNode(const TBalanceTree::TNode* _node) {
	if (_node == pRoot) return nullptr;
	TNode* res = pRoot;
	while (true) {
		if ((res->pLeft == nullptr) && (res->data.key > _node->data.key) || (res->pRight == nullptr) && (res->data.key < _node->data.key)) return nullptr;
		if ((res->pLeft == _node) || (res->pRight == _node)) return res;
		else if (res->data.key > _node->data.key) res = res->pLeft;
		else if (res->data.key < _node->data.key) res = res->pRight;
	}
}