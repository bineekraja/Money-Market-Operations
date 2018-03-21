#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printMain();
void printMenu();
void BasicMenu();
void AdvanceMenu();
void AdvanceMenuOption();

void displaySucess();
void BasicMenuOptions();

void simpleIntrest1();
void simpleIntrest2();

void forwardRate1();
void forwardRate2();

void presentValue1();
void presentValue2();

void futureValue1();
void futureValue2();

void yieldCalculation();
void yieldAnalysis();

//char *mygets(char *buf, size_t size);


int main()
{

	int choice; //choice variable
	printMain();
	scanf("%d",&choice);

	while(choice == 1)
	{
		int opt;
		printMenu();
		printf("Enter choice: \n");
		scanf("%d",&opt);
		while(opt != 3)
		{
			switch(opt)
			{
				case 1:
					BasicMenu(); // to acess the Basic operation menu, further acess the menu items
				break;

				case 2:
					AdvanceMenu();

				break;

				default:
					printf("\n Please enter a valid option");

			}

		printMenu();
		printf("Enter choice: \n");
		scanf("%d",&opt);

		}

		printMain();
		scanf("%d",&choice);

	}
	return 0;

}

/* Function to print the pop-up screen */
void printMain()
{

	printf("\t\t================= Treasury Banking and Money Market Operation ===============\n");
	//printf("\t\t\t \t******** Console *********\n");
	printf("\npress 1 to continue ");
	printf("\npress any key to EXIT ");

}


void printMenu()
{
	printf("\t\t================= Treasury Banking and Money Market Operation ===============\n");
	printf("\t\t\t\t Menu: \n");
	printf("\t *****************************************************\n");
	printf("\t\t\t1. Basic Operations \n");
	printf("\t\t\t2. Advance Operations \n");
	printf("\t\t\t3. Main Menu\n");

}

void BasicMenu()
{
	printf("\t ================= Treasury Banking and Money Market Operation ===============\n");
	int b_opt, temp;
	printf("\n 	 **** Basic Operations **** \n");
	BasicMenuOptions();	 //to display the options in the Basic operation Menu
	scanf("%d",&b_opt);
	switch(b_opt){
		case 1:
			printf("1. Simple Interest less than 1 year \n");
			printf("2. Simple Interest more than 1 year \n");
			printf("Enter the Choice \n");
			scanf("%d",&temp);
			switch(temp)
			{
				case 1:
					simpleIntrest1();
					void displaySucess();
				 break;

				case 2:
					simpleIntrest2();
					void displaySucess();
				 break;
				default:
					printf("Please enter the correct option .....");
			}
			break;


		case 2:
			printf("1. Forward Rate less than 1 year \n");
			printf("2. Forward Rate more than 1 year \n");
			printf("Enter the Choice \n");
			scanf("%d",&temp);
			switch(temp)
			{
				case 1:
					forwardRate1();
					displaySucess();
				 break;

				case 2:
					forwardRate2();
					displaySucess();
				 break;
				default:
					printf("Please enter the correct option .....");
			}
		 break;

		case 3:
			printf("1. Present Value less than 1 year \n");
			printf("2. Present Value more than 1 year \n");
			printf("Enter the Choice \n");
			scanf("%d",&temp);
			switch(temp)
			{
				case 1:
					presentValue1();
					void displaySucess();
				 break;

				case 2:
					presentValue2();
					void displaySucess();
				 break;
				default:
					printf("Please enter the correct option .....");
			}

		 break;

		case 4:
			printf("1. Future Value less than 1 year \n");
			printf("2. Future Value more than 1 year \n");
			printf("Enter the Choice \n");
			scanf("%d",&temp);
			switch(temp)
			{
				case 1:
					futureValue1();
					void displaySucess();
				 break;

				case 2:
					futureValue2();
					void displaySucess();
				 break;
				default:
					printf("Please enter the correct option .....");
			}

		 break;

		default:
			printf("\n Please enter a valid option");

	}
}

void BasicMenuOptions()
{
	printf("\t ================= Treasury Banking and Money Market Operation ===============\n");
	printf("1. Simple Interest \n");
	printf("2. Forward Rate \n");
	printf("3. Present Value\n");
	printf("4. Future Value\n");
	printf("Enter the option: \n");

}

