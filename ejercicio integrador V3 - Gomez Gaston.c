#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct reserva{
	int piso;
	int cantidad;
	int hab;
};
struct costo{
	char hab[12];
	int precio;
};
struct cuentas{
	int contador;
	int costo;
	int inqui;
};
int menu();
void ord_piso();
void mayor_piso_inqui(struct cuentas result[13][6]);
void mayor_hab_inqui(struct cuentas result[13][6]);
void reset_cant();
void reset_hab();
void reset_piso();
void reset_precio();
void reset_res();
void ord_hab();
void mayor_piso_hab(struct cuentas result[13][6]);
void lee_res(int cant_res,struct reserva res[]);
void lee_precio(int Precio[6]);
void lee_pisos(char pisos[12][12]);
void mayor_hab(struct cuentas result[13][6]);
void mayor_piso(struct cuentas result[13][6]);
void resultados(int cant_res,struct reserva res[],struct cuentas result[13][6]);
void reset_arch();
void lee_hab(char habitacion [5][12]);
int select_hab();
int select_piso();
void craft_res();
int testeo();
int n_res();
void inicio();
int main(){
    int opcion,cant_res=0,salir=0;
    struct reserva res[1];
	struct cuentas result[13][6];
	inicio();
	do{
        cant_res=testeo();
        realloc(res,cant_res*sizeof (struct reserva));
        resultados(cant_res,res,result);
        system("cls");
        opcion=menu();
        salir=0;
        switch (opcion){
            case 0: reset_arch(); break;
            case 1: system("cls");craft_res(); break;
            case 2: if (cant_res==0){printf("\nNo hay reservas realizadas");} else {mayor_piso_hab(result);}break;
            case 3: if (cant_res==0){printf("\nNo hay reservas realizadas");} else {mayor_piso(result);}break;
            case 4: if (cant_res==0){printf("\nNo hay reservas realizadas");} else {mayor_hab(result);} break;
            case 5: if (cant_res==0){printf("\nNo hay reservas realizadas");} else {mayor_piso_inqui(result);} break;
            case 6: if (cant_res==0){printf("\nNo hay reservas realizadas");} else {mayor_hab_inqui(result);}break;
            case 7: ord_piso();break;
            case 8: ord_hab();break;
            default: salir=1;printf("\nPrecionaste 9, vas a salir");break;
        }printf("\nPresione una tecla para continuar");
        getch();
	}while (salir!=1);
    printf("\nCerrando el programa");
return 0;
}
int menu(){
    int opcion;char num;
    int j=39;int sal=0;
    printf("\n%c",201);
    for (int i=0;i<j;i++)
        printf("%c",205);
    printf("%c",187);
    printf("\n%c\tSeleccion de Opcion:\t\t%c",186,186);
    printf("\n%c0-Reiniciar archivos\t\t\t%c",186,186);
    printf("\n%c1-Realizar reserva\t\t\t%c",186,186);
    printf("\n%c2-Habitacion y Piso mas elegido\t%c",186,186);
    printf("\n%c3-Piso mas elegido\t\t\t%c",186,186);
    printf("\n%c4-Habitacion mas elegida\t\t%c",186,186);
    printf("\n%c5-Cantidad de reservas por piso\t%c",186,186);
    printf("\n%c6-Cantidad de reservas por Habitacion\t%c",186,186);
    printf("\n%c7-Nombres de pisos Ordenados\t\t%c",186,186);
    printf("\n%c8-Nombres de habitaciones Ordenados\t%c",186,186);
    printf("\n%c9-Salir\t\t\t\t%c",186,186);
    printf("\n%c",200);
    for (int i=0;i<j;i++)
        printf("%c",205);
    printf("%c\n",188);
    do{ num=getch();sal=0;
        opcion=num-'0';
        if ((opcion<10)&&(opcion>=0))
            sal=1;
    }while(sal!=1);
    printf("\tOpcion seleccionada: %d",opcion);
    return opcion;
}
void ord_piso(){
char Pisos[12][12];
char pibote[12];
int i,j=1,h;
int temp=0;;int salida=0;
lee_pisos(Pisos);
int sal_pri=0;
do{h=0;
i=0;j=1;salida=0;temp=0;
    do{
        if(strcmp(Pisos[i],Pisos[j])>0){
            strcpy(pibote,Pisos[i]);
            strcpy(Pisos[i],Pisos[j]);
            strcpy(Pisos[j],pibote);

            temp=i;j++;h++;
        }else if(strcmp(Pisos[i],Pisos[j])<0){
        i=j;j++;temp=i;
        }else if(strcmp(Pisos[i],Pisos[j])==0){
        j++;
        }
        if ((j>=12)||(i>=12))
            salida=1;
    }while (salida!=1);
    if (h==0)
        sal_pri=1;
}while(sal_pri!=1);
for(i=0;i<12;i++)
printf("\n%s",Pisos[i]);
}
void ord_hab(){
char habitacion [5][12];
char pibote[12];
int i,j=1,h;
int temp=0;;int salida=0;
lee_hab(habitacion);
int sal_pri=0;
do{h=0;
i=0;j=1;salida=0;temp=0;
    do{
        if(strcmp(habitacion[i],habitacion[j])>0){
            strcpy(pibote,habitacion[i]);
            strcpy(habitacion[i],habitacion[j]);
            strcpy(habitacion[j],pibote);
            temp=i;j++;h++;
        }else if(strcmp(habitacion[i],habitacion[j])<0){
        i=j;j++;temp=i;
        }else if(strcmp(habitacion[i],habitacion[j])==0){
        j++;
        }
        if ((j>=5)||(i>=5))
            salida=1;
    }while (salida!=1);
    if (h==0)
        sal_pri=1;
}while(sal_pri!=1);
for(i=0;i<5;i++)
printf("\n%s",habitacion[i]);
}

