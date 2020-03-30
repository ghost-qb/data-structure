#include "Node.h"
#ifndef LIST_H
#define LIST_H

template <class Type>
class ListNode
{
protected:
	HeadNode<Type> headNode;

public:

	int getCount()
	{
		return headNode.getCount();
	}

	void displayList();
	void appendNode(Type data);
	void insertNodeByValue(Type data);
	void insertFirst(Type data);
	void deleteNode(Type data);
	void deleteFirst();
	void emptyList();

};

template <class Type>
class StackNode : protected ListNode <Type>
{

public:
	void push(Type d)
	{
		this->insertFirst(d);
	}
	void pop()
	{
		this->deleteFirst();
	}

	void destroyStack()
	{
		this->emptyList();
	}

	Type topStack();

	void displayStack();
	

};
#endif

/*	DisplayList Function Definition
This function traverse thru the list and display the node data*/
template <class Type>
void ListNode<Type>::displayList()
{
	Node<Type> *nodePtr;

	nodePtr = headNode.getNextPtr();

	if (getCount() == 0) // check if the list is empty to print only the head node
	{

		cout << "[count: " << getCount() << ";rear pointer: null" << "]-->null";
	}
	else //if the list is not empty print every node
	{

		cout << "[count: " << getCount() << ";rear pointer: " << headNode.getRearPtrData() << "]-->";
		while (nodePtr) // while nodePtr is not nullptr travers the list and print out the nodes 
		{
			cout << "[" << nodePtr->getValue() << "]-->";

			nodePtr = nodePtr->getNextPtr(); // set the nodePtr to point to the next node. 
		}
		cout << "null";
	}

	cout << endl << endl;

}

/*	AppendNode Function Definition
This function will take the data same type as the node
and add the new node at the end of the list*/
template <class Type>
void ListNode<Type>::appendNode(Type data)
{

	Node<Type> *newNode;
	Node<Type> *nodePtr;


	newNode = new Node < Type >;
	nodePtr = new Node < Type >;

	if (getCount() == 0) // check if the list is empty, if the list is empty append as the first node 
	{

		newNode->setValue(data); // set the data of the new node 
		newNode->setNextPtr(nullptr);// set the next ptr of the new node to null

		headNode.setNextPtr(newNode);// point the head's next ptr to the new node
		headNode.setRearPtr(newNode);// point the rear ptr of the head to the new node 
		headNode.incrementData(); // increment the node count
	}

	else // if the list is not empty traverse thru the list and append at the end
	{

		nodePtr = headNode.getNextPtr(); // set the nodePtr to point at the first node
		newNode->setValue(data); // set the value of new node to the input data
		newNode->setNextPtr(nullptr); // set the newnode's next ptr to nullp



		while (nodePtr->getNextPtr()) //to traverse thru the list and find the last node 
		{
			nodePtr = nodePtr->getNextPtr(); // set nodePtr to point at the same node as its next ptr to traverse
		}
		headNode.incrementData(); // increment count when add new node
	}
	nodePtr->setNextPtr(newNode); // point the next ptr of the last node of the list to the new node to add the new node to the list

	headNode.setRearPtr(newNode); // set the rear ptr of the head node to the new node.
}

/*	InsertFirst Function Definition
This function will insert the node as the first node
*/

template <class Type>
void ListNode<Type>::insertFirst(Type data)
{
	Node <Type> *newNode;


	newNode = new Node < Type >; // allocate memory for the new node

	newNode->setValue(data);

	if (getCount() == 0) //check if the list is empty 
	{
		newNode->setNextPtr(nullptr);// set the next ptr of the newnode to null

		headNode.setNextPtr(newNode);// set the next ptr of the head node to the new node
		headNode.setRearPtr(newNode);// set the rear ptr of the head node to the new node
		headNode.incrementData(); //increment the count
	}
	else // if the list is not empty
	{
		newNode->setNextPtr(headNode.getNextPtr());//point the nextNode to the current first node
		headNode.setNextPtr(newNode); // set the next ptr of the head node to point at the new node

		headNode.incrementData(); // increment the count

	}
}

