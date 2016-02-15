
int modpow(int a, int n)
{
	int k = 1;
	while (n) {
		k *= (n % 2 == 1 ? a : 1);
		k %= mod;
		n /= 2;
		a *= a;
		a %= mod;
	}
	return k;
}
