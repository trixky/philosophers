#include "philosopher.h"

int		ft_error(char *str, int ret_value)
{
	ft_putstr(str);
	return (ret_value);
}

void	ft_destroy_eating_semaphore(t_all *all)
{
	int i;

	i = 0;
	while (i < all->arg_nbr_philosopher)
	{
		sem_close(all->array_phi[i].eating);
		i++;
	}
}

int		ft_free(t_all *all, int ret_value)
{
	int i;

	i = 0;
	if (all->array_phi != NULL)
	{
		ft_destroy_eating_semaphore(all);
		free(all->array_phi);
		if (all->array_thr != NULL)
		{
			free(all->array_thr);
			all->array_thr = NULL;
		}
		all->array_phi = NULL;
	}
	while (i++ < all->arg_nbr_philosopher)
		sem_post(all->semaphore);
	sem_close(all->semaphore);
	sem_unlink(SEMAPHORE);
	pthread_mutex_destroy(&all->speak);
	return (ret_value);
}
