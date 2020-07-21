#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 3


int respcadastro; // quando o produto nao estiver cadastrado, responda 1 para cadastrar ou 0 para voltar par o menu
int ncadastrados = 0 /* controlar o numero de produtos cadastrados */, printar=0 /*controlar listagemdo estoque */ ,vendaconcluida=0 /* controlar listagem das vendas concluidas */;
int vet_carrinho1[48];
char vet_carrinho2[50];

typedef struct{
	int codigo, qtdestoque, totalvendas;
	char nome[100];
	float preco;
	
}Produto;
Produto produto[TAM];

typedef struct{
	float saldo, receita, despesa;
}CaixaMercado;
CaixaMercado caixa[TAM];

void MenuPrincipal();
void VendasConcluidas(CaixaMercado *caixa, Produto *produto);
void InfoCaixa(CaixaMercado *caixa, Produto *produto);
void AlterarProduto(Produto *produto);
void VerEstoque(Produto *produto);
void CadastrarProduto(Produto *produto);
void OpcoesDeEstoque(Produto *produto);
void MenuPrincipal();

int main (){
	
	MenuPrincipal();
}
void VendasConcluidas(CaixaMercado *caixa, Produto *produto){
	int i, voltarmenu;
	
	system("cls");
	printf("================= \n");
	printf("VENDAS CONCLUIDAS \n");
	printf("================= \n");
	
	printf("NOME     CODIGO     PRECO    VENDIDOS   QUANTIDADE \n");
	for(i=0;i<vendaconcluida;i++){
		if(produto[i].totalvendas != 0){
				printf("%s     ",produto[i].nome);
				printf("%d     ", produto[i].codigo);
				printf("%.2f     ", produto[i].preco);
				printf("%d             ", produto[i].totalvendas);
				printf("%d  " , produto[i].qtdestoque);
				printf("\n");
		}
		
	}	printf("TECLE 1 PARA VOLTAR AO MENU PRINCIPAL \n");
		scanf("%d", &voltarmenu);
		
		switch(voltarmenu){
			case 1: MenuPrincipal(); break;
			default: MenuPrincipal(); break;
		}
		
			
}
void InfoCaixa(CaixaMercado *caixa, Produto *produto){
		system("cls");
		int opcaocaixa;
	printf("   ================ \n");
	printf("\n INFORMACOES DO CAIXA \n");
	printf("   ================== \n");
	
	printf("\n\n 1. VENDAS CONCLUIDAS \n 2. RECEITA E DESPESA \n");
	scanf("%d", &opcaocaixa);
	
	switch(opcaocaixa){
		case 1: VendasConcluidas(caixa, produto); break;
	}
	
}
void AlterarProduto(Produto *produto){
			int j,alterar, newqtd, newcode;
			float newpreco;
			char nomeprod[100];
			
			printf("Digite o nome do produto que deseja alterar :\n");
				scanf("%s", &nomeprod);
							
			for(j=0; j<TAM; j++){
				
				if(strcmp(nomeprod, produto[j].nome) == 0){
				
				printf("O que voce deseja alterar no produto %s ? \n 1. PRECO \n 2. QTD \n 3. CODIGO \n", produto[j].nome);
				scanf("%d", &alterar);
				
				switch(alterar) {
				
				case 1:
					printf("INFORME O NOVO PRECO DO PRODUTO \n");
						scanf("%f", &newpreco);
						produto[j].preco = newpreco;
					MenuPrincipal();
			break;				
				case 2:
				
					printf("INFORME A NOVA QUANTIDADE DO PRODUTO \n");
					scanf("%d", &newqtd);
					produto[j].qtdestoque = newqtd;
						MenuPrincipal();
			break;
				case 3:				
					printf("INFORME O NOVO CODIGO DO PRODUTO \n");
					scanf("%d", &newcode);
					produto[j].codigo = newcode;
						MenuPrincipal();
			break;
				default:
				MenuPrincipal();
				}
			}		
		}
}
void VerEstoque(Produto *produto){
	int opcaoverestoque;
	int i;
	printf("NOME        CODIGO     PRECO      QUANTIDADE \n");
	if(produto[ncadastrados].qtdestoque == 0){
	printf("ESTOQUE VAZIO !\n\n");
	}
	for(int i=0; i<printar ;i++){
				printf("%s              ",produto[i].nome);
				printf("%d   ", produto[i].codigo);
				printf("%.2f          ", produto[i].preco);
				printf("%d ", produto[i].qtdestoque);
				printf("\n");
				}

	printf("\n1. ALTERAR DADOS DO PRODUTO \n 2. VOLTAR AO MENU PRINCIPAL \n");
	scanf("%d", &opcaoverestoque);
	switch(opcaoverestoque){
		case 1: AlterarProduto(produto); break;
		case 2: MenuPrincipal(); break;
		default: printf("OPCAO INVALIDA, VOCE SERA REDIRECIONADO AO MENU PRINCIPAL! \n"); 
		system("pause");
		MenuPrincipal(); 
		break;
	}
}
	

