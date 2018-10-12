#include <iostream>
#include <string>
#include "GenStack.h"

using namespace std;

class SyntaxChecker
{
  public:
    SyntaxChecker();
    ~SyntaxChecker();
    void ReadInputFile(string fileName);
    void NextFile();
    int charCount;
    int lineCount;
    char expectedChar;
    bool foundError;

  private:
    GenStack<char> *stack;
};
