# Instaliranje paketa pomoću Redhat Package Manager (RPM)

**RPM (Red Hat Package Manager)** je efikasan sistem za rukovanje sa paketima koji može da se pokrene u komandnom interpreteru. 

Služi za instaliranje, deinstaliranje, proveravanje, ispitivanje i osvežavanje paketa. Svaki paket se sastoji iz kompresovanih fajlova i informacija o paketu (to su: broj verzije, opis, osobine).

Ime paketa izgleda ovako: `ime_paketa.verzija.arhitektura[.distribucija].rpm`.

Komandi:
> Informacije se traže pomoću naredbe `rpm -q <ime fajla>`, gde je `-q` skraćenica od query (upit).
> 
> Uvek pisemo `-q`

1. Pomoću opcije `-f` se može saznati kom paketu pripada fajl koji je na računaru
```
rpm -qf /bin/ls

coreutils-5.97-11

```
2. Informacije o instaliranim rpm paketima se traže takođe sa opcijom `-q`, ali se sada priključuje opcija `-i` (information).
```
rpm -qi autofs

Name : autofs
Relocations : (not relocatable)
Version : 5.0.1
Vendor  : Red Hat, Inc.
...
```
3. Svi fajlovi se listaju pomoću opcije `-l` (list).
```
rpm -ql coreutils

/bin/basename
/bin/cat
/bin/chgrp
/bin/chmod
...
```
> Ako se izlistava paket koji nije instaliran, dobija se poruka o grešci:
```
rpm -ql mc
package autorun is not installed
```