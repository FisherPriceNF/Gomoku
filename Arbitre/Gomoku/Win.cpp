#include "stdafx.h"
#include "Gomoku.h"

int		NT(std::map<int, char> tab, int pos)
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

char	check(std::map<int, char> tab, int cc, int pos)
{
	if (tab[pos] != '-')
		if (cc == 1)
		{
			if ((pos % 19 < 15 && tab[pos + 1] == tab[pos] && tab[pos + 2] == tab[pos] && tab[pos + 3] == tab[pos] && tab[pos + 4] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1) == 0 && NT(tab, pos + 2) == 0 && NT(tab, pos + 3) == 0 && NT(tab, pos + 4) == 0) ||
				(pos % 19 < 16 && pos % 19 > 0 && tab[pos + 1] == tab[pos] && tab[pos + 2] == tab[pos] && tab[pos + 3] == tab[pos] && tab[pos - 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1) == 0 && NT(tab, pos + 2) == 0 && NT(tab, pos + 3) == 0 && NT(tab, pos - 1) == 0) ||
				(pos % 19 < 17 && pos % 19 > 1 && tab[pos + 1] == tab[pos] && tab[pos + 2] == tab[pos] && tab[pos - 2] == tab[pos] && tab[pos - 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1) == 0 && NT(tab, pos + 2) == 0 && NT(tab, pos - 2) == 0 && NT(tab, pos - 1) == 0) ||
				(pos % 19 < 18 && pos % 19 > 2 && tab[pos + 1] == tab[pos] && tab[pos - 3] == tab[pos] && tab[pos - 2] == tab[pos] && tab[pos - 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1) == 0 && NT(tab, pos - 3) == 0 && NT(tab, pos - 2) == 0 && NT(tab, pos - 1) == 0) ||
				(pos % 19 < 19 && pos % 19 > 3 && tab[pos - 4] == tab[pos] && tab[pos - 3] == tab[pos] && tab[pos - 2] == tab[pos] && tab[pos - 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos - 4) == 0 && NT(tab, pos - 3) == 0 && NT(tab, pos - 2) == 0 && NT(tab, pos - 1) == 0) ||
				(pos < 361 - 4 * 19 && tab[pos + 1 * 19] == tab[pos] && tab[pos + 2 * 19] == tab[pos] && tab[pos + 3 * 19] == tab[pos] && tab[pos + 4 * 19] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 19) == 0 && NT(tab, pos + 2 * 19) == 0 && NT(tab, pos + 3 * 19) == 0 && NT(tab, pos + 4 * 19) == 0) ||
				(pos < 361 - 3 * 19 && tab[pos + 1 * 19] == tab[pos] && tab[pos + 2 * 19] == tab[pos] && tab[pos + 3 * 19] == tab[pos] && tab[pos - 1 * 19] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 19) == 0 && NT(tab, pos + 2 * 19) == 0 && NT(tab, pos + 3 * 19) == 0 && NT(tab, pos - 1 * 19) == 0) ||
				(pos < 361 - 2 * 19 && tab[pos + 1 * 19] == tab[pos] && tab[pos + 2 * 19] == tab[pos] && tab[pos - 2 * 19] == tab[pos] && tab[pos - 1 * 19] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 19) == 0 && NT(tab, pos + 2 * 19) == 0 && NT(tab, pos - 2 * 19) == 0 && NT(tab, pos - 1 * 19) == 0) ||
				(pos < 361 - 1 * 19 && tab[pos + 1 * 19] == tab[pos] && tab[pos - 3 * 19] == tab[pos] && tab[pos - 2 * 19] == tab[pos] && tab[pos - 1 * 19] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 19) == 0 && NT(tab, pos - 3 * 19) == 0 && NT(tab, pos - 2 * 19) == 0 && NT(tab, pos - 1 * 19) == 0) ||
				(pos < 361 && tab[pos - 4 * 19] == tab[pos] && tab[pos - 3 * 19] == tab[pos] && tab[pos - 2 * 19] == tab[pos] && tab[pos - 1 * 19] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos - 4 * 19) == 0 && NT(tab, pos - 3 * 19) == 0 && NT(tab, pos - 2 * 19) == 0 && NT(tab, pos - 1 * 19) == 0) ||
				(pos % 19 < 15 && pos < 361 - 4 * 19 && tab[pos + 1 * 19 + 1] == tab[pos] && tab[pos + 2 * 19 + 2] == tab[pos] && tab[pos + 3 * 19 + 3] == tab[pos] && tab[pos + 4 * 19 + 4] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1 * 19 + 1) == 0 && NT(tab, pos + 2 * 19 + 2) == 0 && NT(tab, pos + 3 * 19 + 3) == 0 && NT(tab, pos + 4 * 19 + 4) == 0) ||
				(pos % 19 < 16 && pos < 361 - 3 * 19 && tab[pos + 1 * 19 + 1] == tab[pos] && tab[pos + 2 * 19 + 2] == tab[pos] && tab[pos + 3 * 19 + 3] == tab[pos] && tab[pos - 1 * 19 - 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1 * 19 + 1) == 0 && NT(tab, pos + 2 * 19 + 2) == 0 && NT(tab, pos + 3 * 19 + 3) == 0 && NT(tab, pos - 1 * 19 - 1) == 0) ||
				(pos % 19 < 17 && pos < 361 - 2 * 19 && tab[pos + 1 * 19 + 1] == tab[pos] && tab[pos + 2 * 19 + 2] == tab[pos] && tab[pos - 2 * 19 - 2] == tab[pos] && tab[pos - 1 * 19 - 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1 * 19 + 1) == 0 && NT(tab, pos + 2 * 19 + 2) == 0 && NT(tab, pos - 2 * 19 - 2) == 0 && NT(tab, pos - 1 * 19 - 1) == 0) ||
				(pos % 19 < 18 && pos < 361 - 1 * 19 && tab[pos + 1 * 19 + 1] == tab[pos] && tab[pos - 3 * 19 - 3] == tab[pos] && tab[pos - 2 * 19 - 2] == tab[pos] && tab[pos - 1 * 19 - 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1 * 19 + 1) == 0 && NT(tab, pos - 3 * 19 - 3) == 0 && NT(tab, pos - 2 * 19 - 2) == 0 && NT(tab, pos - 1 * 19 - 1) == 0) ||
				(pos % 19 < 19 && pos < 361 && tab[pos - 4 * 19 - 4] == tab[pos] && tab[pos - 3 * 19 - 3] == tab[pos] && tab[pos - 2 * 19 - 2] == tab[pos] && tab[pos - 1 * 19 - 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos - 4 * 19 - 4) == 0 && NT(tab, pos - 3 * 19 - 3) == 0 && NT(tab, pos - 2 * 19 - 2) == 0 && NT(tab, pos - 1 * 19 - 1) == 0) ||
				(pos % 19 > 3 && pos < 361 - 4 * 19 && tab[pos + 1 * 19 - 1] == tab[pos] && tab[pos + 2 * 19 - 2] == tab[pos] && tab[pos + 3 * 19 - 3] == tab[pos] && tab[pos + 4 * 19 - 4] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1 * 19 - 1) == 0 && NT(tab, pos + 2 * 19 - 2) == 0 && NT(tab, pos + 3 * 19 - 3) == 0 && NT(tab, pos + 4 * 19 - 4) == 0) ||
				(pos % 19 > 2 && pos < 361 - 3 * 19 && tab[pos + 1 * 19 - 1] == tab[pos] && tab[pos + 2 * 19 - 2] == tab[pos] && tab[pos + 3 * 19 - 3] == tab[pos] && tab[pos - 1 * 19 + 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1 * 19 - 1) == 0 && NT(tab, pos + 2 * 19 - 2) == 0 && NT(tab, pos + 3 * 19 - 3) == 0 && NT(tab, pos - 1 * 19 + 1) == 0) ||
				(pos % 19 > 1 && pos < 361 - 2 * 19 && tab[pos + 1 * 19 - 1] == tab[pos] && tab[pos + 2 * 19 - 2] == tab[pos] && tab[pos - 2 * 19 + 2] == tab[pos] && tab[pos - 1 * 19 + 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1 * 19 - 1) == 0 && NT(tab, pos + 2 * 19 - 2) == 0 && NT(tab, pos - 2 * 19 + 2) == 0 && NT(tab, pos - 1 * 19 + 1) == 0) ||
				(pos % 19 > 0 && pos < 361 - 1 * 19 && tab[pos + 1 * 19 - 1] == tab[pos] && tab[pos - 3 * 19 + 3] == tab[pos] && tab[pos - 2 * 19 + 2] == tab[pos] && tab[pos - 1 * 19 + 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos + 1 * 19 - 1) == 0 && NT(tab, pos - 3 * 19 + 3) == 0 && NT(tab, pos - 2 * 19 + 2) == 0 && NT(tab, pos - 1 * 19 + 1) == 0) ||
				(pos < 361 && tab[pos - 4 * 19 + 4] == tab[pos] && tab[pos - 3 * 19 + 3] == tab[pos] && tab[pos - 2 * 19 + 2] == tab[pos] && tab[pos - 1 * 19 + 1] == tab[pos] &&
				NT(tab, pos) == 0 && NT(tab, pos - 4 * 19 + 4) == 0 && NT(tab, pos - 3 * 19 + 3) == 0 && NT(tab, pos - 2 * 19 + 2) == 0 && NT(tab, pos - 1 * 19 + 1) == 0))
			return tab[pos];
		}
		else if ((pos % 19 < 15 && tab[pos + 1] == tab[pos] && tab[pos + 2] == tab[pos] && tab[pos + 3] == tab[pos] && tab[pos + 4] == tab[pos]) ||
			(pos % 19 < 16 && pos % 19 > 0 && tab[pos + 1] == tab[pos] && tab[pos + 2] == tab[pos] && tab[pos + 3] == tab[pos] && tab[pos - 1] == tab[pos]) ||
			(pos % 19 < 17 && pos % 19 > 1 && tab[pos + 1] == tab[pos] && tab[pos + 2] == tab[pos] && tab[pos - 2] == tab[pos] && tab[pos - 1] == tab[pos]) ||
			(pos % 19 < 18 && pos % 19 > 2 && tab[pos + 1] == tab[pos] && tab[pos - 3] == tab[pos] && tab[pos - 2] == tab[pos] && tab[pos - 1] == tab[pos]) ||
			(pos % 19 < 19 && pos % 19 > 3 && tab[pos - 4] == tab[pos] && tab[pos - 3] == tab[pos] && tab[pos - 2] == tab[pos] && tab[pos - 1] == tab[pos]) ||
			(pos < 361 - 4 * 19 && tab[pos + 1 * 19] == tab[pos] && tab[pos + 2 * 19] == tab[pos] && tab[pos + 3 * 19] == tab[pos] && tab[pos + 4 * 19] == tab[pos]) ||
			(pos < 361 - 3 * 19 && tab[pos + 1 * 19] == tab[pos] && tab[pos + 2 * 19] == tab[pos] && tab[pos + 3 * 19] == tab[pos] && tab[pos - 1 * 19] == tab[pos]) ||
			(pos < 361 - 2 * 19 && tab[pos + 1 * 19] == tab[pos] && tab[pos + 2 * 19] == tab[pos] && tab[pos - 2 * 19] == tab[pos] && tab[pos - 1 * 19] == tab[pos]) ||
			(pos < 361 - 1 * 19 && tab[pos + 1 * 19] == tab[pos] && tab[pos - 3 * 19] == tab[pos] && tab[pos - 2 * 19] == tab[pos] && tab[pos - 1 * 19] == tab[pos]) ||
			(pos < 361 && tab[pos - 4 * 19] == tab[pos] && tab[pos - 3 * 19] == tab[pos] && tab[pos - 2 * 19] == tab[pos] && tab[pos - 1 * 19] == tab[pos]) ||
			(pos % 19 < 15 && pos < 361 - 4 * 19 && tab[pos + 1 * 19 + 1] == tab[pos] && tab[pos + 2 * 19 + 2] == tab[pos] && tab[pos + 3 * 19 + 3] == tab[pos] && tab[pos + 4 * 19 + 4] == tab[pos]) ||
			(pos % 19 < 16 && pos < 361 - 3 * 19 && tab[pos + 1 * 19 + 1] == tab[pos] && tab[pos + 2 * 19 + 2] == tab[pos] && tab[pos + 3 * 19 + 3] == tab[pos] && tab[pos - 1 * 19 - 1] == tab[pos]) ||
			(pos % 19 < 17 && pos < 361 - 2 * 19 && tab[pos + 1 * 19 + 1] == tab[pos] && tab[pos + 2 * 19 + 2] == tab[pos] && tab[pos - 2 * 19 - 2] == tab[pos] && tab[pos - 1 * 19 - 1] == tab[pos]) ||
			(pos % 19 < 18 && pos < 361 - 1 * 19 && tab[pos + 1 * 19 + 1] == tab[pos] && tab[pos - 3 * 19 - 3] == tab[pos] && tab[pos - 2 * 19 - 2] == tab[pos] && tab[pos - 1 * 19 - 1] == tab[pos]) ||
			(pos % 19 < 19 && pos < 361 && tab[pos - 4 * 19 - 4] == tab[pos] && tab[pos - 3 * 19 - 3] == tab[pos] && tab[pos - 2 * 19 - 2] == tab[pos] && tab[pos - 1 * 19 - 1] == tab[pos]) ||
			(pos % 19 > 3 && pos < 361 - 4 * 19 && tab[pos + 1 * 19 - 1] == tab[pos] && tab[pos + 2 * 19 - 2] == tab[pos] && tab[pos + 3 * 19 - 3] == tab[pos] && tab[pos + 4 * 19 - 4] == tab[pos]) ||
			(pos % 19 > 2 && pos < 361 - 3 * 19 && tab[pos + 1 * 19 - 1] == tab[pos] && tab[pos + 2 * 19 - 2] == tab[pos] && tab[pos + 3 * 19 - 3] == tab[pos] && tab[pos - 1 * 19 + 1] == tab[pos]) ||
			(pos % 19 > 1 && pos < 361 - 2 * 19 && tab[pos + 1 * 19 - 1] == tab[pos] && tab[pos + 2 * 19 - 2] == tab[pos] && tab[pos - 2 * 19 + 2] == tab[pos] && tab[pos - 1 * 19 + 1] == tab[pos]) ||
			(pos % 19 > 0 && pos < 361 - 1 * 19 && tab[pos + 1 * 19 - 1] == tab[pos] && tab[pos - 3 * 19 + 3] == tab[pos] && tab[pos - 2 * 19 + 2] == tab[pos] && tab[pos - 1 * 19 + 1] == tab[pos]) ||
			(pos < 361 && tab[pos - 4 * 19 + 4] == tab[pos] && tab[pos - 3 * 19 + 3] == tab[pos] && tab[pos - 2 * 19 + 2] == tab[pos] && tab[pos - 1 * 19 + 1] == tab[pos]))
			return tab[pos];
	return (0);
}
