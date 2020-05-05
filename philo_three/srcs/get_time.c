#include "philosopher.h"

int		ft_get_time(struct timeval *start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((int)((end.tv_sec - start->tv_sec) * 1000000 +
	(end.tv_usec - start->tv_usec)) / 1000);
}
