//
//  LINKEDLIST.h
//  DataStructure(HLT)
//
//  Created by Quan Bach  on 8/30/17.
//  Copyright © 2017 QB. All rights reserved.
//

#ifndef LINKEDLIST_h
#define LINKEDLIST_h

#include "NODE.h"


template <class Type>

class LinkedList
{
private:
    //head node of the linked list
    HeadNode <Type> * headNode;
    
public:
    //constructor
    LinkedList ()
    {
        headNode = new HeadNode();
    }
    
    //function to append new node
    void appendNode (Type data);
    
    //function to insert node at an index
    void insertNodeAt (Type data, int index);
    
    //function to insert new node in accending sorting manner
    void insertNodeAccending (Type data);
    
    //function to delete a node contain a certain data value
    void deleteNode (Type data);
    
    //function to delete a node at a certain index
    void deleteNodeAt (int index);

};

#endif /* LINKEDLIST_h */

