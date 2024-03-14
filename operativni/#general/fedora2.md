# March 14

Opcije/naredbe (flags) za komandi

```
command -flag --hude-flag
```
* `-` skratčeno
* `--` osnovno

Takođe možna pisati nekoliko naredbe
```
ls -l -a

// isto kao
ls -la 
```

## ls

Opciji za `ls` komandu

- `-l` - pokazati vreme stvaranja i dozvoljenja sa prava
- `-a` - pokazati sve fajlovi (uključujuči sakrijeni)
- `-R` - reverse, pokazuje duže output šta unutra drugi foldera, koji u trenutnom folderu

> *Sakrieni fajlovi su fajlovi i direktoriji koji imaju na početku `.`. (Npr, `.vscode/`, `.logs.txt`)*

```
user@fedora$ ls -l

Totak 52
(1)d(2.0)rwxr-xr-x. 1 (2.1)steve-dekart (2.2)steve-dekart   (3)18 мар 14 13:27 (4)css
-rw-r--r--. 1 steve-dekart steve-dekart 1023 мар 14 12:51 index.html
...
```

1. **Prvi slovo pokazuje vrstu fajla:**
    - `d` - direktorija
    - `-` - fajl
    - `l` - link 

2. korisnik:grupa, kojem pripada ova direktorija/fajla

    * `rw-|r--|r--` - pokazuje šta dozvoljeno `korisniku|grupe|svim`. Broj pokazuje:

        * `0` `-` - ništa
        * `1` `x` - samo dostup za run (npr. neki skript). `execute`
        * `2` `w` - samo write
        * `3` `wx` - samo write i run
        * `4` `r` - samo read
        * `5` `rx` - samo read i run
        * `6` `rw` ' read i write
        * `7` `rwx` - read, write, run

3. **Broj `1023` pokazuje koliko bajt košta fajl (osim foldera)**

4. **Naziv fajla/foldera**

## mkdir

Opcije:

- `-p` - omogućava kreiranje nadređene folder zajedno sa ugnežđenom folderom `mkdir folder1/folder2`
- `-v` - pokazuje logs šta je bio stavarano
- `-m` - pravo (`-m700`, -> `drwx - -`)

```
user@fedora$ mkdir -pv -m700 test/nested_folder

mkdir: создан каталог 'test'
mkdir: создан каталог 'test/nested_folder'
```

## Brisanje foldera

Za brisanje foldera sa fajlovami umesto ~~rmdir~~ treba

```
rm -rf <folder>
```
gde:
* `-r` - reverse
* `-f` - brisanje bez pitanja

## Promena prava

* `chmod` - promena prava za folder *(može korisnik)*
* `chown` ' promena vladalaca (i može grupe) *(samo root)*
* `chgrp` - promena grupe *(samo root)*

Primeri:

**Za fajlovi:**
```
////// Za fajlovi

// Za korisnika
sudo chown <user/root> <file>

// Za grupu
sudo chgrp <group/root> <file>

// Za pravo
sudo chmod 764 <user/root> <file>

```
**Za folder:**
```
// Za korisnika
sudo chown -R <user/root> <folder>

// Za grupu
sudo chgrp -R <group/root> <folder>

// Za pravo
sudo chmod -R 764 <user/root> <folder>
```
---
> Za `chown` ima skratčena zapis promene i za korisnika, i za grupu
>> ``` sudo chown <user>:<group> <file/folder>```

---
Takođe imamo drugi zapis kao **who**
* `u` - user
* `g` - group
* `o` - drugi ljudi
* `a` - sve, šta gore

i šta potrebno **what**:
* `-` oduzeti pravo
* `+` dodati pravo
* `=` postaviti pravo

```
chmod u=rw,og=r new_file.txt

// znači, šta user ima pravo na readwrite, a grupa i ostale samo read
```

Drugi primari:
```
chmod a+x new_script.sh
=
chmod +x new_script.sh

chmod o-r *.html
chmod -R o-r *
...
```

