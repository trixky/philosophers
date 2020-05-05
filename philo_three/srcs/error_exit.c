#include "philosopher.h"

int		ft_error(char *str, int ret_value)
{
	ft_putstr(str);
	return (ret_value);
}

int		ft_kill_everyone(t_all *all)
{
	int i;

	i = 0;
	while (i < all->arg_nbr_philosopher)
	{
		kill(all->array_pid[i], 15);
		i++;
	}
	return (FALSE);
}

void	ft_unlink(void)
{
	sem_unlink(SEM_START);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_SPEAK);
	sem_unlink(SEM_END);
}

int		ft_free(t_all *all, int ret_value)
{
	if (all->array_phi != NULL)
	{
		free(all->array_phi);
		if (all->array_thr != NULL)
		{
			free(all->array_thr);
			if (all->array_pid != NULL)
			{
				free(all->array_pid);
				all->array_pid = NULL;
			}
			all->array_thr = NULL;
		}
		all->array_phi = NULL;
	}
	sem_close(all->sem_start);
	sem_close(all->sem_forks);
	sem_close(all->sem_speak);
	sem_close(all->sem_end);
	ft_unlink();
	return (ret_value);
}
