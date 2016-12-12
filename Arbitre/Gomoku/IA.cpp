#include "stdafx.h"
#include "IA.hh"

IA::IA(int _cc, int _db, char _c, char _e)
{
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
	c.p = -1;
	c.weight = 2147483647;
	return (c);
}

IA::Chosen	IA::MaxChosen() /* fonction d'initialisation */
{
	IA::Chosen	c;
	c.p = -1;
	c.weight = -2147483647;
	return (c);
}

IA::Chosen	IA::min(std::map<int, char> tab, int size, int prof, IA::Chosen alpha, IA::Chosen beta) /* Cette fonction cherche le pire coup possible (joué par l'adversaire) */
{
	IA::Chosen	Min = beta, tmp;
	int		ev;

	for (std::map<int, char>::iterator it = tab.begin(); it != tab.end(); it++)
	{
		if ((*it).second == '-')
		{
			(*it).second = this->e;
			if (double_trois(tab, (*it).first) == 0 || this->db == 0)
			{
				ev = eval(tab, size, (*it).first);
				tmp = this->newChosen(ev, (*it).first);
				if (tmp.weight < Min.weight)
					Min = tmp;
				if (prof > size)
				{
					tmp = this->max(tab, size + 1, prof, alpha, Min);
					if (tmp.weight < Min.weight)
						Min = tmp;
				}
			}
			(*it).second = '-';
		}
		if (Min.weight >= beta.weight)
			break;
	}
	return (Min);
}

IA::Chosen	IA::max(std::map<int, char> tab, int size, int prof, IA::Chosen alpha, IA::Chosen beta)	/* Cette fonction cherche le meilleurs coup possible */
{
	IA::Chosen	Max = alpha, tmp;
	int		ev;

	for (std::map<int, char>::iterator it = tab.begin(); it != tab.end(); it++)		/* pour un nombre de case donné il va tester toutes les possibilité (actuellement toutes les cases) */
	{
		if ((*it).second == '-')
		{
			(*it).second = this->c;
			if (double_trois(tab, (*it).first) == 0 || this->db == 0)
			{
				ev = eval(tab, size, (*it).first);
				tmp = this->newChosen(ev, (*it).first);
				if (tmp.weight > Max.weight)
					Max = tmp;
				if (prof > size)
				{
					tmp = this->min(tab, size + 1, prof, Max, beta);
					if (tmp.weight > Max.weight)
						Max = tmp;
				}
			(*it).second = '-';
			}
		}
		if (Max.weight <= alpha.weight)
			break;
	}
	return (Max);
}

int		IA::eval(std::map<int, char> tab, int size, int pos) /* cette fonction a pour but d'évaluer le coup qui vient d'être jouer un nombre positif indiquera un coup favorable et un nombre négatif un coup défavorable
													J'ai mis de base 1000 - [nbr de coup] pour donné une valeur à la victoire ou à la défaite */
{
	char	r;
	if ((r = check(tab, this->cc, pos)) == this->c)
		return (1000 - size);
	else if (r == this->e)
		return (-1000 + size);
	return (0);
}

void IA::Play(std::map<int, char> *tab, int *cap0, int *cap1) /* fonction de lancement pas très importante */
{
	IA::Chosen Cho = this->max(*tab, 0, 1, this->MaxChosen(), this->MinChosen());
	std::cout << Cho.p << std::endl << Cho.weight << std::endl;
	add_pos(tab, this->c, Cho.p / 19, Cho.p % 19);
	taken(tab, Cho.p, cap0, cap1);
}
