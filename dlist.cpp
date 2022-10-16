#include <cstddef> 
#include <iostream>
//#include "dlist.h"

using namespace std;

typedef int ItemType;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>*	next;
	NodeType<ItemType>*	back;
};

template <class ItemType>		
DList<ItemType>::DList()		// Class constructor
{
    length = 0;
    head = NULL;
}

template <class ItemType>
DList<ItemType>::~DList   ()		
{
	// Post: List is empty; All items have been deallocated.
  makeEmpty();
}

template <class ItemType>
void DList<ItemType>::makeEmpty()
{
    // Post: List is empty; all items have been deallocated.
  while (head != NULL)
    deleteItem(head->info);
    //delete head;
    



}

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)	
{
	//  Pre :  item to be deleted is passed in via parameter 
        // Post :  item is deleted if it exists in list 
   if (inList(item)){
     deleteLocation(location(item));}
   else
     cout << "Item not in List";


}

template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
        // Post :  function returns bool value if item is found 
 return (location(item) != NULL);


}

template <class ItemType>
bool DList<ItemType>::isEmpty() const		
{
	// Post : function returns true if list is empty, false otherwise
	return (head == NULL);
}

template <class ItemType>
void DList<ItemType>::print() const	
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen
	NodeType<ItemType>* pNode = new NodeType<ItemType>;
    pNode = head;
    
    while (pNode != NULL){
      cout << pNode->info << " ";
      pNode = pNode->next;}

}
	
template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)	
{
	//  Pre : item to be inserted is passed in via parameter
        // Post : item is inserted at head of list;  Former first node is 
        //        linked back to this new one via double link;
        //        Length incremented;  Special case handled if list is empty 
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
    newNode->info = item;
    newNode->back = NULL; //empty bc new front

    if (head != NULL)  
    {
      head -> back = newNode; //current head linked to new node

      newNode-> next = head; //link new head to old head

    }
    else
      newNode->next = NULL; //only 1 item in list

    head = newNode;
    length++;

}

template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
        // Post :  item is added to tail of list; Former last node
        //         is linked to this new one via double link 
  NodeType<ItemType>* newNode = new NodeType<ItemType>;
    newNode->info = item;
    newNode->next = NULL; //empty bc new back
    //cout << last();//tester for last
    if (head == NULL){
      newNode->back = NULL;
      head = newNode;}
    else{
      
      newNode->back = last();
      last()->next = newNode;}

    
    length++;


}

template <class ItemType>
int DList<ItemType>::lengthIs() const	
{
	// Post : Function returns current length of list  
 return length;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const	
{
	//  Pre : item to be located is passed in via parameter 
        // Post : function returns address of item being searched for --
        //        if not found, NULL is returned  
	NodeType<ItemType>* fNode = head;
  
  while (fNode != NULL)
    if (fNode->info == item)
      return fNode;
    else
      fNode = fNode->next;
    
  return NULL;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const	
{
	// Post : Function returns location of current last item in list
 NodeType<ItemType>* lastNode = head;

 while (lastNode->next != NULL && lastNode != NULL){
   lastNode = lastNode->next;
  }
 return lastNode;
	
}

template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)	
{

	//  Pre : Item to be deleted exits in list and its location
        //        is passed in via parameter
                   
	// Post : Location passed in is removed from list;  Length
        //        is decremented, and location is deallocated 

        // Special Cases Handled for Deleting Only One Item in List,
        // The Head Item of List, and the Tail Item of List
    if (delPtr->next == NULL && delPtr->back == NULL){
      head = NULL;}
      else if (delPtr-> next == NULL){
        delPtr->back->next = NULL;}
      else if (delPtr -> back == NULL){
        delPtr->next->back = NULL;
        head = delPtr->next;}
      else {
        delPtr->next->back = delPtr->back;
        delPtr->back->next = delPtr->next;}
    delete delPtr;
    length --;
   

}
