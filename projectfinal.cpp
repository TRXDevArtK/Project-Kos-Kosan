#include <iostream> //fungi input, outout (cin,cout)
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream> // untuk (i/o) file atau stream file
#include <math.h>
#include <time.h> // untuk mendeklarasikan waktu
#include <windows.h> // sebagai fungsi SLEEP / jeda
#include <sstream> // mengkonversi int ke string
#include <string>
#include <vector> // pengganti array dinamis

using namespace std;

class deldata{ // class khusus untuk mendelete data
	private:
		int pilihan; //u ntuk menu pilihan
	public:
		void delloginlog(); // untuk mendelete login_log
		void delalldata(); // untuk mendelete semua data kost
		void delpaydata(); // untuk menghapus data pembayaran
};

void deldata::delloginlog(){
	if( remove( "login_log" ) != 0 ) // jika data tidak terbaca / terbaca
	{
    cout<<"Error dalam menghapus data / Data tidak ada"<<endl<<endl;
	}
  	else
	{
    cout<<endl;
    cout<< "=====Data sudah di hapus====="<<endl;
    //cout<<"Harap restart aplikasi jika anda ingin membuka catatan/Log"<<endl;
	}
}

void deldata::delpaydata(){
	if( remove( "paydata" ) != 0 )
	{
    cout<<"Error dalam menghapus data / Data tidak ada"<<endl<<endl;
	}
  	else
	{
	cout<<endl;
    cout<< "=====Data sudah di hapus====="<<endl;
    //cout<<"Harap restart aplikasi jika anda ingin membuka catatan/Log"<<endl;
	}
}

void deldata::delalldata(){
	if( remove( "data" ) != 0 )
	{
    cout<<"Error dalam menghapus data / Data tidak ada"<<endl<<endl;
	}
  	else
	{
    cout<<endl;
    cout<< "=====Data sudah di hapus====="<<endl;
    //cout<<"Harap restart aplikasi jika anda ingin membuka catatan/Log"<<endl;
	}
}

struct sorting{ //menempatkan/mendeklarasi data di text ke c++
	int kamar;
	char halaman[50];
	char namadepan[50];
	char namabelakang[50];
	char tempatlahir[50];
	int umur;
	char agama[50];
	int nohp;
	int nohportu;
	char noktp[50];
	int uang;
	int bulan;
};

class sort{ // class khusus mensort file
	private:
		char penyangga[1000]; //untuk penyangga file
		int MAKS = 100; //jmlh cek MAKS file
		int pilihan;
		vector<sorting>kmr; // pengganti array dinamis khusus
		sorting temp;
		int n;
	public:
		ifstream ifsortfile; // ambil data
		ofstream ofsortfile; // simpan data
		void login_logshow();
		void showfulldata();
		void showpartdata();
		void showwifidata();
		void showpaydata();
		void sortingdata_umur(); // khusus sorting umur
		void sortingdata_kamar(); // khusus sorting kamar
		void sortinglisting_full();
		void sortinglisting_part();
		void loadfull();
		void loadpart();
		void delkostdata(); // hapus data kosan (terpaksa disini karena penting)
};
 
void sort::loadfull(){ // baca data
	system("cls"); // clear screen ( refresh screen )
		ofsortfile.open("data", ios::app);
		ofsortfile.close();
		ifsortfile.open("data"); // buka data 
		if(ifsortfile.is_open()){
		while(ifsortfile){
			ifsortfile>>temp.kamar;
			ifsortfile>>temp.halaman;
			ifsortfile>>temp.namadepan;
			ifsortfile>>temp.namabelakang;
			ifsortfile>>temp.tempatlahir;
			ifsortfile>>temp.umur;
			ifsortfile>>temp.agama;
			ifsortfile>>temp.nohp;
			ifsortfile>>temp.nohportu;
			ifsortfile>>temp.noktp;
			ifsortfile>>temp.uang;
			ifsortfile>>temp.bulan;
			
			kmr.push_back(temp);
			n++;
		}
		
		kmr.pop_back();
		n--;
		ifsortfile.close();
		}
}

