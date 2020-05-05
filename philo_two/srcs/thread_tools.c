#include "philosopher.h"

void	ft_speak(t_philosopher *phi, int status)
{
	int		i;
	char	str[300];

	i = 0;
	ft_putnbr(ft_get_time(phi->start), str, &i);
	str[i++] = ' ';
	str[i++] = ' ';
	str[i++] = ' ';
	ft_putnbr(phi->my_id + 1, str, &i);
	if (status == L_FORK)
		ft_std_add_str(str, &i, "   has taken a fork\n");
	else if (status == R_FORK)
		ft_std_add_str(str, &i, "   has taken a fork\n");
	else if (status == EAT)
		ft_std_add_str(str, &i, "   is eating\n");
	else if (status == SLEEP)
		ft_std_add_str(str, &i, "   is sleeping\n");
	else if (status == THINK)
		ft_std_add_str(str, &i, "   is thinking\n");
	str[i++] = '\0';
	pthread_mutex_lock(phi->speak);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(phi->speak);
}

void	ft_take_fork(t_philosopher *phi)
{
	sem_wait(phi->semaphore);
	ft_speak(phi, L_FORK);
	sem_wait(phi->semaphore);
	ft_speak(phi, R_FORK);
}

void	ft_return_fork(t_philosopher *phi)
{
	sem_post(phi->semaphore);
	sem_post(phi->semaphore);
}

void	ft_set_eating_status(t_philosopher *phi, int status)
{
	sem_wait(phi->eating);
	phi->eating_status = status;
	sem_post(phi->eating);
}
