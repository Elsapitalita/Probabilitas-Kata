/*
Nama		:	1. Valentine Trihandayani	-	11418007
				2. Elsa Pitalita Sihombing	-	11418025
				3. Diana Grace Marbun		-	11418027
Kelas		: 	41TI-1
Deskripsi	:	Mini Project Mencari Probabilitas Kata
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//2D Array untuk menampung kata
char daftarKata[101][101]={0};
void tambahKalimatBaru(char *pathData,char *namaKalimat,char *jumlahKalimat);


//Fungsi untukh menampung kata dan mengembalikan ukuran/total kata yang ditampung
int tampungKata(char* kalimat)
{
    char *inp;
    char *pathData="perhitungankalimat.txt";
    
    int x=0;
    inp = strtok(kalimat, " ");
    while(inp != NULL){
        strcpy(daftarKata[x++], inp);
        inp = strtok(NULL, " ");
        FILE *pf;
        
        while(inp != NULL){
        strcpy(daftarKata[x++], inp);
        inp = strtok(NULL, " ");
    }
    return x;
}
}
//Fungsi untuk menghitung apakah kata yang dicari sama dengan yang ditampung
int hitung(char* cari, char daftarKata[101][101], int x){
    int i, Y=0;
    FILE *pf;
    

    for(i=0; i<x; i++){
        if(strcmp(cari, daftarKata[i])==0)
        		Y++;
    }
    return Y;
}

int main()
{
    char kalimat[1001];
    char cari[101];
    int i;
    FILE *pf;
     char kar, again='y';
    int opsi;

 
    
    do{
    	printf("\n");
		printf("==================================================     W E L C O M E     ===========================================");
		printf("\n\n");
		printf("Silahkan masukkan pilihan Anda: \n");
    	printf("[1] Menghitung Probabilitas Kata\n");
	    printf("[2] Peluang yang muncul\n");
	    printf("[3] History kata yang dicari\n");
	    printf("[4] Exit\n");
        printf("Masukkan opsi >>> ");
        scanf("%d", &opsi);
        switch(opsi){
            case 1:
                    printf("Masukkan sebuah kalimat: ");
                    getchar();
                    scanf("%[^\n]", kalimat);
                    
                    FILE *test=fopen("kalimat.txt","w");
                    
					fprintf(test, "%s",strcat(kalimat,""));

                    int arrSize = tampungKata(kalimat);

                    printf("Cari kata: ");
                    scanf("%s", cari);
                    
                    FILE *test2 = fopen("history.txt","w");
                    fprintf(test2,"%s",strcat(cari,""));
                    fclose(test2);
                    int ans=0;
					
                    for(i=0; i<arrSize; i++){
                        if(strcmp(cari, daftarKata[i])==0)
                            ans++;
                    }
					fclose(test);
					
                    printf("Kata %s muncul %d kali\n\n", cari, hitung(cari, daftarKata, arrSize));
                   	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    DESAIN BY    <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
					printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   ELSA       DIANA       VALENTINE  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					break;
            

            case 2:
				
                    printf("Cari kata: ");
                    scanf("%s", cari);
                    
                    printf("Peluang kata yang muncul, %d/%d kata dalam kalimat\n\n", hitung(cari, daftarKata, arrSize),arrSize);
                    break;
                    
            case 3:
           	{	
			 printf (" Nama Kata\t|Jumlah Kata\t|\n");
          		 if ((pf=fopen("history.txt","r"))== NULL)
        	{
      			printf("file tak dapat dibuka !\r\n");
       			exit(1);
    		}
			while((kar=fgetc(pf)) !=EOF)
            putchar(kar);
            printf("\n");
            fclose(pf);
            	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    DESAIN BY    <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
				printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   ELSA       DIANA       VALENTINE  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        }
            	printf("Kembali ke menu [y/t] ? ");
  		again=getch();
        break;
            case 4:
                    break;
            default: printf("Inputan salah!\n");
        }
    } while(opsi != 4);

    return 0;
	}
