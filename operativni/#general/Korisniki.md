# Korisniki

Svaki korisnik poseduje jedinstveni identifikator (UID – user identificator), i pripada jednoj ili više grupi (GID – group identificator). 

Ove informacije su sadržane u fajlovima `/etc/passwd` i `/etc/group`.

Postoji još i fajl `/etc/shadow`, koji sadrži kriptovane lozinke i može da ga čita **samo korisnik root**.

## Table of contents

* [Analiz informacije](#analiz-informacije)
    * [Korisnici (/etc/passwd)](#korisnici-etcpasswd)
    * [Lozinki (/etc/shadow)](#lozinki-etcpasswd)
    * [Grupe (/etc/grouo)](#grupe-etcgroup)
* [Upravljanje korisnicima](#upravljanje-korisnicima)
    * [Stvaranje korisnika](#stvaranje-korisnika)


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
...

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

### Stvaranje korisnika

### 