/*	InsertNodeByValue Function Definition
This function will take a data same type as the node and add it to the list at the location based on its data value
*/
template <class Type>
void ListNode<Type>::insertNodeByValue(Type data)
{
	Node <Type> *newNode;
	Node <Type> *nodePtr;
	Node <Type> *preNode = nullptr;

	newNode = new Node <Type>; // allocate memory for the new node
	newNode->setValue(data); //set data for the new node with the input data

	if (getCount() == 0) // check if the list is empty
	{

		newNode->setNextPtr(nullptr);// set the next ptr of the newnode to null

		headNode.setNextPtr(newNode);// set the next ptr of the head node to the new node
		headNode.setRearPtr(newNode);// set the rear ptr of the head node to the new node
		headNode.incrementData(); //increment the count
	}
	else // if the list is not empty traverse the list and add the new node at the appropriate location
	{
		nodePtr = headNode.getNextPtr(); // set the nodePtr to point at the first node

		while (nodePtr != nullptr && nodePtr->getValue() < data) //traverse the nodePtr thru the list until stop at the appropriate location
		{
			preNode = nodePtr; // traverse the preNode with the nodePtr
			nodePtr = nodePtr->getNextPtr(); // traverse the nodePtr
		}

		if (preNode == nullptr) // check if the new node should be added as the first node
		{
			headNode.setNextPtr(newNode); //set the head's next ptr to point at the new node
			newNode->setNextPtr(nodePtr);// set the new node's next ptr to point at the following node
			headNode.incrementData(); // increment the count 
		}
		else // if the new node won't be added as the first node 
		{
			preNode->setNextPtr(newNode);// set the preNode's next ptr to point at the new node
			newNode->setNextPtr(nodePtr);// set the new node's next ptr to point at the current node <where nodePtr is pointing at>
			headNode.incrementData();// increment count 
		}
	}
}
/*	DeleteNode Function Definition
This function will delete the node contain the input data
*/
template <class Type>
void ListNode<Type>::deleteNode(Type data)
{
	Node <Type> *nodePtr;
	Node <Type> *preNode = nullptr;

	if (getCount() == 0) // check if the list is empty 
	{
		cout << endl << "The list is empty..." << endl; // if the list is empty print out the message 
		return;
	}
	else // if the list is not empty
	{
		nodePtr = headNode.getNextPtr(); // set the nodePtr to point at the first node

		while (nodePtr != nullptr && nodePtr->getValue() != data)//condition to traverse to the data desired to delete
		{
			preNode = nodePtr;//set the preNode to point at the same node as the nodePtr
			nodePtr = nodePtr->getNextPtr();// then traverse the nodePtr to the next node until the data match
		}

		if (nodePtr)// if the node contains the desired data is found then proceed to delete the node
		{
			preNode->setNextPtr(nodePtr->getNextPtr());// set the next ptr of the preNode to point at the node pointed at by the nodePtr
			delete nodePtr;// delete the node
			headNode.decrementData();// decrement the count 
		}
		else // if the data wanted to delete is not in the list simply print the message 
		{
			cout << "**List does not contain the data " << data << endl << endl;
		}
	}
}

/*	DeleteFirst Function Definition
This function will delete the first node of the list
*/
template <class Type>
void ListNode<Type>::deleteFirst()
{
	Node <Type> *nodePtr;

	if (getCount() == 0)// check if the list is empty
	{
		cout << "The list is empty!" << endl;
	}
	else
	{
		nodePtr = headNode.getNextPtr(); // set the nodePtr to point at the first node
		headNode.setNextPtr(nodePtr->getNextPtr()); //set the next ptr of the head node to point at the second node
		delete nodePtr;	//delete the first node
		headNode.decrementData(); // decrement the count 
	}
}

/*	EmptyList Function Definition
This function will delete all the node in the list one by one
*/
template <class Type>
void ListNode<Type>::emptyList()
{
	Node <Type> *nodePtr;
	Node <Type> *nextNode;

	nodePtr = headNode.getNextPtr(); // set the nodePtr to point at the first node

	while (nodePtr != nullptr) // begin at the first node til the last 
	{
		nextNode = nodePtr->getNextPtr(); // set the next node to point at the node after the first 

		delete nodePtr; // delete the first node
		headNode.decrementData();// decrement the count 

		nodePtr = nextNode;// set nodePtr back to the first node after deleting 
	} 

	
}



/*	DisplayStack Function Definition
This function will display the stack
*/
template <class Type>
void StackNode<Type>::displayStack()
{
	Node <Type> *nodePtr;

	nodePtr = headNode.getNextPtr();

	cout << endl;


	if(this->getCount() == 0)
	{
		cout << "count: " << this->getCount() << endl << endl;
		cout << "Stack is empty" << endl << endl; 
	}

	else
	{
		cout << "count: " << this->getCount() << endl << endl;
		while (nodePtr)
		{
			cout << "|[" << nodePtr->getValue() << "]|" << endl;
			nodePtr = nodePtr->getNextPtr();
		}

		cout << "______" << endl << endl;
	}
}

/*	TopStack Function
This function will return the value of the node on top of the stack*/
template <class Type>

Type StackNode <Type> ::topStack()
{
	Node <Type> *nodePtr;

	nodePtr = headNode.getNextPtr();

	return nodePtr->getValue();
}



