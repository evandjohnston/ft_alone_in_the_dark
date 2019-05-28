#include <stdio.h>

unsigned int lcm_hcf(unsigned int a, unsigned int b)
{
  int hcf = (a < b) ? a : b;
  if (a == 0 || b == 0)
    return (0);
  while (hcf > 0)
  {
    if (a % hcf == 0 && b % hcf == 0)
      break;
    else
      hcf--;
  }
  return ((a*b) / hcf);
}

unsigned int	lcm1(unsigned int a, unsigned int b)
{
	int		gcd;
	int		old_a;
	int		old_b;

	gcd = 0;
	old_a = a;
	old_b = b;
	while (1)
	{
		if (a == 0)
			break ;
		b %= a;
		if (b == 0)
			break ;
		a %= b;
	}
	gcd = (!b) ? a : b;
	return (gcd ? (old_a / gcd * old_b) : 0);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int lonum;
	unsigned int hinum;
  unsigned int mult_by = 1;
  unsigned int ans;

	lonum = (a < b) ? a : b;
	if	(a == 0 || b == 0)
		return (0);
	hinum = (lonum == a) ? b : a;
  ans = hinum;
	//lonum * hinum;//To get the max we cannot get a number higher than the multiple of the 2
	while (ans <= (a * b))
	{
    ans = hinum * mult_by;
		if (ans % lonum == 0 && ans % hinum == 0)
			return (ans);
		else
			mult_by++;
	}
  return (ans);
}

int main(void) {
  printf("Hello World\n");
  printf("lcm_hcf: %i\n", lcm_hcf(72, 132));
  printf("lcm_alt: %i\n", lcm1(132, 72));
  printf("lcm: %i", lcm(72, 132));
  return 0;
}