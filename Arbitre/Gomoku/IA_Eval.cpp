#include "stdafx.h"
#include "IA.hh"

/*int		next_char(std::map<int, char> *tab, int size, int pos, char c)
{
	if ((((*tab)[pos - 1] == c && pos % 19 > 0) ||
		((*tab)[pos + 1] == c && pos % 19 < 18) ||
		((*tab)[pos - 19] == c && pos / 19 > 0) ||
		((*tab)[pos + 19] == c && pos / 19 < 18) ||
		((*tab)[pos - 1 + 19] == c && pos % 19 > 0 && pos / 19 < 18) ||
		((*tab)[pos + 1 - 19] == c && pos % 19 < 18 && pos / 19 > 0) ||
		((*tab)[pos - 19 - 1] == c && pos % 19 > 0 && pos / 19 > 0) ||
		((*tab)[pos + 19 + 1] == c && pos % 19 < 18 && pos / 19 < 18)))
		return (20 - size);
	if ((((*tab)[pos - 1] == c && pos % 19 > 1 && (*tab)[pos - 2] == c) ||
		((*tab)[pos + 1] == c && pos % 19 < 17 && (*tab)[pos + 2] == c) ||
		((*tab)[pos - 19] == c && pos / 19 > 1 && (*tab)[pos - 2 * 19] == c) ||
		((*tab)[pos + 19] == c && pos / 19 < 17 && (*tab)[pos + 2 * 19] == c) ||
		((*tab)[pos - 1 + 19] == c && pos % 19 > 1 && pos / 19 < 17 && (*tab)[pos - 2 + 2 * 19] == c) ||
		((*tab)[pos + 1 - 19] == c && pos % 19 < 17 && pos / 19 > 1 && (*tab)[pos + 2 - 2 * 19] == c) ||
		((*tab)[pos - 19 - 1] == c && pos % 19 > 1 && pos / 19 > 1 && (*tab)[pos - 2 * 19 - 2] == c) ||
		((*tab)[pos + 19 + 1] == c && pos % 19 < 17 && pos / 19 < 17 && (*tab)[pos + 2 * 19 + 2] == c)))
		return (30 - size);
	if ((((*tab)[pos - 1] == c && pos % 19 > 2 && (*tab)[pos - 2] == c && (*tab)[pos - 3] == c) ||
		((*tab)[pos + 1] == c && pos % 19 < 16 && (*tab)[pos + 2] == c && (*tab)[pos + 3] == c) ||
		((*tab)[pos - 19] == c && pos / 19 > 2 && (*tab)[pos - 2 * 19] == c && (*tab)[pos - 3 * 19] == c) ||
		((*tab)[pos + 19] == c && pos / 19 < 16 && (*tab)[pos + 2 * 19] == c && (*tab)[pos + 3 * 19] == c) ||
		((*tab)[pos - 1 + 19] == c && pos % 19 > 2 && pos / 19 < 16 && (*tab)[pos - 2 + 2 * 19] == c && (*tab)[pos - 3 + 3 * 19] == c) ||
		((*tab)[pos + 1 - 19] == c && pos % 19 < 16 && pos / 19 > 2 && (*tab)[pos + 2 - 2 * 19] == c && (*tab)[pos + 3 - 3 * 19] == c) ||
		((*tab)[pos - 19 - 1] == c && pos % 19 > 2 && pos / 19 > 2 && (*tab)[pos - 2 * 19 - 2] == c && (*tab)[pos - 3 * 19 - 3] == c) ||
		((*tab)[pos + 19 + 1] == c && pos % 19 < 16 && pos / 19 < 16 && (*tab)[pos + 2 * 19 + 2] == c && (*tab)[pos + 3 * 19 + 3] == c)))
		return (40 - size);
	return (0);
}*/

int		IA::eval2(std::map<int, char> *tab, int size, int pos) /* cette fonction a pour but d'évaluer le coup qui vient d'être jouer un nombre positif indiquera un coup favorable et un nombre négatif un coup défavorable
															  J'ai mis de base 1000 - [nbr de coup] pour donné une valeur à la victoire ou à la défaite */
{
	char	r = 0;
	int		a = 0, b = 0;
	if ((r = check(*tab, this->cc, pos)) == this->c)
		return (100000 - size);
	else if (r == this->e)
		return (-10000 + size);
	r = taken(tab, pos, &a, &b);
	if ((*tab)[pos] == this->c && r > 0)
		return (r * 100 - size);
	else if (r > 0)
		return (-(r * 100 - size));
    /*if ((((*tab)[pos - 1] == this->e && pos % 19 > 2 && (*tab)[pos - 2] == this->e && (*tab)[pos - 3] == '-' && (*tab)[pos + 1] == '-') ||
		((*tab)[pos + 1] == this->e && pos % 19 < 16 && (*tab)[pos + 2] == this->e && (*tab)[pos + 3] == '-' && (*tab)[pos - 1] == '-') ||
		((*tab)[pos - 19] == this->e && pos / 19 > 2 && (*tab)[pos - 2 * 19] == this->e && (*tab)[pos - 3 * 19] == '-' && (*tab)[pos + 19] == '-') ||
		((*tab)[pos + 19] == this->e && pos / 19 < 16 && (*tab)[pos + 2 * 19] == this->e && (*tab)[pos + 3 * 19] == '-' && (*tab)[pos - 19] == '-') ||
		((*tab)[pos - 1 + 19] == this->e && pos % 19 > 2 && pos / 19 < 16 && (*tab)[pos - 2 + 2 * 19] == this->e && (*tab)[pos - 3 + 3 * 19] == '-' && (*tab)[pos + 1 - 19] == '-') ||
		((*tab)[pos + 1 - 19] == this->e && pos % 19 < 16 && pos / 19 > 2 && (*tab)[pos + 2 - 2 * 19] == this->e && (*tab)[pos + 3 - 3 * 19] == '-' && (*tab)[pos - 1 + 19] == '-') ||
		((*tab)[pos - 19 - 1] == this->e && pos % 19 > 2 && pos / 19 > 2 && (*tab)[pos - 2 * 19 - 2] == this->e && (*tab)[pos - 3 * 19 - 3] == '-' && (*tab)[pos + 19 + 1] == '-') ||
		((*tab)[pos + 19 + 1] == this->e && pos % 19 < 16 && pos / 19 < 16 && (*tab)[pos + 2 * 19 + 2] == this->e && (*tab)[pos + 3 * 19 + 3] == '-' && (*tab)[pos - 19 - 1] == '-')))
		return (1000 - size);
	if ((r = next_char(tab, size, pos, this->c)) != 0)
		return (r);
	if ((r = next_char(tab, size, pos, this->e)) != 0)
        return (-r + 10);*/
	return (0);
}

int     IA::eval(std::map<int, char> *tab, int size, int pos)
{
    int result = eval2(tab, size, pos);
    if (result != 0)
        std::cout << "eval result : " << result << std::endl;
    return result;
}
