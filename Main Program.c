#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main();
void menu();
void a();
void pblil();
void pbliu();
void pdgl();
void pdgu();
void r();
void rpdg();
void rpbli();
void info();
void amenu();
void apdg();
void wapdg();
void eapdg();
void apbli();
void wapbli();
void eapbli();
void konf();
void konfpb();
void konfpd();
void inputwarga();
void twarga();
void prior();
void pdglm();
void lihatdagang();
void stok_sapi();
void stok_kambing();
void beli_sapi();
void beli_kambing();
void pdglm();
void kbli();
void kblik();
void pblilm();



char input_hewan[50];
char npb[100],npg[100],pilpb,pilbs;
char pilw,pil;
char au[100],ap[100];
char caripg[50],caripb[50],cariw[50],caris[50],carilpd[50],caribs[50],caribs2[50],carikpbl[50],carikpbl2[50],carikpbl3[50];
int x,xmenu,xapdg,xr,xapbli,xkonf;
int i,j,n,n_sapi,n_kambing;
int detect;

FILE *admin;
FILE *pedagang;
FILE *pedagang2;
FILE *pembeli;
FILE *pembeli2;
FILE *warga;
FILE *warga2;
FILE *wargap;
FILE *s;
FILE *s2;
FILE *sb;
FILE *sb2;
FILE *k;
FILE *k2;
FILE *kb;
FILE *kb2;

struct{
	char namaps[90],namabs[90],namasapi[90],berat[10],detil[90];
	int harga; // ini struct buat harga sapi
}sapi;
struct{
	char namapk[90],namabk[90],namakambing[90],berat[10],detil[90];
	int harga; // ini struct buat harga kambing
}kambing;
struct{
	char namaw[50],jakw[50];
	int pghslw; // struct input penghasilan warga
}wrg,sa[50],temp,wrgp;
struct{
	char us[100],pass[100];
}adm;
struct{
	char namapg[90],uspg[90],passpg[90];
	int statuspg;
}rpg;
struct{
	char namapg[90],uspg[90],passpg[90];
	int statuspg;
}lpg;
struct{
	char namapb[90],uspb[90],passpb[90],umurpb[90],pkjpb[90];
	int statuspb;
}rpb;
struct{
	char namapb[90],uspb[90],passpb[90];
	int statuspb;
}lpb;
void main()
{
	printf("*************************************************\n");
	printf("|\t\tQurban Application\t\t|\n");
	printf("*************************************************\n\n\nPress Enter To Continue...");
	getchar();
	menu();
}
void menu()
{
	system("cls");
	printf("*************************************************\n");
	printf("|\t\t\tMENU\t\t\t|\n");
	printf("*************************************************\n\n");
	printf("\n1.Admin\n2.Pembeli\n3.Pedagang\n4.Registrasi\n\n*Masukan Pilihan\t: ");scanf("%i",&x);getchar();
	switch(x)
	{
		case 1: a();break;
		case 2:pblil();break;
		case 3:pdgl();break;
		case 4:r();break;
		default : menu();break;
	}
}

void a()
{
	system("cls");
	printf("*************************************************\n");
	printf("|\t\t\tAdmin\t\t\t|\n");
	printf("*************************************************\n\n");
	printf("Username\t: "); gets(au);
	printf("Password\t: "); gets(ap);
	admin=fopen("admin.dat","rb");
	while(fread(&adm,sizeof(adm),1,admin)==1)
	{ 
		if(strcmp(au,adm.us)==0&&strcmp(ap,adm.pass)==0)
		{
			system("cls");
			printf("\n\n\n\t\t\t\t--!!!LOGIN SUKSES!!!--\nenter to continue...");
			getchar();
			amenu();
		}
		else{
			system("cls");
			printf("\n\n\n\t\t\t\t--!!!LOGIN GAGAL!!!--\nenter to continue...");
			getchar();
			menu();
		}
	}
	
}
	void amenu()
{
	system("cls");
	printf("*************************************************\n");
	printf("|\t\tWelcome Admin\t\t\t|\n");
	printf("*************************************************\n\n");
	printf("\n1.Pedagang\n2.Pembeli\n3.Konfirmasi\n4.Input Warga Penerima Qurban\n5.Tampilkan Urutan Prioritas Warga\n6.Warga yang akan diprioritaskan Manual\n7.Menu Utama\n\n*Masukan Pilihan\t: ");scanf("%i",&xmenu);getchar();
	switch(xmenu)
	{
		case 1: apdg();break;
		case 2: apbli();break;
		case 3: konf();break;
		case 4: inputwarga();break;
		case 5: twarga();break;
		case 6: prior();break;
		case 7: menu();break;
		default : amenu();break;
	}
}

