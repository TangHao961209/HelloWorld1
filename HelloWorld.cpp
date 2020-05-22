#include  <stdio.h>
#include <pthread.h>
#include  "pthread_test.h"
#include <unistd.h>
#include <string.h>
class Cat{
public:
	Cat();
	Cat(char *name,int *year);
	~Cat();
	void setName(char *name);
	void setYear(int year);
	void getNmae();
	void setName();
private:
 char *name;
 int *year;
};

Cat::Cat(char *name,int *year){
	this->name = name;
	this->year = year;
}
Cat::Cat(){
	printf("调用无参构造\n");
}
Cat::~Cat(){
	printf("%s bye...\n",this->name);
}
void Cat::setName(char *name){
	this->name = name;
}
void Cat::getNmae(){
	printf("Cat's name is %s\n",this->name);
}

void *ThreadFunc()
{
    static int count = 1;
    printf ("Create thread %d\n", count);
    count++;
}

int plus1(int a){
	return a+1;
}


int main(int argc, char **argv) {
#ifdef TEST_ADD
	printf("Hello \t world \n");
#endif

#ifdef Cat_ADD
	char *name = "sit";
	int year =19;
	Cat  *cat1 = new Cat(name,&year);
    cat1->getNmae();

    Cat cat2;
    cat2.setName(name);
    cat2.getNmae();
#endif
    void (*pV)(int) = NULL;
    int result = 0;
    pV = plus1;
    result = ((int(*)(int))pV)(5);
    printf("result = %d \n",result);

    int **p = NULL;
    int *p1 = NULL;
    int a = 1;
    p1 = &a;
    p = &p1;
    printf("a = %d \n",**p);
    //改变a的值,二级指针改变的值
    **p = 5;
    printf("a = %d \n",a);

    int* q[4];  //指针数组
    //q[0] = &a;

   // *p[0] = &a;
    printf("指针数组 p[0] = %d",*q[0]);
    mct_pipeline_thread_data_t  *data;
    pthread_t tidp;
    //printf("main thread start\n");
    for(int i = 0;i < 10;i++){
    	if ((pthread_create(&tidp, NULL,checknum,(void*) data)) == -1)
    	         {
    	             printf("create error!\n");
    	             return 1;
    	         }
//    	usleep(2000);
    	//printf("hello");
//    	int err= pthread_create(&tidp, NULL, ThreadFunc, NULL);
//    	           if(err != 0){
//    	               printf("can't create thread: %s\n",strerror(err));
//    	               break;
//    	           }
    	          //usleep(2000);
    	          //pthread_join(tidp,NULL);
    }
   // checknum(&data);

    printf("main thread finish\n");
    pthread_exit(NULL);
	return 0;
}


