/********************************************************************
* Header Files
*********************************************************************/
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

/*********************************
* Declaring Global Variable
**********************************/
int awake=0;

int loadcell();
int qt_call ();

/*********************************************************************************
* Declaring the thread that will periodically check water level in the food bowl
* Will warn the pet owner if water level is too low
**********************************************************************************/
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

/*********************************************************************************
* Declaring the thread that will count down to the next feeding time 
* Once the counter end food will be dispensed once again
**********************************************************************************/
void Timekeeper(int hours)
{
int seconds=hours*10;
for(int t=seconds;t>=0;t--){
usleep(1000000);
//cout<< "timer"<<t<<endl;
}
//cout<<"I am awake"<<endl;
awake=1;
}

/***************************************************************
* Declaring a function to read the output from the load cell 
****************************************************************/
void load_cell()
{
int d;
d=loadcell();
}

/**********************************************************************************************
* The main function for App-PET-ite
* Welcomes the user to App-PET-ite
* Launches UI for the user to enter the weight of food to be dispensed for the Pet in grams
* Launches UI for the user to enter the time between food times in hours
* Asks the user to verify the input for weight and time
* Dispenses the amuont of food specified by the user
* Starts thread 1- The count down thread
*           This thread counts down to the next feeding time
* Starts thread 2- The water level sensor update
*            This thread periodically measures the water level in the food bowl
* Once the counter has counted down food is dispensed again
* This continues till all the food has been dispensed
***********************************************************************************************/
int main(int argc,char *argv[])
{
/****************************	
* Welcome to App-PET-ite
*****************************/
cout<<"Welcome to App-PET-ite"<<endl;
	
/*******************************
* Initializing the Qt UI 
********************************/
int qt_weight,qt_time;
QApplication app(argc, argv);
QTextStream cout(stdout);

/********************************
* Declarations of variables
*********************************/
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
	
	/***********************************************
	* Launching the UI for inputing weight in grams
	************************************************/
	int qt_weight = 0;
	qt_weight = QInputDialog::getInt(0, "Appetite UI","Enter the weight to be dispensed:", 0);
	/**********************************************
	* Launching the UI for inputing time
	***********************************************/
        int qt_time = 0;
        qt_time = QInputDialog::getInt(0, "Appetite UI","Enter the time for next dispense in hours:", 1);
	/**********************************************
	* Verifying the User inputs
	***********************************************/
	QString response = QString("You have entered weight as %1 and time as %2.\n Have you entered the right values").arg(qt_weight).arg(qt_time);
	answer = QMessageBox::question(0, "Play again?", response,
	QMessageBox::Yes | QMessageBox::No);
	
    } while (answer == QMessageBox::No);
 
cout<<qt_weight<< endl<<qt_time<<endl;
int weight, time;
weight = qt_weight;
time = qt_time;
int thrs = 40;

/*****************************************
* Dispensing the food initially
******************************************/
 while(1)
{
	 int b;
	 b=loadcell();
	 cout<<"weight"<<(b-thrs)<<endl;
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
	
/**************************************************
* Dispensing food using threads and continuous mode
***************************************************/
while(1)
{		 
	 /********************************
	 * Starting the threads
	 *********************************/
	 std::thread first (Timekeeper,time);
	 std::thread second (Water_Level_Update);

	 first.join();
	 second.join();
	 awake = 0;
	 int c;
	while(1)
	{
	     c=loadcell();
	     cout<<(c-thrs)<<endl;
	     if((c-thrs)<=weight)
	     {
		 motor_Run_time(150000); 
	     }
	     if((c-thrs)>weight)
             {
	     cout<<"Food set to desired limit"<<endl;
	     break;
	     }
	}     
	 
}

 return 0;






