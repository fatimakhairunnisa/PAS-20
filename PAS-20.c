#include<stdio.h>
#include<stdlib.h>

/* 
	PAS - FoodGo!
	Fatima khairunnisa – 2106651515
	Muhammad Fajri Alqomaril – 2106651635 */

void read();
void ubah();
void tambah();
void hapus();
void pesanan ();
void readPass(char *temp); //untuk menyamarkan password menjadi ****

struct //menyimpan variabel dengan tipe data yang berbeda
{
    char pkt [100], makan[100], minum[50]; //deklarasi nama menggunakan array
    int harga, jum;
} d,p; //per struct

struct
{
    char user[100], pass [100], meja[10], antre [10]; //deklarasi uname pass menggunakan array
} aptkl, aptkr, plgr;

struct
{
    char nama[50],alamat[50];
    int antri, n, hp;
}psn;

struct{
	char dicari[50];
}cr;


 //File pointer yang akan menunjukkan alamat dari file tsb
FILE*mmenu1;
FILE*mmenu;
FILE*regis;

int main ()
{
	int pil;
    system("cls"); //membersihkan layar
    printf ("\n\n\n\n\n\n\n\n\n\t\t\t\t******SELAMAT DATANG DI RESTORAN KAMEE******\n\n");
    printf ("\t\t\t\t||                      \t||\n");
    printf ("\t\t\t\t|| 1. ADMIN \t\t\t||\n");
    printf ("\t\t\t\t|| 2. PELANGGAN \t\t||\n");
    printf ("\t\t\t\t|| 3. EXIT \t\t\t||\n");
    printf ("\n\t\t\t\t Silakan Masukkan Pilihan (1/2/3) : ");
    scanf("%d",&pil); 
    getchar(); //membaca data dalam tipe data char
    switch(pil) //percabangan yg membaca hasil dari inputan "pil" yang akan disesuaikan di case
    {
    	
    case 1 :
    {
    	int i;
    	char admin[10],pasadmin[10];
    	do{
    		system("cls");
        	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tSELAMAT DATANG ADMIN\n");
        	printf("\t\t\t\t\t   Silahkan Login\n\n");
        	printf ("\t\t\tUsername : "); 
        	gets(admin); //input uname
        	printf ("\t\t\tPassword : ");
        	readPass(pasadmin); //input pass tak terlihat
        	if (strcmp(admin,"admin")==0 &&strcmp(pasadmin,"admin")==0) //membandingkan dua buah string
        	{
        		system ("cls");
        		printf("\n\n\n\n\n\n\n\n\n\t\t\t=================================================================\n"); 
				printf("\t\t\t\t                     LOGIN BERHASIL\n"); 
			    printf("\t\t\t\t                  SELAMAT DATANG ADMIN\n");  
			    printf("\t\t\t=================================================================\n"); 
			    Sleep(2500); 
				system("cls");
            	menu (); //memanggil menu
        	}
        	else{
        		system("cls");
			    printf("\n\n\n\n\n\n\n\n\n\t\t\t=================================================================\n");  
			    printf("\t\t\t\t                     PASSWORD SALAH\n");  
			    printf("\t\t\t=================================================================\n");  
			    i++;  
			    Sleep(2000);  
			    system("cls");
			}
		}
		while(i<3);  
		if(i>=3)  
		{
		   printf("\n\n\n\n\n\n\n\n\n\t\t\t=================================================================\n");  
	       printf("\t\t\t\t                      Akses Ditolak\n");  
	       printf("\t\t\t=================================================================\n"); 
	       Sleep(2000); 
	       system("cls");
	       main();
		}  
		printf("\n\n");  
		system("pause");  
		return 0;
    }

    case 2 :
    {
        system("cls");
        char cari[100];
        regis = fopen("regis.txt","w"); //w = file baru akan dibuat
        printf("\t\t\t\tSilahkan Mendaftar Untuk Menjadi Pelanggan RESTORAN KAMEE\n\n");
        printf("\t\t\tMasukkan Nama Reservasi : ");
        gets(plgr.user);
        printf("\t\t\tMasukkan Nomor Meja 	  : ");
        gets(plgr.meja);
        printf("\t\t\tMasukkan Nomor Antre 	  : ");
        gets(plgr.antre);
        fwrite(&plgr, sizeof (plgr), 1, regis);
        printf("\n\n");
        printf("\t\t\tTampilkan Menu:\n");
        read();
        printf("\t\t\tPaket Makanan Yang Dicari : ");
        gets(cari);
        mmenu=fopen("mmenu.dat","rb"); //menyatakan mode biner dan hanya dibaca
        while(fread(&d,sizeof(d),1,mmenu)==1)
        {
            if(strcmp(cr.dicari,d.pkt)==0) //jika paket yang dicari ada di file mmenu.dat
            {
            	int total,m;
            	printf("\t\t\tNama PAKET Makanan: %s\n", d.pkt);
                printf("\t\t\tNama Makanan: %s", d.makan);
                printf("\t\t\tNama Minuman: %s", d.minum);
                printf("\t\t\tHarga Paket\t\t: %d", d.harga);
                printf("\t\t\tjumlah\t\t: "); scanf("%d",&m);
                total=d.harga*m;
                printf("\t\t\tHarga Total : %d ",total);
                
                break;
            }
            else //jika makanan yang dicari tidak ada
            {
            	char y;
                printf("\t\t\tPaket Makanan yang dicari tidak dapat ditemukan pada daftar\n");
                printf("\t\t\tingin pesan Paket Makanan ? (jika iya tekan 'y') : ");
                scanf("%s",&y);
                if(y=='y')
                {
                   pesanan(); //memanggil pesanan();
                }
                fclose(pesanan);
            }
             break ;
        }
        fclose(mmenu);
        fclose(regis);
        
        system ("pause");
        main();
        return 0;
    }

    case 3 : //keluar dari program
    {
    	system("cls");
        printf("\n\n\n\n\n\n\n\n\n\t\t\tTerima Kasih Telah Mengunjungi Restoran Kamee \n\n");
        printf("\t\t\t\t  Sampai Jumpa Kembali!");
        printf("\n\n");
        printf("\t\t\t\tTekan Enter Untuk Keluar\n\n\n\n\n\n");

    }
    }
}


