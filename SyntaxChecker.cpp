#include "SyntaxChecker.h"
#include "GenStack.h"
#include <fstream>

using namespace std;

SyntaxChecker::SyntaxChecker()
{
  lineCount = 1;
  foundError = false;
  stack = new GenStack<char>(); //initializing new stack
}

SyntaxChecker::~SyntaxChecker()
{
  delete stack;
}

//Reads in input file and checks for syntax errors
void SyntaxChecker::ReadInputFile(string fileName)
{
  char checker = '\0'; //holds gs.pop()
  GenStack<char> gs;
  ifstream input(fileName);
  if(input.fail()) //checking if input file exsists
  {
    cout<<"Invalid file path. Please compile again with a correct file."<<endl;
  }
  else
  {
    string line;
    while(getline(input, line)) //iterates line by line
    {
      for(char& curChar : line) //iterates by character in that line
      {
        if(curChar == '{' || curChar == '[' || curChar == '(')
        {
          gs.push(curChar);
        }
        if(curChar == '}')
        {
          checker = gs.pop();
          if(checker == '{')
          {
            //continue
          }
          if(checker == '(')
          {
            cout<<"Found } in line " << lineCount << ". Expected )" << endl;
            foundError = true;
          }
          if(checker == '[')
          {
            cout<<"Found } in line " << lineCount << ". Expected ]" << endl;
            foundError = true;
          }
        }
        if(curChar == ']')
        {
          checker = gs.pop();
          if(checker == '{')
          {
            cout<<"Found ] in line " << lineCount << ". Expected }" << endl;
            foundError = true;
          }
          if(checker == '(')
          {
            cout<<"Found ] in line " << lineCount << ". Expected )" << endl;
            foundError = true;
          }
          if(checker == '[')
          {
            //continue
          }
        }
        if(curChar == ')')
        {
          checker = gs.pop();
          if(checker == '{')
          {
            cout<<"Found ) in line " << lineCount << ". Expected }" << endl;
            foundError = true;
          }
          if(checker == '(')
          {
            //continue
          }
          if(checker == '[')
          {
            cout<<"Found ) in line " << lineCount << ". Expected ]" << endl;
            foundError = true;
          }
        }
      }
      lineCount++;
    }
    if(!foundError)
    {
      cout<<"No errors were found in the file."<<endl;
    }
    NextFile();
  }
}

//checking if the user wants to input another file
void SyntaxChecker::NextFile()
{
  string input;
  string fileName;
  cout<<"Would you like to input another file (y/n): "<<endl;
  cin>>input;
  if(input == "y")
  {
    cout<<"Please enter file name: "<<endl;
    cin>>fileName;
    ReadInputFile(fileName);
  }
  else
  {
    cout<<"Exiting program"<<endl;
  }
}
