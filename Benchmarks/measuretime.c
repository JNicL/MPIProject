
struct timeval t0,t1,t2;
gettimeofday(&t0, 0);
gettimeofday(&t1, 0);
gettimeofday(&t2, 0);
long elapsed1 = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
long elapsed2 = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;

printf("%ld\n",elapsed1);
printf("%ld\n",elapsed2);

printf("Please press <ENTER> to continue.");
while(getchar() != '\n');