void lee_pisos(char pisos[12][12]){
	FILE * archivo;
	archivo=fopen("Pisos.data","rb");
	fread(pisos,sizeof(pisos[12]),12,archivo);
	fclose(archivo);
}
void lee_hab(char habitacion [5][12]){
	FILE * archivo;
	archivo=fopen("Habitaciones.data","rb");
	fread(habitacion,sizeof(habitacion[12]),5,archivo);
	fclose(archivo);
}
void lee_precio(int Precio[6]){
	FILE * Arch_Precio;
	Arch_Precio=fopen("Precios.data","rb");
	fread(Precio,sizeof(int),6,Arch_Precio);
	fclose(Arch_Precio);
}
void lee_res(int cant_res,struct reserva res[]){
	FILE*reservas;
	reservas=fopen("Reservas.data","rb");
	fread(res,sizeof(struct reserva),cant_res,reservas);
	fclose(reservas);
}
void resultados(int cant_res,struct reserva res[],struct cuentas result[13][6]){//printf("ingres");

	char habitacion[5][12];
	lee_hab(habitacion);//printf("hab");
	char pisos[12][12];
	lee_pisos(pisos);//printf("piso");
	int Precio[6];
	lee_precio(Precio);//printf("precio");
int i,j;
for (i=1;i<13;i++){
	for (j=1;j<6;j++){
		result[i][j].inqui=0;
		result[i][j].contador=0;
		result[i][j].costo=0;
	}
}
//printf("contadores");
lee_res(cant_res,res);//printf("reserv");
for (i=0;i<cant_res;i++){
	result[res[i].piso][res[i].hab].contador++;
	result[res[i].piso][res[i].hab].inqui+=res[i].cantidad;
	result[res[i].piso][res[i].hab].costo=	result[res[i].piso][res[i].hab].contador*Precio[res[i].hab];
}
}
void mayor_hab_inqui(struct cuentas result[13][6]){
	int i,j;
	int P_temp=1;
	int H_temp=1;
	int sum_p_inq[6];
	for (j=0;j<6;j++)
	{
		sum_p_inq[j]=0;
		}
	for (j=1;j<6;j++)
	{
		for (i=1;i<13;i++)
		{
		sum_p_inq[j]+=result[i][j].inqui;
		}

		if (sum_p_inq[j]>=sum_p_inq[P_temp])
			{
			P_temp = j;
			}
		}
	char habitacion[5][12];
	lee_hab(habitacion);

printf("\nLa Habitacion con Mayor cantidad de inquilinos es: %s, con un total de: %d inquilinos",habitacion[P_temp-1],sum_p_inq[P_temp]);
}
void mayor_piso_inqui(struct cuentas result[13][6]){
	int i,j;
	int P_temp=1;
	int H_temp=1;
	int sum_p_inq[13];
	for (j=0;j<13;j++)
	{
		sum_p_inq[j]=0;
		}
	for (j=1;j<13;j++)
	{
		for (i=1;i<6;i++)
		{
		sum_p_inq[j]+=result[j][i].inqui;
		}
		if (sum_p_inq[j]>=sum_p_inq[P_temp])
			{
			P_temp = j;
			}
	}
	char pisos[12][12];
	lee_pisos(pisos);
printf("\nEl Piso con Mayor cantidad de inquilinos es: %s, con un total de: %d inquilinos",pisos[P_temp-1],sum_p_inq[P_temp]);
}
void mayor_piso_hab(struct cuentas result[13][6]){
	int i,j;
	int P_temp=1;
	int H_temp=1;
	int sum_p_h[13][6];
	int sum_precio[13][6];
	int Precio[6];
	lee_precio(Precio);
	for (j=0;j<13;j++)
	{
		for (i=0;i<6;i++)
		{
		sum_p_h[j][i]=0;
		sum_precio[j][i]=0;
		}
	}
	for (j=1;j<13;j++)
	{
		for (i=1;i<6;i++)
		{
		sum_precio[j][i]+=result[j][i].contador*Precio[i];
		if (result[j][i].contador>=result[P_temp][H_temp].contador)
			{
			P_temp = j; H_temp = i;
			}
		}
	}
	char pisos[12][12];
	lee_pisos(pisos);
	char habitacion[5][12];
	lee_hab(habitacion);
printf("\nEl Piso y Habitacion mas solicitado en conjunto son: %s y %s, con una recaudacion de: %d",pisos[P_temp-1],habitacion[H_temp-1],sum_precio[P_temp][H_temp]);
}
void mayor_piso(struct cuentas result[13][6]){
	int i,j;
	int temp=1;
	int sum_pisos[13];
	int sum_precio[13];
	int Precio[6];
	lee_precio(Precio);
	for (j=1;j<13;j++)
	{
	sum_pisos[j]=0;
	sum_precio[j]=0;
		for (i=1;i<6;i++)
		{
		sum_pisos[j]+=result[j][i].contador;
		sum_precio[j]+=result[j][i].contador*Precio[i];
		}
	if(sum_pisos[j]>sum_pisos[temp])
		temp=j;
	}
	char pisos[12][12];
	lee_pisos(pisos);
printf("\n el piso con mas solicitado es %s, con una recaudacion de : $%d",pisos[temp-1],sum_precio[temp]);
}
void mayor_hab(struct cuentas result[13][6]){
	int Precio[6];
	lee_precio(Precio);
	int i,j;
	int temp=1;
	int sum_hab[6];
	int sum_precio[6];
	for (j=1;j<6;j++)
	{
	sum_hab[j]=0;
	sum_precio[j]=0;
		for (i=1;i<13;i++)
		{
		sum_hab[j]+=result[i][j].contador;
		sum_precio[j]+=result[i][j].contador * Precio[j];
		}
	if(sum_hab[j]>sum_hab[temp])
		temp=j;
	}
	char habitacion[5][12];
	lee_hab(habitacion);
printf("\n la habitacion mas solicitada es %s , con una recaudacion de : $%d",habitacion[temp-1],sum_precio[temp]);
}
int n_res(){
	int f_res=0;
	printf("Fin de reserva? (1-SI / 0-NO)");
	scanf("%d",&f_res);
	if (f_res==1)
		return 1;
	else
		return 0;
}
int testeo(){
FILE*test_c;int cant_res;
			test_c=fopen("Cantidades.data","rb");
			fread(&cant_res,sizeof(cant_res),1,test_c);
			fclose(test_c);
FILE*test_r;struct reserva reserva[cant_res];
			test_r=fopen("Reservas.data","rb");
			fread(reserva,sizeof(struct reserva),cant_res,test_r);
			fclose(test_r);
	char habitacion[5][12];
	lee_hab(habitacion);
	char pisos[12][12];
	lee_pisos(pisos);
*/return cant_res;
}
void craft_res(){
	struct reserva res;
	res.piso=select_piso();
	res.hab=select_hab();
	printf("\nCantidad de inquilinos: ");
	scanf("%d",&res.cantidad);
int cant_res;
FILE * res_arch;
res_arch=fopen("Reservas.data","ab");
fwrite(&res,sizeof(struct reserva),1,res_arch);
fclose(res_arch);
FILE * cant_arch;
cant_arch=fopen("Cantidades.data","r+b");
fseek(cant_arch,0,SEEK_SET);
fread(&cant_res,sizeof(cant_res),1,cant_arch);
cant_res++;
fseek(cant_arch,0,SEEK_SET);
fwrite(&cant_res,sizeof(cant_res),1,cant_arch);
fclose(cant_arch);system("cls");
}
int select_piso(){
char pisos[12][12];
int resultado=0;
int opcion=0; int i;
lee_pisos(pisos);
    int j=23;
    printf("\n%c",201);
    for ( i=0;i<j;i++)
        printf("%c",205);
    printf("%c",187);
printf("\n%cSeleccion de Piso:\t%c",186,186);
for (i=0;i<12;i++)
    printf("\n%c\t%d-%s  \t%c",186,i+1,pisos[i],186);
    printf("\n%c",200);
    for ( i=0;i<j;i++)
        printf("%c",205);
    printf("%c\n",188);
do{
    scanf("%d",&opcion);fflush(stdin);
    if ((opcion>0)&&(opcion<13)){
        resultado=1; system("cls");return opcion;
        }
    else{
        printf("Piso inexistente\n");
        }
}while (resultado!=1);
}
int select_hab(){
char habitacion[5][12];
int resultado=0;
int opcion=0; int i;
lee_hab(habitacion);
int j=26;
    printf("\n%c",201);
    for ( i=0;i<j;i++)
        printf("%c",205);
    printf("%c",187);
printf("\n%cSeleccion de Habitacion:  %c",186,186);
for (i=0;i<5;i++)
    printf("\n%c\t%d-%s   \t   %c",186,i+1,habitacion[i],186);
    printf("\n%c",200);
    for ( i=0;i<j;i++)
        printf("%c",205);
    printf("%c\n",188);
do{
    scanf("%d",&opcion);fflush(stdin);
    if ((opcion>0)&&(opcion<6)){
        resultado=1;system("cls");return opcion;
        }
    else{
        printf("Habitacion inexistente\n");
        }
}while (resultado!=1);
}
void reset_cant(){
	remove("Cantidades.data");
	FILE * primero;
	primero=fopen("Cantidades.data","wb");
	int cant_res =0;
	fwrite(&cant_res,sizeof (cant_res), 1,primero);
	fclose(primero);
	printf("\nCreado cantidad");
}
void reset_hab(){
	remove("Habitaciones.data");
	char Habitaciones[5][12];
	strcpy(Habitaciones[0],"Suite");
	strcpy(Habitaciones[1],"Individual");
	strcpy(Habitaciones[2],"Doble");
	strcpy(Habitaciones[3],"Triple");
	strcpy(Habitaciones[4],"Junior");
	FILE* segundo;
	segundo=fopen("Habitaciones.data","wb");
	fwrite(Habitaciones,sizeof(Habitaciones),1,segundo);
	fclose(segundo);
	printf("\nCreado Habitacion");
}
void reset_piso(){
	char Pisos[12][12]; 
	for (int i=0;i<12;i++)
		strcpy(Pisos[i],"           ");
	strcpy(Pisos[0],"Zeus");
	strcpy(Pisos[1],"Hera");
	strcpy(Pisos[2],"Hefesto");
	strcpy(Pisos[3],"Atenea");
	strcpy(Pisos[4],"Apolo");
	strcpy(Pisos[5],"Artemisa");
	strcpy(Pisos[6],"Ares");
	strcpy(Pisos[7],"Afrodita");
	strcpy(Pisos[8],"Hestia");
	strcpy(Pisos[9],"Hermes");
	strcpy(Pisos[10],"Demeter");
	strcpy(Pisos[11],"Poseidon");
	FILE* tercero;
	tercero=fopen("Pisos.data","wb");
	fwrite(Pisos,sizeof(Pisos),1,tercero);
	fclose(tercero);
	printf("\nCreado Pisos");
}
void reset_precio(){
	int Precio[6];
	Precio[1]=1800;
	Precio[2]=800;
	Precio[3]=1000;
	Precio[4]=1300;
	Precio[5]=900;
	remove("Precios.data");
	FILE* cuarto;
	cuarto=fopen("Precios.data","wb");
	fwrite(Precio,sizeof(Precio),6,cuarto);
	fclose(cuarto);
	printf("\nCreado Precios\n");
}
void reset_res(){
	remove("reservas.data");
	FILE * quinto;
        fclose(quinto);
        quinto=fopen("Reservas.data","wb");
    fclose(quinto);
}
void inicio(){
	FILE * quinto;
	quinto=fopen("Reservas.data","rb");
	if(quinto==NULL){
        fclose(quinto);printf("primer");
        quinto=fopen("Reservas.data","wb");printf("segun");}
    fclose(quinto);
    FILE * primero;
    primero=fopen("Cantidades.data","rb");
    if(primero==NULL){
	fclose(primero);
	primero=fopen("Cantidades.data","wb");
	int cant_res =0;
	fwrite(&cant_res,sizeof (cant_res), 1,primero);
	fclose(primero);}
	printf("\nCreado cantidad");
	reset_precio();reset_hab();reset_piso();
}
void reset_arch(){
reset_cant();
reset_hab();
reset_piso();
reset_precio();
reset_res();
}
