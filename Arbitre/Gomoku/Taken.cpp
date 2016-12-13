#include "stdafx.h"
#include "Gomoku.h"

int	taken(std::map<int, char> *tab, int pos, int *cap1, int *cap2)
{
	int	t = 0;

	if (pos % 19 < 16 && (*tab)[pos] == (*tab)[pos + 3] &&
		(*tab)[pos + 1] == (*tab)[pos + 2] &&
		(*tab)[pos + 1] != '-' && (*tab)[pos] != (*tab)[pos + 1])
	{
		if ((*tab)[pos] == 'x')
			(*cap1) += 2;
		else
			(*cap2) += 2;
		(*tab)[pos + 1] = '-';
		(*tab)[pos + 2] = '-';
		t++;
	}
	if (pos % 19 > 2 && (*tab)[pos] == (*tab)[pos - 3] &&
		(*tab)[pos - 1] == (*tab)[pos - 2] &&
		(*tab)[pos - 1] != '-' && (*tab)[pos] != (*tab)[pos - 1])
	{
		if ((*tab)[pos] == 'x')
			(*cap1) += 2;
		else
			(*cap2) += 2;
		(*tab)[pos - 1] = '-';
		(*tab)[pos - 2] = '-';
		t++;
	}
	if (pos < 303 && (*tab)[pos] == (*tab)[pos + 19 * 3] &&
		(*tab)[pos + 19] == (*tab)[pos + 19 * 2] &&
		(*tab)[pos + 19] != '-' && (*tab)[pos] != (*tab)[pos + 19])
	{
		if ((*tab)[pos] == 'x')
			(*cap1) += 2;
		else
			(*cap2) += 2;
		(*tab)[pos + 19] = '-';
		(*tab)[pos + 19 * 2] = '-';
		t++;
	}
	if (pos > 56 && (*tab)[pos] == (*tab)[pos - 19 * 3] &&
		(*tab)[pos - 19] == (*tab)[pos - 19 * 2] &&
		(*tab)[pos - 19] != '-' && (*tab)[pos] != (*tab)[pos - 19])
	{
		if ((*tab)[pos] == 'x')
			(*cap1) += 2;
		else
			(*cap2) += 2;
		(*tab)[pos - 19] = '-';
		(*tab)[pos - 2 * 19] = '-';
		t++;
	}
	if (pos < 303 && pos % 19 < 16 &&
		(*tab)[pos] == (*tab)[pos + 3 + 19 * 3] &&
		(*tab)[pos + 1 + 19] == (*tab)[pos + 2 + 19 * 2] &&
		(*tab)[pos + 1 + 19] != '-' && (*tab)[pos] != (*tab)[pos + 1 + 19])
	{
		if ((*tab)[pos] == 'x')
			(*cap1) += 2;
		else
			(*cap2) += 2;
		(*tab)[pos + 1 + 19] = '-';
		(*tab)[pos + 2 + 2 * 19] = '-';
		t++;
	}
	if (pos > 56 && pos % 19 < 16 &&
		(*tab)[pos] == (*tab)[pos + 3 - 19 * 3] &&
		(*tab)[pos + 1 - 19] == (*tab)[pos + 2 - 19 * 2] &&
		(*tab)[pos + 1 - 19] != '-' && (*tab)[pos] != (*tab)[pos + 1 - 19])
	{
		if ((*tab)[pos] == 'x')
			(*cap1) += 2;
		else
			(*cap2) += 2;
		(*tab)[pos - 19 + 1] = '-';
		(*tab)[pos - 2 * 19 + 2] = '-';
		t++;
	}
	if (pos < 303 && pos % 19 > 2 &&
		(*tab)[pos] == (*tab)[pos - 3 + 19 * 3] &&
		(*tab)[pos - 1 + 19] == (*tab)[pos - 2 + 19 * 2] &&
		(*tab)[pos - 1 + 19] != '-' && (*tab)[pos] != (*tab)[pos - 1 + 19])
	{
		if ((*tab)[pos] == 'x')
			(*cap1) += 2;
		else
			(*cap2) += 2;
		(*tab)[pos - 1 + 19] = '-';
		(*tab)[pos - 2 + 2 * 19] = '-';
		t++;
	}
	if (pos > 56 && pos % 19 > 2 &&
		(*tab)[pos] == (*tab)[pos - 3 - 19 * 3] &&
		(*tab)[pos - 1 - 19] == (*tab)[pos - 2 - 19 * 2] &&
		(*tab)[pos - 1 - 19] != '-' && (*tab)[pos] != (*tab)[pos - 1 - 19])
	{
		if ((*tab)[pos] == 'x')
			(*cap1) -= 2;
		else
			(*cap2) -= 2;
		(*tab)[pos - 19 - 1] = '-';
		(*tab)[pos - 2 * 19 - 2] = '-';
		t++;
	}
	return (t);
}