void sort::sortingdata_umur(){
	n = 0; // untuk counter / perhitungan
 	loadfull();
	sorting x; //deklarasi struct sorting
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(kmr[i].umur < kmr[j].umur){ //sorting umurnya
				
				x.kamar = kmr[i].kamar; // pindah x. ke kmr[i]
				strcpy(x.halaman, kmr[i].halaman);
				strcpy(x.namadepan, kmr[i].namadepan);
				strcpy(x.namabelakang, kmr[i].namabelakang);
				strcpy(x.tempatlahir, kmr[i].tempatlahir);
				x.umur = kmr[i].umur;
				strcpy(x.agama, kmr[i].agama);
				x.nohp = kmr[i].nohp;
				x.nohportu = kmr[i].nohportu;
				strcpy(x.noktp, kmr[i].noktp);
				x.uang = kmr[i].uang;
				x.bulan = kmr[i].bulan;
				
				kmr[i].kamar = kmr[j].kamar; // pindah kmr[i] ke kmr [j]
				strcpy(kmr[i].halaman, kmr[j].halaman);
				strcpy(kmr[i].namadepan, kmr[j].namadepan);
				strcpy(kmr[i].namabelakang, kmr[j].namabelakang);
				strcpy(kmr[i].tempatlahir, kmr[j].tempatlahir);
				kmr[i].umur = kmr[j].umur;
				strcpy(kmr[i].agama, kmr[j].agama);
				kmr[i].nohp = kmr[j].nohp;
				kmr[i].nohportu = kmr[j].nohportu;
				strcpy(kmr[i].noktp, kmr[j].noktp);
				kmr[i].uang = kmr[j].uang;
				kmr[i].bulan = kmr[j].bulan;
				
				kmr[j].kamar = x.kamar; // pindah kmr[j] kembali ke x.
				strcpy(kmr[j].halaman, x.halaman);
				strcpy(kmr[j].namadepan, x.namadepan);
				strcpy(kmr[j].namabelakang, x.namabelakang);
				strcpy(kmr[j].tempatlahir, x.tempatlahir);
				kmr[j].umur = x.umur;
				strcpy(kmr[j].agama, x.agama);
				kmr[j].nohp = x.nohp;
				kmr[j].nohportu = x.nohportu;
				strcpy(kmr[j].noktp, x.noktp);
				kmr[j].uang = x.uang;
				kmr[j].bulan = x.bulan;
				
			}
		}
	}
	
	system("cls");
	cout<<"NOTE : Jika datanya kosong / tidak ada, berarti belum ada yang mendaftar"<<endl<<endl;
	for(int i=0;i<n;i++){ // baca dan outputkan file sesuai n (counter) 
		cout<<"Kamar = "<<kmr[i].kamar<<endl;
		cout<<"Halaman = "<<kmr[i].halaman<<endl;
		cout<<"Nama Depan = "<<kmr[i].namadepan<<endl;
		cout<<"Nama Belakang = "<<kmr[i].namabelakang<<endl;
		cout<<"Tempat Lahir = "<<kmr[i].tempatlahir<<endl;
		cout<<"Umur = "<<kmr[i].umur<<endl;
		cout<<"Agama = "<<kmr[i].agama<<endl;
		cout<<"No.Hp Pribadi = "<<kmr[i].nohp<<endl;
		cout<<"No.Hp Orang Tua = "<<kmr[i].nohportu<<endl;
		cout<<"No.KTP = "<<kmr[i].noktp<<endl;
		cout<<endl;
	}
		
}

//penjelasannya sama begitu juga yang dibawah

void sort::sortingdata_kamar(){
	n = 0;
 	loadfull();
	sorting x;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(kmr[i].kamar < kmr[j].kamar){ //sorting kamarnya
				
				x.kamar = kmr[i].kamar;
				strcpy(x.halaman, kmr[i].halaman);
				strcpy(x.namadepan, kmr[i].namadepan);
				strcpy(x.namabelakang, kmr[i].namabelakang);
				strcpy(x.tempatlahir, kmr[i].tempatlahir);
				x.umur = kmr[i].umur;
				strcpy(x.agama, kmr[i].agama);
				x.nohp = kmr[i].nohp;
				x.nohportu = kmr[i].nohportu;
				strcpy(x.noktp, kmr[i].noktp);
				x.uang = kmr[i].uang;
				x.bulan = kmr[i].bulan;
				
				kmr[i].kamar = kmr[j].kamar;
				strcpy(kmr[i].halaman, kmr[j].halaman);
				strcpy(kmr[i].namadepan, kmr[j].namadepan);
				strcpy(kmr[i].namabelakang, kmr[j].namabelakang);
				strcpy(kmr[i].tempatlahir, kmr[j].tempatlahir);
				kmr[i].umur = kmr[j].umur;
				strcpy(kmr[i].agama, kmr[j].agama);
				kmr[i].nohp = kmr[j].nohp;
				kmr[i].nohportu = kmr[j].nohportu;
				strcpy(kmr[i].noktp, kmr[j].noktp);
				kmr[i].uang = kmr[j].uang;
				kmr[i].bulan = kmr[j].bulan;
				
				kmr[j].kamar = x.kamar;
				strcpy(kmr[j].halaman, x.halaman);
				strcpy(kmr[j].namadepan, x.namadepan);
				strcpy(kmr[j].namabelakang, x.namabelakang);
				strcpy(kmr[j].tempatlahir, x.tempatlahir);
				kmr[j].umur = x.umur;
				strcpy(kmr[j].agama, x.agama);
				kmr[j].nohp = x.nohp;
				kmr[j].nohportu = x.nohportu;
				strcpy(kmr[j].noktp, x.noktp);
				kmr[j].uang = x.uang;
				kmr[j].bulan = x.bulan;
				
			}
		}
	}
	
	system("cls");
	cout<<"NOTE : Jika datanya kosong / tidak ada, berarti belum ada yang mendaftar"<<endl<<endl;
	for(int i=0;i<n;i++){
		cout<<"Kamar = "<<kmr[i].kamar<<endl;
		cout<<"Halaman = "<<kmr[i].halaman<<endl;
		cout<<"Nama Depan = "<<kmr[i].namadepan<<endl;
		cout<<"Nama Belakang = "<<kmr[i].namabelakang<<endl;
		cout<<"Tempat Lahir = "<<kmr[i].tempatlahir<<endl;
		cout<<"Umur = "<<kmr[i].umur<<endl;
		cout<<"Agama = "<<kmr[i].agama<<endl;
		cout<<"No.Hp Pribadi = "<<kmr[i].nohp<<endl;
		cout<<"No.Hp Orang Tua = "<<kmr[i].nohportu<<endl;
		cout<<"No.KTP = "<<kmr[i].noktp<<endl;
		cout<<endl;
	}
		
}

