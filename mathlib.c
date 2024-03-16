float prod(float multiplicand, int multiplicator){
	int is_negative = 0;
	if(multiplicator < 0){
		multiplicator = - multiplicator;
		is_negative = 1;
	}
	if(multiplicator == 0) return 0;
	int res = multiplicand;
	for(int i = 1; i < multiplicator; i++) res = res + multiplicand;
	
	if(is_negative) return - res;
	return res;
}

float pow(float base, unsigned int exp){
	if(exp == 0) return 1;
	float res = base;
	for(int i = 1; i < exp; i++) res = res * base;
	return res;
}

int rem(unsigned int dividend, unsigned int divisor){
	while(dividend >= divisor) dividend = dividend - divisor;
	return dividend;
}

float div(unsigned int dividend, unsigned int divisor){
	int safe_memory = 0;
	float quotient = 0.0;
	float increment = 1;
	while(dividend != 0 && safe_memory < 256){
		dividend = dividend - divisor;
		quotient = quotient + increment;

		if(dividend < divisor){
			dividend = dividend * 10;
			increment = increment * 0.1;
		}

		safe_memory++;
	}
	return quotient;
}

int fact(unsigned int num){
	if(num == 0) return 1;
	for(int i = (num - 1); i >= 1; i--) num = num * i;
	return num;
}

int peer_succ(unsigned int num){
	if(rem(num, 2) == 0) return num + 2;
	else return num + 1;
}

int is_prime(unsigned int num){
	if(num == 0 || num == 1) return -1;

	int divisions = 0;
	for (int i = 1; i <= num; i++){
		if(rem(num, i) == 0) divisions++;	
	}
	
	if(divisions > 2) return -1;
	return 1;
}

int nth_fib(int nth){
	int ult = 1;
	int penult = 1;
	int nth_res = -1;

	if(nth == 1) return penult;
	else if(nth == 2) return ult;

	for (int i = 2; i < nth; i++){
		nth_res = ult + penult;
		penult = ult;
		ult = nth_res;
	}

	return nth_res;
}

int sum_ricci(int nth, int n1, int n2){
	int ult = n2;
	int penult = n1;
	int nth_res = -1;
	int sum = 0;

	if(nth == 1) return n1;
	else if (nth == 2) return n2;

	for (int i = 2; i < nth; i++){
		nth_res = ult + penult;
		penult = ult;
		ult = nth_res;
		sum = sum + nth_res;
	}

	return sum + (n1 + n2);
}

int nth_ricci(int nth, int n1, int n2){
	int ult = n2;
	int penult = n1;
	int nth_res = -1;

	if(nth == 1) return n1;
	else if (nth == 2) return n2;

	for (int i = 2; i < nth; i++){
		nth_res = ult + penult;
		penult = ult;
		ult = nth_res;
	}

	return nth_res;
}

int odd_succ(unsigned int num){
	if(rem(num, 2) != 0) return num + 2;
	else return num + 1;
	return -1;
}

float euler(unsigned int n){
	if(n < 10) return -1;

	float euler = 0.0;
	for (int i = 0; i < n; i++){
		euler = euler + 1/(float)(fact(i));
	}

	return euler;
}

float calc_s_fib(unsigned int nth){
	int term = nth_fib(nth);
	float result;
	for (int i = 0; i < term; i++){
		result = result + (i + 1)/(float)(term - i);
	}
	return result;
}

float calc_s_succ(unsigned int n){
	int successor = peer_succ(n);
	float result;
	for (int i = 0; i < successor; i++){
		result = result + (i + 1)/(float)(successor - i);			
	}
	return result;
}
double cube_root_bin_search(double num) {
	double init = 0.0;
	double end = num;
	double middle;

	while (end - init > 0.00001) {
		middle = (init + end) / 2;
		if (pow(middle, 3) < num) {
			init = middle;
		} else {
			end = middle;
		}
	}
	return (init + end) / 2;
}

int is_perfect(int num){
	int sum = 0;
	for (int i = 1; i < num; i++){
		if(rem(num, i) == 0) sum = sum + i;
	}
	if(sum == num) return 1;
	else return -1;
}

int succ_is_perfect(unsigned int n){
	int succ_int = peer_succ(n);
	int res = is_perfect(succ_int);
	if(res == 1) return 1;	
	return -1;
}

int nth_fetuccine(unsigned int n, int n1, int n2){
	int ult = n2;
	int penult = n1;
	int term;

	if(n == 1) return n1;
	else if(n == 2) return n2;

	for(int i = 2; i < n; i++){
		if(rem(i, 2) == 0){
			term = ult + penult;
			penult = ult;
			ult = term;
		}
		else if (rem(i, 2) != 0){
			term = ult - penult;
			penult = ult;
			ult = term;
		}
	}
	return term;
}

float pi() {
	int odd;
	float S = 0, t, t2;

	for (int i = 0; i < 51; i++)
	{
		odd = 2 * i + 1;
		S += (pow(-1, i)) / pow(odd, 3);
	}

	return cube_root_bin_search(S*32);
}

float sen(float x) {
	int odd;
	float sen = 0, rad;

	rad = x * (pi()/180);

	for (int i = 0; i < 15; i++)
	{
		odd = (2*i) + 1;
		sen += (pow(-1, i) * pow(rad, odd)) / fact(odd);
	}

	return sen;
}

float cos(unsigned int x){
	float x_rad = (x * pi())/180;
	double result = 0.0;
	for (int i = 0; i < 15; i++){
		float pow1 = pow(-1, i);
		float pow2 = pow(x_rad, 2 * i);
		long int f = fact(2 * i);	
		result = result + ((pow1 * pow2) / f);
	}
	return result;
}

int is_triangular(int num) {
	int i, result;

	for(i = 1; prod(prod(i, i+1), i+2) <= num; i++)
		result = prod(prod(i, i+1), i+2);
	
	return result == num ? 1 : 0;
}

double sum_nth_ricci(int nth, int n1, int n2) {
	int ricci;
	double sum = 0;

	ricci = nth_ricci(nth, n1, n2);

	for (int i = 1; i <= ricci; i++)
	{
		sum += 1 / pow(i, i);
	}
	
	return sum;
}

int cp_nums(unsigned int n1, unsigned int n2) {
	if (is_prime(n1) == 1 && is_prime(n2) == 1) return 1;
	int result = 1;
	for (int i = 2; i <= n1; i++){
		if(rem(n1, i) == 0 && rem(n2, i) == 0){
			result = -1;
			break;
		}
	}
	return result;
}