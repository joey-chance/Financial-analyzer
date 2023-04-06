#pragma once
#include <iostream>
#include <vector>

#include "../Header/Scorer.h"

using namespace std;

class Commands
{
protected:
	// limit maximum number of arguments per command
	const static int ARG_LIMIT = 10;
	Scorer* scorer;


public:
	std::vector<std::string *> args;

	Commands(Scorer* scorer) : scorer(scorer) {
		args.reserve(ARG_LIMIT);
	}

	virtual void execute() = 0;

	void add_args(std::string* input) {
		args.push_back(input);
	}
};