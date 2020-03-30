//
//  NODE.h
//  DataStructure(HLT)
//
//  Created by Quan Bach  on 8/30/17.
//  Copyright © 2017 QB. All rights reserved.
//

#ifndef NODE_H
#define	NODE_H


//template ADT for the Node
template <class Type>

class Node
{
protected:
    // variable to store data of the node
    Type data;
    
    //pointer link with the right node
    Node <Type>  * rightPtr;
    
    //pointer to link with the left node
    Node <Type>	 * leftPtr;
public:
    //constructor
    Node()
    {
        rightPtr = nullptr;
        leftPtr = nullptr;
    }
    
    //function to assign value for the node data
    void setValue(Type d)
    {
        data = d;
    }
    
    
    //function to return data of the node
    Type getValue()
    {
        return data;
    }
    
    //function to set address for the right pointer
    void setRightPtr(Node <Type> *ptr)
    {
        rightPtr = ptr;
    }
    
    //function to set address for the left pointer
    void setRearPtr(Node <Type> *ptr)
    {
        leftPtr = ptr;
    }
    
    //function to return the reference of the right pointer
    Node <Type>  * getRightPtr()
    {
        return rightPtr;
    }
    
    //function to return the reference of the left pointer
    Node <Type> * getLeftPtr()
    {
        return leftPtr;
    }
    
};


//template for the head node ADT: a derrived class from class Node
template <class Type>

class HeadNode : public Node <Type>
{
private:
    //store int data of the head node 
    int data;
    
public:
    //constructor
    HeadNode()
    {
        data = 0;
    }
    
    //return the int data of the head node
    int getCount()
    {
        return data;
    }
    
    //overload operator ++ to increment private data
    int operator ++ ()
    {
        return data++;
    }
    
    //overload operator -- to decremnt private data
    int operator -- ()
    {
        return data--;
    }
};

#endif




#endif /* NODE_h */
