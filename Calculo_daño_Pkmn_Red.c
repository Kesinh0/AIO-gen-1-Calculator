#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int Level, Critical, Attack, Defense, Power, Speed, random1=217, random2=255;
	float Stab, Type1, Type2;
	printf("Welcome to the Pokemon Red Version damage calculator \n");
	printf("I m going to ask you some values about the pokemon, and you have to answer \n");
	printf("to get them right \n");				//presentation
	printf("I need this values: \n");
	printf("The pokemons level \n");
	do {
		scanf("%d", &Level);
	}
	while (Level<0, Level>100);
	printf("the opponent pokemons defense stat \n ");
	do {
		scanf("%d", &Defense);	
	}
	while (Defense<0, Defense>255);
	printf("the pokemons speed stat \n");
	do {
		scanf("%d", &Speed);
	}
	while (Speed<0, Speed>255);
	printf("the pokemons attack stat \n");
	do {
		scanf("%d", &Attack);
	}
	while (Attack<0, Attack>255);
	printf("the power of the move \n");
	do {
		scanf("%d", &Power);
	}
	while (Power<0, Power>300);
	printf("Enter the Effectiveness of the move in the opp pokemon type1 \n");
	printf("(0) if its invulnerable, (0.5) if its not very effective \n");
	printf("(1) if its neutral, (2) if its supereffective \n");
	do{
		scanf("%f", &Type1);
	}
	while (Type1<-1, Type1>2);
	printf("Enter the Effectiveness of the move in the opp pokemon type2 \n");
	printf("(0) if its invulnerable, (0.5) if its not very effective \n");
	printf("(1) if its neutral, (2) if its supereffective \n");
	printf("if the pokemon doesnt have a second type, insert 1 \n");
	do{
		scanf("%f", &Type2);
	}
	while (Type2 < -1, Type2 > 2);
	printf("enter if the attack was STAB \n");
	printf("if the attack is stab put 1.5, if it is not, put 1 \n");
	do{
		scanf("%f", &Stab);
	}
	while (Stab<0.9, Stab>1.6);
	printf("if the attack was crit insert (2), if not, insert (1)\n");
	do{
		scanf("%d", &Critical);
	}
	while(Critical<0, Critical>3);
	int random = rand() % (random1 - random2 + 1) + random1;
	printf("the damage inflicted is: \n");
	float Damage = round(((((((2*Level*Critical)/5)+2)*Power*(Attack/Defense))/50)+2)*Stab*Type1*Type2);
	printf("%f", Damage);
	return 0;
}
	