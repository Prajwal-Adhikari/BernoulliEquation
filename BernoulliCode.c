#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//Defining Universal Constants used in the problem definiton. All values are in S.I. units.

#define PI 3.141592653589
#define GRAVITY 9.81
#define DENSITY_OF_WATER 1000.0

//Declaring noOfCases as global variable as int datatype.
int noOfCases;


//Function to greet the user.
void Greet()
{
	printf("\n************************************** BERNOULLI'S PRINCIPLE IMPLEMENTATION IN C **************************************\n");
	printf("\n--------------------------------------- Welcome user --------------------------------------------------------------- \n");
}

//User Manual to use the program
void UserManual()
{

	printf("The problem statement is \n\nA pipe 200m long slopes down at 1 in 100 and tapers from 600 mm diameter at the higher end to 300 mm diameter at the lower end, and carries 100 liters/sec of oil(sp. Gravity 0.8). If the pressure gauge at the higher end reads 60 KN/m^2\n\nDetermine : \n\n1. Velocities at both ends\n\n2. Pressure at the lower end\n");

	printf("\n--------------------------------------- USER MANUAL --------------------------------------------------------------------- \n\nYou can generate multiple cases by entering valid inputs.\n-------------------------------------------------------------------------------------\n\nFollowings are the correct ways of inputting data to this program\n\n1. Please enter only numerical values (e.g. 100 for 100 meters as in height), omit the units.\n\n2. While entering multiple inputs in the array please enter values in space ganerated single line fashion\n\nYou will get another prompt to enter furthur data to the program\n\n3. You don't have to enter universal constant values like pi and g. Those are already defined by the program for you.\n\n4.You can create multiple different cases by entering the number of cases you want to try out\n\n5. Enter every data as per in the problem statement. Don't worry about units used. Program will automatically convert    \n them into S.I. units\n\n6. The units used in final outputs are same as in inputs.\n\n7.All the ouputs are stored automatically in a file named outputs.csv.Please checkout the final answers there.\n\n*********************************** END OF USER MANUAL *************************************************************\n");
}


//All the functions are declared and defined here.

//Calculating slopes for noOfCases entered by user with the help of noOfCases of rise and run 
float SlopeCalculator(float rise[noOfCases], float run[noOfCases], float slope[noOfCases])
{
	int i;
	for (i = 0; i < noOfCases; ++i)
	{
	slope[i] = rise[i] / run[i];
	}
	return slope[noOfCases];
}



//Calculating Inclinations for noOfCases entered by user with the help of noOfCases of slopes
float InclinationCalculator(float slope[noOfCases], float inclination[noOfCases])
{
	int i;
	for (i = 0; i < noOfCases; ++i)
	{
	inclination[i] = (atan(slope[i]) * 180) / PI;
		
	}
	return inclination[noOfCases];
}

//Calculating Sine values for noOfCases entered by user with the help of noOfCases of inclinaitons
float SineValue(float inclination[noOfCases], float sValue[noOfCases])
{
int i;
	for (i = 0; i < noOfCases; ++i)
	{
	sValue[i] = (sin(inclination[i]) * PI) / 180;
		
	}
	return sValue[noOfCases];
}



//Calculating Upperheight for noOfCases entered by user with the help of noOfCases of sValues and lengths
float UpperHeight(float sValue[noOfCases], float length[noOfCases], float upperHeight[noOfCases])
{
	int i;
	for (i = 0; i < noOfCases; ++i)
	{
	upperHeight[i] = ceil(sValue[i] * length[i]);
		
	}
	return upperHeight[noOfCases];
}



//Calculating Density of oil for noOfCases entered by user with the help of noOfCases of specific gravity of oil. Here the constant Density of water defined in line 10 is used.

float OilDesnity(float specificGravityOil[noOfCases], float densityofOil[noOfCases])
{
	int i;
	for (i = 0; i < noOfCases; ++i)
	{
	densityofOil[i] = specificGravityOil[i] * DENSITY_OF_WATER;
		
	}
	return densityofOil[noOfCases];
}


