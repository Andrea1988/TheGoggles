// API.h, Andrea
// Description: The class for API interface.
// The default ranking is 10 which is the lowest possible.
// Notice we use const in C++ instead of #define.
#include <iostream>
#include <string>
//#include "composer.h"
#include "database.h"
using namespace std;

class API : public Database {
  public:
    API();
    ~API();

    void CommandList();
    void AskComposerDetails();
    void RetrieveComposer();
    void ChangeRank(); 
    void ShowAll();
    void ShowAllByRank();

  private:
    Database database;
};