void menu ()
{
	int pil;
    system("cls");
    printf("\n");
    printf("\t\t\t\tSilahkan pilih menu dibawah ini\n\n");
    printf("\t\t\t1. Tambah Menu\n");
    printf("\t\t\t2. List Menu\n");
    printf("\t\t\t3. Hapus Menu\n");
    printf("\t\t\t4. Ubah Menu\n");
    printf("\t\t\t5. Data Pelanggan\n");
    printf("\t\t\t6. Kembali\n\n\n");
    printf ("Silahkan Masukkan Pilihan (1/2/3/4/5/6/7) : ");
    scanf("%d",&pil);
    getchar();
    switch(pil)
    {
    case 1 :
    {
    	char y;
        system ("cls");
        tambah();
        printf("\n\nKembali Ke Menu Tekan y : ");
        scanf("%s",&y);
        if (y=='y')
        {
            menu() ;
        }
        break;
    }
    case 2 :
    {
    	char y;
    	system("cls");
        read();
        printf("\n\nKembali Ke Menu Tekan y : ");
        scanf("%s",&y);
        if (y=='y')
        {
             menu () ;
        }
        break;
    }
    
    case 3:
    {
    	char y;
    	system("cls");
    	read();
        hapus ();
        printf("\n\nKembali Ke Menu Tekan y : ");
        scanf("%s",&y);
        if (y=='y')
        {
            menu();
        }
        break;
    }
    
    case 4 :
    {
    	char y ;
       	system("cls");
       	read();
        ubah();
        printf("\n\nKembali Ke Menu Tekan y : ");
        scanf("%s",&y);
        if (y=='y')
        {
            menu();
        }
        break;
    }
    
    case 5 :
        {
            FILE*pesanan;
            regis = fopen("regis.txt","r"); //hanya membaca file regis
            pesanan = fopen("pesan.dat", "rb"); //membaca file pesan.dat dalam mode biner
            while(fread(&plgr,sizeof(plgr),1,regis)==1) //menyatakan data sebanyak 1x ukuran variabel struct plgr
            {
                printf("\n\t\t\tNama     : %s\n",plgr.user);
                printf("\t\t\tNomor Meja : %s\n",plgr.meja);
                printf("\t\t\tNomor Antre : %s\n",plgr.antre);
            }
            getchar();
            while(fread(&psn,sizeof(psn),1,pesanan)==1)	//bernilai salah
            {
                printf("\t\t\tNama Pemesan : %s\n",psn.nama);
                printf("\t\t\tAlamat       : %s\n",psn.alamat);
                printf("\t\t\tNomor Antre  : %d\n",psn.antri);
                printf("\t\t\tBanyak Paket : %d\n",psn.n);
            }
            while(fread(&p,sizeof(p),1,pesanan)==1)
            {
            	printf("\t\t\tNama Paket   : %s\n",p.pkt);
                printf("\t\t\tNama Makanan : %s\n",p.makan);
                printf("\t\t\tNama Minuman : %s\n",p.minum);
                printf("\t\t\tJumlah       : %s\n",p.jum);
            }
            fclose(regis);
            fclose(pesanan);
            system("pause");
        }
    case 6 :
        {
            printf("Press Any Key To Back \n");
            main ();
        }

    }

    }


