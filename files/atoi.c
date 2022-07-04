
#include "../includes/game_utils.h"

bool	is_instr(char car, char *st)
{
	while (*st != '\0')
	{
		if (car == *st)
		{
			return (true);
		}
		st++;
	}
	return (false);
}

bool	cmeno(char st)
{
	if (st == 45 || st == 43)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

bool	iss(char car)
{
	return (is_instr(car, "\t\n\v\f\r "));
}

bool	isn(char car)
{
	if (car >= '0' && car <= '9')
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

int		ft_atoi(char *str)
{
	int ris;
	int sign;

	ris = 0;
	sign = 1;
	while (iss(*str))
		str++;
	while (cmeno(*str))
	{
		if (*str == 45)
		{
			sign = sign * -1;
		}
		str++;
	}
	while (isn(*str))
	{
		ris = ris * 10;
		ris = ris + *str - 48;
		str++;
	}
	return (ris * sign);
}
