#include "philosopher.h"

int	ft_init_thread(t_all *all)
{
	int i;

	if ((all->array_thr = malloc(sizeof(pthread_t) *
			all->arg_nbr_philosopher)) == NULL)
		return (TRUE);
	i = 0;
	while (i < all->arg_nbr_philosopher)
	{
		gettimeofday(&all->array_phi[i].last_meal, NULL);
		pthread_create(&all->array_thr[i], NULL, ft_thread, &all->array_phi[i]);
		pthread_detach(all->array_thr[i]);
		usleep(WAIT_PHI);
		i++;
	}
	return (FALSE);
}
