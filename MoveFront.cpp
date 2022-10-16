
using namespace std;
typedef int ItemType;

#include <iostream>
#include <cctype>
#include "dlist.h"

char PrintMenu (char sel);
void insertHead(DList<int>& list);
void appendTail(DList<int>& list);
void deleteItem(DList<int>& list);
void printLength(const DList<int>& list);
void printList (const DList<int>& list);
void accessItem (DList<int>& list);
void findAndReplace (int i, DList<int>& list);

int main()
{
  DList<int> list;
  char sel;
  do
  {
    sel = PrintMenu (sel);
    switch (toupper(sel))
    {
     
      case 'H' : insertHead(list); break;
      
      case 'T' : appendTail(list); break;
      case 'A' : accessItem(list); break;
      case 'D' : deleteItem(list); break;
      case 'P' : printList(list); break;
      case 'L' : printLength(list); break;
      
      case 'Q' : cout << "\tExiting Program...\n"; break;
      
      default : cout << "\tError. Try Again." << endl;
      
    }
  } while (toupper(sel) != 'Q');
}

char PrintMenu (char sel)
{
  cout << "\n------------------------------------------------";
  cout << "\nH: Insert number at the front of the list" << endl;
  cout << "T: Insert number at the end of the list" << endl;
  cout << "A: Access a number in the list and move it to the front" << endl;
  cout << "D: Delete a number from the list" << endl;
  cout << "P: Print the list" << endl;
  cout << "L: Print the length of the list" << endl;
  cout << "Q: Exit the program" << endl << endl;
  cout << "Enter a selection:";
  cin >> sel;
  return sel;
}

void insertHead(DList<int>& list)
{
  int value;
  cout << "Enter integer to be added to front:";
  cin >> value;
  if (list.inList(value))
    cout << "Item not added, already in list";
  else
    list.insertHead(value);
}

void appendTail(DList<int>& list)
{
  int value;
  cout << "Enter integer to be added to end:";
  cin >> value;
  if (list.inList(value))
    cout << "Item not added, already in list";
  else
    list.appendTail(value);
}

void deleteItem(DList<int>& list)
{
  int value;
  cout << "Enter integer to be deleted:";
  cin >> value;
  if (list.inList(value))
    list.deleteItem(value);
  else
    cout << "ERROR: not in list, try again";
}

void printLength(const DList<int>& list)
{
  int len = list.lengthIs();
  if (len == 0)
    cout << "List is empty";
  else
    cout << len;
}

void printList (const DList<int>& list)
{
  
  if (list.isEmpty())
    cout << "List is empty";
  else 
    list.print();
}

void accessItem (DList<int>& list)
{
  int i;
  cout << "Enter item to be accessed: ";
  cin >> i;
  findAndReplace(i, list);
}

void findAndReplace (int i, DList<int>& list)
{
  if (list.inList(i)){
  list.deleteItem(i);
    list.insertHead(i);
    
    cout << i << " moved to front";}
  else
    cout << "Item not in list";
}
