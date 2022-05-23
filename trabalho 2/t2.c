#include <stdio.h>
#include <stdlib.h>

/* 
Implementações feitas:

 * Contador de cedulas
 * Menus
 * Revarga de Cedulas (com checagem para 0 e numeros negativos) (limite de cedulas)
 * Total sacado e saldo existente
 * Checagem de saque (se o saldo < saque avisar o usuario)
 * fome da porra
 * Contagem de cedulas

TODO:

 * Validador de CPF
 * Escrever numeros por extenso
 * Checar se é possivel dar o valor (com as notas disponiveis)

*/


int main(){
    int escolha, escolhaGerente, escolhaCedulas, qntCedulas; //escolhas

    int saque, saque_holder;
    int cpf;

    int totalSacado = 0;

    //contador de cedulas
    int cedulas450, cedulas250, cedulas50, cedulas20, cedulas10, cedulas5, cedulas2, cedulas1;
    cedulas450 = 100;
    cedulas250 = 200;
    cedulas50 = 400;
    cedulas20 = 800; 
    cedulas10 = 1600;
    cedulas5 = 3200;
    cedulas2 = 6400;
    cedulas1 = 12800;

    int limite450, limite250, limite50, limite20, limite10, limite5, limite2, limite1;
    limite450 = 100;
    limite250 = 200;
    limite50 = 400;
    limite20 = 800; 
    limite10 = 1600;
    limite5 = 3200;
    limite2 = 6400;
    limite1 = 12800;

    int saque450, saque250, saque50, saque20, saque10, saque5, saque2, saque1;

    int saldo = cedulas450 * 450 + cedulas250 * 250 + cedulas50 * 50 + cedulas20 * 20 + cedulas10 * 10 + cedulas5 * 5 + cedulas2 * 2 + cedulas1;

    do {
        printf("----------Menu----------\n1.Saque\n2.Gerente\n3.Finalizar\n -> Escolha sua opcao: ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1: // saque
                printf(" -> Informe o valor a ser sacado: ");
                scanf("%d", &saque);
                printf(" -> Informe seu CPF: ");
                scanf("%d", &cpf);

                if(cpf == 0) {// implementar validador de cpf
                    printf("CPF Invalido!\n");
                    break;
                }

                if(saque > saldo) {  //impossivel sacar mais dinheiro do que a maquina tem
                    printf("A maquina nao possui saldo suficiente\n");
                    break;
                }
                saque_holder = saque;
                    saque450 = 0;
                    saque250 = 0;
                    saque50 = 0;
                    saque20 = 0; 
                    saque10 = 0;
                    saque5 = 0;
                    saque2 = 0;
                    saque1 = 0;


                while (saque_holder > 0) { // saque_holder != 0 testar dps
                    if (saque_holder - 450 >= 0 && cedulas450 > 0) {
                        cedulas450--;
                        saque_holder -= 450;
                        saque450++;
                        continue;
                    }
                    if (saque_holder - 250 >= 0 && cedulas250 > 0) {
                        cedulas250--;
                        saque_holder -= 250;
                        saque250++;
                        continue;
                    }
                    if (saque_holder - 50 >= 0 && cedulas50 > 0) {
                        cedulas50--;
                        saque_holder -= 50;
                        saque50++;
                        continue;
                    }
                    if (saque_holder - 20 >= 0 && cedulas20 > 0) {
                        cedulas20--;
                        saque_holder -= 20;
                        saque20++;
                        continue;
                    }
                    if (saque_holder - 10 >= 0 && cedulas10 > 0) {
                        cedulas10--;
                        saque_holder -= 10;
                        saque10++;
                        continue;
                    }
                    if (saque_holder - 5 >= 0 && cedulas5 > 0) {
                        cedulas5--;
                        saque_holder -= 5;
                        saque5++;
                        continue;
                    }
                    if (saque_holder - 2 >= 0 && cedulas2 > 0) {
                        cedulas2--;
                        saque_holder -= 2;
                        saque2++;
                        continue;
                    }
                    if (saque_holder - 1 >= 0 && cedulas1 > 0) {
                        cedulas1--;
                        saque_holder -= 1;
                        saque1++;
                        continue;
                    }
                }
                printf("Saque %d:\n%d notas de 450\n%d notas de 250\n%d notas de 50\n%d notas de 20\n%d notas de 10\n%d notas de 5\n%d notas de 2\n%d notas de 1", saque450, saque250, saque50, saque20, saque10, saque5, saque2, saque1);
                saldo -= saque;

            break;
            case 2: // menu gerente
                do {
                    printf("----------Menu gerente:----------\n(1) Valor total sacado\n(2) Valor do saldo existente\n(3) Quantidade de cedulas existentes\n(4) Abastecer o caixa eletronico\n(5) Voltar ao menu principal\n -> Sua escolha: ");
                    scanf("%d", &escolhaGerente);
                    switch(escolhaGerente){
                        case 1: //valor total sacado
                            printf("O valor total sacado nesse caixa eletronico foi de %d\n", totalSacado);
                        break;
                        case 2: //Valor do saldo existente
                            printf("Saldo existente: %d\n", saldo);
                        break;
                        case 3: //quantidade de cedulas existentes
                            printf("Quantidade de cedulas:\nCedulas de 450: %d\nCedulas de 250: %d\nCedulas de 50: %d\nCedulas de 20: %d\nCedulas de 10: %d\nCedulas de 5: %d\nCedulas de 2: %d\nCedulas de 1: %d\n", cedulas450, cedulas250, cedulas50, cedulas20, cedulas10, cedulas5, cedulas2, cedulas1);
                        break;
                        case 4: //Abastecer caixa eletronico
                            do {
                                printf("----------Menu abastecer o caixa eletronico:----------\n(450) Cedulas de 450\n(250) Cedulas de 250\n(50) Cedulas de 50\n(20) Cedulas de 20\n(10) Cedulas de 10\n(5) Cedulas de 5\n(2) Cedulas de 2\n(1) Cedulas de 1\n(0) Voltar para o menu gerente\n -> Sua escolha:");
                                scanf("%d", &escolhaCedulas);
                                switch(escolhaCedulas){
                                    case 450:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite450 < qntCedulas + cedulas450) {
                                            printf("A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite450, cedulas450);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas450 += qntCedulas;
                                    break;
                                    case 250:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite250 < qntCedulas + cedulas250) {
                                            printf("A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite250, cedulas250);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas250 += qntCedulas;
                                    break;
                                    case 50:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite50 < qntCedulas + cedulas50) {
                                            printf("A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite50, cedulas50);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas50 += qntCedulas;
                                    break;
                                    case 20:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite20 < qntCedulas + cedulas20) {
                                            printf("A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite20, cedulas20);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas20 += qntCedulas;
                                    break;
                                    case 10:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite10 < qntCedulas + cedulas10) {
                                            printf("A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite10, cedulas10);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas10 += qntCedulas;
                                    break;
                                    case 5:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite5 < qntCedulas + cedulas5) {
                                            printf("A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite5, cedulas5);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas5 += qntCedulas;
                                    break;
                                    case 2:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite2 < qntCedulas + cedulas2) {
                                            printf("A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite2, cedulas2);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas2 += qntCedulas;
                                    break;
                                    case 1:
                                        printf(" -> Quantidade de cedulas de %d: ", escolhaCedulas);
                                        scanf("%d", &qntCedulas);
                                        if(limite1 < qntCedulas + cedulas1) {
                                            printf("A quantidade (%d) ultrapassa o limite de %d cedulas de %d\n", qntCedulas, limite1, cedulas1);
                                            break;
                                        }
                                        if (qntCedulas <= 0) {
                                            printf("Impossivel inserir valores negativos ou neutros.\n");
                                            break;
                                        }
                                        cedulas1 += qntCedulas;
                                    break;
                                    case 0:
                                        printf("Retornando ao menu gerente.\n");
                                    break;
                                    default:
                                        printf("Escolha uma opcao valida!\n");
                                }
                            
                            
                            } while (escolhaCedulas != 0);
                        break;
                        case 5: //sair
                            printf("Voltando ao menu principal.\n");
                        break;
                        default:
                            printf("Escolha uma opcao valida!\n");
                    }
                } while (escolhaGerente != 5);


            break;
            case 3:
                printf("Finalizado\n");
            break;
            default:
                printf("Escolha um valor valido!\n");
        }
    } while (escolha != 3);
}