#include "stdafx.h"
#include "Gomoku.h"

void	print_tab(std::map<int, char> tab)
{
	int	i = 0, j = 1;

	for (std::map<int, char>::iterator it = tab.begin(); it != tab.end(); it++)
	{
		i++;
		std::cout << it->second;
		if (i % 19 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

int		add_pos(std::map<int, char> *tab, char c, int v, int h)
{	
	std::map<int, char>::iterator	it = tab->begin();
	int	i = 0;

	while (v > 1)
	{
		it++;
		if (++i % 19 == 0)
			v--;
	}
	while (--h > 0)
		it++;
	if (it->second == '-')
		it->second = c;
	else
		return (0);
	return (1);
}

void	loop(std::map<int, char> tab, int db, int cc, int ia)
{
	int	t = -1, h, v, val, pos, cap[2];
	std::string in;

	std::cout << "here" << std::endl;
	cap[0] = 0;
	cap[1] = 1;

	while (check(tab, cc) == 0 && ++t >= 0 && cap[0] < 10 && cap[1] < 10)
	{
		print_tab(tab);
		val = 0;
		std::cout << "> Joueur : " << t % 2 + 1 << std::endl;
		if (ia == 0 || t % 2 == 0)
			while (val == 0)
			{
				std::cout << "> Position vertical : ";
				std::cin >> in;
				if (in == "quit")
					return;
				v = stoi(in);
				std::cout << "> Position horizontal : ";
				std::cin >> in;
				if (in == "quit")
					return;
				h = stoi(in);
				if (h <= 19 && v <= 19 && h > 0 && v > 0)
					if (t % 2 == 1)
						val = add_pos(&tab, 'x', v, h);
					else
						val = add_pos(&tab, 'o', v, h);
				if (double_trois(tab, (v - 1) * 19 + h - 1) != 0 && db == 1)
				{
					tab[(v - 1) * 19 + h - 1] = '-';
					val = 0;
				}
				if (val == 0)
				{
					std::cout << "error" << std::endl;
					print_tab(tab);
				}
			}
		taken(&tab, (v - 1) * 19 + h - 1, &(cap[0]), &(cap[1]));
	}
	print_tab(tab);
	std::cout << "Winner is : ";
	if (cap[0] >= 10)
		std::cout << "x" << std::endl;
	else if (cap[1] >= 10)
		std::cout << "o" << std::endl;
	else
		std::c	out << check(tab, cc) << std::endl;
}

std::map<int, char>	create()
{
	std::map<int, char> tab;
	for (int i = 0; i < 19 * 19; ++i)
		tab[i] = '-';
	return (tab);
}

int main()
{
	int	db = 1, cc = 1, ia = 1;
	std::string tmp;

	std::cout << "Activé la règle du double 3 ? (Oui / Non)" << std::endl;
	std::cin >> tmp;
	if (tmp == "Non" || tmp == "non" || tmp == "NON")
		db = 0;
	std::cout << "Activé la règle du cinq cassable ? (Oui / Non)" << std::endl;
	std::cin >> tmp;
	if (tmp == "Non" || tmp == "non" || tmp == "NON")
		cc = 0;
	std::cout << "Jouer contre l'IA ? (Oui / Non)" << std::endl;
	std::cin >> tmp;
	if (tmp == "Non" || tmp == "non" || tmp == "NON")
		ia = 0;

	std::map<int, char>	tab = create();
	loop(tab, db, cc, ia);
	return 0;
}
