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

int optionHandler(int hideOption) {
	/*
	*	Função responsável por controlar a lógica da entrada de dados.
	*	Usa um laço do while que obriga o usuário a selecionar um atributo válido.
	*	hidOption é um inteiro representando a opção de atributo a ser escondida. Se for -1, não esconde nada,
	*	caso diferente, esconde-se um atributo.
	*/
	int option;

	printf("\n|------------------------------|\n");
	printf("Selecione o atributo de comparação: ");

	//Array de strings com as possíveis opções. Usado para esconder a opção já selecionada pelo usuário.
	char opts[5][30] = {"População", "Área", "Pib", "Pontos turísticos", "Densidade demográfica"};

	do {

		//For loop que exibe as opções e impede que o usuário selecione opções iguais.
		for (int i=0; i<5; i++) {
			if (i+1 == hideOption) continue;
			else printf("\n%d. %s", (i+1), opts[i]);
		}
		printf("\n");
		scanf("%d", &option);

		if(option < 1 || option > 5) printf("Opção inválida. Tente novamente\n");

	} while(option < 1 || option > 5);

	return option;
}

int comparassionHandler(int option, struct card cardA, struct card cardB) {
	/*
	*	FUNÇÃO QUE REALIZA A COMPARASSÃO.
	*	@PARAM(OPTION: Int): OPÇÃO A SER COMPARADA, DE 1 A 5.
	*	@PARAM(cardA/cardB: CARD): STRUCT DE CARD COM OS PARÂMETROS;
	*/
	printf("\n|------------------------------|\n");
	printf("RESULTADO DA RODADA\n");
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

	printf("\nAtributo 1:\n");
	int option1 = optionHandler(-1);
	comparassionHandler(option1, card1, card2);

	printf("Atributo 2: ");
	int option2;
	//Impede a seleção de dois atributros iguais
	do {
		option2 = optionHandler(option1);
		if (option1 == option2) printf("Não é permitido selecionar o mesmo atributo 2 vezes. Tente novamente.");
	} while (option2 == option1);
	
	
	comparassionHandler(option2, card1, card2);

	//Soma dos atributos para determinar o vencedor da rodada
	float maxCard1, maxCard2 = 0;

	switch (option1)
	{
	case 1:
		maxCard1 += card1.population;
		maxCard2 += card2.population;
		break;
	case 2: 
		maxCard1 += card1.area;
		maxCard2 += card2.area;
		break;
	case 3:
		maxCard1 += card1.pib;
		maxCard2 += card2.pib;
		break;
	case 4:
		maxCard1 += card1.touristAttractions;
		maxCard2 += card2.touristAttractions;
		break;
	case 5:
		maxCard1 += card1.populationDensity;
		maxCard2 += card2.populationDensity;
		break;
	default:
		break;
	}


	switch (option2)
	{
	case 1:
		maxCard1 += card1.population;
		maxCard2 += card2.population;
		break;
	case 2: 
		maxCard1 += card1.area;
		maxCard2 += card2.area;
		break;
	case 3:
		maxCard1 += card1.pib;
		maxCard2 += card2.pib;
		break;
	case 4:
		maxCard1 += card1.touristAttractions;
		maxCard2 += card2.touristAttractions;
		break;
	case 5:
		maxCard1 += card1.populationDensity;
		maxCard2 += card2.populationDensity;
		break;
	default:
		break;
	}

	printf("\nRESULTADO DA PARTIDA\n");
	printf("\nSoma total da carta %s: %.2f - Soma total da carta %s: %.2f\n",card1.country, maxCard1, card2.country, maxCard2);
	if(maxCard1 == maxCard2) printf("\nA partida terminou em empate\n");
	else {
		printf("\nO vencedor foi %s\n",maxCard1 > maxCard2 ? card1.country : card2.country);
	}
	
	return 0;
}

 