void sort::showpartdata(){
	system("cls");
	cout<<"======Masukkan Nomor Kamar Kost====="<<endl;
	cout<<"===Yang Datanya Akan Di Tampilkan==="<<endl;
	cout<<"Nomor : ";
	cin>>pilihan;
	n = 0;
	loadfull(); // ambil procedure baca file tadi
	system("cls");
		cout<<"NOTE : Jika datanya kosong / tidak ada, berarti belum ada yang mendaftar"<<endl<<endl;
		for(int i=0;i<n;i++){
			if(kmr[i].kamar == pilihan){ // jika kamar = pilihan yang kita masukkan maka tampilkan data sesuai kamar = pilihan
			cout<<"Kamar = "<<kmr[i].kamar<<endl;
			cout<<"Halaman = "<<kmr[i].halaman<<endl;
			cout<<"Nama Depan = "<<kmr[i].namadepan<<endl;
			cout<<"Nama Belakang = "<<kmr[i].namabelakang<<endl;
			cout<<"Tempat Lahir = "<<kmr[i].tempatlahir<<endl;
			cout<<"Umur = "<<kmr[i].umur<<endl;
			cout<<"Agama = "<<kmr[i].agama<<endl;
			cout<<"No.Hp Pribadi = "<<kmr[i].nohp<<endl;
			cout<<"No.Hp Orang Tua = "<<kmr[i].nohportu<<endl;
			cout<<"No.KTP = "<<kmr[i].noktp<<endl;
			cout<<endl;
			}
		}	
}

void sort::showfulldata(){// menampilkan seluruh data tanpa sorting
	n = 0;
	loadfull();
	system("cls");
	cout<<"NOTE : Jika datanya kosong / tidak ada, berarti belum ada yang mendaftar"<<endl<<endl;
	for(int i=0;i<n;i++){
		cout<<"Kamar = "<<kmr[i].kamar<<endl;
		cout<<"Halaman = "<<kmr[i].halaman<<endl;
		cout<<"Nama Depan = "<<kmr[i].namadepan<<endl;
		cout<<"Nama Belakang = "<<kmr[i].namabelakang<<endl;
		cout<<"Tempat Lahir = "<<kmr[i].tempatlahir<<endl;
		cout<<"Umur = "<<kmr[i].umur<<endl;
		cout<<"Agama = "<<kmr[i].agama<<endl;
		cout<<"No.Hp Pribadi = "<<kmr[i].nohp<<endl;
		cout<<"No.Hp Orang Tua = "<<kmr[i].nohportu<<endl;
		cout<<"No.KTP = "<<kmr[i].noktp<<endl;
		cout<<endl;
	}
}

void sort::showwifidata(){ // menampilkan data wifi
	system("cls");
	cout<<"NOTE : Jika datanya kosong / tidak ada, berarti belum ada yang mendaftar"<<endl<<endl;
	ifstream file_masukan("wifi"); // baca data
	while (file_masukan)
	{
	file_masukan.getline (penyangga,MAKS);
	cout<<penyangga<<endl;
	}
	file_masukan.close(); // tutup kembali file agar tidak spam memory
}

void sort::showpaydata(){ // tampilkan data pembayaran
	system("cls");
	cout<<"NOTE : Jika datanya kosong / tidak ada, berarti belum ada yang mendaftar"<<endl<<endl;
	ifstream file_masukan("paydata");
	while (file_masukan)
	{
	file_masukan.getline (penyangga,MAKS);
	cout<<penyangga<<endl;
	}
	file_masukan.close();
}

void sort::login_logshow(){ // tampilkan login_log
	system("cls");
	cout<<"NOTE : Jika datanya kosong / tidak ada, berarti belum ada yang mendaftar"<<endl<<endl;
	ifstream file_masukan("login_log");
	while (file_masukan)
	{
	file_masukan.getline (penyangga,MAKS);
	cout<<penyangga<<endl;
	}
	file_masukan.close();
}

