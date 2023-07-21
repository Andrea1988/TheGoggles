#include <iostream>
#include <ios>
#include <limits>
#include "API.h"

int main() {

  enum Choice {
    NewComposer = 1,
    GetComposer = 2,
    ChangeRank  = 3,
    ListAll     = 4,
    ListAllByRa = 5,
    Quit = 0
  };

  API MyAPI;
  MyAPI.CommandList();
  int UserInput = 6;

  while( UserInput != 0) {
    cin >> UserInput;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    switch(UserInput) {

      case NewComposer:
        MyAPI.AskComposerDetails();
        break;

      case GetComposer:
        MyAPI.RetrieveComposer();
        break;
      
      case ChangeRank:
        MyAPI.ChangeRank();
        break;
     
      case ListAll:
        MyAPI.ShowAll();
        break;
      
      case ListAllByRa:
        MyAPI.ShowAllByRank();
        break;

      case Quit:
        break;
    }
//   cout << UserInput << endl; 
    MyAPI.CommandList();
  }
}
