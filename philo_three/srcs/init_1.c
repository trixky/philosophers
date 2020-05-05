#include "philosopher.h"

int		ft_init_null(t_all *all)
{
	all->array_phi = NULL;
	all->array_thr = NULL;
	all->array_pid = NULL;
	return (FALSE);
}

int		ft_init_sem_start(t_all *all)
{
	if ((all->sem_start = sem_open(SEM_START, O_CREAT, 0, 1)) == SEM_FAILED)
		return (TRUE);
	return (FALSE);
}

int		ft_init_sem_fork(t_all *all)
{
	int nbr_forks;

	nbr_forks = (all->arg_nbr_philosopher == 1) ? 2 : all->arg_nbr_philosopher;
	if ((all->sem_forks = sem_open(SEM_FORKS, O_CREAT, 0, nbr_forks)) ==
			SEM_FAILED)
		return (TRUE);
	return (FALSE);
}

int		ft_init_sem_speak(t_all *all)
{
	if ((all->sem_speak = sem_open(SEM_SPEAK, O_CREAT, 0, 1)) == SEM_FAILED)
		return (TRUE);
	return (FALSE);
}

int		ft_init_sem_end(t_all *all)
{
	if ((all->sem_end = sem_open(SEM_END, O_CREAT, 0, 1)) == SEM_FAILED)
		return (TRUE);
	return (FALSE);
}
