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

	// Constructors : 

	List() : first(nullptr), last(nullptr) {}

	List(std::vector<T>& v) : first(nullptr), last(nullptr)
	{
		for (auto i = v.begin(); i != v.end(); i++)
		{
			PushBack(*i);
		}
	}

	// Methods : 

	bool isEmpty() const
	{
		return first == nullptr;
	}


	void PushBack(const T& newElement)
	{
		Node* element = new Node;

		if (isEmpty())
		{
			element->next = nullptr;
			element->prev = nullptr;
			element->data = newElement;

			first = last = element;
		}
		else
		{
			element->next = nullptr;
			element->prev = last;
			element->data = newElement;

			last->next = element;

			last = element;
		}
	}


	void PopFront()
	{
		if (first != nullptr)
		{
			Node* element = first;

			first = first->next;

			if (first != nullptr)
			{
				first->prev = nullptr;
			}
			else
			{
				last = nullptr;  // If first was the only node, then we are updating last.
			}

			delete element;
		}
	}

	void PopBack()
	{
		if (last != nullptr)
		{
			Node* element = last;

			last = last->prev;

			if (last != nullptr)
			{
				last->next = nullptr;
			}
			else
			{
				first = nullptr;  // If last was the only node, then we are updating first.
			}

			delete element;
		}
	}


	void Clear()
	{
		while (first != nullptr)
		{
			PopBack();
		}
	}


	~List()
	{
		Clear();
	}
};

int main()
{

	return 0;
}
