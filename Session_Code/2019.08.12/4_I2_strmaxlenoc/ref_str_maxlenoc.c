// Written by Alexander Carlson (@acarlson)

#include <stdlib.h>
#include <unistd.h>

int cmp(char *a, char *b, int current_len) {
	int i = 0;
	while (i < current_len && a[i] && a[i] == b[i])
		++i;
	if (i >= current_len)
		return (0);
	return (a[i] - b[i]);
}

int cmpall(char *a, char *b, int blen, int current_len) {
	for (int i = 0; i + current_len <= blen; ++i) {
		if (!cmp(a, b+i, current_len))
			return (0);
	}
	return (1);
}

int ft_strlen(char *a) {
	int i = 0;
	while (a[i])
		++i;
	return (i);
}

int main(int argc, char **argv) {
	if (argc < 2)
		goto end;

	int current_len = ft_strlen(argv[1]);
	int max_len = current_len;
	int start = 0;
	
	while (1) {
		int good = 1;
		for (int i = 2; good && i < argc; ++i) {
			if (cmpall(argv[1] + start, argv[i], ft_strlen(argv[i]), current_len))
				good = 0;
		}
		if (!good) {
			if (start + current_len >= max_len) {
				start = 0;
				--current_len;
			}
			else
				++start;
		}
		else
			break ;
	}

	write(1, argv[1] + start, current_len);


end:
	write(1, "\n", 1);

}