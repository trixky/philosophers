#include "philosopher.h"

int	ft_is_eating(t_philosopher *phi)
{
	int	ret;

	sem_wait(phi->eating);
	ret = phi->eating_status;
	sem_post(phi->eating);
	return (ret);
}

int	ft_someone_is_dead(t_all *all)
{
	int i;

	i = 0;
	while (i < all->arg_nbr_philosopher)
	{
		if (ft_get_time(&all->array_phi[i].last_meal) > all->arg_time_to_die &&
				ft_is_eating(&all->array_phi[i]) == FALSE)
		{
			pthread_mutex_lock(&all->speak);
			ft_putnbr(ft_get_time(&all->start), NULL, NULL);
			write(1, "   ", 3);
			ft_putnbr(i + 1, NULL, NULL);
			write(1, "   ", 3);
			write(1, "is died\n", 8);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int	ft_everyone_is_satisfied(t_all *all)
{
	int i;

	i = 0;
	if (all->arg_must_eat == ERROR)
		return (FALSE);
	while (i < all->arg_nbr_philosopher)
	{
		if (all->array_phi[i].nbr_meal < all->arg_must_eat)
			return (FALSE);
		i++;
	}
	pthread_mutex_lock(&all->speak);
	return (TRUE);
}
