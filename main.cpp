#include <iostream>
#include <string>
#include "SyntaxChecker.h"
#include "GenStack.h"

using namespace std;

int main (int argc, char **argv)
{
  if(argc > 1)
  {
    string inputFile = argv[1]; //grabs second command line argument as a file name
    SyntaxChecker sc;
    sc.ReadInputFile(inputFile);
  }
  else
  {
    cout<<"Please make sure your file name is your second command line argument"<<endl;
  }
}
