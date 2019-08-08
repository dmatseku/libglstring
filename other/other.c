#include <lgs.h>

char*	strjoin(char* str1, char* str2)
{
	char*	res;

	if (!(res = (char*)malloc(sizeof(char) * (strlen(str1) + strlen(str2)+ 1))))
		return (0);
	res[0] = 0;
	strcat(res, str1);
	strcat(res, str2);
	return (res);
}