class data{ // class khusus data / pendataan
	private:
		int pilihan; //pilihan menu 1
		char pilihan2; // pilihan menu 2
		char pilihan3; // -- 3
		int index; // untuk index no kost
		int biayabulanan = 300000;
		int bulan_bayar; // berapa bulan bayar
		int uang_penyewa;
		string nama_depan[34];
		string nama_belakang[34];
		string tempat_asal[34];
		string agama[34];
		int umur[34];
		unsigned long long int no_pribadi[34];
		unsigned long long int no_ortu[34];
		int tanggal_lahir[34];
		int bulan[34];
		int tanggal[34];
		int tahun[34];
		unsigned long long int no_ktp[34];
		int wifi = 30000;
		int reg_wifi;
		int no_kos;
		string for_name; // untuk siapa / atas nama
	public:
		void product();
		void inputdata();
		void outputdata();
		void pesan_wifi();
};

void data::pesan_wifi(){
	ofstream datawifi;
	datawifi.open("datawifi", ios::app); // buka file
	time_t waktu; //panggil fungsi time.h
	time(&waktu); // deklarasi waktunya
	system("cls");
	cout<<"===============PENDATAAN==============="<<endl;
	cout<<"Masukkan No Kost : ";
	cin>>no_kos;
	cout<<"Atas Nama : ";
	cin>>for_name;
	cout<<"===============PEMESANAN==============="<<endl;
	cout<<"Biaya WIFI Hotspot Perbulan : "<<wifi<<endl;
	cout<<"Masukkan untuk berapa bulan : ";
	cin>>reg_wifi;
	cout<<"Masukkan uang yang dimiliki penyewa : ";
	cin>>uang_penyewa;
	int totalan_wifi = uang_penyewa-(wifi*reg_wifi);
	cout<<endl;
	if(totalan_wifi >= 0 )
	{
		cout<<"Total kembalian : "<<totalan_wifi<<endl;
		cout<<"Selamat, tidak ada hutang"<<endl;
	}
	else if(totalan_wifi < 0)
	{
		cout<<"Total hutang = "<<totalan_wifi<<endl;
		cout<<"Mohon hutangnya segera dibayar :)"<<endl;
	}
	cout<<"======================================="<<endl;
	cout<<"TERTERA PADA : "<<ctime(&waktu)<<endl<<endl;
	////////////////////
	datawifi<<"===============PENDATAAN==============="<<endl;
	datawifi<<"No Kost : "<<no_kos<<endl;
	datawifi<<"Atas Nama : "<<for_name<<endl;
	datawifi<<"===============PEMESANAN==============="<<endl;
	if(totalan_wifi >= 0 )
	{
		cout<<"Total kembalian : "<<totalan_wifi<<endl;
		cout<<"Selamat, tidak ada hutang"<<endl;
		datawifi<<"Total kembalian : "<<totalan_wifi<<endl;
		datawifi<<"Selamat, tidak ada hutang"<<endl;
	}
	else if(totalan_wifi < 0)
	{
		cout<<"Total hutang = "<<-totalan_wifi<<endl;
		cout<<"Mohon hutangnya segera dibayar :)"<<endl;
		datawifi<<"Total hutang = "<<-totalan_wifi<<endl;
		datawifi<<"Mohon hutangnya segera dibayar :)"<<endl;
	}
	datawifi<<"Terdaftar untuk "<<reg_wifi<<" bulan"<<endl;
	datawifi<<"Mohon cek kembali setelah "<<reg_wifi<<" Bulan"<<endl;
	datawifi<<"======================================="<<endl;
	datawifi<<"TERTERA PADA : "<<ctime(&waktu)<<endl<<endl;
	
}

void data::inputdata(){ // pendataan
	system("cls");
	cout<<"=====Anda memilih kos dengan nomor "<<"("<<index<<")"<<"====="<<endl;
	if(index >= 1 && index <= 3)
	{
		cout<<"=========Berada di [Halaman Depan]========="<<endl;
	}
	else if(index >= 4 && index <= 12)
	{
		cout<<"==========Berada di [Halaman Tengah]========="<<endl;
	}
	else if(index >= 13 && index <= 32)
	{
		cout<<"==========Berada di [Halaman Belakang]========="<<endl;
	}
	cout<<"===========Masukkan data penyewa==========="<<endl<<endl;
	cout<<"Nama Depan : ";
	cin>>nama_depan[index];
	cout<<"Nama Belakang : ";
	cin>>nama_belakang[index];
	cout<<"Tempat Tinggal Asal : ";
	cin>>tempat_asal[index];
	cout<<"Umur : ";
	cin>>umur[index];
	cout<<"Agama/Kepercayaan : ";
	cin>>agama[index];
	cout<<"No.HP Pribadi : ";
	cin>>no_pribadi[index];
	cout<<"No.HP Orang tua : ";
	cin>>no_ortu[index];
	cout<<"No.KTP : ";
	cin>>no_ktp[index];
	outputdata();
}

