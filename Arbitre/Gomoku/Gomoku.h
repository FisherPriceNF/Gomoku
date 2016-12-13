#ifndef GOMOKU_HPP
#define GOMOKU_HPP

#include <string>
#include <iostream>
#include <list>
#include <map>
#include <cstring>
#include "stdafx.h"

int		ia(std::map<int, char> *tab);
int		double_trois(std::map<int, char> tab, int pos);
int		taken(std::map<int, char> *tab, int pos, int *cap1, int *cap2);
char		check(std::map<int, char> tab, int cc, int pos);
void		print_tab(std::map<int, char> tab);
int		add_pos(std::map<int, char> *tab, char c, int v, int h);

#endif