void AdvanceMenu()
{
	printf("\t ================= Treasury Banking and Money Market Operation ===============\n");

	int a_opt;
	printf("\n 	 **** Advance Operations **** \n");
    AdvanceMenuOption();
    scanf("%d",&a_opt);
    //printf("\nER00");
	switch(a_opt)
	{
		case 1:
			yieldCalculation();
            break;

		case 2:
			yieldAnalysis();
		  break;

		default:
			printf("Enter an valid option...");
	}


}

void AdvanceMenuOption()
{
	printf("\t ================= Treasury Banking and Money Market Operation ===============\n");
	printf("\n \t\t\t Advance Operation \n");
	printf("\t****************************************************");
	printf("\n\t 1. Yield Calculation\n");
	printf("\t 2. Yield Analysis \n");
	

}


void yieldCalculation()
{
	printf("\t ================= Treasury Banking and Money Market Operation ===============\n");
	printf("\tYield value calculation in progress........");
	float MV;
	float month;
	float EROI;
	float FaV;
	float roi;
	int i=0;
	FILE *fp= fopen("yield.csv","r");
	//printf("Done");
	FILE *fq= fopen("yield_out.csv","a");
	fscanf(fp,"%f %f %f %f",&month,&FaV,&roi,&MV);
	while(!feof(fp))
	{

		EROI=roi+((MV-FaV)/FaV)*100;
		fprintf(fq,"%f %f %f %f %f \n",month,FaV,roi,MV, EROI);
		fscanf(fp,"%f %f %f %f",&month,&FaV,&roi,&MV);
	}
	fclose(fp);
	fclose(fq);

}

void yieldAnalysis()
{
	printf("\t ================= Treasury Banking and Money Market Operation ===============\n");
	printf("\tYield value analysis in progress........ \n\tUseful in determining the performance of the Financial Instrument.\n");
	float MV;
	float month;
	float EROI;
	float FaV;
	float roi;
	char par;
	FILE *fp= fopen("yield.csv","r");	
	
	FILE *fq= fopen("yield_Analysis_out.csv","a");
	fscanf(fp,"%f %f %f %f",&month,&FaV,&roi,&MV);
	while(!feof(fp))
	{

		if(MV>FaV)
		{
			par='+';

		}
		else
		{
			par='-';
		}

		fprintf(fq,"%f %f %f %f %c \n",month,FaV,roi,MV, par);
		fscanf(fp,"%f %f %f %f",&month,&FaV,&roi,&MV);
	}
	fclose(fp);
	fclose(fq);
}




void displaySucess()
{
	printf("\nThe requested operation Succesfull\n ");
}

void simpleIntrest1()
{

	/*const char *inp_file[10];
	printf("\nEnter the Input file name: ");
	gets(inp_file);*/

	//const char *out_file[10];
	//printf("\nEnter the Output file name: ");
	//gets(out_file);
	float C=0;
	float r=0;
	int D=0;
	int B=0;
	float SI=0;
	FILE *fp=fopen("si_1.csv","r");
	FILE *fq=fopen("SI_out.csv","a");
	fscanf(fp,"%f %f %d %d",&C,&r,&D,&B);
	while (!feof(fp))
	{

		SI=(C*r)*((1.0)*D/B);
		fprintf(fq,"%f %f %d %d %f\n",C,r,D,B,SI);
		fscanf(fp,"%f %f %d %d",&C,&r,&D,&B);
	}

	fclose(fp);
	fclose(fq);

}

void simpleIntrest2()
{
	float C=0;
	float r=0;
	int D=0;
	int B=0;
	float SI=0;
	FILE *fp=fopen("si_2.csv","r");
	FILE *fq=fopen("SI_out.csv","a");
	fscanf(fp,"%f %f %d %d",&C,&r,&D,&B);
	while (!feof(fp))
	{

		SI=(C*r)*((1.0)*D/B);
		fprintf(fq,"%f %f %d %d %f\n",C,r,D,B,SI);
		fscanf(fp,"%f %f %d %d",&C,&r,&D,&B);
	}

	fclose(fp);
	fclose(fq);

}

