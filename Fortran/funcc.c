#define chain(i,j) chain.chainf(i,j)

typedef double (*dfunc)(int *,int *);

double add(int *a,int *b){
	return *a+*b;
}
extern struct{
	int a,b;
	dfunc c;
}chain;

int main(){
	chain.c=add;

}

