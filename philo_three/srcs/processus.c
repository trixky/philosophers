#include "philosopher.h"

void	*ft_processus(t_philosopher *phi)
{
	if (phi->starter == FALSE)
		sem_wait(phi->sem_start);
	usleep(WAIT_PHI);
	sem_post(phi->sem_start);
	gettimeofday(&phi->last_meal, NULL);
	pthread_create(&phi->thread, NULL, ft_end_thread, phi);
	pthread_detach(phi->thread);
	while (1)
	{
		ft_take_fork(phi);
		gettimeofday(&phi->last_meal, NULL);
		ft_set_eating_status(phi, TRUE);
		ft_speak(phi, EAT);
		usleep(phi->arg_time_to_eat);
		phi->nbr_meal++;
		ft_return_fork(phi);
		ft_is_satiated(phi);
		ft_speak(phi, SLEEP);
		ft_set_eating_status(phi, FALSE);
		usleep(phi->arg_time_to_sleep);
		ft_speak(phi, THINK);
	}
	return (NULL);
}
