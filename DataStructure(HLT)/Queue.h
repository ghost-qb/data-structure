#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;

template <class Type>
class QueueNode: protected ListNode<Type> //derived class to implement Queue
{
public:
	void enqueue(Type a) // function to add node at the end of the list
	{
		this->appendNode(a);
	}
	void dequeue() // function to remove node from the beginning of the list
	{
		this->deleteFirst();
	}
	int itemTots() // function to check if the queue is empty and output the # of items
	{
		this->getCount();
	}

	void destroyQueue() // function to remove all items from queue
	{
		this->emptyList();
	}

	void queueFirst();
	void queueLast();
	void displayQueue();
};
#endif


/* displayQueue Function
This function will display all the items in the queue*/
template <class Type>
void QueueNode<Type>::displayQueue()
{

	Node<Type> *nodePtr;
	nodePtr = headNode.getNextPtr();

	if (this->getCount() == 0) {
		cout << "count: " << this->getCount() << endl;
		cout << "Queue is empty." << endl;
	}

	else {

		cout << "count: " << this->getCount() << endl;
		while (nodePtr)
		{
			cout << "|[" << nodePtr->getValue() << "]| --> ";
			nodePtr = nodePtr->getNextPtr();
		}

		cout << "|[NULL]|" << endl << "______" << endl << endl;
	}


}

/*This function will output the first item of the Queue*/
template <class Type>
void QueueNode<Type>::queueFirst()
{
	Node<Type> *nodePtr;
	nodePtr = headNode.getNextPtr();
	cout << nodePtr->getValue();
}


/*This function will output the last item of the Queue*/
template<class Type>
void QueueNode<Type>::queueLast()
{
	Node<Type> *nodePtr;
	nodePtr = headNode.getRearPtr();
	cout << nodePtr->getValue();

}

#pragma once
