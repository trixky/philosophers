#include "philosopher.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_atoi(char *str)
{
	int i;
	int number;

	i = 0;
	number = 0;
	if (str[i] < '0' || str[i] > '9')
		return (ERROR);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - 48;
		i++;
	}
	return (number);
}

void	ft_putnbr(int nb, char *str, int *i)
{
	char c;

	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, str, i);
		ft_putnbr(nb % 10, str, i);
	}
	else
	{
		c = nb + '0';
		if (str == NULL)
			write(1, &c, 1);
		else
		{
			str[*i] = c;
			*i = *i + 1;
		}
	}
}

void	ft_std_add_str(char *dest, int *i, char *src)
{
	int j;

	j = 0;
	while (src[j])
	{
		dest[*i] = src[j];
		*i = *i + 1;
		j++;
	}
}
