#include "philosopher.h"

int		ft_init_eating_status(t_all *all)
{
	if ((all->eating = malloc(sizeof(sem_t) *
			all->arg_nbr_philosopher)) == NULL)
		return (TRUE);
	return (FALSE);
}

int		ft_init_philosopher(t_all *all)
{
	int i;

	if ((all->array_phi = malloc(sizeof(t_philosopher) *
			all->arg_nbr_philosopher)) == NULL)
		return (TRUE);
	i = -1;
	while (++i < all->arg_nbr_philosopher)
	{
		all->array_phi[i].starter = (i == all->arg_nbr_philosopher - 1) ?
				TRUE : FALSE;
		all->array_phi[i].my_id = i;
		all->array_phi[i].nbr_meal = 0;
		gettimeofday(&all->array_phi[i].start, NULL);
		all->array_phi[i].eating = &all->eating[i];
		all->array_phi[i].eating_status = FALSE;
		all->array_phi[i].arg_time_to_die = all->arg_time_to_die;
		all->array_phi[i].arg_time_to_eat = all->arg_time_to_eat;
		all->array_phi[i].arg_time_to_sleep = all->arg_time_to_sleep;
		all->array_phi[i].arg_must_eat = all->arg_must_eat;
		all->array_phi[i].sem_start = all->sem_start;
		all->array_phi[i].sem_forks = all->sem_forks;
		all->array_phi[i].sem_speak = all->sem_speak;
		all->array_phi[i].sem_end = all->sem_end;
	}
	return (FALSE);
}

int		ft_init_start(t_all *all)
{
	gettimeofday(&all->start, NULL);
	return (FALSE);
}

int		ft_init_synchronisation_start(t_all *all)
{
	int i;

	i = 0;
	while (i < all->arg_nbr_philosopher)
	{
		all->array_phi[i].start.tv_sec = all->start.tv_sec;
		all->array_phi[i].start.tv_usec = all->start.tv_usec;
		i++;
	}
	return (FALSE);
}

int		ft_init_processus(t_all *all)
{
	int i;

	if ((all->array_thr = malloc(sizeof(pthread_t) *
			all->arg_nbr_philosopher)) == NULL)
		return (TRUE);
	if ((all->array_pid = malloc(sizeof(pid_t) *
			all->arg_nbr_philosopher)) == NULL)
		return (TRUE);
	i = 0;
	while (i < all->arg_nbr_philosopher)
	{
		if ((all->array_pid[i] = fork()) == 0)
			ft_processus(&all->array_phi[i]);
		usleep(WAIT_PHI);
		i++;
	}
	return (FALSE);
}