void data::outputdata(){ // konfirmasi data
	system("cls");
	cout<<"=====Mohon dicek kembali====="<<endl<<endl;
	cout<<"=====Anda memilih kos dengan nomor "<<"("<<index<<")"<<"====="<<endl;
	if(index >= 1 && index <= 3)
	{
		cout<<"=========Berada di [Halaman Depan]========="<<endl;
	}
	else if(index >= 4 && index <= 12){
		cout<<"==========Berada di [Halaman Tengah]========="<<endl;
	}
	else if(index >= 13 && index <= 32){
		cout<<"==========Berada di [Halaman Belakang]========="<<endl;
	}
	cout<<"Nama Depan : "<<nama_depan[index]<<endl;
	cout<<"Nama Belakang : "<<nama_belakang[index]<<endl;
	cout<<"Tempat tinggal asal "<<tempat_asal[index]<<endl;
	cout<<"Umur : "<<umur[index]<<endl;
	cout<<"Agama/Kepercayaan : "<<agama[index]<<endl;
	cout<<"No.HP Pribadi : "<<no_pribadi[index]<<endl;
	cout<<"No.HP Orang tua : "<<no_ortu[index]<<endl;
	cout<<"No.KTP : "<<no_ktp[index]<<endl;
	cout<<endl;
	cout<<"Apakah data diatas sudah benar ? Ya/Tidak"<<endl;
	cout<<"Masukkan (Y/T) : ";cin>>pilihan2; // konfirmasi datanya
	if(pilihan2 == 'Y' || pilihan2 =='y')
	{
		ofstream data;
		ofstream paydata;
		data.open("data", ios::app);
		paydata.open("paydata", ios::app);
		time_t waktu;
		time(&waktu);
		data<<index<<endl;
		if(index >= 1 && index <= 3)
		{
			data<<"Depan"<<endl; // masukkan ini kedalam file jika
		}
		else if(index >= 4 && index <= 12)
		{
			data<<"Tengah"<<endl;
		}
		else if(index >= 13 && index <= 32)
		{
			data<<"Belakang"<<endl;
		}
		////////////
		data<<nama_depan[index]<<endl;
		data<<nama_belakang[index]<<endl;
		data<<tempat_asal[index]<<endl;
		////////////
		data<<umur[index]<<endl;
		data<<agama[index]<<endl;
		data<<no_pribadi[index]<<endl;
		data<<no_ortu[index]<<endl;
		data<<no_ktp[index]<<endl;
		/////////////////////
		cout<<endl;
		cout<<"======================================="<<endl;
		cout<<"Biaya Kost Perbulan = Rp."<<biayabulanan<<endl;
		cout<<"Bayar untuk berapa bulan ? : ";
		cin>>bulan_bayar;
		cout<<"Masukkan uang yang dimiliki penyewa : ";
		cin>>uang_penyewa;
		int totalan = uang_penyewa-(biayabulanan*bulan_bayar);
		cout<<endl;
		if(totalan >= 0 )
		{
			cout<<"Total kembalian : "<<totalan<<endl;
			cout<<"Selamat, tidak ada hutang"<<endl;
			data<<totalan<<endl;
		}
		else if(totalan < 0)
		{
			cout<<"Total hutang = "<<-totalan<<endl;
			cout<<"Mohon hutangnya segera dibayar :)"<<endl;
			data<<-totalan<<endl;
		}
		cout<<"Terdaftar untuk "<<bulan_bayar<<" bulan"<<endl;
		cout<<"Mohon cek kembali setelah "<<bulan_bayar<<" Bulan"<<endl;
		data<<bulan_bayar<<endl;
		cout<<"======================================="<<endl;
		/////////////////////
		//data pembayaran///
		paydata<<"================Data Pembayaran================"<<endl;
		paydata<<"Atas Nama : "<<nama_depan[index]<<endl;
		paydata<<"Kos No : "<<index<<endl;
		if(totalan >= 0 )
		{
			paydata<<"Total kembalian : "<<totalan<<endl;
			paydata<<"Selamat, tidak ada hutang"<<endl;
		}
		else if(totalan < 0)
		{
			paydata<<"Total hutang = "<<-totalan<<endl;
			paydata<<"Mohon hutangnya segera dibayar :)"<<endl;
		}
		paydata<<"Terdaftar untuk "<<bulan_bayar<<" bulan"<<endl;
		paydata<<"Mohon cek kembali setelah "<<bulan_bayar<<" Bulan"<<endl;
		paydata<<"TERTERA PADA : "<<ctime(&waktu);
		paydata<<"=================================================="<<endl;
		paydata<<endl;
		////////////////////
		cout<<"Terima kasih sudah memakai jasa aplikasi ini :)"<<endl;
		
	}
	if(pilihan2 == 'T' || pilihan2 =='t')
	{
		system("cls");
		cout<<"=====Silahkan masukkan kembali datanya dengan benar====="<<endl;
		cout<<"==================Mohon tunggu sebentar================="<<endl;
		for(int i=0;i<10;i++)
		{
	    	cout<<" . ";
	    	Sleep( 80 );
		}
		inputdata();
	}
}

