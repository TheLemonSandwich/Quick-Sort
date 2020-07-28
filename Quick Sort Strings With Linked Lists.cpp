#include <iostream>
#include <string>

using namespace std;

struct node
{
	string name;
	node* next;
	node* prev;
};

class QuickSort
{
public:
	bool Append();
	node* head, * tail;
	QuickSort()
	{
		head = tail = NULL;
		small = head;
		
	}
	void sort(node* n, node* tail);
	void display(node* head);
private:
	char i1, i2;
	node* small;
	string current;
};

void QuickSort::sort(node* head,node* tail)
{
	//	Taking Initials

	i1 = head->name.at(0);
	i2 = tail->name.at(0);
	
	if (head->name == "" || tail->name == "" || head == tail)
	{
		small = small->next;
		current = small->name;
		small->name = tail->name;
		tail->name = current;
		cout << "Displaying\n";
		display(this->head);
		return;
	}
	if (int(i2) > 64 && int(i2) < 91) // Checking if its a capital letter
	{
		cout << "i2 is capital\n";
		if (int(i1) > 64 && int(i1) < 91)
		{
			cout << "i1 is capital\n";
			if (int(i2) > int(i1))
			{
				cout << "i1 is small\n";
				small = small->next;
				if (small->name != "" || small->name != head->name)
				{
					current = small->name;
					small->name = head->name;
					head->name = current;

				}
			}
			else if (int(i2) <= int(i1))
			{
				cout << "i2 is small\n";
			}
			sort(head->next, tail);
			
		}
		else if (int(i1) > 96 && int(i1) < 123)
		{
			cout << "i1 is small letter\n";
			if (int(i2) + 32 > int(i1))
			{
				cout << "i1 is small\n";
				small = small->next;
				if (small->name != "" || small->name != head->name)
				{
					current = small->name;
					small->name = head->name;
					head->name = current;
					
				}
			}
			else if (int(i2) + 32 <= int(i1))
			{
				cout << "i2 is small\n";
			}
			sort(head->next, tail);
		}
	}
	else if (int(i2) > 96 && int(i2) < 123) // Checking if its a small letter
	{
		cout << "i2 is small letter\n";
		if (int(i1) > 64 && int(i1) < 91)
		{
			if (int(i2) - 32 > int(i1))
			{
				cout << "i1 is greater\n";
				small = small->next;
				if (small->name != "" || small->name != head->name)
				{
					current = small->name;
					small->name = head->name;
					head->name = current;

				}
			}
			else if (int(i2) - 32 <= int(i1))
			{
				cout << "i1 is smaller\n";
			}
			sort(head->next, tail);
		}
		else if (int(i1) > 96 && int(i1) < 123)
		{
			cout << "i1 is capital letter\n";
			if (int(i2) > int(i1))
			{
				cout << "i1 is greater\n";
				small = small->next;
				if (small->name != "" || small->name != head->name)
				{
					current = small->name;
					small->name = head->name;
					head->name = current;

				}
			}
			else if (int(i2) <= int(i1))
			{
				cout << "i2 is smaller\n";
			}
			sort(head->next, tail);
		}
	}
}
void QuickSort::display(node* head)
{
	if (head == NULL)
		return;
	cout << head->name << endl;
	display(head->next);

}
bool QuickSort::Append()
{
	node* n = new node;
	cout << ">>\t";
	getline(cin, n->name);
	if (n->name == "")
		return false;
	n->next = NULL;
	if (head == NULL)
	{
		head = n;
		tail = n;
		small = new node;
		head->prev = small;
		small->next = head;
		small->name = "";
		small->prev = NULL;
		cout << "head filled\n";
	}
	else
	{
		tail->next = n;
		n->prev = tail;
		tail = n;
		n->next = NULL;
		cout << "added in tail\n";
	}
	return true;
}

int main()
{
	QuickSort q;
	cout << "To Stop Adding Names, Press Enter In the Area.\n";
	while (q.Append());
	q.sort(q.head,q.tail);

}