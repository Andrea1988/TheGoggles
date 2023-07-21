#include "database.h"

Database::Database() : composers_(){};
Database::~Database(){};

void Database::setSlot(int slot) {
  next_slot_ = slot;
}

Composer& Database::AddComposer(string in_first_name,
                                string in_last_name,
                                string in_genre,
                                int in_yob,
                                string in_fact) {
    
  int Slot = getSlot();   
  
  composers_[Slot].set_first_name(in_first_name),
  composers_[Slot].set_last_name(in_last_name),
  composers_[Slot].set_composer_genre(in_genre), 
  composers_[Slot].set_composer_yob(in_yob),
  composers_[Slot].set_fact(in_fact);
  composers_[Slot].set_ranking(0);
  
  setSlot(Slot + 1);

  return composers_[Slot];
}

Composer& Database::GetComposer(string in_last_name) {
  
  int entries = getSlot();
  string last_name;
 
  for (int i = 0; i < entries; i++) {

    last_name = composers_[i].last_name();

    if (last_name == in_last_name) {
      return composers_[i];
    }
  }
}

void Database::DisplayAll() {

  int Slots = getSlot();
  
  for( int i = 0; i < Slots; i++) {
    composers_[i].Display();
  }
}

void Database::DisplayByRank() {
  int entries = getSlot();
  int P, min, arr[entries], temp;
  
  for (int i = 0; i < entries; i++) {

    arr[i] = composers_[i].ranking();
  }

  for (int i = 0; i < entries - 1; i++) {

    min = composers_[i].ranking();
    P = i;
    
    for (int j = i + 1; j < entries; j++) {
      
      if( min > arr[j]) {
        
        min = arr[j];
        P = j;
      }
    }
     
    temp = arr[i];
    arr[i] = arr[P];
    arr[P] = temp;
  }

  for (int i = 0; i <= entries; i++) {

    for (int j = 0; j <= entries; j++) {
    
      if (arr[i] == composers_[j].ranking()) {
        cout << composers_[j].last_name() << ": ";
        cout << composers_[j].ranking() << endl;
      }
    }
  } 
}
