#include <iostream>
#include <vector>

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

public:

	List() : first(nullptr), last(nullptr) {}

	List(std::vector<T>& v) : first(nullptr), last(nullptr)
	{
		for (auto i = v.rbegin(); i != v.rend(); i++)
		{
			PushBack(*i);
		}
	}


	bool isEmpty() const
	{
		return first == nullptr;
	}
};

int main()
{

	return 0;
}
