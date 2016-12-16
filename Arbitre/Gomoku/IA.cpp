#include "stdafx.h"
#include "IA.hh"

int	global = 0;

IA::IA(int _cc, int _db, char _c, char _e)
{
    srand(time(0));
	this->cc = _cc;
	this->db = _db;
	this->c = _c;
	this->e = _e;
}

IA::Chosen	IA::newChosen(int _w, int _p) /* fonction d'initialisation */
{
	IA::Chosen	c;
	c.p = _p;
	c.weight = _w;
	return (c);
}

IA::Chosen	IA::MinChosen() /* fonction d'initialisation */
{
	IA::Chosen	c;
	c.p = rand() % 361;
	c.weight = 247000000;
	return (c);
}

IA::Chosen	IA::MaxChosen() /* fonction d'initialisation */
{
	IA::Chosen	c;
	c.p = rand() % 361;
	c.weight = -247000000;
	return (c);
}

int	next_to(std::map<int, char>::iterator it, std::map<int, char> tab)
{
	if ((tab[(*it).first - 1] == 'x') || (tab[(*it).first - 1] == 'o'))
		return (1);
	if ((tab[(*it).first + 1] == 'x') || (tab[(*it).first + 1] == 'o'))
		return (1);
	if ((tab[(*it).first - 19] == 'x') || (tab[(*it).first - 19] == 'o'))
		return (1);
	if ((tab[(*it).first + 19] == 'x') || (tab[(*it).first + 19] == 'o'))
		return (1);
	if ((tab[(*it).first - 1 + 19] == 'x') || (tab[(*it).first - 1 + 19] == 'o'))
		return (1);
	if ((tab[(*it).first + 1 - 19] == 'x') || (tab[(*it).first + 1 - 19] == 'o'))
		return (1);
	if ((tab[(*it).first - 19 - 1] == 'x') || (tab[(*it).first - 19 - 1] == 'o'))
		return (1);
	if ((tab[(*it).first + 19 + 1] == 'x') || (tab[(*it).first + 19 + 1] == 'o'))
		return (1);
	return 0;
}

IA::Chosen	IA::min(std::map<int, char> tab, int size, int prof, IA::Chosen alpha, IA::Chosen beta)
{
    IA::Chosen	Min = this->MinChosen(), tmp;
    int		ev;

    for (std::map<int, char>::iterator it = tab.begin(); it != tab.end(); it++)
    {
        if ((*it).second == '-' && next_to(it, tab) != 0)
        {
            (*it).second = this->e;
            if (double_trois(tab, (*it).first) == 0 || this->db == 0)
            {
                ev = eval(&tab, size, (*it).first);
				tmp = newChosen(ev, (*it).first);
                if (tmp.weight < Min.weight)
                    Min = tmp;
                if (prof > size)
                {
                    tmp = this->max(tab, size + 1, prof, alpha, Min);
                    if (-tmp.weight < Min.weight)
                        Min = tmp;
                }
            }
            (*it).second = '-';
            if (Min.weight >= beta.weight)
                break;
        }
    }
    return (Min);
}

IA::Chosen	IA::max(std::map<int, char> tab, int size, int prof, IA::Chosen alpha, IA::Chosen beta)
{
    IA::Chosen	Max = this->MaxChosen(), tmp;
    int		ev;

    for (std::map<int, char>::iterator it = tab.begin(); it != tab.end(); it++)
       {
        if ((*it).second == '-' && next_to(it, tab) != 0)
        {
            (*it).second = this->c;
            if (double_trois(tab, (*it).first) == 0 || this->db == 0)
            {
                ev = eval(&tab, size, (*it).first);
                tmp = newChosen(ev, (*it).first);
                if (tmp.weight > Max.weight)
                    Max = tmp;
                if (prof > size)
                {
                    tmp = this->min(tab, size + 1, prof, Max, beta);
                    if (-tmp.weight > Max.weight)
                        Max = tmp;
                }
            }
            (*it).second = '-';
            if (Max.weight <= alpha.weight)
                break;
        }
        }
    return (Max);
}


int IA::Play(std::map<int, char> *tab, int *cap0, int *cap1) /* fonction de lancement pas très importante */
{
	global = 0;
	IA::Chosen Cho = this->max(*tab, 0, 1, this->MaxChosen(), this->MinChosen());
	while ((*tab)[Cho.p] != '-')
	{
		global = 0;
		Cho = this->max(*tab, 0, 1, this->MaxChosen(), this->MinChosen());
	}
	(*tab)[Cho.p] = this->c;
	taken(tab, Cho.p, cap0, cap1);
	return (Cho.p);
}
