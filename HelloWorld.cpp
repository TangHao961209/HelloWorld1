#include  <stdio.h>

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
	return 0;
}
