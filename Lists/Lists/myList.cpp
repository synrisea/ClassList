#include <iostream>

template <typename T>

class List
{
private:

	struct Node
	{
		T data;
		Node* prev;
		Node* next;
	};

	Node* first;
	Node* last;
};

int main()
{
	
	return 0;
}
