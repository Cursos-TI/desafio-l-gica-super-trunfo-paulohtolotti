#include <stdio.h>
#include <math.h>

/*	Estrutura de dados que representa uma carta.
*	Escolhi uma struct para encapsular todos os dados que representam uma carta.
*	Apesar de não ter sido solicitado como requisito, resolvi incluir pois tenho 
*	familiaridade com esse conceito e acho válido para agrupar dados com um mesmo propósito.
*/
struct card {
 	char state;
	char id[4];
	char country[50];
	unsigned long int population;
	float area;
	float pib;
	int touristAttractions;
	float populationDensity;
	float gdpPerCapita; //Pib per capita
	float superPower;
};

int optionHandler() {
	/*
	*	Função responsável por controlar a lógica da entrada de dados.
	*	Usa um laço do while que obriga o usuário a selecionar um atributo válido.
	*/
	int option;

	printf("\n|------------------------------|\n");
	printf("Selecione o atributo de comparação: ");
	do {

		printf("\n1. População \n2. Área \n3. PIB \n4. Pontos turísticos \n5. Densidade demográfica\n");
		scanf("%d", &option);

		if(option < 2 || option > 6) printf("Opção inválida. Tente novamente\n");

	} while(option < 2 || option > 6);

	return option;
}

void comparassionHandler(int option, struct card cardA, struct card cardB) {

	printf("\n|------------------------------|\n");
	printf("RESULTADO FINAL\n");
	printf("%s vs %s", cardA.country, cardB.country);
	printf("\nAtributo escolhido: ");

	switch(option) {
		case 1:
			printf("população");
			printf("\nPopulação de %s = %d habitantes-- População de %s = %d habitantes", cardA.country, cardA.population, cardB.country, cardB.population);

			if(cardA.population > cardB.population) {
				printf("\n%s venceu!\n", cardA.country);

			} else if (cardB.population > cardA.population) {
				printf("\n%s venceu!\n", cardB.country);

			} else {
				printf("\nEmpate!\n");
			}
			break;
		case 2:
			printf("área");
			printf("\nÁrea de %s = %.2fkm² -- Área de %s = %.2fkm²",cardA.country, cardA.area, cardB.country, cardB.area);
			
			if(cardA.area > cardB.area) {
				printf("\n%s venceu!\n", cardA.country);

			} else if (cardB.area > cardA.area) {
				printf("\n%s venceu!\n", cardB.country);

			} else {
				printf("\nEmpate!\n");
			}
			break;
		case 3:
			printf("PIB");
			printf("\nPIB de %s = %.2f bilhões -- PIB de %s = %.2f bilhões",cardA.country, cardA.pib, cardB.country, cardB.pib);
			
			if(cardA.pib > cardB.pib) {
				printf("\n%s venceu!\n", cardA.country);

			} else if (cardB.pib > cardA.pib) {
				printf("\n%s venceu!\n", cardB.country);

			} else {
				printf("\nEmpate!\n");
			}
			break;
		case 4:
			printf("pontos turísticos");
			printf("\nPontos turísticos de %s = %d -- Pontos turísticos de %s = %d",cardA.country, cardA.touristAttractions, cardB.country, cardB.touristAttractions);
			
			if(cardA.touristAttractions > cardB.touristAttractions) {
				printf("\n%s venceu!\n", cardA.country);

			} else if (cardB.touristAttractions > cardA.touristAttractions) {
				printf("\n%s venceu!\n", cardB.country);

			} else {
				printf("\nEmpate!\n");
			}
			break;
		case 5:
			printf("densidade populacional");
			printf("\nDensidade populacional de %s = %.2f hab/km² -- Densidade populacional de %s = %.2f hab/km²",cardA.country, cardA.populationDensity, cardB.country, cardB.populationDensity);
			
			if(cardA.populationDensity < cardB.populationDensity) {
				printf("\n%s venceu!\n", cardA.country);

			} else if (cardB.populationDensity < cardA.populationDensity) {
				printf("\n%s venceu!\n", cardB.country);

			} else {
				printf("\nEmpate!\n");
			}
			break;
		default:
			printf("\n Opção inválida.");

	}
}

int main () {

	printf("Boas vindas ao Super trunfo C.");
	printf("\nCadastre 2 cartas");	

	//Declaração das duas structs, representando as duas cartas.
	struct card card1, card2;
	printf("\nDados da carta 1\n");

    printf("Nome do país: ");
    scanf(" %49[^\n]", card1.country); //scanf retirando a quebra delinha

	printf("Número de habitantes: ");
	scanf("%d", &card1.population);

	printf("Area (km²): ");
	scanf("%f", &card1.area);

	printf("PIB(bilhões): ");
	scanf("%f", &card1.pib);

	printf("Quantidade de pontos turísticos: ");
	scanf("%d", &card1.touristAttractions);

	//Cálculos
	card1.populationDensity = card1.population / card1.area;
	card1.gdpPerCapita = card1.pib * pow(10,9) / card1.population;

	printf("\nInsira os dados da carta 2\n"); 

    printf("Nome do país: ");
    scanf(" %49[^\n]", card2.country); //scanf retirando a quebra delinha

	printf("Número de habitantes: ");
	scanf("%d", &card2.population);

	printf("Area (km²): ");
	scanf("%f", &card2.area);

	printf("PIB(bilhões): ");
	scanf("%f", &card2.pib);

	printf("Quantidade de pontos turísticos: ");
	scanf("%d", &card2.touristAttractions);

	card2.populationDensity = card2.population / card2.area;
	card2.gdpPerCapita = card2.pib * pow(10,9) / card2.population;

	//Bloco de comparação
	int option = optionHandler();
	comparassionHandler(option, card1, card2);


	return 0;
}

 