#include "stdafx.h"
#include "Gomoku.h"

int		NT(std::map<int,char> tab, int pos)
{
	if ((tab[pos] == tab[pos + 1] && tab[pos] != tab[pos + 2] && tab[pos] != tab[pos - 1] &&
		tab[pos - 1] != tab[pos + 2] && (tab[pos - 1] == '-' || tab[pos + 2] == '-')) ||
		(tab[pos] == tab[pos + 1 + 19] && tab[pos] != tab[pos + 2 + 2 * 19] && tab[pos] != tab[pos - 1 - 19] &&
		tab[pos - 1 - 19] != tab[pos + 2 + 2 * 19] && (tab[pos - 1 - 19] == '-' || tab[pos + 2 + 2 * 19] == '-')) ||
		(tab[pos] == tab[pos + 19] && tab[pos] != tab[pos + 2 * 19] && tab[pos] != tab[pos - 19] &&
		tab[pos - 19] != tab[pos + 2 * 19] && (tab[pos - 19] == '-' || tab[pos + 2 * 19] == '-')) ||
		(tab[pos] == tab[pos - 1 + 19] && tab[pos] != tab[pos - 2 + 19 * 2] && tab[pos] != tab[pos + 1 - 19] &&
		tab[pos + 1 - 19] != tab[pos - 2 + 19 * 2] && (tab[pos + 1 - 19] == '-' || tab[pos - 2 + 2 * 19] == '-')) ||
		(tab[pos] == tab[pos - 1] && tab[pos] != tab[pos - 2] && tab[pos] != tab[pos + 1] &&
		tab[pos + 1] != tab[pos - 2] && (tab[pos + 1] == '-' || tab[pos - 2] == '-')) ||
		(tab[pos] == tab[pos - 1 - 19] && tab[pos] != tab[pos - 2 - 2 * 19] && tab[pos] != tab[pos + 1 + 19] &&
		tab[pos + 1 + 19] != tab[pos - 2 - 2 * 19] && (tab[pos + 1 + 19] == '-' || tab[pos - 2 - 2 * 19] == '-')) ||
		(tab[pos] == tab[pos - 19] && tab[pos] != tab[pos - 19 * 2] && tab[pos] != tab[pos + 19] &&
		tab[pos + 19] != tab[pos - 2 * 19] && (tab[pos + 19] == '-' || tab[pos - 2 * 19] == '-')) ||
		(tab[pos] == tab[pos + 1 - 19] && tab[pos] != tab[pos + 2 - 2 * 19] && tab[pos] != tab[pos - 1 + 19] &&
		tab[pos - 1 + 19] != tab[pos + 2 - 2 * 19] && (tab[pos - 1 + 19] == '-' || tab[pos + 2 - 2 * 19] == '-')))
			return 1;
	return 0;
}

char	check(std::map<int, char> tab, int cc)
{
	int	end = 0;

	for (int i = 0; i != 19 * 19; i++)
		if (tab[i] != '-')
			if (cc == 1)
			{
				if ((i % 19 < 15 && tab[i + 1] == tab[i] && tab[i + 2] == tab[i] && tab[i + 3] == tab[i] && tab[i + 4] == tab[i] &&
					NT(tab, i) == 0 && NT(tab, i + 1) == 0 && NT(tab, i + 2) == 0 && NT(tab, i + 3) == 0 && NT(tab, i + 4) == 0) ||
					(i < 266 && tab[i + 1 * 19] == tab[i] && tab[i + 2 * 19] == tab[i] && tab[i + 3 * 19] == tab[i] && tab[i + 4 * 19] == tab[i] &&
					NT(tab, i) == 0 && NT(tab, i + 19) == 0 && NT(tab, i + 2 * 19) == 0 && NT(tab, i + 3 * 19) == 0 && NT(tab, i + 4 * 19) == 0) ||
					(i % 19 < 15 && i < 285 && tab[i + 1 * 19 + 1] == tab[i] && tab[i + 2 * 19 + 2] == tab[i] && tab[i + 3 * 19 + 3] == tab[i] && tab[i + 4 * 19 + 4] == tab[i] &&
					NT(tab, i) == 0 && NT(tab, i + 1 * 19 + 1) == 0 && NT(tab, i + 2 * 19 + 2) == 0 && NT(tab, i + 3 * 19 + 3) == 0 && NT(tab, i + 4 * 19 + 4) == 0) ||
					(i % 19 > 3 && i < 285 && tab[i + 1 * 19 - 1] == tab[i] && tab[i + 2 * 19 - 2] == tab[i] && tab[i + 3 * 19 - 3] == tab[i] && tab[i + 4 * 19 - 4] == tab[i] &&
					NT(tab, i) == 0 && NT(tab, i + 1 * 19 - 1) == 0 && NT(tab, i + 2 * 19 - 2) == 0 && NT(tab, i + 3 * 19 - 3) == 0 && NT(tab, i + 4 * 19 - 4) == 0))
					return tab[i];
			}
		else if ((i % 19 < 15 && tab[i + 1] == tab[i] && tab[i + 2] == tab[i] && tab[i + 3] == tab[i] && tab[i + 4] == tab[i]) ||
				(i < 266 && tab[i + 1 * 19] == tab[i] && tab[i + 2 * 19] == tab[i] && tab[i + 3 * 19] == tab[i] && tab[i + 4 * 19] == tab[i]) ||
				(i % 19 < 15 && i < 285 && tab[i + 1 * 19 + 1] == tab[i] && tab[i + 2 * 19 + 2] == tab[i] && tab[i + 3 * 19 + 3] == tab[i] && tab[i + 4 * 19 + 4] == tab[i]) ||
				(i % 19 > 3 && i < 285 && tab[i + 1 * 19 - 1] == tab[i] && tab[i + 2 * 19 - 2] == tab[i] && tab[i + 3 * 19 - 3] == tab[i] && tab[i + 4 * 19 - 4] == tab[i]))
			return tab[i];
	return (0);
}