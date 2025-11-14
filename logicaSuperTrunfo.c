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
	char city[50];
	unsigned long int population;
	float area;
	float pib;
	int touristAttractions;
	float populationDensity;
	float gdpPerCapita; //Pib per capita
	float superPower;
};

int main () {

	printf("Boas vindas ao Super trunfo C.");
	printf("\nCadastre 2 cartas");	

	//Declaração das duas structs, representando as duas cartas.
	struct card card1, card2;
	printf("\nDados da carta 1\n");

    printf("Estado: ");
    scanf(" %c", &card1.state); 

    printf("Código (Estado + numero da carta. Ex: A01): ");
    scanf("%s", card1.id); 

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", card1.city); //scanf retirando a quebra delinha

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
    printf("Estado: ");
    scanf(" %c", &card2.state); 

    printf("Código (Estado + numero da carta. Ex: A01): ");
    scanf("%s", card2.id); 

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", card2.city); //scanf retirando a quebra delinha

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

	//Bloco de comparação com IF e ELSE simples.
	printf("---------------------------------------------------------------");
	printf("\nComparação de Áreas\n");
    printf("Área de %s = %.2f km²", card1.city, card1.area);
    printf("\nÁrea de %s = %.2f km²", card2.city, card2.area);
	
    if (card1.area > card2.area) printf("\nA carta 1 (%s) venceu!", card1.city);
    else printf("\nA carta 2 (%s) venceu!\n", card2.city);


	return 0;
}