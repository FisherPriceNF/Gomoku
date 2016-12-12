#ifndef IA_HH_
#define IA_HH_
#pragma once

#include "Gomoku.h"

class IA
{
public:
	IA() {};
	IA(int, int, char, char);
	~IA() {};

	std::map<int, char> Play(std::map<int, char> tab);
	
	struct Chosen
	{
		int	weight, p;
	};

private:
	int		eval(std::map<int, char>, int);
	Chosen	min(std::map<int, char>, int, int);
	Chosen	max(std::map<int, char>, int, int);
	Chosen	newChosen(int, int);
	Chosen	MinChosen();
	Chosen	MaxChosen();

	char	c, e;
	int		cc, db;
};

#endif // !IA_HH_