void inputwarga()
{
	system ("cls");
	warga=fopen("warga.dat","ab");
	printf("\n\n\t\t-------Input Warga-------\n");
	printf("Nama Kepala Keluarga\t: ");gets(wrg.namaw);
	printf("Jumlah Anggota Keluarga\t: ");gets(wrg.jakw);
	printf("Penghasilan Kepala Keluarga\t: ");scanf("%i",&wrg.pghslw);getchar();
	fwrite(&wrg,sizeof(wrg),1,warga);
	fclose(warga);
	
	printf("\nApakah Input Sudah Selesai?(y/n)");scanf("%s",&pilw);
	getchar();
	if( pilw=='y'||pilw=='Y')
	{
		printf("enter to continue...");
		getchar();
		amenu();
	}
	else if( pilw=='n'||pilw=='N')
	{
		printf("enter to continue...");
		getchar();
		inputwarga();
	}
}
	
void twarga()
{
	system ("cls");

		wargap=fopen("prioritas.dat","rb");
	i=1;
	n=0; 
	while(fread(&wrg,sizeof(wrg),1,wargap)==1)
	{
		printf("\n* Nama\t\t: %s",wrg.namaw);
		printf("\n  Penghasilan\t: %i",wrg.pghslw);
	}
fclose(wargap);
warga=fopen("warga.dat","rb");
	while(fread(&wrg,sizeof(wrg),1,warga)==1)
	{

		sa[i]=wrg;
		i++;
	}
	n=i-1;
	//proses bubble sort
	for (i=n;i>=1;i--) 
	{
		for (j=1;j<=i;j++)  
		{ 
			if (sa[j-1].pghslw>sa[j].pghslw) 
			{ 
				temp=sa[j-1]; 
				sa[j-1]=sa[j]; 
				sa[j]=temp; 
			}
		}
	}	
	//menampilkan hasil sorting
	 for(i=1;i<=n;i++)
	 {
	 	printf("\n%i Nama\t\t: %s",i,sa[i].namaw);
		printf("\n  Penghasilan\t: %i",sa[i].pghslw);
	 }
	fclose(warga);
	
	printf("\nPress Any Key to Continue...");
	getchar();
	amenu();
	
}
void prior()
{
	system ("cls");
	
	warga2 = fopen("warga2.dat", "wb");
	wargap = fopen("prioritas.dat","ab");
	printf("\nMasukkan nama yang akan prioritaskan\t: "); gets(cariw);
	warga = fopen("warga.dat", "rb");
	while (fread(&wrg,sizeof (wrg),1,warga)==1)
	{

		if (strcmp(wrg.namaw, cariw)==0)
		{
			fwrite(&wrg, sizeof(wrg),1, wargap);
		}

		if (strcmp(wrg.namaw, cariw)!=0)
		{
			fwrite(&wrg, sizeof(wrg),1, warga2);
		}
	}

	
	fclose(warga);
	fclose(warga2);
	fclose(wargap);
	remove("warga.dat");
	rename("warga2.dat","warga.dat");
	system ("cls");

		wargap=fopen("prioritas.dat","rb");
	i=1;
	n=0; 
	while(fread(&wrg,sizeof(wrg),1,wargap)==1)
	{
		printf("\n. Nama\t\t: %s",wrg.namaw);
		printf("\n  Penghasilan\t: %i",wrg.pghslw);
	}
fclose(wargap);
warga=fopen("warga.dat","rb");
	while(fread(&wrg,sizeof(wrg),1,warga)==1)
	{

		sa[i]=wrg;
		i++;
	}
	n=i-1;
	for (i=n;i>=1;i--) 
	{
		for (j=1;j<=i;j++)  
		{ 
			if (sa[j-1].pghslw>sa[j].pghslw) 
			{ 
				temp=sa[j-1]; 
				sa[j-1]=sa[j]; 
				sa[j]=temp; 
			}
		}
	}	
	 for(i=1;i<=n;i++)
	 {
	 	printf("\n  Nama\t\t: %s",sa[i].namaw);
		printf("\n  Penghasilan\t: %i",sa[i].pghslw);
	 }
	fclose(warga);
	
	printf("\nPress Any Key to Continue...");
	getchar();
	amenu();
	
}
void apdg()
{
	system("cls");
	printf("\n1.Daftar Pedagang\n2.Hapus Data Pedagang\n3.Menu Admin\n\n*Masukan Pilihan\t: ");scanf("%i",&xapdg);getchar();
	switch(xapdg)
	{
		case 1: wapdg();break;
		case 2: eapdg();break;
		case 3: amenu();break;
		default : apdg();break;
	}
}
void apbli()
{
	system("cls");
	printf("\n1.Daftar Pembeli\n2.Hapus Data Pembeli\n3.Menu Admin\n\n*Masukan Pilihan\t: ");scanf("%i",&xapbli);getchar();
	switch(xapbli)
	{
		case 1: wapbli();break;
		case 2: eapbli();break;
		case 3: amenu();break;
		default : apbli();break;
	}
}
void wapdg(){
	system("cls");
	printf("*************************************************\n");
	printf("|\t\tDaftar Pedagang\t\t\t|\n");
	printf("*************************************************\n\n");
	pedagang=fopen("pedagang.dat","rb");
	i=1;
	while(fread(&rpg,sizeof(rpg),1,pedagang)==1)
	{
		printf("\n%i.Nama\t\t: %s",i,rpg.namapg);
		printf("\n  Username\t: %s",rpg.uspg);
		printf("\n  Pasword\t: %s",rpg.passpg);
		printf("\n  Status\t: %d\n",rpg.statuspg);
		i++;
	}
	fclose(pedagang);
	printf("\nPress enter to continue..");
	getchar();
	apdg();

}
void wapbli()
{
	system("cls");
	printf("*************************************************\n");
	printf("|\t\tDaftar Pembeli\t\t\t|\n");
	printf("*************************************************\n\n");
	pembeli=fopen("pembeli.dat","rb");
	i=1;
	while(fread(&rpb,sizeof(rpb),1,pembeli)==1)
	{
		printf("\n%i.Nama\t\t: %s",i,rpb.namapb);
		printf("\n  Username\t: %s",rpb.uspb);
		printf("\n  Pasword\t: %s",rpb.passpb);	
		printf("\n  Umur\t\t: %s",rpb.umurpb);
		printf("\n  Pekerjaan\t: %s",rpb.pkjpb);
		printf("\n  Status\t: %d\n",rpb.statuspb);
		i++;
	}
	fclose(pembeli);
	printf("\nPress enter to continue..");
	getchar();
	apbli();
}
void eapdg(){
	system("cls");
	pedagang=fopen("pedagang.dat","rb");
	i=1;
	while(fread(&rpg,sizeof(rpg),1,pedagang)==1)
	{
		printf("\n%i.Nama\t\t: %s",i,rpg.namapg);
		printf("\n  Username\t: %s",rpg.uspg);
		printf("\n  Pasword\t: %s",rpg.passpg);
		printf("\n  Status\t: %d\n",rpg.statuspg);
		i++;
	}
	fclose(pedagang);
	pedagang = fopen("pedagang.dat", "rb");
	pedagang2 = fopen("pedagang2.dat", "wb");
	printf("\nMasukkan nama yang akan dihapus\t: "); gets(caripg);
	while (fread(&rpg,sizeof (rpg),1,pedagang)==1)
	{
		if (strcmp(rpg.namapg, caripg)!=0)
		{
			fwrite(&rpg, sizeof(rpg),1, pedagang2);
		}
		if (strcmp(rpg.namapg, caripg)==0)
		{
			printf("Data Telah Dihapus\n");
		}
	}
	fclose(pedagang);
	fclose(pedagang2);
	remove("pedagang.dat");
	rename("pedagang2.dat","pedagang.dat");
	system("cls");
	pedagang=fopen("pedagang.dat","rb");
	i=1;
	while(fread(&rpg,sizeof(rpg),1,pedagang)==1)
	{
		printf("\n%i.Nama\t\t: %s",i,rpg.namapg);
		printf("\n  Username\t: %s",rpg.uspg);
		printf("\n  Pasword\t: %s",rpg.passpg);
		printf("\n  Status\t: %d\n",rpg.statuspg);
		i++;
	}
	fclose(pedagang);
	printf("\nPress enter to continue..");
	getchar();
	apdg();
	
	printf("\nPress Enter to Continue...");
	getchar();
	apdg();
}
void eapbli(){
	system("cls");
	pembeli=fopen("pembeli.dat","rb");
	i=1;
	while(fread(&rpb,sizeof(rpb),1,pembeli)==1)
	{
		printf("\n%i.Nama\t\t: %s",i,rpb.namapb);
		printf("\n  Username\t: %s",rpb.uspb);
		printf("\n  Pasword\t: %s",rpb.passpb);	
		printf("\n  Umur\t\t: %s",rpb.umurpb);
		printf("\n  Pekerjaan\t: %s",rpb.pkjpb);
		printf("\n  Status\t: %d\n",rpb.statuspb);
		i++;
	}
	fclose(pembeli);
	
	pembeli = fopen("pembeli.dat", "rb");
	pembeli2 = fopen("pembeli2.dat", "wb");
	printf("\nMasukkan nama yang akan dihapus\t: "); gets(caripb);
	while (fread(&rpb,sizeof (rpb),1,pembeli)==1)
	{
		if (strcmp(rpb.namapb, caripb)!=0)
		{
			fwrite(&rpb, sizeof(rpb),1, pembeli2);
		}
	}
		if (strcmp(rpb.namapb, caripb)==0)
		{
			printf("Data Telah Dihapus\n");
		}
	fclose(pembeli);
	fclose(pembeli2);
	remove("pembeli.dat");
	rename("pembeli2.dat","pembeli.dat");
	system("cls");
	pembeli=fopen("pembeli.dat","rb");
	i=1;
	while(fread(&rpb,sizeof(rpb),1,pembeli)==1)
	{
		printf("\n%i.Nama\t\t: %s",i,rpb.namapb);
		printf("\n  Username\t: %s",rpb.uspb);
		printf("\n  Pasword\t: %s",rpb.passpb);	
		printf("\n  Umur\t\t: %s",rpb.umurpb);
		printf("\n  Pekerjaan\t: %s",rpb.pkjpb);
		printf("\n  Status\t: %d\n",rpb.statuspb);
		i++;
	}
	fclose(pembeli);
	printf("\nPress Enter to Continue...");
	getchar();
	apbli();
}
void konf()
{
	system("cls");
	printf("*************************************************\n");
	printf("|\t\tKonfirmasi Akun\t\t\t|\n");
	printf("*************************************************\n\n");
	printf("\n1.Konfirmasi Akun Pedagang\n2.Konfirmasi Akun Pembeli\n3.Menu Admin\n\n*Masukan Pilihan\t: ");scanf("%i",&xkonf);getchar();
	switch(xkonf)
	{
		case 1: konfpd();break;
		case 2: konfpb();break;
		case 3: amenu();break;
		default : konf();break;
	}
}
void konfpb()
{
	system("cls");
	
	pembeli=fopen("pembeli.dat","rb+");
	printf("\n\n------------Daftar Pembeli----------------");
	i=1;
	while(fread(&rpb,sizeof(rpb),1,pembeli)==1)
	{
		printf("\n%i.Nama\t\t: %s",i,rpb.namapb);
		printf("\n  Username\t: %s",rpb.uspb);
		printf("\n  Pasword\t: %s",rpb.passpb);	
		printf("\n  Umur\t\t: %s",rpb.umurpb);
		printf("\n  Pekerjaan\t: %s",rpb.pkjpb);
		printf("\n  Status\t: %d\n",rpb.statuspb);
		i++;
	}
	printf("\nMasukkan username yang akan dikonfirmasi\t: ");gets(npb);
	rewind(pembeli);
	while(fread(&rpb,sizeof(rpb),1,pembeli)==1)
	{
		system("cls");
		if(strcmp(npb,rpb.uspb)==0)
		{
			printf("\n  Nama\t\t: %s",rpb.namapb);
			printf("\n  Username\t: %s",rpb.uspb);
			printf("\n  Pasword\t: %s",rpb.passpb);	
			printf("\n  Umur\t\t: %s",rpb.umurpb);
			printf("\n  Pekerjaan\t: %s",rpb.pkjpb);
			printf("\n  Status\t: %d\n",rpb.statuspb);
			printf("\nApakah user %s ingin dikonfirmasi?(Y/N) ",npb);scanf("%s",&pilpb);
			if(pilpb=='y'||pilpb=='Y')
			{
				fseek(pembeli,-sizeof(rpb),SEEK_CUR);
				rpb.statuspb=1;
				fwrite(&rpb,sizeof(rpb),1,pembeli);
				printf("\nAkun telah dikonfirmasi.");
				getchar();
				getchar();
				fclose(pembeli);
				break;
			}		
		}
	}
	fclose(pembeli);
	getchar();
	konf();
}
void konfpd()
{
	system("cls");
	
	pedagang=fopen("pedagang.dat","rb+");
	printf("\n\n------------Daftar Pedagang----------------");
	i=1;
	while(fread(&rpg,sizeof(rpg),1,pedagang)==1)
	{
		printf("\n%i.Nama\t\t: %s",i,rpg.namapg);
		printf("\n  Username\t: %s",rpg.uspg);
		printf("\n  Pasword\t: %s",rpg.passpg);	
		printf("\n  Status\t: %d\n",rpg.statuspg);
		i++;
	}
	printf("\nMasukkan username yang akan dikonfirmasi\t: ");gets(npg);
	rewind(pedagang);
	while(fread(&rpg,sizeof(rpg),1,pedagang)==1)
	{
		system("cls");
		if(strcmp(npg,rpg.uspg)==0)
		{
			printf("\n  Nama\t\t: %s",rpg.namapg);
			printf("\n  Username\t: %s",rpg.uspg);
			printf("\n  Pasword\t: %s",rpg.passpg);	
			printf("\n  Status\t: %d\n",rpg.statuspg);
			printf("\nApakah user %s ingin dikonfirmasi?(Y/N) ",npb);scanf("%s",&pilpb);
			if(pilpb=='y'||pilpb=='Y')
			{
				fseek(pedagang,-sizeof(rpg),SEEK_CUR);
				rpg.statuspg=1;
				fwrite(&rpg,sizeof(rpg),1,pedagang);
				printf("\nAkun telah dikonfirmasi.");
				getchar();
				getchar();
				fclose(pedagang);
				break;
			}		
		}
	}
	fclose(pedagang);
	getchar();
	konf();
}

