#include "philosopher.h"

int		ft_is_eating(t_philosopher *phi)
{
	int	ret;

	sem_wait(phi->eating);
	ret = phi->eating_status;
	sem_post(phi->eating);
	return (ret);
}

void	ft_set_eating_status(t_philosopher *phi, int status)
{
	sem_wait(phi->eating);
	phi->eating_status = status;
	sem_post(phi->eating);
}
