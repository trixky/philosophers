#include "philosopher.h"

void	*ft_thread(void *arg)
{
	t_philosopher *phi;

	phi = arg;
	while (1)
	{
		ft_take_fork(phi);
		ft_speak(phi, EAT);
		gettimeofday(&phi->last_meal, NULL);
		ft_set_eating_status(phi, TRUE);
		usleep(phi->arg_time_to_eat);
		phi->nbr_meal++;
		ft_return_fork(phi);
		if (phi->arg_must_eat != ERROR && phi->nbr_meal >= phi->arg_must_eat)
			return (NULL);
		ft_set_eating_status(phi, FALSE);
		ft_speak(phi, SLEEP);
		usleep(phi->arg_time_to_sleep);
		ft_speak(phi, THINK);
	}
	return (NULL);
}