void r()
{
	system("cls");
	printf("*************************************************\n");
	printf("|\t\tRegistrasi\t\t\t|\n");
	printf("*************************************************\n\n");
	printf("\n1.Pedagang\n2.Pembeli\n3.Menu Utama\n\n*Masukan Pilihan\t: ");scanf("%i",&xr);getchar();
	switch(xr)
	{
		case 1: rpdg();break;
		case 2: rpbli();break;
		case 3: menu();break;
		default: r();
	}
	
}
void rpdg()
{
	system("cls");
	printf("\n\n---------------Registrasi Pedagang-----------------\n\n");
	pedagang=fopen("pedagang.dat","ab");
	printf("\nNama\t\t: ");gets(rpg.namapg);
	printf("Username\t: ");gets(rpg.uspg);
	printf("Password\t: ");gets(rpg.passpg);
	rpg.statuspg=0;
	fwrite(&rpg,sizeof(rpg),1,pedagang);
	fclose(pedagang);
	printf("\n\nRegistrasi sukses, silahkan tunggu konfirmasi admin");getchar();
	r();
}
void rpbli()
{
	system("cls");
	printf("\n\n---------------Registrasi Pembeli-----------------\n\n");
	pembeli=fopen("pembeli.dat","ab");
	printf("\nNama\t\t: ");gets(rpb.namapb);
	printf("Username\t: ");gets(rpb.uspb);
	printf("Password\t: ");gets(rpb.passpb);
	printf("Umur\t\t: ");gets(rpb.umurpb);
	printf("Pekerjaan\t: ");gets(rpb.pkjpb);
	rpb.statuspb=0;
	fwrite(&rpb,sizeof(rpb),1,pembeli);
	fclose(pembeli);
	printf("\n\nRegistrasi sukses, silahkan tunggu konfirmasi admin");getchar();
	r();
}

