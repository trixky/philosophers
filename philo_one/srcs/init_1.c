#include "philosopher.h"

int	ft_init_null(t_all *all)
{
	all->array_frk = NULL;
	all->array_phi = NULL;
	all->array_thr = NULL;
	return (FALSE);
}

int	ft_init_speak(t_all *all)
{
	pthread_mutex_init(&all->speak, NULL);
	pthread_mutex_unlock(&all->speak);
	return (FALSE);
}

int	ft_init_fork(t_all *all)
{
	int i;
	int nbr_forks;

	nbr_forks = (all->arg_nbr_philosopher == 1) ? 2 : all->arg_nbr_philosopher;
	if ((all->array_frk = malloc(sizeof(pthread_mutex_t) * nbr_forks)) == NULL)
		return (TRUE);
	i = 0;
	while (i < nbr_forks)
	{
		pthread_mutex_init(&all->array_frk[i], NULL);
		pthread_mutex_unlock(&all->array_frk[i]);
		i++;
	}
	return (FALSE);
}

int	ft_init_philosopher(t_all *all)
{
	int i;

	if ((all->array_phi = malloc(sizeof(t_philosopher) *
			all->arg_nbr_philosopher)) == NULL)
		return (TRUE);
	i = -1;
	while (++i < all->arg_nbr_philosopher)
	{
		all->array_phi[i].my_id = i;
		all->array_phi[i].nbr_meal = 0;
		all->array_phi[i].start = &all->start;
		all->array_phi[i].speak = &all->speak;
		pthread_mutex_init(&all->array_phi[i].eating, NULL);
		pthread_mutex_unlock(&all->array_phi[i].eating);
		all->array_phi[i].eating_status = FALSE;
		all->array_phi[i].arg_time_to_eat = all->arg_time_to_eat;
		all->array_phi[i].arg_time_to_sleep = all->arg_time_to_sleep;
		all->array_phi[i].arg_must_eat = all->arg_must_eat;
		all->array_phi[i].left_fork = &all->array_frk[i];
		if (i == all->arg_nbr_philosopher - 1 && all->arg_nbr_philosopher != 1)
			all->array_phi[i].right_fork = &all->array_frk[0];
		else
			all->array_phi[i].right_fork = &all->array_frk[i + 1];
	}
	return (FALSE);
}

int	ft_init_start(t_all *all)
{
	gettimeofday(&all->start, NULL);
	return (FALSE);
}
