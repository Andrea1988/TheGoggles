#include "composer.h"

Composer::Composer(){};
Composer::~Composer(){};

void Composer::set_first_name(string in_first_name) {
	first_name_ = in_first_name;
}

void Composer::set_last_name(string in_last_name) {
	last_name_ = in_last_name;
}

void Composer::set_composer_yob(int in_composer_yob) {
	composer_yob_ = in_composer_yob;
}

void Composer::set_composer_genre(string in_composer_genre) {
	composer_genre_ = in_composer_genre;
}

void Composer::set_ranking(int in_ranking) {
	ranking_ = in_ranking;
}

void Composer::set_fact(string in_fact) {
	fact_ = in_fact;
}

void Composer::Promote(int increment) {
	int ranking = Composer::ranking() + increment;
	Composer::set_ranking(ranking);
}

void Composer::Demote(int decrement) {
	int ranking = Composer::ranking() - decrement;
	Composer::set_ranking(ranking);
}

void Composer::Display() {
	cout << first_name() << endl;
	cout << last_name() << endl;
	cout << composer_yob() << endl;
	cout << composer_genre() << endl;
	cout << ranking() << endl;
	cout << fact() << endl;
}

