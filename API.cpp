//============================================================================
// Name        : TheGoogles.cpp
// Author      : Andrea
// Version     :
// Copyright   : Your copyright notice
// Description : Ansi-style
//============================================================================

// API for database app
//
// This program tests the Composer class.
//#include "composer.h"
//#include "database.h"
#include "API.h"
#include <ios>
#include <limits>

API::API(){};
API::~API(){};

void API::CommandList() {
 
 cout << "---------------------------------------------" << endl;
 cout << "Composer Database" << endl;
 cout << "---------------------------------------------" << endl;
 cout << "1) Add a new composer" << endl;
 cout << "2) Retrieve a composer's data" << endl;
 cout << "3) Promote/demote a composer's rank" << endl;
 cout << "4) List all composers" << endl;
 cout << "5) List all composers by rank" << endl;
 cout << "0) Quit" << endl;
 cout << "---------------------------------------------" << endl;

}

void API::AskComposerDetails() {

  string in_first_name, in_last_name, in_genre, in_fact;
  int in_yob;

  cout << "First name of the composer:" << endl;
  getline(cin, in_first_name); 
   
  cout << endl << "Last name of the composer:" << endl;
  getline(cin, in_last_name);

  cout << endl << "Music style of the composer:" << endl;
  getline(cin, in_genre);
  
  cout << endl << "Year of birth of the composer:" << endl;
  cin >> in_yob;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

  cout << endl << "An interesting fact related to the composer:" << endl;
  getline(cin, in_fact);
  cout << endl;
  
  database.AddComposer(in_first_name, in_last_name, in_genre, in_yob, in_fact);
}

void API::RetrieveComposer() {
  
  string in_last_name;
  
  cout << "Enter the last name of the composer you want to retrieve" << endl;
  getline(cin, in_last_name);
  
  Composer& comp = database.GetComposer(in_last_name);

  comp.Display();
}

void API::ChangeRank() {
  
  string in_last_name;
  int NewRank;
  
  cout << "Enter the last name of the composer you want to change the Rank" << endl;
  getline(cin, in_last_name); 
  
  cout << "Enter the number of position to shift" << endl;
  cin  >> NewRank;
  
  Composer& comp = database.GetComposer(in_last_name);
  
  if (NewRank > 0 ) {

    comp.Promote(NewRank);

  } else if (NewRank < 0 ) {

    comp.Demote(NewRank);

  } else {

    comp.Promote(NewRank);
  }
}

void API::ShowAll() {
  database.DisplayAll();
}

void API::ShowAllByRank() {
  database.DisplayByRank();
}

