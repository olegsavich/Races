#include "../inc/minilibmx.h"

int mx_atoi(const char *str) {
  	int sign = 0;
    int plus = 0;
  	int digit = 0;
  	for (unsigned int i = 0; str[i]; ++i) {
    	if (!mx_isspace(str[i])) {
      		if (mx_isdigit(str[i]))
        		digit = digit * 10 + (str[i] - '0');
      		else if (mx_isspace(str[i + 1]) && str[i] == '-')
        		return NOT_INT;
      		else {
        		if (str[i] == '-') {
                    if (!str[i + 1])
                        return NOT_INT;
          			else if (sign == 0 && plus == 0)
          				sign = 1;
          			else
          				return NOT_INT;//sign == 1 ? -digit : digit;
        		}
                else if (str[i] == '+') {
                    if (!str[i + 1])
                        return NOT_INT;
                    else if (plus == 0 && sign == 0) {
                        plus = 1;
                    }
                    else
                        return NOT_INT;//sign == 1 ? -digit : digit;
                }
        		else
        			return NOT_INT;//sign == 1 ? -digit : digit;
      		}
    	}
  	}
  	return sign == 1 ? -digit : digit;
}
