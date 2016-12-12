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
	c.weight = INFINITY;
	return (c);
}

IA::Chosen	IA::MaxChosen() /* fonction d'initialisation */
{
	IA::Chosen	c;
	c.p = -1;
	c.weight = -INFINITY;
	return (c);
}

IA::Chosen	IA::min(std::map<int, char> tab, int size, int prof) /* Cette fonction cherche le pire coup possible (joué par l'adversaire) */
{
	IA::Chosen	Min = this->MinChosen(), tmp;
	int		ev;

	std::cout << "Min " << size << std::endl;
	for (std::map<int, char>::iterator it = tab.begin(); it != tab.end(); it++)
		if ((*it).second == '-')
			if (double_trois(tab, (*it).first) == 0 || this->db == 0)
			{
				(*it).second = this->e;
				if ((ev = eval(tab, size)) != 0)
					return (this->newChosen(ev, (*it).first));
				else if (prof > size)
				{
					tmp = this->max(tab, size + 1, prof);
					if (tmp.weight < Min.weight)
						Min = tmp;
					(*it).second = '-';
				}
			}
	return (Min);
}

IA::Chosen	IA::max(std::map<int, char> tab, int size, int prof)	/* Cette fonction cherche le meilleurs coup possible */
{
	IA::Chosen	Max = this->MaxChosen(), tmp;
	int		ev;

	std::cout << "Max " << size << std::endl;
	for (std::map<int, char>::iterator it = tab.begin(); it != tab.end(); it++)		/* pour un nombre de case donné il va tester toutes les possibilité (actuellement toutes les cases) */
		if ((*it).second == '-')
			if (double_trois(tab, (*it).first) == 0 || this->db == 0)
			{
				(*it).second = this->c;
				if ((ev = eval(tab, size)) != 0)									/* si eval est égale à 0 ça signifie que le coup jouer n'est pas déterminant 
																					Cette fonction sera à améliorer avec l'évolution de la fonction eval*/
					return (this->newChosen(ev, (*it).first));
				else if (prof > size)
				{
					tmp = this->min(tab, size + 1, prof);
					if (tmp.weight > Max.weight)
						Max = tmp;
					(*it).second = '-';
				}
			}
	return (Max);
}


int		IA::eval(std::map<int, char> tab, int size) /* cette fonction a pour but d'évaluer le coup qui vient d'être jouer un nombre positif indiquera un coup favorable et un nombre négatif un coup défavorable
													J'ai mis de base 1000 - [nbr de coup] pour donné une valeur à la victoire ou à la défaite */
{
	char	r;
	if ((r = check(tab, this->cc)) == this->c)
		return (1000 - size);
	else if (r == this->e)
		return (-1000 + size);
	return (0);
}

std::map<int, char> IA::Play(std::map<int, char> tab) /* fonction de lancement pas très importante */
{
	IA::Chosen Cho = this->max(tab, 0, 1);
	tab[Cho.p] = this->c;
	return (tab);
}