void data::product(){	// denah simple untuk kostnya ( tidak efektif )
			system("cls");
			cout<<"=====Mohon program nya dizoom agar seluruh denah keliatan====="<<endl;
			cout<<"Denah Simple : "<<endl<<endl;
			cout<<"######################################################################################################################################################"<<endl;
			cout<<"##===============================(^8)==(^9)==(^10)==(^11)==(^12)=(T)================================================================================##"<<endl;
			cout<<"##===============================(~4)==(~5)==(~6)===(~7)==(WC)===(T)=====(13)==(14)==(15)==(16)==(17)==(18)==(19)==(20)==(21)==(22)==(G)============##"<<endl;
			cout<<"==::---------Halaman-----------::--------------Halaman--------------::----------------------------Halaman-----------------------------------====(WC)##"<<endl;
			cout<<"==::----------Depan------------::---------------Tengah--------------::----------------------------Belakang----------------------------------====(WC)##"<<endl;
			cout<<"##(WC)==(~G)==(~-)==(~-)=(T)===(...............Rumah...............)=================(23)==(24)==(25)==(26)==(27)==(28)==(29)==(30)==(31)=======(32)##"<<endl;
			cout<<"##(WC)==(^1)==(^2)==(^3)=(T)===(..............Pemilik..............)=================(23)==(24)==(25)==(26)==(27)==(28)==(29)==(30)==(31)=======(32)##"<<endl;
			cout<<"######################################################################################################################################################"<<endl<<endl;
			
			cout<<"Legends/Penjelasan : "<<endl;
			cout<<"^  = Lantai atas         ~  = Lantai bawah"<<endl;
			cout<<"WC = Kamar Mandi/WC      G  = Gudang"<<endl;
			cout<<"T  = Tangga              :: = Gerbang"<<endl<<endl;
			
			cout<<"Masukkan Kamar Kos yang akan disewa : ";
			cin>>index;
			if(index > 0 && index <= 32)
			{
				inputdata();
			}
			else
			{
				cout<<"Mohon masukkan nomor kosan yang tersedia di atas (1-32) :";
				cin>>index;
				inputdata();
			}
}

class changereg{ // khusus untuk pengubahan sesuatu seperti username/password
	private:
		string temp_pass; // temp artinya temporary = sementara
		string temp_name;
		string reg_pass[2];
		string reg_name[2];
		string username;
		string password;
		char pilihan;		
	public:
		void intocpass();
		void intocname();
};

void changereg::intocpass(){ // menu ganti password
	
	ofstream login_log;
	login_log.open("login_log", ios::app); // perubahan akan tercatat ke login_log
	time_t waktu;
	time(&waktu);
    ifstream f("registration");
		if (!f.is_open())
        {
            cout<<"could not open file\n";
        }
    getline(f, username, '\n'); // dapatkan line pertama sebagai username
    getline(f, password, '\n'); // dapatkan line kedua sebagai password
    
    for(int i = 0;i<=4;i++)
	{
		if(i<=3)
		{
	    cout<<"Masukkan Password Lama : ";
		cin>>temp_pass;
			if(temp_pass == password)
			{
				cout<<"Masukkan Password Baru : ";
				cin>>reg_pass[0];
				cout<<"Konfirmasi Password Baru : ";
				cin>>reg_pass[1];
					if(reg_pass[0] == reg_pass[1])
					{	
					ofstream g("registration"); 
					    if (!g.is_open())
					    {
					        cout<<"could not open file\n";
					    }
					g<<username; // dapatkan username tadi yang tidak diubah
					g<<'\n'; //enter / kebawah
					g<<reg_pass[1]; // dapatkan password baru nya
					g.close();
					login_log<<ctime(&waktu)<<" Password Diubah "<<endl;
					login_log<<endl;
					system("cls");
					cout<<"==========TERIMA KASIH========="<<endl;
					cout<<"SILAHKAN RESTART ULANG APLIKASI"<<endl; // butuh restart agar password terupdate
					exit(0);
					}
				}
		else
		{
			if(i<=2)
			{
			system("cls");	
			cout<<"PASSWORD LAMA YANG ANDA MASUKKAN SALAH"<<endl;
			cout<<"          SILAHKAN COBA LAGI          "<<endl<<endl;
			}
			
			else
			{
			system("cls");
			cout<<"   ANDA TELAH 3 KALI SALAH MEMASUKKAN PASSWORD LAMA  "<<endl;
			cout<<"     HUBUNGI PEMBUAT SOFTWARE UNTUK LEBIH LANJUT     "<<endl;
			cout<<"====================================================="<<endl<<endl;
			exit(0);
			}
		}
		}
	}
	
}