//Calculating upper level velocity for noOfCases entered by user with the help of noOfCases of flowrate and upperdiamter already converted into si units

float FlowRateEquation(float siflowrate[noOfCases], float siUpDiameter[noOfCases], float upperVelocity[noOfCases])
{
	int i;
	for (i = 0; i < noOfCases; ++i)
	{
	upperVelocity[i] = (siflowrate[i] * 4) / (PI * siUpDiameter[i] * siUpDiameter[i]);
		
	}
	return upperVelocity[noOfCases];
}


//Calculating lowerlevel velocity for noOfCases entered by user with the help of noOfCases of upper diameter, uppervelocity already converted into si units.

float ContinuityEquation(float siUpDiameter[noOfCases], float upperVelocity[noOfCases], float siLowDiameter[noOfCases], float lowerVelocity[noOfCases])
{
	int i;
	for (i = 0; i < noOfCases; ++i)
	{
	lowerVelocity[i] = (siUpDiameter[i] * siUpDiameter[i] * upperVelocity[i]) / (siLowDiameter[i] * siLowDiameter[i]);
		
	}
	return lowerVelocity[noOfCases];
}

//This is the Bernoulli's Theorem implementation

float BernoullisEquation(float siUpperPressure[noOfCases], float densityofOil[noOfCases], float upperVelocity[noOfCases], float upperHeight[noOfCases], float lowerPressure[noOfCases], float lowerVelocity[noOfCases], float lowerHeight)
{
	int i;
	for (i = 0; i < noOfCases; ++i)
	{
	lowerPressure[i] = (siUpperPressure[i] + 0.5 * densityofOil[i] * upperVelocity[i] * upperVelocity[i] + densityofOil[i] * GRAVITY * upperHeight[i] - 0.5 * densityofOil[i] * lowerVelocity[i] * lowerVelocity[i] - densityofOil[i] * GRAVITY * lowerHeight);
	}

	return lowerPressure[noOfCases];
}





