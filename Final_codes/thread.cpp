#include <iostream>
#include <thread>
#include "keypad.cpp"
#include "PWM.cpp"
#include "mcp3008SpiTest.cpp"
#include "hx711.cpp"
#include "main.cpp"


#include "QApplication"
#include "QPushButton"
#include "QtGui"
#include <QInputDialog>
#include <QTranslator>

using namespace std;
int awake=0;

int abc();
int qt_call ();

void Motor()
{
unsigned int b;
motor_Run_time(67000);
}

void Water_Level_Update()
{
int c;
while(1){
c=WaterLevel();
//cout<<c<<endl;
if (c<100){
	cout<<" refill to max level"<<endl;
}
usleep(15000000);
if(awake==1){
	break;}
}
}

void Timekeeper(int hours)
{
int seconds=hours*10;
for(int t=seconds;t>=0;t--){
usleep(1000000);
cout<< "timer"<<t<<endl;
}
cout<<"I am awake"<<endl;
awake=1;
}

void counter(){
 while(1){
 	if(awake==0){
             cout<<"Sleeping"<<endl;
             usleep(1000000);
             	     }
        else{break;}
         }
}
void load_cell()
{
int d;

d=abc();

}


int main(int argc,char *argv[])
{

//Initializing the Food Dispenser through user input 
cout<<"Welcome to App-PET-ite"<<endl;
int qt_weight,qt_time;
QApplication app(argc, argv);
QTextStream cout(stdout);

// Declarations of variables
int answer = 0;
QGraphicsScene scene;
QGraphicsView view(&scene);
QGraphicsPixmapItem item(QPixmap("/home/pi/local_repo/App-PET-ite/Images/Logo.png"));
scene.addItem(&item);
view.show();

QLabel label("<img src='Logo.jpg' />");
label.show();

do {
	// local variables to the loop:
	int qt_weight = 0;
	qt_weight = QInputDialog::getInt(0, "Appetite UI","Enter the weight to be dispensed:", 0);
    int qt_time = 0;
    qt_time = QInputDialog::getInt(0, "Appetite UI","Enter the time for next dispense in hours:", 1);
	QString response = QString("You have entered weight as %1 and time as %2.\n Have you entered the right values").arg(qt_weight).arg(qt_time);
	answer = QMessageBox::question(0, "Play again?", response,
	QMessageBox::Yes | QMessageBox::No);
	
    } while (answer == QMessageBox::No);
 
//Calling the QT window
//qt_weight,qt_time = qt_call();
cout<<qt_weight<< endl<<qt_time<<endl;
 
 /*First getting the Weight Input
 int weight;
 int status_w;
 while(1){
 weight=Keys_weight();
 status_w=Keys_verify_weight();
 if(status_w==1){
 		break;}
 }
 cout<<"Weight successfully stored"<<endl;

 //Getting the Time Input
 int time;
 int status_t;
 while(1){
 time=Keys_time();
 status_t=Keys_verify_time();
 if(status_t==1){
 		break;}
 }
 cout<<"Time successfully stored"<<endl;
 */
usleep(10000);
int weight, time;
weight = qt_weight;
time = qt_time;
int thrs = 40;

 while(1)
{
	 int b;
	 b=abc();
	 cout<<"weight"<<(b-thrs)<<endl;
	 usleep(1000000);
	 if((b-thrs)<=weight)
	 {
		motor_Run_time(67000); 
		//usleep(1000);
	 }
	 if((b-thrs)>weight)
	 {
		 break;
     }
 }		 
		 cout<<"Food set to desired limit"<<endl;
while(1)
{		 
		 std::thread first (Timekeeper,time);
		 std::thread second (Water_Level_Update);
		 
		 first.join();
		 second.join();
		 usleep(1000000);
		 awake = 0;
		 int c;
	     c=abc();
	     cout<<(c-thrs)<<endl;
	     usleep(1000);
	     if((c-thrs)<=weight)
	     {
		 motor_Run_time(67000); 
		 //usleep(1000);
	     }
	     
		 //usleep(1000);
		 if((c-thrs)>weight)
		 {
			cout<<"Food set to desired limit"<<endl;
			
		 
	     }
	     
	 
}

 return 0;