void changereg::intocname(){ // sama seperti procedure ganti password tadi hanya saja ini username
	
	ofstream login_log;
	login_log.open("login_log", ios::app);
	time_t waktu;
	time(&waktu);
	ifstream f("registration");
		if (!f.is_open())
	    {
	        cout<<"could not open file\n";
	    }
	getline(f, username, '\n');
	getline(f, password, '\n');
    
    for(int i = 0;i<=4;i++)
	{
		if(i<=3)
		{
	    cout<<"Masukkan Username Lama : ";
	    cin>>temp_name;
	    if(temp_name == username)
			{
				cout<<"Masukkan Username Baru : ";
				cin>>reg_name[0];
				cout<<"Konfirmasi Username Baru : ";
				cin>>reg_name[1];
					if(reg_name[0] == reg_name[1])
					{	
					ofstream g("registration");
				    if (!g.is_open())
				    {
				        cout<<"could not open file\n";
				    }
				    g<<reg_name[1];
				    g<<'\n'; 
				    g<<password;
				    g.close();
				    login_log<<ctime(&waktu)<<" Username Diubah "<<endl;
					login_log<<endl;
					system("cls");
					cout<<"==========TERIMA KASIH========="<<endl;
					cout<<"SILAHKAN RESTART ULANG APLIKASI"<<endl;
					exit(0);
					}
			}
		else
		{
			if(i<=2)
			{
			system("cls"); 
			cout<<"USERNAME LAMA YANG ANDA MASUKKAN SALAH"<<endl;
			cout<<"          SILAHKAN COBA LAGI          "<<endl<<endl;
			}
			
			else
			{
			system("cls");
			cout<<"   ANDA TELAH 3 KALI SALAH MEMASUKKAN USERNAME LAMA  "<<endl;
			cout<<"     HUBUNGI PEMBUAT SOFTWARE UNTUK LEBIH LANJUT     "<<endl;
			cout<<"====================================================="<<endl<<endl;
			exit(0);
			}
		}
		}
	}
		
}

class menu{ // pilihan menu umum
	private:
		int pilihan;
		int koslist;
		char pilihan2;
		char pilihan3;
		int pilihan4;
		int pilihan5;
	public:
		void product();
		void datamenu();
		void del_datamenu();
		void backtomenu();
		void intomenu();
		void pesan_wifi();
		changereg c;
		data e;
		sort f;
		deldata g;
};

void menu::backtomenu(){ // fungsi yang memudahkan untuk kembali ke menu
	cout<<endl;
	cout<<"Apa anda ingin kembali ke menu ? : Ya/Tidak"<<endl;
	cout<<"Masukkan (Y/T) : ";
	cin>>pilihan2;
	if(pilihan2 == 'Y' || pilihan2 =='y')
	{
		system("cls");
		intomenu();
	}
	if(pilihan2 == 'T' || pilihan2 =='t')
	{
		system("cls");
		cout<<"=====Terima kasih sudah memakai aplikasi ini====="<<endl;
		cout<<"================================================="<<endl;
	}
	
}

void menu::datamenu(){ // menu sorting
	system("cls");
	cout<<"================DATA MENU================"<<endl;
	cout<<"1.Tampilkan Semua Data Kost Berdasarkan Pendaftaran (awal-terakhir mendaftar)"<<endl;
	cout<<"2.Tampilkan Semua Data Kost Berdasarkan Kamar"<<endl;
	cout<<"3.Tampilkan Semua Data Kost Berdasarkan Umur"<<endl;
	cout<<"4.Tampilkan Data Kost Berdasarkan Input No Kost"<<endl;
}

void menu::del_datamenu(){ // menu untuk delete sesuatu
	system("cls");
	cout<<"=============HAPUS DATA============="<<endl;
	cout<<"1.Hapus Data Kost"<<endl;
	cout<<"2.Hapus Log Login"<<endl;
	cout<<"3.Hapus Data Pembayaran"<<endl<<endl;
}

void menu::intomenu(){ // menu umum
	cout<<"====================MENU===================="<<endl;
	cout<<"1.Sewa Kamar Kos"<<endl;
	cout<<"2.Sewa WIFI Hostpost"<<endl;
	cout<<"3.Data Kamar Kos"<<endl;
	cout<<"4.Data Pembayaran Kost"<<endl;
	cout<<"5.Data WIFI Hostspot"<<endl;
	cout<<"================Administrasi==============="<<endl;
	cout<<"6.Ganti Username"<<endl;
	cout<<"7.Ganti Password"<<endl;
	cout<<"8.Catatan Login"<<endl;
	cout<<"9.Hapus Data"<<endl<<endl;
	cout<<"Masukkan Pilihan : ";
	cin>>pilihan;// switch case tidak diperbolehkan jadi kami menggunakan if
		if(pilihan==1){
			e.product();
			backtomenu();
		}
		
		else if(pilihan==2){
			e.pesan_wifi();
			backtomenu();
		}
		
		else if(pilihan==3){
			datamenu();
			for(int i = 0;i<=1;i--)
			{
				cout<<"Masukkan Pilihan : ";
				cin>>pilihan4;
				if(pilihan4 == 1){
					f.showfulldata();
					backtomenu();
					exit(0);
				}
				else if(pilihan4 == 2){
					f.sortingdata_kamar();
					backtomenu();
					exit(0);
				}
				else if(pilihan4 == 3){
					f.sortingdata_umur();
					backtomenu();
					exit(0);
				}
				else if(pilihan4 == 4){
					f.showpartdata();
					backtomenu();
					exit(0);
				}
			}
		}
		
		else if(pilihan==4){
			f.showpaydata();
			backtomenu();
		}
		
		else if(pilihan == 5){
			f.showwifidata();
			backtomenu();
		}
		
		else if(pilihan == 6){
			c.intocname();
		}
		
		else if(pilihan == 7){
			c.intocpass();
		}
			
		else if(pilihan == 8){
			f.login_logshow();
			backtomenu();
		}
		
		else if(pilihan == 9){
			del_datamenu();
			for(int i = 0;i<=1;i--)
			{
				cout<<"Masukkan Pilihan : ";
				cin>>pilihan5;
				if(pilihan5 == 1){
					g.delalldata();
					backtomenu();
					exit(0);
				}
				else if(pilihan5 == 2){
					g.delloginlog();
					backtomenu();
					exit(0);
				}
				else if(pilihan5 == 3){
					g.delpaydata();
					backtomenu();
					exit(0);
				}
			}
		}
		
		else{ // jika selain pilihan yang dimasukkan 1-9
			system("cls");
			cout<<"===Pilihan pilihan menu tidak ada==="<<endl;
			cout<<"=======Mohon masukkan kembali======="<<endl<<endl;
			
			intomenu();
		}	
}

