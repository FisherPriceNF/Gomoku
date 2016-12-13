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
	c.p = 200;
	c.weight = 2147483647;
	return (c);
}

IA::Chosen	IA::MaxChosen() /* fonction d'initialisation */
{
	IA::Chosen	c;
	c.p = 200;
	c.weight = -2147483647;
	return (c);
}

IA::Chosen	IA::min(std::map<int, char> tab, int size, int prof, IA::Chosen alpha, IA::Chosen beta) /* Cette fonction cherche le pire coup possible (jou� par l'adversaire) */
{
  IA::Chosen	Min = beta, tmp;
  int			ev;

  for (std::map<int, char>::iterator it = tab.begin(); it != tab.end(); it++)
    {
      if ((*it).second == '-' &&
	  ((tab[(*it).first - 1] != '-' && (*it).first % 19 > 0) ||
	   (tab[(*it).first + 1] != '-' && (*it).first % 19 < 18) ||
	   (tab[(*it).first - 19] != '-' && (*it).first / 19 > 0) ||	
	   (tab[(*it).first + 19] != '-' && (*it).first / 19 < 18) ||
	   (tab[(*it).first - 1 + 19] != '-' && (*it).first % 19 > 0 && (*it).first / 19 < 18) ||
	   (tab[(*it).first + 1 - 19] != '-' && (*it).first % 19 < 18 && (*it).first / 19 > 0) ||
	   (tab[(*it).first - 19 - 1] != '-' && (*it).first % 19 > 0 && (*it).first / 19 > 0) ||
	   (tab[(*it).first + 19 + 1] != '-' && (*it).first % 19 < 18 && (*it).first / 19 < 18)))
	{
	  std::cout << "Min " << size << " " << (*it).first << " " << Min.p << " " << Min.weight << std::endl;
	  (*it).second = this->e;
	  if (double_trois(tab, (*it).first) == 0 || this->db == 0)
	    {
	      ev = eval(&tab, size, (*it).first);
	      tmp = this->newChosen(ev, (*it).first);
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

IA::Chosen	IA::max(std::map<int, char> tab, int size, int prof, IA::Chosen alpha, IA::Chosen beta)	/* Cette fonction cherche le meilleurs coup possible */
{
  IA::Chosen	Max = alpha, tmp;
  int			ev;

  for (std::map<int, char>::iterator it = tab.begin(); it != tab.end(); it++)		/* pour un nombre de case donn� il va tester toutes les possibilit� (actuellement toutes les cases) */
    {
      if ((*it).second == '-' &&
	  ((tab[(*it).first - 1] != '-' && (*it).first % 19 > 0) ||
	   (tab[(*it).first + 1] != '-' && (*it).first % 19 < 18) ||
	   (tab[(*it).first - 19] != '-' && (*it).first / 19 > 0) ||
	   (tab[(*it).first + 19] != '-' && (*it).first / 19 < 18) ||
	   (tab[(*it).first - 1 + 19] != '-' && (*it).first % 19 > 0 && (*it).first / 19 < 18) ||
	   (tab[(*it).first + 1 - 19] != '-' && (*it).first % 19 < 18 && (*it).first / 19 > 0) ||
	   (tab[(*it).first - 19 - 1] != '-' && (*it).first % 19 > 0 && (*it).first / 19 > 0) ||
	   (tab[(*it).first + 19 + 1] != '-' && (*it).first % 19 < 18 && (*it).first / 19 < 18)))
	{
	  std::cout << "Max " << size << " " << (*it).first << " " << Max.p << " " << Max.weight << std::endl;
	  (*it).second = this->c;
	  if (double_trois(tab, (*it).first) == 0 || this->db == 0)
	    {
	      ev = eval(&tab, size, (*it).first);
	      tmp = this->newChosen(ev, (*it).first);
	      if (tmp.weight > Max.weight)
		Max = tmp;
	      if (prof > size)
		{
		  tmp = this->min(tab, size + 1, prof, Max, beta);
		  if (-tmp.weight > Max.weight)
		    Max = tmp;
		}
	      (*it).second = '-';
	    }
	  if (Max.weight <= alpha.weight)
	    break;
	}
    }
  return (Max);
}

int		IA::eval(std::map<int, char> *tab, int size, int pos) /* cette fonction a pour but d'�valuer le coup qui vient d'�tre jouer un nombre positif indiquera un coup favorable et un nombre n�gatif un coup d�favorable
									 J'ai mis de base 1000 - [nbr de coup] pour donn� une valeur � la victoire ou � la d�faite */
{
  char	r = 0;
  int		a = 0, b = 0;
  if ((r = check(*tab, this->cc, pos)) == this->c)
    return (1000 - size);
  else if (r == this->e)
    return (-1000 + size);
  r = taken(tab, pos, &a, &b);
  if ((*tab)[pos] == this->c && r > 0)
    return (r * 100 - size);
  else if (r > 0)
    return (-(r * 100 - size));
  if ((tab[(*it).first - 1] == this->c && (*it).first % 19 > 0) ||
      (tab[(*it).first + 1] == this->c && (*it).first % 19 < 18) ||
      (tab[(*it).first - 19] == this->c && (*it).first / 19 > 0) ||	
      (tab[(*it).first + 19] == this->c && (*it).first / 19 < 18) ||
      (tab[(*it).first - 1 + 19] == this->c && (*it).first % 19 > 0 && (*it).first / 19 < 18) ||
      (tab[(*it).first + 1 - 19] == this->c && (*it).first % 19 < 18 && (*it).first / 19 > 0) ||
      (tab[(*it).first - 19 - 1] == this->c && (*it).first % 19 > 0 && (*it).first / 19 > 0) ||
      (tab[(*it).first + 19 + 1] == this->c && (*it).first % 19 < 18 && (*it).first / 19 < 18))
    return (10);
  return (0);
}

void IA::Play(std::map<int, char> *tab, int *cap0, int *cap1) /* fonction de lancement pas tr�s importante */
{
	IA::Chosen Cho = this->max(*tab, 0, 1, this->MaxChosen(), this->MinChosen());
	std::cout << "I play" << std::endl << Cho.p << std::endl << Cho.weight << std::endl;
	std::cout << (*tab)[Cho.p] << std::endl;
	(*tab)[Cho.p] = this->c;
	taken(tab, Cho.p, cap0, cap1);
}