void forwardRate1()
{
	float FR=0;
	float rl=0;
	float rs=0;
	int Dl=0;
	int Ds=0;
	int Dls=0;
	int B=0;
	float T1=0;
	float T2=0;
	FILE *fp=fopen("forwardRate_1.csv","r");
	FILE *fq=fopen("forwardRate_1_out.csv","a");
	fscanf(fp,"%f %f %d %d %d %d",&rl,&rs,&Dl,&Ds,&Dls, &B);
	while (!feof(fp))
	{

		T1=1.0+(rl*((1.0)*Dl/B));
		T2=1.0+(rs*((1.0)*Ds/B));
		FR=((T1/T2)-1.0)*((1.0)*B/Dls);
		fprintf(fq,"%f %f %d %d %d %d %f\n",rl,rs,Dl,Ds,Dls,B,FR);
		fscanf(fp,"%f %f %d %d %d %d ",&rl,&rs,&Dl,&Ds,&Dls, &B);
	}

	fclose(fp);
	fclose(fq);

}

void forwardRate2()
{
	float FR=0;
	float rl=0;
	float rs=0;
	float N=0;
	float n=0;
	float Nn=0;
	double T1=0;
	double T2=0;

	FILE *fp=fopen("forwardRate_2.csv","r");
	FILE *fq=fopen("forwardRate_2_out.csv","a");
	fscanf(fp,"%f %f %f %f %f",&rl,&rs,&N,&n, &Nn );
	while (!feof(fp))
	{
		float r1= 1.0+rl;
		float r2= 1.0+rs;
		T1=pow(r1,N);

		T2=pow(r2,n);
		float T= (T1/T2);

		FR=(pow(T,(1/Nn))-1);
		fprintf(fq,"%f %f %f %f %f %f \n",rl,rs,N,n, Nn, FR );
		fscanf(fp,"%f %f %f %f %f",&rl,&rs,&N,&n, &Nn );
	}

	fclose(fp);
	fclose(fq);
	printf(" \n Calculation of Forward Rate Done..\n\n\n");
}


void presentValue1()
{
	float FV;
	float r;
	float D;
	float B;
	float PV;
	FILE *fp=fopen("presentValue_1.csv","r");
	FILE *fq=fopen("presentValue_1_out.csv","a");
	fscanf(fp,"%f %f %f %f",&FV,&r,&D,&B);
	while (!feof(fp))
	{
		PV= FV/(1+(D/B));
		fprintf(fq,"%f %f %f %f %f \n",FV,r,D,B, PV );
		fscanf(fp,"%f %f %f %f",&FV,&r,&D,&B);
	}

	fclose(fp);
	fclose(fq);
	printf("\nCalculation of Present Value Done..\n\n\n");


}

void presentValue2()
{
	float FV;
	float r;
	float n;
	float PV;

	FILE *fp=fopen("presentValue_2.csv","r");
	FILE *fq=fopen("presentValue_2_out.csv","a");
	fscanf(fp,"%f %f %f",&FV,&r,&n);
	while (!feof(fp))
	{

		PV= FV/pow((1+r),n);
		fprintf(fq,"%f %f %f %f \n",FV,r,n,PV );
		fscanf(fp,"%f %f %f",&FV,&r,&n);
	}

	fclose(fp);
	fclose(fq);
	printf("\n Calculation of Present Value Done.. \n\n\n");

}

void futureValue1()
{
	float PV;
	float r;
	float D;
	float B;
	float FV;

	FILE *fp=fopen("futureValue_1.csv","r");
	FILE *fq=fopen("futureValue_1_out.csv","a");
	fscanf(fp,"%f %f %f %f",&PV,&r,&D,&B);
	while (!feof(fp))
	{

		FV= PV+(PV*r*(D/B));
		fprintf(fq,"%f %f %f %f %lf\n",PV,r,D,B,FV );
		fscanf(fp,"%f %f %f %f",&PV,&r,&D,&B);
	}

	fclose(fp);
	fclose(fq);
	printf("\n Calculation of Future Value Done.. \n\n\n");


}

void futureValue2()
{
	float C;
	float r;
	float n;
	float FV;

	FILE *fp=fopen("futureValue_2.csv","r");
	FILE *fq=fopen("futureValue_2_out.csv","a");
	fscanf(fp,"%f %f %f",&C,&r,&n);
	while (!feof(fp))
	{

		FV= C*(pow((1+r),n));
		fprintf(fq,"%f %f %f %f\n",C,r,n,FV );
		fscanf(fp,"%f %f %f",&C,&r,&n);
	}

	fclose(fp);
	fclose(fq);
	printf("\n Calculation of Future Value Done.. \n\n\n");

}

