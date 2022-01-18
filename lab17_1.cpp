#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *x,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(x+i);
        if(i>=0&&i%M==M-1) cout << endl;
        else cout << " ";
    }
}

void randData(double *y,int N,int M){
    for(int i = 0; i < N*M; i++){
        *(y+i) = (rand()%101)/100.00 ;
    }
}

void findRowSum(const double *inp,double *sum,int N,int M){
	int remem=0;
	for(int i=0;i<N;i++){
		sum[i] = 0; 
		for(int j=0;j<M;j++){
			*(sum+i)+= *(inp+remem);
			remem++;
		}
	}
}

void findColSum(const double *inp,double *sum,int N,int M){
	for(int i=0;i<M;i++){
		sum[i] = 0; 
		for(int j=0;j<N;j++){
			*(sum+i) +=  *(inp+i+M*j);
		}
	}
}

