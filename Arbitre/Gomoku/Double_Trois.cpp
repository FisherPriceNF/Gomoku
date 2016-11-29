#include "stdafx.h"
#include "Gomoku.h"

int		alligne_trois(std::map<int, char> tab, int pos, int *pos2, int *pos3)
{
	int	nb = 0;

	if (tab[pos] == tab[pos + 1] && tab[pos] == tab[pos + 2] &&
		tab[pos + 3] == '-' && tab[pos - 1] == '-')
	{
		*pos2 = pos + 1;
		*pos3 = pos + 2;
		nb++;
	}
	if (tab[pos] == tab[pos + 1] && tab[pos] == tab[pos + 3] &&
		tab[pos + 2] == '-' && tab[pos - 1] == '-')
	{
		*pos2 = pos + 1;
		*pos3 = pos + 3;
		nb++;
	}
	if (tab[pos] == tab[pos + 2] && tab[pos] == tab[pos + 3] &&
		tab[pos + 1] == '-' && tab[pos - 1] == '-')
	{
		*pos2 = pos + 2;
		*pos3 = pos + 3;
		nb++;
	}
	if (tab[pos] == tab[pos - 1] && tab[pos] == tab[pos + 2] &&
		tab[pos + 1] == '-' && tab[pos - 2] == '-')
	{
		*pos2 = pos - 1;
		*pos3 = pos + 2;
		nb++;
	}
	if (tab[pos] == tab[pos + 1] && tab[pos] == tab[pos - 1] &&
		tab[pos + 2] == '-' && tab[pos - 2] == '-')
	{
		*pos2 = pos - 1;
		*pos3 = pos + 1;
		nb++;
	}
	if (tab[pos] == tab[pos - 2] && tab[pos] == tab[pos + 1] &&
		tab[pos - 1] == '-' && tab[pos + 2] == '-')
	{
		*pos2 = pos + 1;
		*pos3 = pos - 2;
		nb++;
	}
	if (tab[pos] == tab[pos - 2] && tab[pos] == tab[pos - 3] &&
		tab[pos + 1] == '-' && tab[pos - 1] == '-')
	{
		*pos2 = pos - 2;
		*pos3 = pos - 3;
		nb++;
	}
	if (tab[pos] == tab[pos - 1] && tab[pos] == tab[pos - 3] &&
		tab[pos - 2] == '-' && tab[pos + 1] == '-')
	{
		*pos2 = pos - 1;
		*pos3 = pos - 3;
		nb++;
	}
	if (tab[pos] == tab[pos - 1] && tab[pos] == tab[pos - 2] &&
		tab[pos - 3] == '-' && tab[pos + 1] == '-')
	{
		*pos2 = pos - 1;
		*pos3 = pos - 2;
		nb++;
	}

	if (tab[pos] == tab[pos + 19] && tab[pos] == tab[pos + 2 * 19] &&
		tab[pos + 3 * 19] == '-' && tab[pos - 19] == '-')
	{
		*pos2 = pos + 19;
		*pos3 = pos + 2 * 19;
		nb++;
	}
	if (tab[pos] == tab[pos + 19] && tab[pos] == tab[pos + 3 * 19] &&
		tab[pos + 2 * 19] == '-' && tab[pos - 19] == '-')
	{
		*pos2 = pos + 19;
		*pos3 = pos + 3 * 19;
		nb++;
	}
	if (tab[pos] == tab[pos + 2 * 19] && tab[pos] == tab[pos + 3 * 19] &&
		tab[pos + 19] == '-' && tab[pos - 19] == '-')
	{
		*pos2 = pos + 2 * 19;
		*pos3 = pos + 3 * 19;
		nb++;
	}
	if (tab[pos] == tab[pos - 19 * 2] && tab[pos] == tab[pos + 19] &&
		tab[pos + 2 * 19] == '-' && tab[pos - 2 * 19] == '-')
	{
		*pos2 = pos - 19 * 2;
		*pos3 = pos + 19;
		nb++;
	}
	if (tab[pos] == tab[pos - 19] && tab[pos] == tab[pos + 19] &&
		tab[pos + 2 * 19] == '-' && tab[pos - 2 * 19] == '-')
	{
		*pos2 = pos - 19;
		*pos3 = pos + 19;
		nb++;
	}
	if (tab[pos] == tab[pos + 19 * 2] && tab[pos] == tab[pos - 19] &&
		tab[pos + 2 * 19] == '-' && tab[pos - 2 * 19] == '-')
	{
		*pos2 = pos + 19 * 2;
		*pos3 = pos - 19;
		nb++;
	}
	if (tab[pos] == tab[pos - 2 * 19] && tab[pos] == tab[pos - 3 * 19] &&
		tab[pos + 19] == '-' && tab[pos - 19] == '-')
	{
		*pos2 = pos - 2 * 19;
		*pos3 = pos - 3 * 19;
		nb++;
	}
	if (tab[pos] == tab[pos - 19] && tab[pos] == tab[pos - 3 * 19] &&
		tab[pos - 2 * 19] == '-' && tab[pos + 19] == '-')
	{
		*pos2 = pos - 19;
		*pos3 = pos - 3 * 19;
		nb++;
	}
	if (tab[pos] == tab[pos - 19] && tab[pos] == tab[pos - 2 * 19] &&
		tab[pos - 3 * 19] == '-' && tab[pos + 19] == '-')
	{
		*pos2 = pos - 19;
		*pos3 = pos - 2 * 19;
		nb++;
	}

	if (tab[pos] == tab[pos + 1 + 19] && tab[pos] == tab[pos + 2 + 19 * 2] &&
		tab[pos + 3 + 19 * 3] == '-' && tab[pos - 1 - 19] == '-')
	{
		*pos2 = pos + 1 + 19;
		*pos3 = pos + 2 + 19 * 2;
		nb++;
	}
	if (tab[pos] == tab[pos + 1 + 19] && tab[pos] == tab[pos + 3 + 19 * 3] &&
		tab[pos + 2 + 19 * 2] == '-' && tab[pos - 1 - 19] == '-')
	{
		*pos2 = pos + 1 + 19;
		*pos3 = pos + 3 + 19 * 3;
		nb++;
	}
	if (tab[pos] == tab[pos + 2 + 2 * 19] && tab[pos] == tab[pos + 3 + 19 * 3] &&
		tab[pos + 1 + 19] == '-' && tab[pos - 1 - 19] == '-')
	{
		*pos2 = pos + 2 + 2 * 19;
		*pos3 = pos + 3 + 3 * 19;
		nb++;
	}
	if (tab[pos] == tab[pos + 1 + 19] && tab[pos] == tab[pos - 2 - 19 * 2] &&
		tab[pos + 2 + 19 * 2] == '-' && tab[pos - 1 - 19] == '-')
	{
		*pos2 = pos - 2 - 2 * 19;
		*pos3 = pos + 1 + 19;
		nb++;
	}
	if (tab[pos] == tab[pos + 1 + 19] && tab[pos] == tab[pos - 19 - 1] &&
		tab[pos + 2 + 19 * 2] == '-' && tab[pos - 2 - 19 * 2] == '-')
	{
		*pos2 = pos - 1 - 19;
		*pos3 = pos + 1 + 19;
		nb++;
	}
	if (tab[pos] == tab[pos - 1 - 19] && tab[pos] == tab[pos + 2 + 19 * 2] &&
		tab[pos - 2 - 19 * 2] == '-' && tab[pos + 1 + 19] == '-')
	{
		*pos2 = pos + 2 + 2 * 19;
		*pos3 = pos - 1 - 19;
		nb++;
	}
	if (tab[pos] == tab[pos - 2 - 2 * 19] && tab[pos] == tab[pos - 3 - 19 * 3] &&
		tab[pos + 1 + 19] == '-' && tab[pos - 1 - 19] == '-')
	{
		*pos2 = pos - 2 - 2 * 19;
		*pos3 = pos - 3 - 3 * 19;
		nb++;
	}
	if (tab[pos] == tab[pos - 1 - 19] && tab[pos] == tab[pos - 3 - 19 * 3] &&
		tab[pos - 2 - 19 * 2] == '-' && tab[pos + 1 + 19] == '-')
	{
		*pos2 = pos - 1 - 19;
		*pos3 = pos - 3 - 19 * 3;
		nb++;
	}
	if (tab[pos] == tab[pos - 1 - 19] && tab[pos] == tab[pos - 2 - 19 * 2] &&
		tab[pos + 1 + 19] == '-' && tab[pos - 3 - 19 * 3] == '-')
	{
		*pos2 = pos - 1 - 19;
		*pos3 = pos - 2 - 2 * 19;
		nb++;
	}

	if (tab[pos] == tab[pos - 1 + 19] && tab[pos] == tab[pos - 2 + 2 * 19] &&
		tab[pos - 3 + 19 * 3] == '-' && tab[pos + 1 - 19] == '-')
	{
		*pos2 = pos - 1 + 19;
		*pos3 = pos - 2 + 19 * 2;
		nb++;
	}
	if (tab[pos] == tab[pos - 1 + 19] && tab[pos] == tab[pos - 3 + 3 * 19] &&
		tab[pos - 2 + 19 * 2] == '-' && tab[pos + 1 - 19] == '-')
	{
		*pos2 = pos - 1 + 19;
		*pos3 = pos - 3 + 19 * 3;
		nb++;
	}
	if (tab[pos] == tab[pos - 2 + 2 * 19] && tab[pos] == tab[pos - 3 + 3 * 19] &&
		tab[pos - 1 + 19] == '-' && tab[pos + 1 - 19] == '-')
	{
		*pos2 = pos - 2 + 19 * 2;
		*pos3 = pos - 3 + 19 * 3;
		nb++;
	}
	if (tab[pos] == tab[pos - 1 + 19] && tab[pos] == tab[pos + 2 - 19 * 2] &&
		tab[pos + 1 - 19] == '-' && tab[pos - 2 + 19 * 2] == '-')
	{
		*pos2 = pos - 1 + 19;
		*pos3 = pos + 2 - 19 * 2;
		nb++;
	}
	if (tab[pos] == tab[pos - 1 + 19] && tab[pos] == tab[pos + 1 - 19] &&
		tab[pos + 2 - 19 * 2] == '-' && tab[pos - 2 + 19 * 2] == '-')
	{
		*pos2 = pos - 1 + 19;
		*pos3 = pos + 1 - 19;
		nb++;
	}
	if (tab[pos] == tab[pos + 1 - 19] && tab[pos] == tab[pos - 2 + 19 * 2] &&
		tab[pos - 1 + 19] == '-' && tab[pos + 2 - 19 * 2] == '-')
	{
		*pos2 = pos + 1 - 19;
		*pos3 = pos - 2 + 19 * 2;
		nb++;
	}
	if (tab[pos] == tab[pos + 2 - 2 * 19] && tab[pos] == tab[pos + 3 - 3 * 19] &&
		tab[pos - 1 + 19] == '-' && tab[pos + 1 - 19] == '-')
	{
		*pos2 = pos + 2 - 19 * 2;
		*pos3 = pos + 3 - 19 * 3;
		nb++;
	}
	if (tab[pos] == tab[pos + 1 - 19] && tab[pos] == tab[pos + 3 - 3 * 19] &&
		tab[pos + 2 - 19 * 2] == '-' && tab[pos - 1 + 19] == '-')
	{
		*pos2 = pos + 1 - 19;
		*pos3 = pos + 3 - 19 * 3;
		nb++;
	}
	if (tab[pos] == tab[pos + 1 - 19] && tab[pos] == tab[pos + 2 - 2 * 19] &&
		tab[pos + 3 - 19 * 3] == '-' && tab[pos - 1 + 19] == '-')
	{
		*pos2 = pos + 1 - 19;
		*pos3 = pos + 2 - 19 * 2;
		nb++;
	}

	return (nb);
}

int		double_trois(std::map<int, char> tab, int pos)
{
	int	pos2 = 0, pos3 = 0, nb;

	if ((nb = alligne_trois(tab, pos, &pos2, &pos3)) >= 1)
	{
		if (nb > 1)
			return (1);
		else if (alligne_trois(tab, pos2, &pos2, &pos) > 1)
			return (1);
		else if (alligne_trois(tab, pos3, &pos3, &pos) > 1)
			return (1);
	}
	return (0);
}