void read()
{
    mmenu=fopen("mmenu.dat", "rb");
    printf("\t\t\t\t\t\tMENU RESTORAN KAMEE\n\n");
    while(fread(&d,sizeof(d),1,mmenu)==1)
    {
    	printf("\t\t\tNama Paket  : %s\n",d.pkt);
        printf("\t\t\tNama Makanan  : %s\n",d.makan);
        printf("\t\t\tNama Minuman  : %s\n",d.minum);
        printf("\t\t\tHarga Paket : %d\n",d.harga);
        printf("\t\t\tStok Paket  : %d\n\n",d.jum);
    }
    fclose(mmenu);
}

void tambah()
{
	int i,n;
    mmenu = fopen("mmenu.dat", "ab");
    printf("\n\n\t\t\t\tSilahkan Masukkan Banyak Paket Tambahan : ");
    scanf("%d", &n);
    getchar();
    for (i=1; i<=n; i++)
    {
    	printf("\n\t\t\tNama Paket\t\t: ");
        //scanf("%s", &d.pkt);
    	gets(d.pkt);
    	
        printf("\t\t\tNama Makanan\t\t: ");
        //scanf("%s", &d.makan);
        gets(d.makan);
        
        printf("\t\t\tNama Minuman\t\t: ");
        //scanf("%s", &d.minum);
        gets(d.minum);

        printf("\t\t\tHarga Paket\t\t: ");
        scanf("%d", &d.harga);
        
        printf("\t\t\tJumlah Stok\t\t: ");
        scanf("%d",&d.jum);
        
        getchar();
        fwrite(&d, sizeof (d), 1, mmenu);
    }

    fclose(mmenu);

}

void hapus ()
{
    mmenu = fopen("mmenu.dat", "rb");
    mmenu1 = fopen("mmenu1.dat", "wb");
    printf("\t\t\t\tSilahkan Masukkan Nama Paket Yang Akan Dihapus: ");
    gets(cr.dicari);
    while (fread(&d,sizeof (d),1, mmenu)==1)
    {
        if (strcmp(d.pkt, cr.dicari)!=0)
        {
            fwrite(&d, sizeof(d), 1, mmenu1);
        }
    }
    fclose(mmenu);
    fclose(mmenu1);
    remove("mmenu.dat");
    rename("mmenu1.dat","mmenu.dat");
}

