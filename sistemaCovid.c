#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h> 

int SimNao(char Resposta[1], int i){
	
	char sim[1] = {"s"};
	int x;
	int Risco = 0;
	printf("\n Digite sua resposta \n \n (SIM) = s (N�O) = n \n");
	scanf("%s", Resposta);
	fflush(stdin);
	
	if(strcmp(sim,Resposta)== 0){
		for(x=0; x<i; x++){
			Risco++;
		}
	}
	system("cls");
	return Risco;
}
	
int main() {

	FILE *reg;
	setlocale(LC_ALL, "Portuguese");

	char Resposta[1];
	int i, NivelRisco, TotalRisco = 0;
	char Risc[6];
	struct cadastro {
		char CPF[15];
		char Nome[50];
		char Sexo[10];
		float Idade;
	};

	struct cadastro paciente1;
	
	printf("\n Digite seu CPF \n");
	gets(paciente1.CPF);
	fflush(stdin);
	printf("\n Digite seu Nome \n");
	gets(paciente1.Nome);
	fflush(stdin);
	printf("\n Digite seu Sexo \n");
	scanf("%s", &paciente1.Sexo);
	fflush(stdin);
	printf("\n Digite sua Idade \n");
	scanf("%g", &paciente1.Idade);
	fflush(stdin);
	system("cls");
	
	printf("\n Tem Febre? \n");
		NivelRisco = SimNao(Resposta, i = 5);
		TotalRisco = TotalRisco + NivelRisco;
	printf("\n Tem dor de cabe�a? \n");
		NivelRisco = SimNao(Resposta, i = 1);
		TotalRisco = TotalRisco + NivelRisco;
	printf("\n Tem secre��o nasal ou espirros? \n");
		NivelRisco = SimNao(Resposta, i = 1);
		TotalRisco = TotalRisco + NivelRisco;
	printf("\n Tem dor/irrita��o na garganta? \n");
		NivelRisco = SimNao(Resposta, i = 1);
		TotalRisco = TotalRisco + NivelRisco;
	printf("\n Tem tosse seca? \n");
		NivelRisco = SimNao(Resposta, i = 3);
		TotalRisco = TotalRisco + NivelRisco;
	printf("\n Tem dificuldade respirat�ria? \n");
		NivelRisco = SimNao(Resposta, i = 10);
		TotalRisco = TotalRisco + NivelRisco;
	printf("\n Tem dores no corpo?  \n");
		NivelRisco = SimNao(Resposta, i = 1);
		TotalRisco = TotalRisco + NivelRisco;
	printf("\n Tem diarr�ia? \n");
		NivelRisco = SimNao(Resposta, i = 1);
		TotalRisco = TotalRisco + NivelRisco;
	printf("\n Esteve em contato, nos �ltimos 14 dias, com um caso diagnosticado com COVID-19? \n");
		NivelRisco = SimNao(Resposta, i = 10);
		TotalRisco = TotalRisco + NivelRisco;
	printf("\n Esteve em locais com grande aglomera��o? \n");
		NivelRisco = SimNao(Resposta, i = 3);
		TotalRisco = TotalRisco + NivelRisco;
	
	if(TotalRisco < 10){
		strcpy (Risc,"Baixo");
		printf("\n Risco Baixo \n");
	}
	if(TotalRisco > 9 && TotalRisco < 20){
		strcpy (Risc,"Medio");
		printf("\n Risco Medio \n");
	}	
	else{
		strcpy (Risc, "Alto");
		printf("\n Risco Alto \n");
	}	
	printf("Total de Risco �: %d ", TotalRisco);
	reg = fopen("arquivo.txt", "a");

		if(reg == NULL){
			printf("\n Arquivo n�o foi aberto. Ocorreu um erro! \n");
		}
		else{
			fprintf(reg,"\n \t Dados do Paciente \n");
			fprintf(reg,"\n CPF do Paciente %s", paciente1.CPF);
			fprintf(reg,"\n Nome: %s", paciente1.Nome);
			fprintf(reg,"\n Sexo: %s", paciente1.Sexo);
			fprintf(reg,"\n Idade: %g", paciente1.Idade);
			fprintf(reg,"\n Nivel de Risco � %s", Risc);
			fprintf(reg,"\n Pontos de Risco: %d ", TotalRisco);
		}

	fclose(reg);

	return 0;
}