void BuscarProduto( Produto *produto){
	char nomeprod[100];
	int i;	
	
				printf("BUSCAR PRODUTO ... \n");
				fflush(stdin);
				gets(nomeprod);
				fflush(stdin);
				for(i=0; i<printar ;i++){
					if(strcmp(nomeprod, produto[i].nome) == 0){
						
					
				printf("NOME DO PRODUTO: %s \n",produto[i].nome);
				printf("CODIGO: %d \n", produto[i].codigo);
				printf("PRECO: %.2f\n", produto[i].preco);
				printf("QUANTIDADE EM ESTOQUE: %d \n", produto[i].qtdestoque);
				system("pause");
				}
		}
		
				
}

void CadastrarProduto(Produto *produto){
	int resp=1, i=ncadastrados;
		do	{
		printf("\nFrutas Cod. 1 - 10\n");
		printf("\nVerduras Cod. 11 - 20\n");
		printf("\nLegumes Cod. 21 - 30\n");
		printf("\nProteinas Cod. 31 - 40\n");
		printf("\nCongelados Cod. 41 - 50\n");
		printf("\nBebidas Cod. 51 - 60\n");
		printf("\nBebidas Alcoolicas Cod. 61 - 70\n");
		printf("\nPanificadora Cod. 71 - 80\n\n");
		
		for(i=ncadastrados;i>=ncadastrados and i<TAM;i++){
					fflush(stdin);
					printf("NOME DO PRODUTO: \n");
						gets(produto[i].nome);
						fflush(stdin);
					printf("CODIGO DO PRODUTO: \n");
						scanf("%d", &produto[i].codigo);
					
					printf("PRECO DO PRODUTO: \n");
						scanf("%f", &produto[i].preco);
					
					printf("QUANTIDADE DO PRODUTO: \n");
						scanf("%d", &produto[i].qtdestoque);
					printar++; //variavel para controlar o FOR da listagem dos produtos, para nao aparecer besteira quando imprimir a lista		
					ncadastrados++;
				printf("\n =================================== \n");
				printf("    CADASTRO EFETUADO COM SUCESSO! \n");
				printf("   CADASTRAR NOVO PRODUTO? \n\n\n 1. SIM \n 0. NAO \n");
					printf("=================================== \n");
				scanf("%d", &resp);
				
				if(resp == 0){
				break;
				}
		} 
					MenuPrincipal();
	}	while(resp!= 0);
}

