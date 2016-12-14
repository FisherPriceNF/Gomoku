#include "Gomoku.h"
#include "IA.hh"



/*void	loop(std::map<int, char> tab, int db, int cc, int ian, int iat)
{
	int	t = -1, h = 0, v = 0, val, pos = 0, cap[2], posv;
	char	vic;
	std::string in;
	IA	*ia = new IA(cc, db, 'x', 'o'), *ia2;
	if (iat == 0)
		ia = new IA(cc, db, 'o', 'x');
	if (ian == 2)
	{
		ia = new IA(cc, db, 'o', 'x');
		ia2 = new IA(cc, db, 'x', 'o');
	}

	cap[0] = 0;
	cap[1] = 0;
	posv = 0;
	while ((vic = check(tab, cc, posv)) == 0 && ++t >= 0 && cap[0] < 10 && cap[1] < 10)
	{
        //std::cout << "victoire : " << check(tab, cc, (v - 1) * 19 + h - 1) << std::endl;
        //draw(tab);
		print_tab(tab);
		val = 0;
		std::cout << "> Joueur : " << t % 2 + 1 << std::endl;
		if (ian != 2 && (ian == 0 || t % 2 != iat))
		{
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
                        posv = (v - 1) * 19 + h - 1;
				if (t % 2 == 1)
					val = tab[posv] = 'x';
				else
					val = tab[posv] = 'o';
				if (double_trois(tab, posv) != 0 && db == 1)
				{
					tab[posv] = '-';
					val = 0;
				}
				if (val == 0)
				{
					std::cout << "error" << std::endl;
					print_tab(tab);
				}
			}
			taken(&tab, posv, &(cap[0]), &(cap[1]));
		}
		else if (ian >= 1 && t % 2 == iat)
			posv = ia->Play(&tab, &(cap[0]), &(cap[1]));
		else if (ian == 2 && t % 2 != iat)
			posv = ia2->Play(&tab, &(cap[0]), &(cap[1]));
	}
	print_tab(tab);
	std::cout << "Winner is : ";
	if (cap[0] >= 10)
		std::cout << "x" << std::endl;
	else if (cap[1] >= 10)
		std::cout << "o" << std::endl;
	else
		std::cout << vic << std::endl;
}*/

std::map<int, char>	create()
{
	std::map<int, char> tab;
	for (int i = 0; i < 19 * 19; ++i)
		tab[i] = '-';
	return (tab);
}

