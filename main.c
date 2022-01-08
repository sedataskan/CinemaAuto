#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
#include <unistd.h>

#define MAX_LIMIT 20
#define max 50

// Fonksiyonların Prototiplerinin Hazırlanması.
int sifredegis();
int biletal();
int biletimigoster();
int koltuklar();
int vizyondakiler();
int yoneticipaneli();
int filmekle();
int filmcikar();
int sifirla();
void dolukoltuklar();
// Global değerleri tanımlama
int ak = 0; // alınmış koltuk sayısı.
int girissayac = 0; // Yanlış şifre deneme sayısı.

int main() {
  int girdi;
  int aktiflik = 0;
  while(aktiflik == 0) {
          system("clear");
          printf("\n        Sinema Bileti Otomasyon Sistemi v1.0\n");
          printf("\n   Lütfen yapmak istediğiniz işlemi tuşlayınız.\n");
          printf(" ==========================================================\n");
          printf("|| Vizyondaki filmlerin listesine göz atmak için:\t [1]  ||\n");
          printf("|| Bilet satın almak için:\t\t\t\t\t\t\t [2]  ||\n");
          printf("|| Aktif biletinizi göstermek için:\t\t\t\t\t [3]  ||\n");
          printf("|| Boş koltuklara göz atmak için:\t\t\t\t\t [4]  ||\n");
          printf("|| Yönetici Paneline giriş yapmak için:\t\t\t\t [5]  ||\n");
          printf("|| Programdan çıkış yapmak için:\t\t\t\t\t [9]  ||\n");
          printf(" ==========================================================\n");
          printf("\n");
          printf("\n");
          printf("Seçiminizi giriniz [1-9]: ");
          scanf("%d", &girdi);
          getchar();
          switch(girdi) { // girilen değere göre fonksiyonu çağıyoruz
          case 1:
            system("clear");
            vizyondakiler();
            break;
          case 2:
            system("clear");
            biletal();
            break;
          case 3:
            system("clear");
            biletimigoster();
            break;
          case 4:
            system("clear");
            koltuklar();
            break;
          case 5:
            system("clear");
            yoneticipaneli();
            break;
          case 9:
            printf("Programdan çıkış yapılıyor...\n");
            aktiflik = 1;
            break;
          default:
            printf("\n");
            printf("Geçersiz bir girdi girişi yaptınız.\n");
            printf("\n");
            sleep(1);
            break;
          }
  }
  return 0;
} 
int biletal() {
  // Srand random sayısının her seferinde farklı bir seed ile verilmesini sağlar.
  srand(time(NULL));
  char menudon,cevap,onay,koltuksirasi[max],koltuksayisi[max],koltuknumarasi[max],tip[max],line[max],harf;
  int adet,sayac,fatura,sayi;
  float ucret;
  long numara;
  printf("Devam etmek için herhangi bir tuşa basın.\n");
  printf("Menüye dönmek için [0]\n");
  scanf(" %c",&menudon);
  if(menudon=='0')
  {
    main(); // eğer kullanıcı geri dönmek isterse main fonksiyonu tekrar çağrılıyor.
  }
  printf("\n");
  printf("\n");
  printf(" Öğrenci: 10₺\n");
  printf(" Normal: 20₺\n ");
  printf("\n");
  printf("\n");
  printf("Kaç adet bilet almak istiyorsunuz?\n");
  scanf("%d", &adet);
  if(adet>0&&adet<=30) // alınabilecek maks ve min koltuk sayısını belirliyoruz
  {
    sayac = adet;
    for (int i=0; i<adet; i++)
    {
      printf("\nAlmak istediğiniz %d. bilet öğrenci için mi? [E-H] \n(E = Evet H = Hayır)\n" , i+1);
      scanf(" %c", &cevap);
      if (cevap == 'E')
      {
        printf("1 adet öğrenci bileti faturası kesildi\n");
        ucret += 10;
        tip[i] = cevap; // ileride fatura kesimi için kullanılacak
      }
      else if (cevap == 'H')
      {
        printf("1 adet tam bilet faturası kesildi\n");
        ucret += 20;
        tip[i] = cevap; // ileride fatura kesimi için kullanılacak
      }
      else
      {
        printf("Uygun bir değer giriniz!\n");
        printf("Bilet al fonksiyonun başına döndürülüyorsunuz...\n");
        printf("\n\n");
        biletal();
      }
      FILE *filekoltuk;
      filekoltuk=fopen("veriler/koltuklar.txt","a");
      FILE *koltuklar;
      koltuklar = fopen("veriler/koltuklar.txt","r");
        if(filekoltuk==NULL || koltuklar==NULL)
        {
          printf("Dosya bulunamadı.");
        } 
        else
        {
          // dolu koltukları listeyen fonksiyonu çağırıyoruz
          dolukoltuklar();
          printf("\n");
          printf("|A1| |A2| |A3| | ❤ | |A5| |A6|\n");
          printf("|B1| |B2| |B3| | ❤ | |B5| |B6|\n");
          printf("|C1| |C2| |C3| | ❤ | |C5| |C6|\n");
          printf("|D1| |D2| |D3| | ❤ | |D5| |D6|\n");
          printf("|E1| |E2| |E3| | ❤ | |E5| |E6|\n");
          printf("Lütfen almak istediğiniz koltuk sırasını giriniz(A-B-C-D-E):");
          scanf(" %c", &koltuksirasi[i]);
          if(koltuksirasi[i]=='A'||koltuksirasi[i]=='B'||koltuksirasi[i]=='C'||koltuksirasi[i]=='D'||koltuksirasi[i]=='E')
          {
          printf("Lütfen almak istediğiniz koltuk numarasını giriniz(1-2-3-4-5-6):");
          scanf(" %c",&koltuknumarasi[i]);
              if(koltuknumarasi[i]>48&&koltuknumarasi[i]<=55) // Numaraların ASCII karşılığını kontrol ediyoruz.
              {
                // ALINMIŞ KOLTUKLARI SATIR SATIR OKUYUP KONTROL EDİYORUZ Kİ ALINAN KOLTUKLARI TEKRAR ALAMASINLAR
                while (fgets(line, sizeof(line), koltuklar))
                {
                  if (line[0] == koltuksirasi[i])
                    if (line[1] == koltuknumarasi[i]) 
                    {
                    system("clear");
                    printf("Seçmiş olduğunuz koltuk zaten alınmış!\nBilet alma fonksiyonunun başında döndüreleceksiniz...\n\n");
                    biletal(); // Fonksiyonu tekrar çağırarak başa dönüyoruz.
                    }
                }
                // Eğer müşteri birden fazla bilet alıyorsa aldığı bilet ile bir önceki bilet aynı numaraya sahip olamaz
                if (koltuksirasi[i] == koltuksirasi[i-1] && koltuknumarasi[i] == koltuknumarasi[i-1]) 
                {
                  system("clear");
                  printf("Aldığınız koltuk bir önceki ile aynı numaraya sahip olamaz.\nFonksiyonun başına döndüreleceksiniz...\n\n\n");
                  biletal();
                }
                // Her şey doğru bir şekilde gerçekleşirse bilet kesimi başarıyla gerçekleşiyor.
                else 
                {
                  printf("Bilet kesimi başarılı.\n");
                }
              }
              // YANLIŞ BİR KOLTUK NUMARASI GİRİLİRSE HATA VERECEK OLAN ELSE FONKSİYONU
              else
              {
                printf("Lütfen geçerli bir değer giriniz! Bilet al fonksiyonunun başına döndüreleceksiniz...\n\n");
                system("pause");
                biletal();   
              } 
          }
          // YANLIŞ KOLTUK HARFİ GİRİLİRSE HATA VERECEK OLAN ELSE FONKSİYONU
          else
          {
            printf("Lütfen geçerli bir değer giriniz! Bilet al fonksiyonunun başına döndüreleceksiniz...\n\n");
            biletal();
          }
          fclose(filekoltuk);
        }
    }
        // Rastgele bir fatura numarası oluşturuyoruz.
        fatura=100000+rand()%899999; // 6 basamaklı rastgele bir sayı oluşturuyoruz bilet sorgusu için gerekecek.
        system("clear");
        printf("Aldığınız koltuklar:\n");
        for (int i=0; i<sayac; i++) {
            printf("%c%c ",koltuksirasi[i],koltuknumarasi[i]);
        }
        printf("\nToplam ödemeniz gereken ücret: %.2f₺\n\n", ucret);
        printf("Ödemeyi onaylıyor musunuz? [E-H]\n");
        scanf(" %c", &onay);
        if (onay=='E')
        {
        printf("Tebrikler bilet satın alma işlemi gerçekleştirdiniz.\n");
        FILE *filekoltuk;
        filekoltuk=fopen("veriler/koltuklar.txt","a");
        FILE *FileFatura;
        FileFatura=fopen("veriler/biletimigoster.txt","a");
          if(FileFatura==NULL)
          {
            printf("Dosya bulunamadı.");
          } 
          else
          {
            for(int i=0; i<sayac; i++)
          {
            fprintf(filekoltuk,"%c%c\n",koltuksirasi[i],koltuknumarasi[i]);
            printf("%d. Bilet numaranız:%d-%c%c\n",i+1,fatura,koltuksirasi[i],koltuknumarasi[i]);
            fprintf(FileFatura,"%d-%c%c-%c\n",fatura,koltuksirasi[i],koltuknumarasi[i],tip[i]);
          }
          fclose(FileFatura);
          fclose(filekoltuk);
          }
        printf("Ana menüye dönmek için 0 tuşuna basın.\n");
        scanf(" %c", &menudon);
          if (menudon=='0')
          {
            main();
          }
        }
        else if (onay=='H')
        {
        printf("Bilet satın alma işlemi iptal ediliyor.\n");
        sleep(2);
        }
  }
  return 0;
}
int biletimigoster() {
  int girdib;
  char biletno[6];
  char kod[6];
  int i = 1;
  int sonuc;
  char dosyaAdi[] = "veriler/biletimigoster.txt";

  FILE* file = fopen(dosyaAdi, "r"); 

  if(!file){
  printf("\n Bilet verileri okunurken hata oluştu!");
  return -1;
  }
  char line[500];
  printf("6 Haneli bilet numaranızı giriniz: ");
  scanf("%s", biletno); 
  printf("\nBu bilet koduna sahip olan aktif biletler: \n\n"); 
  while (fgets(line, sizeof(line), file)) {
  sonuc = 0;
  for (int i= 0;i<6;i++) { // Kaç tane sayının eşleştiğini gösterir.
    if (line[i] == biletno[i]) {
      sonuc += 1;
    }
  }
  if (sonuc == 6) {
      printf("\t%d. Bilet Bilgileri\n",i);
      printf("Koltuk Numaranız: %c",line[7]);
      printf("%c\n",line[8]);
      if (line[10] == 'E') {
        printf("Bilet Tipi: Öğrenci\nBilet Ücreti: 10₺\n\n");
      }
      else {
        printf("Bilet Tipi: Yetişkin\nBilet Ücreti: 20₺\n\n");
      }
        i++;
    }
  }
  fclose(file);
  printf("\n\nAnamenüye dönmek için [0]\n");
  scanf("%d",&girdib);
  if (girdib == 0) {
    main();
  }
  return 0;
}
int koltuklar() {
    int girdik;
    char harf = 'A';
    char line[500];  
    char dosyaAdi[] = "veriler/koltuklar.txt";
    FILE* file = fopen(dosyaAdi, "r");     
    int i=0,j=0;    
    int arr[9][8] ={
    { 1, 2, 3, 4, 5, 6 },
    { 1, 2, 3, 4, 5, 6 },
    { 1, 2, 3, 4, 5, 6 },
    { 1, 2, 3, 4, 5, 6 },
    { 1, 2, 3, 4, 5, 6 }, };    
    printf("\t SİNEMA DOLULUK BİLGİLERİ\n");
    dolukoltuklar();
    printf("\nDolu Koltuk Sayısı: %d\n",ak);
    printf("Boş Koltuk Sayısı: %d\n\n",30-ak);

    printf("\tSalon Koltuk Düzeni \n");
    // 2 adet for döngüsü kullanarak sinema düzenini bastırıyoruz.
    for(i=0;i<5;i++){   
    for(j=0;j<6;j++){
      if (j == 3) {
        printf("| ❤ | "); 
      }
      else {    
      printf("|%c%d| ",harf,arr[i][j]);
      }
      }   
    printf("\n");
    harf++;
    }
    printf("  (❤ = Sevgili Koltukları)");   
    printf("\n\nAna Menüye dönmek için: [0]\n");
    scanf("%d", &girdik);
    if (girdik == 0) {
      main();
    }
    return 0; 
}
int vizyondakiler() {
  system("clear");
  int i = 1;
  char line[max];
  int vizyon_onay;
  char film_verileri[500];
  FILE *filmler = fopen("veriler/filmler_db.txt","r");
  if (filmler == NULL) {
    printf("Filmler dosyasından veri okunurken bir hata oluştu");
  }
  else {
    printf("\t Aktif Olarak Gösterimdeki Filmler\n\n");
    while (fgets(line, sizeof(line), filmler)) {
      if (i == 1) {
        printf("Aktif Film: %s",line);
      }
      else {
        printf("Gelecek Film: %s",line);
      }
      i++;
    }
    fclose(filmler);
    printf("\n\nAna Menüye dönmek için: [0]\n");
    scanf("%d", &vizyon_onay);
    if (vizyon_onay == 1) {
      main();
    }
  }
  return 0;
}
void dolukoltuklar() {
    ak = 0;
    char line[100];
    FILE *file=fopen("veriler/koltuklar.txt","r");
    printf("\n Satın Alınmış (Dolu) Koltuklar:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s",line);
        ak++;
      }
}
int yoneticipaneli() {
  int girdi2;
  int password,sifre;
  char filmadi[30];
  FILE *sifre_db = fopen("veriler/sifre_db.txt","r");
  fscanf(sifre_db,"%d", &sifre);
  fclose(sifre_db);
  printf("Lütfen yönetici paneli için şifreyi giriniz: \n");
  scanf("%d", &password);
  if ( password == sifre) {
    printf("Şifreniz doğrulandı.");
    printf("\n   Lütfen yapmak istediğiniz işlemi tuşlayınız.\n");
    printf(" ================================================\n");
    printf("|| Film eklemek için:\t\t\t\t\t\t[1]||\n");
    printf("|| Film çıkarmak için:\t\t\t\t\t\t[2]||\n");
    printf("|| Şifre değişmek için:\t\t\t\t\t\t[3]||\n");
    printf("|| Verileri sıfırlamak için:\t\t\t\t[4]||\n");
    printf("|| Ana menüye dönmek için:\t\t\t\t\t[5]||\n");
    printf(" ================================================\n");
    printf("\n");
    printf("\n");
    printf("Seçimizini giriniz [1-5]: ");
    scanf("%d", &girdi2);
    getchar();
          switch(girdi2) {
          case 1:
            system("clear");
            filmekle();       
            break;
          case 2:
            system("clear");
            filmcikar();
            break;
          case 3:
            system("clear");
            sifredegis();
            break;
          case 4:
            system("clear");
            sifirla();
            break;
          case 5:
            printf("Ana menüye dönülüyor...\n");
            main();
            break;
          default:
            printf("\n");
            printf("Geçersiz bir girdi girişi yaptınız.\n");
            sleep(2);
            printf("\n");
            system("clear");
            yoneticipaneli();
            break;
          }
         }
  else {
    if(girissayac == 2) // 3 kere yanlış girilirse sistemin en başına dönüyoruz.
      {
        printf("Üç kere yanlış şifre girdiğiniz için sistemden atıldınız.");
        main();
      }
    girissayac++;
    printf("Şifreniz yanlış!\n");
    yoneticipaneli();
  }
  return 0;
} 
int filmekle() {
  char filmadi[50];
  printf("Eklemek istediğiniz film adını giriniz:  ");
  fgets(filmadi, 50, stdin);
  FILE *filmler_db = fopen("veriler/filmler_db.txt","a");
  if (filmler_db == NULL) {
    printf("Filmler dosyası oluşturulurken bir hata oluştu");
  }
  else {
    fprintf(filmler_db,"%s", filmadi);

    fclose(filmler_db);

  }
  return 0;
}
int filmcikar() {
  int girdif;
  int silinen_satir;
  int i= 1,x = 1;
  char line[max];
  char silinen_s[max];
  FILE *filmler = fopen("veriler/filmler_db.txt","r+");
  while (fgets(line, sizeof(line), filmler)) {
    printf("%d. %s",i,line);
    i++;
  }
  fclose(filmler);
  printf("\nSilinmesini istediğiniz filmin satır numarasını giriniz: ");
  scanf("%d", &silinen_satir);
  FILE *silinenler = fopen("veriler/filmler_db.txt","r+");
  FILE *yenifilmler=fopen("veriler/yenifilmler.txt","w");
  while (fgets(line, sizeof(line), silinenler)) {
    if(x==silinen_satir)
    {
      printf("%d. film başarıyla silinmiştir\n",x);
    }
    else
    {
      fprintf(yenifilmler,"%s",line); // silinen film hariç her şey geçici olan yenifilmler.txt dosyasına yazılıyor.
    }
    x++;
  }
  fclose(yenifilmler);
  fclose(silinenler);
  FILE *dosya1 = fopen("veriler/filmler_db.txt","w");
  FILE *dosya2 = fopen("veriler/yenifilmler.txt","r");
  while (fgets(line, sizeof(line), dosya2)) {
    fprintf(dosya1,"%s",line); // geçici olan yenifilmler.txt dosyasını olduğu gibi asıl dosyaya aktarıyoruz.
  }
  fclose(dosya1);
  fclose(dosya2);
  printf("\n\nAna Menüye dönmek için: [0]\n");
  scanf("%d", &girdif);
  if (girdif == 0) {
      main();
    }
    return 0;
}
int sifirla() {
  // Alınmış tüm bilet verilerini sıfırlar, ancak film verilerini sıfırlamaz.
  FILE *biletler = fopen("veriler/biletimigoster.txt","w");
  fclose(biletler);
  FILE *koltuklar = fopen("veriler/koltuklar.txt","w");
  fclose(koltuklar);
  return 0;
}
int sifredegis() {
    int sifre;
    printf("4 haneli bir şifre giriniz [1-9]: ");
    scanf("%d",&sifre);
    FILE *sifre_db = fopen("veriler/sifre_db.txt","w"); // Şifre dosyasını açıyoruz
    if(sifre>=0000 && sifre<=9999) // şifrenin 4 haneli olmasını sağlıyoruz.
    {
     fprintf(sifre_db,"%d",sifre); // girilen şifreyi dosyaya yazıyoruz.
     printf("Şifreniz %d olarak başarıyla kaydedilmiştir.",sifre);
     fclose(sifre_db); // dosyamızı kapatıyoruz.
    }
    else
    {
    printf("Şifreniz 4 haneli bir sayıdan oluşmalıdır!");
    }
  return 0;
}
