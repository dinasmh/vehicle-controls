/*
 * Project.c
 *
 *  Created on: 12 avr. 2022
 *      Author: dinaa
 */

#include <stdio.h>
#include <stdlib.h>

void prints (void);
void menu1(void);
//void turnoff(void);
void turnon(void);
void traffic_light(void);
void enginetemperature(void);
void roomtemp(void);

enum state {
	OFF,ON
};

struct vehicle
{
	int speed;
	int temperature;
	int enginetemp;
	int enginestate;
	int ACstate;
	int eng_temp_cont;
}vehicle;

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	vehicle.speed=40;
	vehicle.temperature=35;
	vehicle.enginetemp=100;
	vehicle.enginestate=ON;
	vehicle.ACstate=OFF;
	vehicle.eng_temp_cont=OFF;
	menu1();
	prints();
}
void prints(void){

	if(vehicle.speed == 30)
		{
			vehicle.ACstate = ON;
			vehicle.temperature = vehicle.temperature *(5/4)+1;
			vehicle.eng_temp_cont = ON;
			vehicle.enginetemp = vehicle.enginetemp *(5/4)+1;
		}

	printf("Engine is %d\n",vehicle.enginestate);
	printf("AC is %d\n", vehicle.ACstate);
	printf("Vehicle Speed: %d \n",vehicle.speed);
	printf("Room Temperature: %d C\n",vehicle.temperature);
	printf("Engine Temperature controller is %d \n",vehicle.eng_temp_cont);
	printf("Engine Temperature : %d C\n",vehicle.enginetemp);
	printf("\n");
}

void menu1(void){

	char choice;
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");

	while(1){
		scanf(" %c",&choice);
		if (choice =='a'){
			vehicle.enginestate = ON;
			turnon();
		}
		else if (choice =='b'){
			vehicle.enginestate = OFF;
			menu1();
		}
		else if (choice =='c'){
			printf("Quit the system");
			exit(0);
		}

	}
	return;
}


void turnon(void){
	char choice;


	printf("a. Turn off the engine.\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n\n");
	while(1){
		scanf("%c",&choice);

		if (choice=='a')
			menu1();

		if (choice == 'b'){

			vehicle.eng_temp_cont = OFF;
			traffic_light();
			prints();
			return;
		}


		if (choice == 'c'){

			vehicle.eng_temp_cont = OFF;
			roomtemp();
			prints();
			return;
		}


		if (choice == 'd'){
			vehicle.eng_temp_cont=ON;
			enginetemperature();
			prints();
			return;
		}
	}

}
void traffic_light(void){
	char light;
	printf("Please insert traffic light: \n");

	scanf(" %c",&light);

	if (light == 'G' || light == 'g'){
		vehicle.speed = 100;
	}
	else if (light == 'O' || light == 'o'){
		vehicle.speed = 30;
	}
	else if (light == 'R' || light == 'r'){
		vehicle.speed = 0;
	}
}

void roomtemp(void){
	int temp;
	printf("Please insert temperature: \n");

	scanf(" %d",&temp);
	if (temp <= 10 || temp >=30){
		vehicle.ACstate=ON;
		vehicle.temperature = 20;
	}
	else{
		vehicle.ACstate=OFF;
		vehicle.temperature=temp;
	}


}

void enginetemperature(void){
	int temp;
	printf("Please insert engine temperature: \n");
	scanf(" %d",&temp);
	if (temp<100||temp>150){
		vehicle.eng_temp_cont=ON;
		vehicle.enginetemp=125;
	}
	else
		vehicle.eng_temp_cont=OFF;
	return;
}
