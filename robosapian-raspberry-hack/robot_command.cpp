#include <unistd.h>
#include <iostream>
extern "C"{
#include "robot.h"
}
extern "C"{
void tell(unsigned int arg);
void init();
};
using namespace std;
int main(){
	init();
        int i  = 0 ;
	for(;;){

		tell(135);
	 	usleep(500000) ;
                cout<<"here"<<endl;
	}
return 0;
}