void ubah ()
{
    FILE *mmenu;
    char cari[100];
    mmenu=fopen("mmenu.dat","rb+");
    printf("Masukkan Nama Paket Makanan Yang Ingin Diedit : ");
    gets(cari);
    while (fread(&d,sizeof (d),1, mmenu)==1)
    {
        if(strcmp(cari,d.pkt)==0)
        {
            printf("\n\t\t\t\tData Lama\n");
            printf("\t\t\tNama Paket \t: %s \n",d.pkt);
            printf("\t\t\tNama Makanan\t: %s \n",d.makan);
            printf("\t\t\tNama Minuman\t: %s \n",d.minum);
            printf("\t\t\tJumlah Stok\t: %d \n ",d.jum);
            printf("\t\t\tHarga Paket\t: %d \n",d.harga);
            fseek(mmenu,-sizeof(d),SEEK_CUR); //menunjukkan posisi pointer
            printf("\n\t\t\t\tData Baru\n");
            printf("\t\t\tNama Paket\t: "); gets(d.pkt);
            printf("\t\t\tNama Makanan\t: "); gets(d.makan);
            printf("\t\t\tNama Minuman\t: "); gets(d.minum);
            printf("\t\t\tJumlah Stok\t: "); scanf("%d",&d.jum);
            printf("\t\t\tHarga Paket\t\t: "); scanf("%d", &d.harga);
            fwrite(&d, sizeof (d), 1, mmenu);
            break;
        }
    }
    fclose(mmenu);
}

void pesanan ()
{
	int i,n;
    FILE*pesanan;
    system ("cls");
    pesanan = fopen("pesan.dat", "wb");
    printf("\t\t\t\t\tFORM DELIVERY\n");
    printf("\t\t\tNama Pemesan : ");fflush(stdin); gets(psn.nama);  //mengosongkan buffer 
    printf("\t\t\tAlamat       : ");fflush(stdin); gets(psn.alamat);
    printf("\t\t\tNomor Antrean: ");fflush(stdin); scanf("%d",&psn.antri);
	printf("\t\t\tNo HP.       : ");fflush(stdin); scanf("%d",&psn.hp);    
    printf("\n\t\t\tSilahkan masukkan banyaknya pesanan : ");
    scanf("%d", &psn.n);
    fwrite(&psn, sizeof (psn), 1, pesanan);
    getchar();
    for (i=1; i<=psn.n; i++)
    {
        printf("\t\t\tNama Paket  : ");
        gets(p.pkt);	
        printf("\t\t\tNama Makanan  : ");
        gets(p.makan);
        printf("\t\t\tNama Minuman  : ");
        gets(p.minum);
        printf("\t\t\tJumlah     : ");
        scanf("%d",&p.jum);
        getchar();
        fwrite(&p, sizeof (p), 1, pesanan);
    }
    printf("\t\t\tTerima kasih!! Pesanan anda segera di proses.\n");
    printf("\t\t\tSilahkan tunggu konfirmasi selanjutnya melalui SMS\n");
    fclose(pesanan);
    system("pause");
    main();
    
}

void readPass(char *temp) {
    int key = 0, index = 0;
    do {
        key = getch(); /* Simpan karakter yang ditekan ke dalam variabel key */
        switch (key) {
        		/* 0 adalah kode awal untuk tombol fungsi (function key), seperti F1, F2, ..., F12 
                 * Misalkan jika tombol F1 ditekan, maka fungsi getch akan mengembalikan
                 * nilai 0 dan menyimpan sebuah kode yang menandakan tombol F1 ditekan ke buffer.
                 */
            case 0:
            	//* 224 adalah kode awal untuk tombol panah, home, page up, page down, end dan lain-lain. 
                 //*Misalkan jika tombol panah ditekan, fungsi getch akan 
                 //* mengembalikan nilai 224 dan menyimpan sebuah kode
                 //* yang menandakan tombol yang ditekan ke buffer.
            case 224:
            	/* Fungsi getch di sini digunakan untuk membersihkan buffer */
                getch();
                break;
                /* Jika tombol back space ditekan, maka mundurkan cursor satu langkah */
            case '\b':
                if (index > 0) {
                    index = index - 1; /* Kurangi index temp sebesar 1 */
                    temp[index] = 0; /* set temp[index] menjadi kosong (NUL) */
                    printf("\b \b"); /* Mundurkan cursor satu langkah */
            }
                break;
            default:
                if (key > 31 && key < 127) { /* Hanya karakter printable yang dapat ditekan, seperti huruf, angka dan karakter spesial */
                    temp[index] = key; 
                    index = index + 1; /* Simpan karakter ke dalam temp[index] */
                    printf("*");
                }
         //* 13 adalah kode ASCII untuk karakter enter.
         //Perulangan akan terus dilakukan sampai tombol enter ditekan.
        }
    } while (key != 13);  
    temp[index] = '\0';
}

