# Particiji

Jedan hard disk može da se podeli u više logičkih celina koje se nazivaju particijama. Ove jedinice opisuje tabela particija.

Sistem Linux-a može da se postavi i sa jednom particijom ali radi boljih performansi umesto swap fajla trebalo bi koristiti drugu particiju. U slučaju servera zbog sigurnosti svrsishodno je ceo sistem podeliti u celine i instalirati na posebne particije.

Preporučuje se korišćenje programa `fdisk` za rukovanje tabelom particija.

* [Informacija o disku](#informacija-o-disku)
* [Upravljanje sa diskom](#upravljanje-sa-diskom)
    * [Kreiranje sistema datoteka](#kreiranje-sistema-datoteka)
    * [Kreiranje particiji](#kreiranje-particiji)
* [Konverzija sistema datoteka ext2 na ext3](#konverzija-sistema-datoteka-ext2-na-ext3)

## Informacija o disku

Dabi pokazati svi uređaji i particiji sa informacije
```shell
fdisk -l
```

```c
//// Prvi disk
// Naziv diska i kolicina
Disk /dev/nvme0n1: 465,76 GiB, 500107862016 bytes, 976773168 sectors
// Model diska
Disk model: KINGSTON SNV2S500G                      
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: dos
Disk identifier: 0xbadc748a

// Particiji
Device         Boot     Start       End   Sectors   Size Id Type
/dev/nvme0n1p1           2048 586149887 586147840 279,5G 83 Linux
/dev/nvme0n1p2      586149888 976769023 390619136 186,3G  7 HPFS/NTFS/exFAT


//// Drugi disk
Disk /dev/nvme1n1: 476,94 GiB, 512110190592 bytes, 1000215216 sectors
Disk model: SKHynix_HFS512GD9TNI-L2A0B              
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: gpt
Disk identifier: 8725A2ED-A50A-47D1-B47A-D2D746A9D4A9

// Particiji
Device             Start        End   Sectors   Size Type
/dev/nvme1n1p1      2048     534527    532480   260M EFI System
/dev/nvme1n1p2    534528     567295     32768    16M Microsoft reserved
/dev/nvme1n1p3    567296  706538699 705971404 336,6G Microsoft basic data
/dev/nvme1n1p4 706539520  717029143  10489624     5G Microsoft basic data
/dev/nvme1n1p5 998166528 1000214527   2048000  1000M Windows recovery environmen
/dev/nvme1n1p6 717029376  719126527   2097152     1G Linux filesystem
/dev/nvme1n1p7 719126528  998166527 279040000 133,1G Linux filesystem

Partition table entries are not in disk order
```
> Za samo jedan uređaj, a ne svi koristimo `fdisk -l <device>`
```shell
fdisk -l /dev/nvme1n1
```

## Upravljanje sa diskom

Davi početi raditi sa diskom treba napisati komandu 

```shell
fdisk <device>

fdisk /dev/spa
```
Naziv uređaja obično **/dev/hd[a-h]** u slučaju diskova tipa IDE, a **/dev/sd[a-p]** u slučaju diskova tipa SCSI.

> Nakon izdavanja ove naredbe program daje prompt i čeka na naredbe. Lista mogućih naredbi se može tražiti tasterom `m`. Najčešće korišćene naredbe:

| taster | opis | на русском | 
| ------ | ---- | ---------- |
| a | Podešavanje boot particije (bootable) | включение или выключения флага boot для раздела;
| d | Brisanje particije (delete) | удалить раздел |
| l | Listanje podržanih tipova particija (list) | вывести список известных типов разделов;
| m | Pomoć (manual) | Помощь 
| n | Kreiranje nove particije (new) | создать новый раздел;
| p | Pregled aktuelne tabele particija (print) | вывести таблицу разделов;
| q | Izlaz bez snimanja (quit) | выйти без сохранения;
| t | Promena tipa particije (type) | изменение типа раздела;
| v | Provera tabele particija (verify) | Проверка таблицы разделов
| w | Izlaz sa snimanjem promena (write) | Записать новую таблицу разделов на диск;
| x | Samo za korisnike stručnjake dodatne funkcionalnosti (expert) | Дополнительная функциональность (только для экспертов)

### Kreiranje sistema datoteka

Naredba `mkfs` (make file system) služi za kreiranje sistema datoteka u Linux-u. (Umesto fajla uređaja može da se zadaje i direktorijum.)

```
mkfs -t <tip sistema datoteka> <fajl uredjaja>
```

* `-t` - tip sistema datoteka. Ako nema, to default je `ext2`

Naredba `mkfs` je ustvari front-end za razne programe koji prave sisteme fajlova. 

Ovi programi se nalaze u folderu `/sbin` pod imenom `mkfs.<fajl sistem>`. Pojedini fajl sistemi mogu imati različita podešavanja, zato pre korišćenja treba prostudirati stranice priručnika (manual) vezane za dati fajl sistem.

```
mkfs -t ext2 /dev/sda1
```

## Kreiranje particiji

Za kreiranje radimo sledeće koraci
> Već moramo imati slobodno mesto

1. Uznamo koji imamo diskovi
```
fdisk -l

Disk /dev/sda: 15.0 GB, 15020457984 bytes
...
```
2. Ulazimo u programu `fdisk` za `/dev/sda`
```
fdisk /dev/sda
```
3. Koristimo taster `n` (Kreiranje nove particije)
4. Sledeće pitanje je tip particije: **proširena (extended)** ili **primarna (primary)** particija. U ovom slučaju je moguće napraviti još jednu primarnu particiju jer je ova četvrta, a peta već mora biti proširena. Bira se dakle opcija `p` i zadaje se redni broj particije: **4**.
```shell
Command (m for help): n

Command action
 e extended
 p primary partition (1-4)

p
Selected partition 4
Using default value 13
```
___
> Glavna razlika između primarnih i proširenih particija je u tome što se prve mogu pokretati. Na disku ih ne može biti više od četiri. U međuvremenu, disk može imati onoliko logičkih particija koliko i MBR disk. Ali za razliku od primarnih particija, one ne mogu da skladište operativne sisteme.
> 
> Logičke particije se mogu kreirati **samo** unutar **proširene particije**.


> Основное различие между первичными и расширенными разделами заключается в том, что первые являются загрузочными. На диске их может быть не более четырех. Между тем, на диске может быть столько же логических разделов, сколько и на диске MBR. Но в отличие от первичных разделов, они не могут хранить операционные системы.
>
> Логические разделы можно создавать **только** внутри **расширенного раздела**.

![Grafik sa particijami unutar diska](https://i.stack.imgur.com/R0K32.png)

![Slika sa konsole](https://i.stack.imgur.com/ogLR0.png)

Kao što možete da vidite na slici, to govori time što daje kod, broj: 1-4 za primarne i proširene particije i 5+ za logičke particije. To je proširena particija koju sam označio crvenom bojom da bih istakao da logičke particije počinju brojem 5 odmah iza proširene particije.

> *Obično se koristi sledeća šema: 3 primarne particije, 1 proširena za logičku*
___
Odgobor, zašto ovde Linux nalazi na 6 particiji kao primarna:
![Imgur](https://imgur.com/q9kaxog.png)

**Koncept primarni particije** se primenjuje na oblasti tabele particija definisane **MBR (Master Boot Record)** standardima. U slučaju **GPT-a (GUID Partition Table)** particije nemaju tako očiglednu podelu na primarne i proširene.

**Stoga, u kontekstu GPT-a, sve particije se smatraju primarnim i ne postoji koncept primarnih i proširenih particija kao u MBR-u.** Na ovaj način, svaka particija (/dev/nvme1n1pKs) na vašem disku je primarna i nema potrebe da ih razlikujete kao primarne ili proširene.

**Понятие первичности разделов** применяется к областям таблицы разделов, определенным стандартами **MBR (Master Boot Record)**. В случае с **GPT (GUID Partition Table)**, которая используется на вашем диске, разделы не имеют такого явного разделения на первичные и расширенные.

**Поэтому, в контексте GPT, все разделы считаются основными, и нет концепции первичных и расширенных разделов, как в MBR.** Таким образом, каждый раздел (/dev/nvme1n1pX) на вашем диске является основным, и нет необходимости различать их как первичные или расширенные.
___

5. Podesite veličinu diska. Ukazujemo od i do.
```c
// koristimo default, nista ne pisemo
First cylinder (10-1044, default 10): 
Using default value 10
// dodamo +10GB
Last cylinder or +size or +sizeM or +sizeK (10-13, default 13): +10G
```
6. `w` - sačuvati promenu
7. `reboot` za restart pc
8. Nakon ponovnog pokretanja sistema kreira se sistema datoteka `ext2` na novoj particiji koja je dobila ime sda4.
```
mkfs -t ext2 /dev/sda4
```
9. Kreira se direktorijum gde se montira nova particija
```
mkdir /mnt/backup
```
10. Naredbom `mount` se nova particija uključuje u fajl sistem. Opcijom -t se određuje tip sistema datoteka mada to nije neophodno jer ga mount automatski prepoznaje. 
```
mount -t <typy_file_system> <particija> <mesto>

mount -t ext2 /dev/sda4 /mnt/backup/
```

___
Posle mi možemo koristiti ovaj novu particiju u folderu `/mnt/backup` za obični stvari
```
cat > /mnt/backup/backup.txt
itd...
```
Svi mounted particiji mi mozemo gledati kroz komandu `mount`.
```
mount
/dev/sda2 on / type ext3 (rw)
proc on /proc type proc (rw)
...
/dev/sda4 on /mnt/backup type ext2 (rw)
```

## Konverzija sistema datoteka ext2 na ext3
