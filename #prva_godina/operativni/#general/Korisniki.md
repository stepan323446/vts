# Korisniki

Svaki korisnik poseduje jedinstveni identifikator (UID – user identificator), i pripada jednoj ili više grupi (GID – group identificator). 

Ove informacije su sadržane u fajlovima `/etc/passwd` i `/etc/group`.

Postoji još i fajl `/etc/shadow`, koji sadrži kriptovane lozinke i može da ga čita **samo korisnik root**.

## Table of contents

* [Analiz informacije](#analiz-informacije)
    * [Korisnici (/etc/passwd)](#korisnici-etcpasswd)
    * [Lozinki (/etc/shadow)](#lozinki-etcpasswd)
    * [Grupe (/etc/group)](#grupe-etcgroup)
* [Upravljanje korisnicima](#upravljanje-korisnicima)
    * [Stvaranje korisnika](#stvaranje-korisnika)
        * [Promena podešavanija za korisnika](#promena-podešavanija-za-korisnika)
    * [Stvaranje lozinki](#stvaranje-lozinki-za-korisnika)
    * [Stvaranje grupe](#stvaranje-grupe)
        * [Promena podešavanija za grupu](#promena-podešavanija-za-grupu)
    * [Opšta komanda](#opšta-komanda)
    * [Brisanje korisnika/grupe](#brisanje-korisnika-i-grupe)


## Analiz informacije

### Korisnici (/etc/passwd)
Za pregled informacije za svih korisnika:
```shell
cat /etc/passwd
```
Osnovna baza podataka sistema Unix/Linux je fajl /etc/passwd, koji se naziva "fajl lozinki" (password file). U ovom fajlu se nalaze sva korisnička imena i informacije vezane za te korisnike.

Primer: 
```
steve-dekart:x:1000:1000:steve-dekart:/home/steve-dekart:/usr/bin/zsh

root:x:0:0:Super User:/root:/bin/bash

mysql:x:27:27:MySQL Server:/var/lib/mysql:/sbin/nologin
```

Svaka informacija podeljena između sobom simbolom `:`

`mysql:x:27:27:MySQL Server:/var/lib/mysql:/sbin/nologin`

* Username `mysql`
* Kriptovana lozinka `x`
* identifikator korisnika (uid – user identificator) `27`
* identifikator grupe (gid – group identificator) `27`
* puno ime korisnika ili neki drugi opis `MySQL Server`
* korisnički početni folder (home directory) `/var/lib/mysql`
* program koji treba da se prvo izvrši prilikom prijavljivanja (login shell) `/sbin/nologin`

### Grupe (/etc/group)
Grupe nalazi na `/etc/group`
```shell
cat /etc/group
```
Gde mi imamo:
```
323446:x:500:
axis:x:502:
```
* `axis` – naziv grupe
* `x` – polje za lozinku grupe; x označava da sistem koristi lozinku senku (shadow)
* `502` – identifikator grupe GID i obično se podudara sa UID istoimenog korisnika


---

### Lozinki (/etc/passwd)

> Mnogo sistema Linux, među ostalima i Fedora, poseduje mogućnost "lozinka senka" (shadow password): 

U ovom slučaju kriptovana lozinka se nalazi u posebnom fajlu pod imenom `/etc/shadow`, koji može da čita **samo korisnik root**

```shell
sudo cat /etc/shadow
```

Tada fajl `/etc/passwd` u drugom polju sadrži samo specijalan karakter `x`.

```
mysql:!:19827::::::

steve-dekart:$y$j9T$5SVNOAlJEMeO5XgFzZGUrWZZ$1qy/Rr1DHJD5yXdgMEzNIiAKfUJ0oHYbjB9ZxH9ipP7::0:99999:7:::
```

* Username `steve-dekart`
* Kriptovana lozinka *(*`!` *– Lozinka još nije zadata i dok se ne zada taj korisnik je blokiran)* `$y$j9T$5...`
* Broj dana od 1. januara 1970 godine kada je bila poslednja promena lozinke. `nista, nikada`
* Broj dana do tog dana kada se lozinka može promeniti (0 znači da se lozinka bilo kada može promeniti). `0`
* Broj dana nakon čega se lozinka mora promeniti (99999 znači da korisnik može da zadrži lozinku još 274 godine). `99999`
* Broj dana kada sistem treba da upozori korisnika da mu ističe lozinka (7 znači jednu nedelju) `7`
* Broj dana nakon čega se korisnikov nalog isključuje posle isteka lozinke `nista :`
*  Broj dana kada će nalog biti isključen računajući od 1. januara 1970 godine `nista :`
* rezervisano za buduću upotrebu

## Upravljanje korisnicima

Dabi promeniti korisnika:
```c
// na root
su

// na drugi korisnika
su - <korisnik>
```

### Stvaranje korisnika

Novi korisnici se prave pomoću naredbe `useradd` (ili `adduser`) koju može izdati **samo korisnik root**.

```shell
adduser aqua
```

> Naredba `useradd` pravi novog korisnika i ako se ne zadaju opcije pravi podrazumevana podešavanja. 

> Pravi korisnički direktorijum u folderu `/home` tako da samo vlasnik može ući u direktorijum i ima sve moguće dozvole (`rwx`)

> Novi red u `/etc/passwd`

Kada se napravi korisnički direktorijum za novog korisnika, sadržaj se pravi na osnovu foldera `/etc/skel`. 

Sadržaj novog direktorijuma `/home/<user>` je isti kao `/etc/skel`.

*U ovom direktorijumu administrator sistema može da kreira okruženje za nove korisnike, npr. može da se napravi fajl `/etc/skel/.profile` koji promenljivu shell-a **EDITOR***

```shell
ls -la /etc/skel/

drwxr-xr-x 3 root root 4096 Oct 5 2007 .
drwxr-xr-x 101 root root 12288 Apr 16 13:32 ..
-rw-r--r-- 1 root root 24 Jul 12 2006 .bash_logout
-rw-r--r-- 1 root root 176 Jul 12 2006 .bash_profile
-rw-r--r-- 1 root root 124 Jul 12 2006 .bashrc
drwxr-xr-x 3 root root 4096 Oct 5 2007 .gnome2
```
> `ls -la`, mi stavimo naredbu `-a` zbog skrivena fajlova

### Promena podešavanija za korisnika

Naredbom `usermod` se menjaju parametri već postojećeg naloga.

* `-G` Korisnik se prebacuje u drugu grupu opcijom 
* `-l` korisničko ime naloga se menja (login), 
* `-d` početni direktorijum se može menjati

> Pažnja! Kod opcije `–G` treba nabrojati sve grupe čiji je član dati korisnik, jer se korisnik briše iz onih grupa koje nisu navedene u listi!

> Внимание! С опцией `-G` должны быть перечислены все группы, членом которых является данный пользователь, поскольку пользователь удаляется из тех групп, которые не указаны!

```
usermod -G axis –d /home/axis_crkva kazuma
```

### Stvaranje lozinki za korisnika

Pomoću naredbe `passwd` korisnik root može da zadaje lozinku nekom korisniku koga treba zadati u parametru.

> **PAŽNJA!** Ako se naredba passwd zadaje bez parametra, tada se menja lozinka korisnika root!

```shell
passwd aqua
```
> Novi red u `/etc/shadow`



### Stvaranje grupe

U Linux-u grupe se mogu kreirati naredbom `groupadd` u karakterskom okruženju.

```shell
groupadd axis
```
> Novi red u fajlu `/etc/group`



### Promena podešavanija za grupu

Parametri grupe se mogu menjati naredbom `groupmod`.

* `-n` menja ime grupe (name)

```shell
groupmod -n axis2024 axis
```

```
usermod -G axis –d /home/axis_crkva kazuma
```

### Opšta komanda

Naredbu `adduser` treba pozvati sa dve opcije. 

* `-g` Dodaje sistemu tako da će ga staviti u grupu koja se navodi iza ove opcije; ova grupa će biti primarna grupa korisnika.
* `-d` korisniku dodeljuje početni direktorijum (koji je naveden iza ove opcije)

```shell
adduser -g axis -d /home/kazuma kazuma
```
> Početni direktorijum oba korisnika je postao `/home/kazuma` i primarna grupa im je `axis` čiji GID je ...:

> Kada sistem je pređi na korisnika, drugi nema dozvole da uđe na taj početni direktorijum. Izlistavanjem foldera `/home` se vidi da samo za vladalaca-korisnika, može ući u folder sa svim dozvolama.

### Brisanje korisnika i grupe

Brisanje naloga se vrši pomoću naredbi `userdel` i `groupdel`. 

> Naredba `userdel` ne briše početni direktorijum korisnika ako je zadata bez opcija.
>
> Opcija `-r` (recursive) briše i početni folder i mailbox.

```
groupdel axis
userdel -r kazuma
```

> Ako folder nije korisnika i/ili početni direktorijum koristi još drugi korisnik, to neće delete čas sa `-r`

```
drwx------ 3 514 514 4096 Apr 17 10:57 kazuma
```
Prilikom listanja direktorijuma `/home` umesto vlasnika direktorijuma `/home/kazuto` pojavljuje se samo stari broj indentifikatora korisnika meda (UID) tako pokazujući na to da taj korisnik više ne postoji.

