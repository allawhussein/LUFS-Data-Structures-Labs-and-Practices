// The code isn't working for unknonwn reason

int GCD(Heap L, Heap R)
{
	int gcd = 1;
	int minL = 1, minR = 1;
	
	while (minL == minR){
	    minL = GetMinimum(L);
	    minR = GetMinimum(R);
	    gcd *= minL;
	    DeleteMin(&L);
	    DeleteMin(&R);
	}
	return gcd;
}