void VenderProduto(Produto *produto, CaixaMercado *caixa){
		int codvenda, qtdvenda,respvenda, statusProdCadastrado = 0,respcadastroProd=0;
		float vrecebido;
		system("cls");
		printf("   ================ \n");
		printf("\n  VENDER PRODUTO \n");
		printf("   ================== \n");
		do{
		printf("1. Frutas\n");
		printf("2. Verduras\n");
		printf("3. Legumes\n");
		printf("4. Proteinas\n");
		printf("5. Congelados\n");
		printf("6. Bebidas\n");
		printf("7. Bebidas Alcoolicas\n");
		printf("8. Panificadora\n");
		
	
				
		printf("CODIGO DO PRODUTO \n");
		scanf("%d", &codvenda);
		
		
		for(int i=0;i<TAM; i++){
			if(codvenda == produto[i].codigo){
				
				
				statusProdCadastrado = 1;
				printf("\n ======================= \n");
				printf("%s \n PRECO: %.2f\n", produto[i].nome, produto[i].preco);
				printf("\n======================= \n");
				printf("\n ======================= \n");
				printf("QUANTIDADE ");
				scanf("%d", &qtdvenda);
				printf("\n ======================= \n");
			
				
			 
				produto[i].qtdestoque -= qtdvenda;
				caixa[i].receita += (produto[i].preco * qtdvenda);
			
				
				float valordacompra = produto[i].preco*qtdvenda;
					if(qtdvenda >= 10 && produto[i].codigo == 1){
					valordacompra = valordacompra - ((produto[i].preco*qtdvenda*5)/100);
					printf("\nFrutas com mais de 10 itens possuem 5 porcento de desconto !\n");
					printf("\n ======================= \n");
					printf("    VALOR DA COMPRA: %.2f \n", valordacompra);
					printf("\n	Frete: 7 reais !");
					printf("\n ======================= \n");
					printf("\n    VALOR RECEBIDO ");
					scanf("%f", &vrecebido);
					printf("\n ======================= \n");
				
				float troco = vrecebido-valordacompra;
				printf("TROCO: %.2f \n", troco);
			
				produto[i].totalvendas++;
				vendaconcluida++;
				}
				else if(qtdvenda >= 8 && produto[i].codigo == 11){
					valordacompra = valordacompra - ((produto[i].preco*qtdvenda*7)/100)+7;
					printf("\nVerduras e legumes acima de 8 itens possuem 7 porcento de desconto !\n");
					printf("\n ======================= \n");
					printf("    VALOR DA COMPRA: %.2f \n", valordacompra);
					printf("\n	Frete: 7 reais !");
					printf("\n ======================= \n");
					printf("\n    VALOR RECEBIDO ");
					scanf("%f", &vrecebido);
					printf("\n ======================= \n");
				
				float troco = vrecebido-valordacompra;
				printf("TROCO: %.2f \n", troco);
			
				produto[i].totalvendas++;
				vendaconcluida++;
				}
				else if(qtdvenda >= 6 && produto[i].codigo == 51){
					valordacompra = valordacompra - produto[i].preco + 7;
					printf("\nA cada 6 bebidas, 1 sai de graça !\n");
						printf("\n ======================= \n");
					printf("    VALOR DA COMPRA: %.2f \n", valordacompra);
					printf("\n	Frete: 7 reais !");
					printf("\n ======================= \n");
					printf("\n    VALOR RECEBIDO ");
					scanf("%f", &vrecebido);
					printf("\n ======================= \n");
				
				float troco = vrecebido-valordacompra;
				printf("TROCO: %.2f \n", troco);
			
				produto[i].totalvendas++;
				vendaconcluida++;
				}
				else if(valordacompra >= 75){
						printf("\n ======================= \n");
					printf("    VALOR DA COMPRA: %.2f \n", valordacompra);
					printf("\n   Frete gratis !\n");
					printf("\n ======================= \n");
					printf("\n    VALOR RECEBIDO ");
					scanf("%f", &vrecebido);
					printf("\n ======================= \n");
				
				float troco = vrecebido-valordacompra;
				printf("TROCO: %.2f \n", troco);
			
				produto[i].totalvendas++;
				vendaconcluida++;
				
				}else{
				valordacompra = valordacompra + 7;
				printf("\n ======================= \n");
				printf("    VALOR DA COMPRA: %.2f \n", valordacompra);
				printf("\n	Frete: 7 reais !");
				printf("\n ======================= \n");
				printf("\n    VALOR RECEBIDO ");
				scanf("%f", &vrecebido);
				printf("\n ======================= \n");
				
				float troco = vrecebido-valordacompra;
				printf("TROCO: %.2f \n", troco);
			
				produto[i].totalvendas++;
				vendaconcluida++;
			}
		}
		}
		
			if(statusProdCadastrado == 0){
				
				printf("\n  ======================= \n");
				printf("\nPRODUTO NAO CADASTRADO! \n");
				printf("   ======================= \n");
				printf("\n\n CADASTRAR PRODUTO? \n 1. SIM \n 2. NAO\n");
				scanf("%d", &respcadastroProd);
					switch(respcadastroProd){
						case 1:CadastrarProduto(produto);break;
						case 2: MenuPrincipal(); break;
					default: printf("OPCAO INVALIDA, VOCE SERA REDIRECIONADO AO MENU PRINCIPAL"); MenuPrincipal(); break;
							
						
					}
			}
		
			printf("VENDER OUTRO PRODUTO? \n 1. SIM \n 0. NAO \n");
			scanf("%d", &respvenda);
			if(respvenda == 0){
				MenuPrincipal();
				
			}	
			
	}while(respvenda != 0);
	
		
	
}

void OpcoesDeEstoque(Produto *produto){
	int opcaoestoque;
	
	system("cls");
	printf("   ================ \n");
	printf("\n OPCOES DE ESTOQUE \n");
	printf("   ================== \n");
	
	printf(" 1 - CADASTRAR NOVO PRODUTO \n 2 - VER ESTOQUE  \n 3 - BUSCAR PRODUTO \n");
	scanf("%d", &opcaoestoque);
	
	switch(toupper(opcaoestoque)){
		case 1: CadastrarProduto(produto); break;
		break;
		case 2: VerEstoque(produto);  break;
		break;
		case 3: BuscarProduto(produto); break;		
		default: MenuPrincipal();
	}
}

void MenuPrincipal(){
	int opcaomenu, resp;
	system("cls");
	
	printf("\n ============= \n");
	printf("    XFOOD \n");
	printf(" ============= \n");
			
	
	printf("\n\n\n 1 - NOVA VENDA \n 2 - INFORMACOES DE ESTOQUE \n 3 - INFORMACOES DE CAIXA \n");
	scanf("%d", &opcaomenu);
	
		switch(opcaomenu){
			case 1:
			VenderProduto(produto, caixa);break;
			case 2:
			OpcoesDeEstoque(produto); break;
			case 3: InfoCaixa(caixa, produto);
			case 0:
			printf("SAINDO DO PROGRAMA... \n"); break;		
		}
		

}
