#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(int* xp, int* yp)    //function swap(menukar)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

struct mobil						//declare struct
{
	char namaMobil[1000];
	int platMobil;
	int tanggalMobil;
	int hargaMobil;	
};

struct motor
{
	char namaMotor[1000];
	int platMotor;
	int tanggalMotor;
	int hargaMotor;	
};

void pilihan()					//print pilihan
{
	printf("1. parkir baru\n");
    printf("2. daftar plat terdaftar\n");
    printf("3. check apakah terdaftar\n");
    printf("4. exit program\n");
    printf("Silahkan masukkan angka: ");
	
}

void terpilihSatu()				//print pilhan untuk case 1
{
	printf("\n1. Mobil\n");
	printf("2. Motor\n");
}


int main()
{
   	
	int first, last, middle;		//declare
	int inputPilihan;
	int jenisK;
	int totalMobil, totalMotor;
	int count = 0;
	int resultMobil, resultMotor;
	int cariMobil, cariMotor;
	int indexMobil = 0, indexMotor = 0;
    int hitungMobil = 0, hitungMotor = 0;
    
    
    char bufferMobil[10000];
    FILE *file;
    
	for(int i = 0; i < 1000; i++)		//for loop
	{
		char tempMobil;
		char tempMotor;

		printf("\n\n***********Welcome to PROJECT AKHIR parking stand**********\n");
	    pilihan();
	    scanf("%d", &inputPilihan);
	    int caseSatu;
	    struct mobil mbl[1000];			//declare array of struct
	    struct motor mtr[1000];

	    switch(inputPilihan)			//switch case
	    {
	    	case 1:
				terpilihSatu();
				printf("Silahkan masukkan jenis kendaraan anda:");
				scanf("%d", &caseSatu);
				switch (caseSatu)			//nested switch
				{
					case 1:
						
						printf("\nNama: ");					//input semua ke array of struct 
						scanf("%s", mbl[indexMobil].namaMobil);
						printf("Plat: ");
						scanf("%d", &mbl[indexMobil].platMobil);
						printf("Tanggal: ");
						scanf("%d", &mbl[indexMobil].tanggalMobil);
						printf("Harga: ");
						scanf("%d", &mbl[indexMobil].hargaMobil);
						
						file = fopen("file.txt", "a");
						
						fputs("Mobil: ", file);
						fputs(mbl[indexMobil].namaMobil, file);
						fputs("\n", file);
						
						
						fclose(file);
						
						
						
						printf("Silahkan tekan apa saja untuk mencetak karcis");
						getchar();
						scanf("%c", &tempMobil );
						if(tempMobil != '\0')			
						{
							hitungMobil++;					//untuk menentukan jumlah mobil yang diinput
						}
						printf("\nIni karcis parkirnya!");	//display karcis
						printf("\n***************************************");
						printf("\nNama: %s\n",mbl[indexMobil].namaMobil);
						printf("Plat: %d\n", mbl[indexMobil].platMobil);
						printf("Tanggal: %d\n", mbl[indexMobil].tanggalMobil);
						printf("Tipe kendaraan: Mobil\n");
						printf("Harga: %d\n", mbl[indexMobil].hargaMobil);
						printf("***************************************\n");
						indexMobil++;
						break;
					case 2:
						printf("\nNama: ");
						scanf("%s", mtr[indexMotor].namaMotor);
						printf("Plat: ");
						scanf("%d", &mtr[indexMotor].platMotor);
						printf("Tanggal: ");
						scanf("%d", &mtr[indexMotor].tanggalMotor);
						printf("Harga: ");
						scanf("%d", &mtr[indexMotor].hargaMotor);
						
						
						file = fopen("file.txt", "a");
						
						fputs("Motor: ", file);
						fputs(mtr[indexMotor].namaMotor, file);
						fputs("\n", file);
						
						
						fclose(file);
						
						
						printf("Silahkan tekan apa saja untuk mencetak karcis");
						getchar();
						scanf("%c", &tempMotor );
						if(tempMotor != '\0')
						{
							hitungMotor++;
						}
						printf("\nIni karcis parkirnya!");
						printf("\n***************************************");
						printf("\nNama: %s\n",mtr[indexMotor].namaMotor);
						printf("Plat: %d\n", mtr[indexMotor].platMotor);
						printf("Tanggal: %d\n", mtr[indexMotor].tanggalMotor);
						printf("Tipe kendaraan: Motor\n");
						printf("Harga: %d\n", mtr[indexMotor].hargaMotor);
						printf("***************************************\n");
						indexMotor++;
						break;
					
						default:
						printf("default\n");
						break;
				}
				break;
						
			case 2:
				printf("Plat terdaftar\n");
				//sort mobil
                for (int i = 0; i < hitungMobil - 1; i++)
                {
                    for (int j = 0; j < hitungMobil - i - 1; j++)
                    {
                         if (mbl[j].platMobil > mbl[j+1].platMobil)
                         {
                             swap(&mbl[j].platMobil, &mbl[j+1].platMobil);
                         }
                            
                    } 
                }
				
				//display jika ada mobil
				if(hitungMobil != 0)
				{
					
					printf("Plat MOBIL\n");
	                for (int i = 0; i < hitungMobil; i++)
	                {
	                    printf("%d ", mbl[i].platMobil);
	                    printf("\n");
	                }
	
				}
				
				//sort motor
					for (int i = 0; i < hitungMotor - 1; i++)
	                {
	                    for (int j = 0; j < hitungMotor - i - 1; j++)
	                    {
	                         if (mtr[j].platMotor > mtr[j+1].platMotor)
	                         {
	                             swap(&mtr[j].platMotor, &mtr[j+1].platMotor);
	                         }
	                            
	                    } 
	                }
				
				//display jika ada motor
	            if (hitungMotor != 0)   
	            {
	            	printf("Plat MOTOR\n");
	                for (int i = 0; i < hitungMotor; i++)
	                {
	                    printf("%d ", mtr[i].platMotor);
	                    printf("\n");
	                }
	                
				}

				break;
				
	    	case 3:
	    	   
	    	    //SEARCHING
	    	    printf("Pilih jenis kendaraan yang mau dicari\n");
	    	    terpilihSatu();
	    	    printf("\nSilahkan masukkan nomor: ");
	    	    scanf("%d", &jenisK);
	    	    switch(jenisK)		//menentukan apa yang mau dicari
	    	    {
	    	        case 1:
        	    	        for (int i = 0; i < hitungMobil - 1; i++)	//bubble sorting
                        {
                            for (int j = 0; j < hitungMobil - i - 1; j++)
                            {
                                 if (mbl[j].platMobil > mbl[j+1].platMobil)
                                 {
                                     swap(&mbl[j].platMobil, &mbl[j+1].platMobil);
                                 }
                                    
                            } 
                        }
                        for(int i = 0; i <hitungMobil; i++)
                        {
                            printf("\n%d\n", mbl[i].platMobil);
                        }
                        
                        
	    	            printf("Silahkan masukkan plat yang mau dicari: ");
	    	            scanf("%d", &cariMobil);  //input yang mau di cari
	    	           
					    first = 0;					//untuk membentuk partisi
                        last = hitungMobil - 1;
                         middle = (first+last)/2;

                         while (first <= last) {
                         if (mbl[middle].platMobil < cariMobil)
                                  first = middle + 1;
                         else if (mbl[middle].platMobil == cariMobil) {
                         printf("%d kendaraan ditemukan di %d.\n", cariMobil, middle+1);
                                 break;
                                }
                                    else
                         last = middle - 1;

                             middle = (first + last)/2;
                            }
                            if (first > last)
                                  printf("Kendaraan dengan plat %d tidak ditemukan.\n", cariMobil);

                        break;
                    case 2:
                         for (int i = 0; i < hitungMotor - 1; i++)
                        {
                            for (int j = 0; j < hitungMotor - i - 1; j++)
                            {
                                 if (mtr[j].platMotor > mtr[j+1].platMotor)
                                 {
                                     swap(&mtr[j].platMotor, &mtr[j+1].platMotor);
                                 }
                                    
                            } 
                        }
                        for(int i = 0; i <hitungMotor; i++)
                        {
                            printf("\n%d\n", mtr[i].platMotor);
                        }
	    	            printf("Silahkan masukkan plat yang mau dicari: ");
	    	            scanf("%d", &cariMotor);
	    	            first = 0;
                        last = hitungMotor - 1;
                         middle = (first+last)/2;

                         while (first <= last) {
                         if (mtr[middle].platMotor < cariMotor)
                                  first = middle + 1;
                         else if (mtr[middle].platMotor == cariMotor) {
                         printf("%d kendaraan ditemukan\n", cariMotor);
                                 break;
                                }
                                    else
                         last = middle - 1;

                             middle = (first + last)/2;
                            }
                            if (first > last)
                                  printf("Kendaraan dengan plat %d tidak ditemukan.\n", cariMotor);
                
                        break;
                    
                
                        break;        
                        
	    	    }
	    	        break;
	    	     	case 4: 
	    	        exit(1);
	  				break;
		}
	}	
    return 0;
}