void pdgl()
{
	system("cls");
	pedagang=fopen("pedagang.dat","rb");
	printf("\n\n\t\t\t----LOGIN AKUN PEDAGANG----\n");
	detect=0;
	printf("Nama     : ");gets(lpg.namapg);
	printf("Username : "); gets(lpg.uspg);
	printf("Password : "); gets(lpg.passpg);
	while(fread(&rpg,sizeof(rpg),1,pedagang)==1)
	{
	if(strcmp(lpg.namapg,rpg.namapg)==0&&strcmp(lpg.uspg,rpg.uspg)==0&&strcmp(lpg.passpg,rpg.passpg)==0&&rpg.statuspg==1)
	{
		printf("\n\n\t\t\t--------Login Berhasil---------\nEnter to continue..");
		getchar();
		pdglm();
	}
	else {
	detect++;
	}
	}
	if(detect=100){
	printf("\n\tLogin Gagal, Silahkan Ulangi Kembali\n");
	getchar();
	menu();

	}
}
void pblil()
{
	system("cls");
	pembeli=fopen("pembeli.dat","rb");
	printf("\n\n\t\t\t----LOGIN AKUN PEMBELI----\n");
	detect=0;
	printf("Nama     : ");gets(lpb.namapb);
	printf("Username : "); gets(lpb.uspb);
	printf("Password : "); gets(lpb.passpb);
	while(fread(&rpb,sizeof(rpb),1,pembeli)==1)
	{
	if(strcmp(lpb.namapb,rpb.namapb)==0&&strcmp(lpb.uspb,rpb.uspb)==0&&strcmp(lpb.passpb,rpb.passpb)==0&&rpb.statuspb==1)
	{
		printf("\n\n\t\t\t--------Login Berhasil---------\nEnter to continue..");
		getchar();
		pblilm();
	}
	else {
	detect++;
	}
	}
	if(detect=100){
	printf("\n\tLogin Gagal, Silahkan Ulangi Kembali\n");
	getchar();
	menu();
}
}
void pblilm()
{
	system("cls");
	printf("*********************************************************\n");
	printf("|\t\tDaftar Menu Pembeli\t\t\t|\n");
	printf("*********************************************************\n\n");
	printf("\n1.Beli Sapi\n2.Beli Kambing\n3.Logout\n\n*Masukan Pilihan\t: ");scanf("%i",&x);getchar();
	switch(x)
	{
		case 1: beli_sapi();break;
		case 2: beli_kambing();break;
		case 3: menu();break;
		default : pblilm();break;
	}
}
	
	void pdglm()// ini deklrasi variabel pedagang sapi
{
	
	system("cls");
	printf("*********************************************************\n");
	printf("|\t\tDaftar Menu Pedagang\t\t\t|\n");
	printf("*********************************************************\n\n");
	printf("\n1.Masukkan Stok sapi\n2.Masukkan Stok Kambing\n3.Lihat Stok Dagangan\n4.Konfirmasi Pembelian Sapi\n5.Konfirmasi Pembelian Kambing\n6.Logout\n\n*Masukan Pilihan\t: ");scanf("%i",&x);getchar();
	switch(x)
	{
		case 1: stok_sapi();break;
		case 2:stok_kambing();break;
		case 3:lihatdagang();break;
		case 4:kbli();break;
		case 5:kblik();break;
		case 6:menu();break;
		default : pdglm();break;
	}
}
void stok_sapi()
{
	system("cls");
	s=fopen("sapi.dat","ab");
	strcpy(sapi.namaps,lpg.namapg);
	printf("\n\n\t\t\t----INPUT STOK SAPI----\n");
	printf("Nama Penjual: %s \n",sapi.namaps);
	printf("Nama Sapi : ");gets(sapi.namasapi);
	printf("Berat sapi(Kg): ");gets(sapi.berat);
	printf("Detil Sapi: ");gets(sapi.detil);
	printf("Harga sapi: ");scanf("%i",&sapi.harga);
	fwrite(&sapi,sizeof(sapi),1,s);
	fclose(s);
	printf("Lanjut?(y/n)");scanf("%s",&n_sapi);
	if(n_sapi=='y'|n_sapi=='Y')
	{
		getchar();
		stok_sapi();
	}
	else{
		getchar();
		pdglm();
	}
}
void stok_kambing()
{
	system("cls");
	k=fopen("kambing.dat","ab");
	strcpy(kambing.namapk,lpg.namapg);
	printf("\n\n\t\t\t----INPUT STOK KAMBING----\n");
	printf("Nama Penjual: %s \n",kambing.namapk);
	printf("Nama Kambing : ");gets(kambing.namakambing);
	printf("Berat Kambing(Kg): ");gets(kambing.berat);
	printf("Detil Kambing: ");gets(kambing.detil);
	printf("Harga Kambing: ");scanf("%i",&kambing.harga);
	fwrite(&kambing,sizeof(kambing),1,k);
	fclose(k);
	printf("Lanjut?(y/n)");scanf("%s",&n_kambing);
	if(n_sapi=='y'|n_sapi=='Y')
	{
		getchar();
		stok_kambing();
	}
	else if(n_sapi=='n'||n_sapi=='N')
	{
		getchar();
		pdglm();
	}
}
void lihatdagang(){
	system("cls");
	s=fopen("sapi.dat","rb");
	strcpy(carilpd,lpg.namapg);
	printf("\t\t\tDaftar Sapi\n");
	while(fread(&sapi,sizeof(sapi),1,s)==1)
	{
		if(strcmp(carilpd,sapi.namaps)==0)
	{
		printf("Nama Pedagang\t: %s\nNama Sapi\t: %s\nBerat Sapi\t: %s\nDetil Sapi\t:% s\nHarga Sapi\t: %i\n\n",sapi.namaps,sapi.namasapi,sapi.berat,sapi.detil,sapi.harga);
	}
	}
	fclose(s);
	k=fopen("kambing.dat","rb");
	strcpy(carilpd,lpg.namapg);
	printf("\t\t\tDaftar Kambing\n");
	while(fread(&kambing,sizeof(kambing),1,k)==1)
	{
		if(strcmp(carilpd,kambing.namapk)==0)
	{
		printf("Nama Pedagang\t: %s\nNama Kambing\t: %s\nBerat Kambing\t: %s\nDetil Kambing\t:% s\nHarga Kambing\t: %i\n\n",kambing.namapk,kambing.namakambing,kambing.berat,kambing.detil,kambing.harga);
	}
	}
	fclose(k);
	printf("\n\n\nenter to continue...");
	getchar();
	pdglm();
}
void kbli()
{
	system("cls");
	sb=fopen("belisapi.txt","rb");
	strcpy(carikpbl,lpg.namapg);
	while(fread(&sapi,sizeof(sapi),1,sb)==1)
	{
		if(strcmp(carikpbl,sapi.namaps)==0)
		{
		printf("Nama Pembeli\t: %s\nNama Pedagang\t: %s\nNama Sapi\t: %s\nBerat Sapi\t: %s\nDetil Sapi\t:% s\nHarga Sapi\t: %i\n\n",sapi.namabs,sapi.namaps,sapi.namasapi,sapi.berat,sapi.detil,sapi.harga);
		}
	}
	fclose(sb);
	s=fopen("sapi.dat","rb");
	s2=fopen("sapi2.dat","wb");
	sb=fopen("belisapi.txt","r");
	sb2=fopen("belisapi2.txt","w");
	printf("Pilih Pembeli yang akan dikonfirmasi:");gets(carikpbl2);
	printf("Pilih Sapi Yang akan dikonfirmasi :"); gets(carikpbl3);
	printf("\nYakin akan melakukan konfirmasi?(y/n)");scanf("%s",&pil);
	if(pil== 'y'||pil=='Y'){	
	while (fread(&sapi,sizeof (sapi),1,s)==1)
	{
		if (strcmp(sapi.namasapi, carikpbl3)!=0)
		{
			fwrite(&sapi, sizeof(sapi),1, s2);
		}
	}fclose(s);
	fclose(s2);
	remove("sapi.dat");
	rename("sapi2.dat","sapi.dat");
	getchar();
	while (fread(&sapi,sizeof (sapi),1,sb)==1)
	{
		if (strcmp(sapi.namasapi, carikpbl3)!=0)
		{
			fwrite(&sapi, sizeof(sapi),1, sb2);
		}
	}
	
	fclose(sb);
	fclose(sb2);
	remove("belisapi.txt");
	rename("belisapi2.txt","belisapi.txt");	
	printf("\nPembelian Telah dikonfirmasi");
	getchar();
}
	
	pdglm();
	
}
void kblik(){
	system("cls");
	kb=fopen("belikambing.txt","rb");
	strcpy(carikpbl,lpg.namapg);
	while(fread(&kambing,sizeof(kambing),1,kb)==1)
	{
		if(strcmp(carikpbl,kambing.namapk)==0)
		{
		printf("Nama Pembeli\t: %s\nNama Pedagang\t: %s\nNama Kambing\t: %s\nBerat Kambing\t: %s\nDetil Kambing\t:% s\nHarga Kambing\t: %i\n\n",kambing.namabk,kambing.namapk,kambing.namakambing,kambing.berat,kambing.detil,kambing.harga);
		}
	}
	fclose(kb);
	k=fopen("kambing.dat","rb");
	k2=fopen("kambing2.dat","wb");
	kb=fopen("belikambing.txt","rb");
	kb2=fopen("belikambing2.txt","wb");
	printf("Pilih Pembeli yang akan dikonfirmasi:");gets(carikpbl2);
	printf("Pilih Sapi Yang akan dikonfirmasi :"); gets(carikpbl3);
	printf("\nYakin akan melakukan konfirmasi?(y/n)");scanf("%s",&pil);
	if(pil== 'y'||pil=='Y'){	
	while (fread(&kambing,sizeof (kambing),1,k)==1)
	{
		if (strcmp(kambing.namakambing, carikpbl3)!=0)
		{
			fwrite(&kambing, sizeof(kambing),1, k2);
		}
	}fclose(k);
	fclose(k2);
	remove("kambing.dat");
	rename("kambing2.dat","kambing.dat");
	getchar();
	while (fread(&kambing,sizeof (kambing),1,kb)==1)
	{
		if (strcmp(kambing.namakambing, carikpbl3)!=0)
		{
			fwrite(&kambing, sizeof(kambing),1, kb2);
		}
	}
	
	fclose(kb);
	fclose(kb2);
	remove("belikambing.txt");
	rename("belikambing2.txt","belikambing.txt");	
	printf("\nPembelian Telah dikonfirmasi");
	getchar();
}
	
	pdglm();
}
void beli_sapi()
{
	system("cls");
	s=fopen("sapi.dat","rb");
	while(fread(&sapi,sizeof(sapi),1,s)==1)
	{

	
		printf("Nama Pedagang\t: %s\nNama Sapi\t: %s\nBerat Sapi\t: %s\nDetil Sapi\t:% s\nHarga Sapi\t: %i\n\n",sapi.namaps,sapi.namasapi,sapi.berat,sapi.detil,sapi.harga);

	}
	fclose(s);
	s=fopen("sapi.dat","rb");
	printf("Masukkan Nama Pedagang\t: ");gets(caribs);
	while(fread(&sapi,sizeof(sapi),1,s)==1)
	{
		if(strcmp(caribs,sapi.namaps)==0)
	{
		printf("\nNama Pedagang\t: %s\nNama Sapi\t: %s\nBerat Sapi\t: %s\nDetil Sapi\t:% s\nHarga Sapi\t: %i\n\n",sapi.namaps,sapi.namasapi,sapi.berat,sapi.detil,sapi.harga);
	}
	}
	fclose(s);
	s=fopen("sapi.dat","rb");
	sb=fopen("belisapi.txt","ab");
	printf("Masukkan Nama Sapi Yang Akan Dibeli\t: ");gets(caribs2);
	while(fread(&sapi,sizeof(sapi),1,s)==1)
	{
			if(strcmp(caribs,sapi.namaps)==0&&strcmp(caribs2,sapi.namasapi)==0)
			{
				strcpy(sapi.namabs,lpb.namapb);
						fwrite(&sapi,sizeof(sapi),1,sb);
						
			}
	
	}fclose(sb);
	printf("\nTunggu Konfirmasi Pedagang");
	getchar();
	pblilm();

}
void beli_kambing()
{
	system("cls");
	k=fopen("kambing.dat","rb");
	while(fread(&kambing,sizeof(kambing),1,k)==1)
	{

	
		printf("Nama Pedagang\t: %s\nNama Kambing\t: %s\nBerat Kambing\t: %s\nDetil Kambing\t:% s\nHarga Kambing\t: %i\n\n",kambing.namapk,kambing.namakambing,kambing.berat,kambing.detil,kambing.harga);

	}
	fclose(k);
	k=fopen("kambing.dat","rb");
	printf("Masukkan Nama Pedagang\t: ");gets(caribs);
	while(fread(&kambing,sizeof(kambing),1,k)==1)
	{
		if(strcmp(caribs,kambing.namapk)==0)
	{
		printf("\nNama Pedagang\t: %s\nNama Kambing\t: %s\nBerat Kambing\t: %s\nDetil Kambing\t:% s\nHarga Kambing\t: %i\n\n",kambing.namapk,kambing.namakambing,kambing.berat,kambing.detil,kambing.harga);
	}
	}
	fclose(k);
	k=fopen("kambing.dat","rb");
	kb=fopen("belikambing.txt","ab");
	printf("Masukkan Nama Kambing Yang Akan Dibeli\t: ");gets(caribs2);
	while(fread(&kambing,sizeof(kambing),1,k)==1)
	{
			if(strcmp(caribs,kambing.namapk)==0&&strcmp(caribs2,kambing.namakambing)==0)
			{
				strcpy(kambing.namabk,lpb.namapb);
						fwrite(&kambing,sizeof(kambing),1,kb);
						
			}
	
	}fclose(kb);
	printf("\nTunggu Konfirmasi Pedagang");
	getchar();
	pblilm();

}

