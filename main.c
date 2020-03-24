#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int i, j;
int lugares[3][21];
char PecaSala1[50] = "Sala 1 / Peca: Animacao";
char PecaSala2[50] = "Sala 2 / Peca: O Drama Da Vida";
char PecaSala3[50] = "Sala 3 / Peca: Viagem ao Oeste";
int sala, lugar, tipoIngresso, idade;
float  valorTeatro = 45;
float valorInteira, valorMeia, valorBeneficiente;
float ValorFatInteira, ValorFatMeia;
int ContafatGratis;

//glob
char SalaePeca[50];
int Poutrona;
int TipoIngresso;
float ValorIngresso;

float CalcularDescontoMeia();
float CalcularDescontoInteira();

void CabecalhoMenu()
{
	system("cls");
	printf("=====================================================");
	printf("\n\n     ------MENU COMPRA INGRESSOS------    	 \n\n");
	printf("=====================================================");
	printf("\n\n");
}

void Comprar(){
	
	Poutrona = 0;
	TipoIngresso = 0;	
	
	CabecalhoMenu();
	
	//Seleção de salas disponiveis no teatro variavel global
	printf("Selecione a Sala e a Peca:");
	printf("\n--------------------\n");
	printf("1 - %s\n", &PecaSala1 );
	printf("2 - %s\n", &PecaSala2 );
	printf("3 - %s\n", &PecaSala3 );
	printf("\n");
	printf("Selecione uma Opcao:");
	scanf("%d", &sala);
	
	CabecalhoMenu();
	
	//Verfica tipod e ingresso a ser comprado
	printf("**Tipo de Ingresso**");
	printf("\n--------------------\n");
	printf(" 1 - Inteira\n");
	printf(" 2 - Meia\n");
	printf(" 3 - Ingressos para crianca carente \n");
	printf("\n");
	printf("Selecione uma Opcao:");
	scanf("%d", &tipoIngresso);
	
	//Exibe lugares disponiveis para compra dos ingressos
	VerificaLugares(sala);
	
	printf("\n\n--------------------\n");
	printf("Por favor, Selecione um assento Disponivel: \n");
	scanf("%d", &lugar);
	
	//Verifica se os lugares escolhidos testão disponiveis
	int validaGravaLugar;
	validaGravaLugar = GravaLugar(sala,lugar);	
	printf("\n\n Por Favor, precione uma tecla para gerar o valor..\n");
	getch();	
	
	if(validaGravaLugar == 1){
		//Finaliza compra gerando desconto para 50% ou não 
		CabecalhoMenu();
		printf("%s \n", SalaePeca   );
		printf("Assento: %d ", Poutrona   );
		Separacao();
		
		switch(tipoIngresso){
				case 1:
					ValorIngresso = CalcularDescontoInteira();
					break;
				case 2:
					ValorIngresso = CalcularDescontoMeia();
					break;
				case 3:
					ValorIngresso = 0;
					break;
		}
		
		printf("R$ %.2f \n", ValorIngresso);
		printf("\n\n Por Favor, precione uma tecla para gerar o ticket..");
		getch();
		
		CabecalhoMenu();

		//Checagem para gerar o faturamento
		char nomeTipoIngresso[20];
		switch(tipoIngresso){
			case 1:
				strcpy(nomeTipoIngresso, "Inteiro");
				ValorFatInteira = ValorFatInteira + ValorIngresso;
				break;
			case 2:
				strcpy(nomeTipoIngresso, "Meia");
				ValorFatMeia = ValorFatMeia + ValorIngresso;
				break;
			case 3:
				strcpy(nomeTipoIngresso, "Gratis");
				ContafatGratis = ContafatGratis + 1;
				break;
		}
		
		//Exibi na tela comprovante de compra 
		//begin
		printf("\n*************************************************\n");
		printf(" | %s, \n", SalaePeca);
		printf(" | Assento:  %d, \n", Poutrona);
		printf(" | Ingresso: %s, ", nomeTipoIngresso);
		printf(" | Valor: 	 R$ %.2f, \n", ValorIngresso);
		printf("\n*************************************************\n");
		//end
		
		
		printf("\n\n Por Favor, precione uma tecla para voltar..");
		getch();
			
	}
		
} 


