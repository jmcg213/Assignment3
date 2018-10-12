#ifndef __GENSTACK_H
#define __GENSTACK_H
#include <iostream>

using namespace std;

template <typename G>
class GenStack
{
  public:
    GenStack()
    {
      myArray = new G[10];
      size = 10;
      top = -1;
    }

    GenStack(int maxSize)
    {
      myArray = new G[maxSize];
      size = maxSize;
      top = -1;
    }

    ~GenStack()
    {
      delete myArray;
      cout << "stack destroyed" << endl;
    }

    void push(G d)
    {
      if(isFull())
      {
        cout<<"Stack Full"<<endl;
      }
      else
      {
        myArray[++top] = d;
      }
    }

    G pop()
    {
      if(isEmpty())
      {
        cout<<"Stack Empty"<<endl;
      }
      else
      {
        return myArray[top--];
      }
    }

    G peek()
    {
      if(isEmpty())
      {
        cout<<"Stack Empty"<<endl;
      }
      else
      {
        return myArray[top];
      }
    }

    bool isFull()
    {
      return (top == size-1);
    }

    bool isEmpty()
    {
      return (top == -1);
    }

    int size;
    int top;

    G *myArray;
};
#endif
