#include<iostream>

using namespace std;

unsigned long long Multiple_1(unsigned long long N){
	unsigned long long sum = 0;
	while(N--){
		if(N%3==0 || N%5==0){
			sum += N;
		}
	}
	return sum;
}

unsigned long long sum_2(unsigned long long N, int factor){
	int i = 1;
	unsigned long long sum = 0;
	while(i*factor < N){
		sum += i * factor;
		++i;
	}

	return sum;
}

unsigned long long Multiple_2(unsigned long long N){
	return sum_2(N, 3) + sum_2(N, 5) - sum_2(N, 15);
}

unsigned long long sum_3(unsigned long long N, int factor){
	N = (N-1) / factor;
	return ((1+N) * N / 2) * factor;
}

unsigned long long Multiple_3(unsigned long long N){
	return sum_3(N, 3) + sum_3(N, 5) - sum_3(N, 15);
}

int main(){
	int T = 0;
	cin >> T;
	while(T--){
		int N = 0;
		cin >> N;
		cout << sum(N, 3) + sum(N, 5) - sum(N, 15) << endl;
	}

	return 0;
}