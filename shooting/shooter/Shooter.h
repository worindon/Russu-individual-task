#pragma once
#include "../target/CircularTarget.h"
#include "../target/HumanFigureTarget.h"
#include "../target/AbstractTarget.h"
#include <string>
class Shooter
{
	int hits = 0;
	int misses = 0;    //?
	int shoots = 0;
	string name;

public:

	Shooter(string name) {
		this->name = name;
	}


	bool fire(AbstractTarget& targ, int x, int y) {
		  ++shoots;
		  if (targ.shoot(x, y)) {
			  ++hits; return true;
		  }
		  else {
			  ++misses; return false;
		  }
	}

	int get_misses() const { return misses; } 
	int get_hits() const { return hits; }
	int get_shoots() const { return shoots; }
	double get_fidelity() const {
		if (this->hits == 0 or this->shoots==0) return 0;
		double temp = (double)hits / shoots;
		return temp * 100;  
	}
};

