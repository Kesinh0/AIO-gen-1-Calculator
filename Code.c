#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>



//funcion de esperar
void waiteo(){
	printf("\ninserte cualquier numero para salir\n");
	int i;
	scanf("%d", i);
}
//funcion de esperar

//read float
float readfloat(float min, float max){
	float num;
	do{
		scanf("%f", &num);
	}while(num<min || num>max);
	return num;
}
//read float

//read int
int readint(int min, int max){
	int num;
	do{
		scanf("%d", &num);
	}while(num<min || num>max);
	return num;
}
//read int

//       damage Calculator        //
void damage_calc(){
	srand(time(NULL));
    int Level, Attack, Defense, Power, Speed;
	bool ifstab;
	float Type1, Type2, Stab;
	printf("\nEnter the Pokemon level \n");
    Level = readint(0, 100);
	
    printf("\nThe opponent Pokemon's defense stat \n");
    Defense = readint(0,255);
	
	printf("\nThe Pokemon's speed stat \n");
    Speed = readint(0, 255); 
	
	printf("\nThe Pokemon's attack stat \n");
    Attack = readint(0, 255);
	
	printf("\nThe power of the move \n");
    Power = readint(0, 300);
	
	printf("\nEnter the Effectiveness of the move in the opponent Pokemon's type1 \n");
    printf("\n(0) if it's invulnerable, (0.5) if it's not very effective \n");
    printf("\n(1) if it's neutral, (2) if it's super effective \n");
    Type1 = readfloat(0, 2);
	
	printf("\nEnter the Effectiveness of the move in the opponent Pokemon's type2 \n");
    printf("\n(0) if it's invulnerable, (0.5) if it's not very effective \n");
    printf("\n(1) if it's neutral, (2) if it's super effective \n");
    printf("\nif the Pokemon doesn't have a second type, insert 1 \n");
    Type2 = readfloat(0, 2);
	
	printf("\nEnter if the attack was STAB \n");
    printf("\nif the attack is STAB put 1, if it is not, put 0 \n");
    ifstab = readint(0, 1);
    switch(ifstab){
    	case true:
    		Stab = 1.5;
    		break;
    	case false:
    		Stab = 1;
    		break;
    	default:
    		Stab = 1;
    		break;
	}
	
	//random func
	int randomnum = 217 + (rand() % 39);
    float random = randomnum / 255.0f;
	printf("\nrandom = %f\n", random);
    
	printf("\nThe damage inflicted is:");
	float Damage = round(((((((2 * Level) / 5) + 2) * Power * (Attack / Defense)) / 50) + 2) * Stab * Type1 * Type2 * random);
	printf("\n%f", Damage);
    printf("\n\nIn the case of a critical hit \n");
    printf("\nThe damage inflicted is:");
	Damage = round(((((((4 * Level) / 5) + 2) * Power * (Attack / Defense)) / 50) + 2) * Stab * Type1 * Type2 * random);
    printf("\n%f", Damage);
    printf("\n\n ----------------------\n\n");    
}
//       damage Calculator        //

//       Catch Simulation        //
void simulation(){
	srand(time(NULL));
	printf("\nCatch Simulation \n");
    
	printf("\nEnter the Pokemon's Catch rate \n");
    int catchrate = readint(1, 255);
    
	printf("\nEnter the Pokemon's max health \n");
    int HP = readint(1, 178);
    
    printf("\nEnter the Pokemon's current health\n");
    int HPr = readint(1, HP);
    
    
    printf("\nInsert which Pokeball you are using \n");
    printf("\n1. Pokeball");
    printf("\n2. Greatball");
    printf("\n3. Ultraball / Safari Ball");
    printf("\n4. Masterball \n");
    int Ball = readint(1,4);
    int Ball_mod;
    switch(Ball){
    	case 1: //pokeball
    		Ball = 255;
    		Ball_mod = 12;
    		break;
    	case 2: //greatball
    		Ball = 200;
    		Ball_mod = 8;
    		break;
    	case 3: //ultraball
    		Ball = 150;
    		Ball_mod =6;
    		break;
    	case 4: //masterball
    		printf("\nPokemon Caught! \n");
    		return;
	}
	
	printf("\nWith which status is the target Pokemon? \n");
    printf("\n1. Frozen / asleep \n");
    printf("\n2. Poisoned / Burned / Paralyzed \n");
    printf("\n3. None \n");
	int status = readint(1,3);
	printf("\n");
	switch (status){
		case 1:  // congelamiento / sueño
			status = 25;
			break;
		case 2:  // veneno / quemadura / paralisis
			status = 12;
			break;
	    default: // sin status
	    	status = 0;
			break;
	}
	
	int F = (HP * 255 * 4) / (HPr * Ball_mod);
	if (F>255) F=255; //limite de gen1
	
	
    
	//calculo de porcentage de captura
	float CatchProb = (float)status / (Ball+1) + ((catchrate + 1) / (float)(Ball+1))  * ((F+1) / 256.0f);
	printf("\n_______\n");
	printf("|%.1f%%|\n", CatchProb * 100);
	printf("-------\n");
	printf("es el porcentaje de captura\n");
	
	waiteo();
	
}
//       Catch Simulation        //


//menu text
void menu_text(){
	printf("\nSelect an option \n");
    printf("1. Damage Calc \n");
    printf("2. Catch Simulation \n");
    printf("3. End \n");
}
//menu text


//       main function           //
int main(){
	printf("Welcome to the GEN 1 AIO calculator \n");
	int option;
	do {
        menu_text();
        option = readint(1,3);
        switch(option){
        	case 1:
        		damage_calc();
        		break;
        	case 2:
        		simulation();
        		break;
        	case 3:
        		printf("\nTerminando el programa \n");
        		break;
        	default:
        		printf("\n ERROR, invalid function!!!!!!!! \n");
        		break;
		}
	} while (option != 3);
	return 0;
}
//       main function           //