void Exibirfaturamento(){
	
		float total = ValorFatInteira + ValorFatMeia;
	
		//Exibe Relatorio consolidaddo do Faturamento corrente
		CabecalhoMenu();
		printf("\n*************************************************\n");
		printf("\n******************FATURAMENTO*********************\n");
		printf(" | INTEIRAS R$ %.2f, \n", ValorFatInteira);
		printf(" | MEIA:  R$ %.2f, \n", ValorFatMeia);
		printf(" | GRATIS: %d, \n", ContafatGratis);
		printf(" | TOTAL:  R$ %.2f, \n", total);
		printf("\n*************************************************\n");
		printf("\n*************************************************\n");
		printf("\n\n Por Favor, precione uma tecla para voltar..");
		getch();
}

float CalcularDescontoMeia()
{
	float valorDesconto = valorTeatro*0.5;
	return valorDesconto;
}

float CalcularDescontoInteira()
{
	int tipoDesconto;
	float valorDesconto;
	
	Separacao();
	printf("1 - Tem 60 anos ou mais \n");
	printf("2 - Professor da rede publica de ensino \n");
	printf("3 - Nem uma da opcoes \n");
	Separacao();
	printf("\n Selecione uma opcao: ");
	scanf("%d",&tipoDesconto);
	
	
	switch(tipoIngresso){
			case 1: // 1 - Tem 60 anos ou mais
				valorDesconto = valorTeatro*0.5;
				printf("\n Desconto de 50% ");
				break;
			case 2: // 2 - Professor da rede publica de ensino
				valorDesconto = valorTeatro*0.5;
				printf("\n Desconto de 50% ");
				break;
			case 3: // 3 - Nem uma da opcoes
				printf("\n Sem Desconto 100% ");
				valorDesconto = 45;
				break;
	}
	
	printf("\n Valor do Ingresso: R$ %.2f \n ",valorDesconto);
	Separacao();

	return valorDesconto;

}

int GravaLugar(i,j){
	
	int vlRetorno = 0;
	
	if(lugares[i][j]==0){
		lugares[i][j] = 1;
		printf("\n\nAssento reservado com sucesso!\n");
		printf("Sala: [%d] Assento: [%d]\n\n", i, j);
		Poutrona = j;
		vlRetorno = 1;
	}else{
		printf("\nAssento ocupado!\n\n");
		vlRetorno = 0;
	}	
	return vlRetorno;
}

int VerificaLugares(s){
	
	//Monta na tela qual Sala e peça que o usuario escolheu anterior mente 
	//begin
	char nomePeca[50];
	switch(s){
			case 1:
				strcpy(nomePeca, PecaSala1);
				break;
			case 2:
				strcpy(nomePeca, PecaSala2);
				break;
			case 3:
				strcpy(nomePeca, PecaSala3);
				break;
	}
	
		
	Separacao();
	printf("\n\n | Assentos Disponiveis, %s ",nomePeca);	
	Separacao();
	//end

	//Lista todos os acentros e verifica se esta ocupado ou nao
	for(j = 1; j < 21; j++){
		
		if (lugares[s][j] == 1){				
			printf("Ocupado: %d ",j );				
		}else{
			strcpy(SalaePeca, PecaSala1);				 
			printf("%d ",j );	
		}
		
		if(j < 20 )		
			printf(",");		
	
	}
	
	return 0;
}

int Cancelar(){
	
	int i,j;
	
	CabecalhoMenu();
	
	printf("\nQual a Sala: ");
	scanf("%d", &i);
	printf("\n Qual o assento: ");
	scanf("%d", &j);
	
	if(lugares[i][j]==1){
		lugares[i][j]=0;
		printf("\n\n Sua Reserva foi Cancelada !\n\n");
	}else{
		printf("\n\n Nenhuma reserva para este assento. \n\n");
	}
	
	getch();
	return 0;
}

void Separacao()
{
	printf("\n --------------------- \n");
}

// Inicio do Programa
int main(int argc, char *argv[]) {
	
	int opcao;
	do{
		CabecalhoMenu();
		printf("1 - Comprar Ingressos\n");
		printf("2 - Cancelar Ingresso\n");
		printf("3 - Faturar\n");
		printf("4 - Encerrar o Sistema\n");
		printf("-------------------------------");
		printf("\n\n");
		printf("Comando: ");
		scanf("%d", &opcao);
		printf("\n\n");
		
		switch(opcao){
			case 1:
				Comprar(); //Função para comprar ingressos
				break;
			case 2:
				Cancelar(); // Função para cancelar a compra do ingresso
				break;
			case 3:
				Exibirfaturamento(); //Lista o faturamento atual
				break;
			case 4:
				system("exit");
				break;
		}
		
	}while(opcao!=4);
	
	return 0;
}
