#include <stdio.h>
#include <stdlib.h>

int main() {
//1
int fun(int n)

int count = 0;
for (int i = n; i > 0; i /= 2)
   for (int j = 0;j < i; j++)
count +=1;
return count;
//time complexity=log(n)

//2
int a=0,b=0;
for(i=0;i<N;i++){
	a=a+rand();
}
for(j=0;j<M;j++){
	b=b+rand();
}
//time complexity=N+M


//4
for(int i=0;i<n;i++){
	i *= k;
	}
//time complexity=log(n)

//5
int i, j, k = 0;
	for (i= n / 2; i <= n; i++) {
		for (j=2; j <= n; j = j * 2)
			k = k + n / 2;
			}
//time complexity=n*log(n)

//6
int i=0,i=N;
while(i>0){
	a+=i;
	i/=2;
}
//O(log(N)

//7
int value = 0;
	for(int i=0;i<n;i++){	
	a += i;
	}

for(int j=0;j<i;j++){
	value += 1;        }
//O(n*n)
		return 0;  
}
