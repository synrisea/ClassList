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


	// Overloading the operator(=) : 

	List& operator= (const List& otherList)
	{
		if (this != &otherList)
		{
			Clear();

			Node* currentNode = otherList.first;
			while (currentNode)
			{
				PushBack(currentNode->data);
				currentNode = currentNode->next;
			}
		}
		return *this;
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


	const T& Back() const
	{
		return last->data;
	}

	const T& Front() const
	{
		return first->data;
	}

	void PrintList() const
	{
		Node* currentNode = first;
		while (currentNode)
		{
			std::cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		std::cout << std::endl;
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
	std::vector<int> vec1{ 4,5,12,2 };
	std::vector<int> vec2{ 5,3,1,2 };

	List<int> myList1(vec1);
	List<int> myList2(vec2);

	myList2 = myList1;

	myList1.PopFront();
	myList1.PushBack(5);
	myList1.PopFront();
	myList1.PushBack(7);
	myList1.PopBack();
	myList1.PushBack(4);
	
	myList1.PrintList();

	std::cout << "\n";

	myList2.PrintList();

	return 0;
}
