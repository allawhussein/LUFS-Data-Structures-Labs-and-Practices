int find_val(Interpretation In, char v[],int *value)
{
	int i;
	for (i = 0; i < In.size; i++)
	if (!strcmp(In.arr[i].var, v)){
	    *value = In.arr[i].val;
	    return 1;
	}
	return 0;
}


int Evaluate(Interpretation In, Expression E, int *Value) 
{
    int bLeft, bRight, vLeft, vRight;
	if (!E) return 0;
	if (!E->left && !E->right) return find_val(In, E->value,  Value);
	bLeft = Evaluate(In, E->left, &vLeft);
	bRight = Evaluate(In, E->right, &vRight);
	
	if (!strcmp(E->value, "NOT")){
	    if(bLeft || !bRight) return 0;
	    *Value = 1 - vRight;
	    return 1;
	}
	if (!bRight || !bLeft) return 0;
	if (!strcmp(E->value, "AND"))
	    *Value = vLeft && vRight;
	else *Value = vLeft || vRight;
	return 1;
}


int Valid(Interpretation arrayInter[], int NBInter, Expression E)
{
	int i, v;
	for (i = 0; i < NBInter; i++){
	    if (!Evaluate(arrayInter[i], E, &v)) return -1;
	    if (!v) return 0;
	}
	return 1;
}