class login{ // class khusus login
	private:
		int pilihan;
		char pilihan2;
		menu b;
	public:
		string username;
		string temp_username; //sementara / temporary
		string password;
		string temp_password;
		void intologin();
};

void login::intologin() 
{ // ke loginnya
	ofstream login_log;
	login_log.open("login_log", ios::app);
	time_t waktu;
	time(&waktu);
	login:
	ifstream f("registration"); // buka file
		if (!f.is_open())
        {
            cout<<"could not open file\n";
        }
    getline(f, username, '\n');
    getline(f, password, '\n');
    f.close();
    cout<<"==========MENU=========="<<endl;
    cout<<"1.Login"<<endl;
    cout<<"2.Appinfo"<<endl;
    cout<<"3.Exit"<<endl;
	cout<<"\nMasukkan Pilihan : ";cin>>pilihan;
	cout<<endl;
	if(pilihan == 1){ // menu login / ke login
			for(int i = 0;i<=4;i++)
			{
				if(i<=3)
				{
				cout<<"MASUKKAN USERNAME : ";
				cin>>temp_username;
				cout<<"MASUKKAN PASSWORD : ";
				cin>>temp_password;
				system("cls");
					if(temp_username == username && temp_password == password)
					{
					system("cls");
					cout<<"=====Anda berhasil masuk====="<<endl;
					cout<<"====Mohon tunggu sebentar===="<<endl;
				    for(int i=0;i<10;i++){
				    	cout<<" . ";
				    	Sleep( 80 );
					}
					login_log<<ctime(&waktu)<<" Berhasil masuk "<<endl;
					login_log<<endl;
					login_log.close();
					system("cls");
					b.intomenu();
					exit(0);
					}
					else
					{
						if(i<=2)
						{
						system("cls");	
						cout<<"MAAF DATA YANG ANDA MASUKKAN SALAH"<<endl;
						cout<<"    SILAHKAN MASUKKAN KEMBALI     "<<endl<<endl;
						}
						
						else
						{
						cout<<"   ANDA TELAH 3 KALI SALAH MEMASUKKAN DATA   "<<endl;
						cout<<"SILAHKAN RESTART ULANG APLIKASI DEMI KEAMANAN"<<endl;
						cout<<"============================================="<<endl;
						login_log<<ctime(&waktu)<<" Password salah 3 kali "<<endl;
						login_log<<endl;
						exit(0);
						}
					}
				}
			}
		}
		if(pilihan == 2){ // menu appinfo / about
			cout<<"===Universitas Ahmad Dahlan==="<<endl;
			cout<<"   Aplikasi ini dibuat oleh   "<<endl<<endl;
			cout<<"Credit :"<<endl<<endl;
			cout<<"================================="<<endl;
			cout<<"1.Refaldi Ergian (1700018013)"<<endl;
			cout<<"2.Aji Gelar Prayogo (1700018016)"<<endl;
			cout<<"3.Bayu Krisna Murti (1700018015)"<<endl;
			cout<<"================================="<<endl<<endl;
			cout<<"Kami membuat aplikasi ini untuk membantu orang-orang serta sebagai tugas akhir kami"<<endl;
			cout<<"Semoga aplikasi ini bermanfaat bagi yang membutuhkan :)"<<endl;
			
		}
		if(pilihan == 3){ // menu exit
			cout<<"\nHint : Anda bisa exit dengan menclose aplikasi ini lewat tanda [ X ] di atas aplikasi"<<endl;
			cout<<"Anda yakin ingin keluar Ya/Tidak : (Y/T) ";
			cin>>pilihan2;
			if(pilihan2 == 'Y' || pilihan2 =='y')
			{
				exit(0);
			}
			if(pilihan2 == 'T' || pilihan2 =='t')
			{
				system("cls");
				return intologin();
			}
		}
			
		else{
			system("cls");
			cout<<"===Pilihan pilihan menu tidak ada==="<<endl;
			cout<<"=======Mohon masukkan kembali======="<<endl<<endl;
			
			intologin();
		}
}

main(){
	system("color 1F"); // ganti warna sistem / background ke biru
	login a;
	a.intologin();
}