//main function starts here
int main()
{

	//calling Greet() and UserManual()
	Greet();

	UserManual();

	//Asking for number of different cases that user want to try out
	printf("Enter how many cases you wanna try : ");
	scanf("%d",&noOfCases); 

	//Declaring all the values in the problem definition as float data type.

	float length[noOfCases],
		upperDiameter[noOfCases],
		lowerDiameter[noOfCases],
		upperHeight[noOfCases],
		lowerHeight,
		flowRate[noOfCases],
		UpperPressure[noOfCases],
		lowerPressure[noOfCases],
		upperVelocity[noOfCases],
		lowerVelocity[noOfCases],
		slope[noOfCases],
		inclination[noOfCases],
		sValue[noOfCases],
		specificGravityOil[noOfCases],
		densityofOil[noOfCases],
		rise[noOfCases],
		run[noOfCases];

	//Taking user inputs


	printf("Enter %d Length(s) of pipe in meters : ",noOfCases); //Taking length of pipe as user input
	int i;
		for (i = 0; i < noOfCases; ++i)
		{

			scanf("%f", &length[i]);
		}

	printf("Enter %d rise(es) of pipe : ",noOfCases); //Taking rises of pipe as user input
		for (i = 0; i < noOfCases; ++i)
		{

			scanf("%f", &rise[i]);
		}

	printf("Enter %d run(s) of pipe : ",noOfCases); //Taking runs of pipe as user input
		for (i = 0; i < noOfCases; ++i)
		{

			scanf("%f", &run[i]);
		}

	printf("Enter %d upper level diameter(s) of pipe in mm : ",noOfCases); //Taking uppeer level diameters of pipe as user input
		for (i = 0; i < noOfCases; ++i)
		{

			scanf("%f", &upperDiameter[i]);
		}

	printf("Enter %d lower level diameter(s) of pipe in mm: ",noOfCases); //Taking lower level diameters of pipe as user input
		for (i = 0; i < noOfCases; ++i)
		{

			scanf("%f", &lowerDiameter[i]);
		}

	printf("Enter %d flow rate(s) of pipe in liters per second: ",noOfCases); //Taking flow rated of oil in pipe as user input
		for (i = 0; i < noOfCases; ++i)
		{

			scanf("%f", &flowRate[i]);
		}

	printf("Enter %d specific gravity(s) of oil in SI units: ",noOfCases); //Taking specific garvity of oil as user input
		for (i = 0; i < noOfCases; ++i)
		{

			scanf("%f", &specificGravityOil[i]);
		}

	printf("Enter %d upper level pressure(s) of pipe original as in kiloNewton per meters square : ",noOfCases); //Taking upper level pressure of pipe as user input
		for (i = 0; i < noOfCases; ++i)
		{

			scanf("%f", &UpperPressure[i]);
		}


	lowerHeight = 0.0; //lower height is set to 0 as we take lower height 0 in the problem definition.


	//declaring float variables to store conveted Si units data
	float siUpDiameter[noOfCases];
	float siLowDiameter[noOfCases];
	float siflowrate[noOfCases];
	float siUpperPressure[noOfCases];


//converting into SI units
	for (i = 0; i < noOfCases; ++i)
	{
		siUpDiameter[i] = upperDiameter[i]/1000;  	
	}




	for (i = 0; i < noOfCases; ++i)
	{
		siLowDiameter[i] = lowerDiameter[i]/1000; 
 	
	}


	for (i = 0; i < noOfCases;++i)
	{

		siflowrate[i] = flowRate[i]/1000;  	

	}

	for (i = 0; i < noOfCases;++i)
	{
		siUpperPressure[i] = UpperPressure[i]*1000;  
	
	}




	//Calling all the declared and defined functions.

	
slope[noOfCases] = SlopeCalculator(rise,run,slope);


inclination[noOfCases] = InclinationCalculator(slope,inclination);


sValue[noOfCases] = SineValue(inclination,sValue);


upperHeight[noOfCases] = UpperHeight(sValue,length,upperHeight);


densityofOil[noOfCases] = OilDesnity(specificGravityOil,densityofOil);


upperVelocity[noOfCases] = FlowRateEquation(siflowrate,siUpDiameter,upperVelocity);




lowerVelocity[noOfCases] = ContinuityEquation(siUpDiameter,upperVelocity,siLowDiameter,lowerVelocity);



lowerPressure[noOfCases] = BernoullisEquation(siUpperPressure,densityofOil,upperVelocity,upperHeight,lowerPressure,lowerVelocity,lowerHeight);


//File handeling starts from here

//Declaring the file pointer as *fp
FILE *fp;
	fp = fopen("outputs.csv","w"); 	//openning the file
	if (fp == NULL)
	{
		printf("Cannot open file\n");
		return 1;
	}




	fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n","S.N.","Lengths","rise","run","UpperDiameter","lowerDiameter","flowRate","specificGravityOil","UpperPressure","upperVelocity","lowerVelocity","lowerPressure");

	int j;
	for (j = 0; j < noOfCases; ++j)
	{
		fprintf(fp,"%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",j+1,length[j],rise[j],run[j],upperDiameter[j],lowerDiameter[j],flowRate[j],specificGravityOil[j],UpperPressure[j],upperVelocity[j],lowerVelocity[j],lowerPressure[j]/1000);
	}


	fclose(fp);
printf("\n--------------------------------------------------------------------------------------------------------------\n");
printf("All the required answers are stored int the csv file named outputs.csv\n");
printf("\n--------------------------------------------------------------------------------------------------------------\n");
printf("The units in which final answers are in are as follows:\nUpper velocity = meters per seconds\n--------------------------------------------------------------------------------------------------------------\nLower velocity = meters per seconds\n--------------------------------------------------------------------------------------------------------------\nLower Pressure = Kilo Newtom per meters square");
return 0;

}

