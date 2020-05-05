#include "philosopher.h"

int		ft_error(char *str, int ret_value)
{
	ft_putstr(str);
	return (ret_value);
}

void	ft_destroy_forks(t_all *all)
{
	int i;
	int nbr_forks;

	i = 0;
	nbr_forks = (all->arg_nbr_philosopher == 1) ? 2 : all->arg_nbr_philosopher;
	while (i < nbr_forks)
	{
		pthread_mutex_destroy(&all->array_frk[i]);
		i++;
	}
}

void	ft_destroy_eating_mustex(t_all *all)
{
	int i;

	i = 0;
	while (i < all->arg_nbr_philosopher)
	{
		pthread_mutex_destroy(&all->array_phi[i].eating);
		i++;
	}
}

int		ft_free(t_all *all, int ret_value)
{
	if (all->array_frk != NULL)
	{
		free(all->array_frk);
		if (all->array_phi != NULL)
		{
			ft_destroy_forks(all);
			ft_destroy_eating_mustex(all);
			free(all->array_phi);
			if (all->array_thr != NULL)
			{
				free(all->array_thr);
				all->array_thr = NULL;
			}
			all->array_phi = NULL;
		}
		all->array_frk = NULL;
	}
	pthread_mutex_destroy(&all->speak);
	return (ret_value);
}
