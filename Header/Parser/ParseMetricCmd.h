#pragma once
#include <iostream>

#include "Commands.h"

class ParseMetricCmd : public Commands
{
public:
	// Constructor for ParseMetricCmd
	ParseMetricCmd(Scorer* scorer);
	
	void execute() override;
	
};