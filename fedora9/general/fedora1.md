# March 7

| Command | Description |
| ------- | ----------- |
| `ls` | pokazuje izgled trenutni direktoriji |
| `rm <fajl>` | uništa neki fajl (za direktoriju treba flag `-rf`) |
| `cd <path>` | pokazuje izgled trenutni direktoriji |
| `mkdir <dir>` | stvariti novu direktoriju |
| `rmdir <dir>` | uništa direktoriju |
| `pwd` | pokazuje trenutni put direktoriji |
| `cat` | pokaz šta unutra fajla/stvariti/dodati u fajl |
| `cp <old_fajl> <novi_fajl>` | kopiranje fajla |
| `mv <old_fajl> <novi_fajl>` | premestiti fajl u drugo mesto |

## Teorija

* Ne možete stavljati posebne znakove u nazive fajla
* Maksimalan broj znakova: 256

## cd

Prelazak iz trenutnog direktorijuma u ​​drugi

```
cd <path>
```

* `cd .` - trenutna direktorija
* `cd ../` - roditeljska direktorija (nazad)
* `cd ~` - početna (korisnička) direktorija
* `cd /` - korenski direktorija

**Primer**:
```
/
-- home/
-- -- steve/
-- -- -- my_project/
-- -- -- -- files/*
-- -- -- vts/
-- var/
-- etc/
-- usr/

* - u trenutnom folderu
```
* `cd ../` = /home/steve/my_project/
* `cd ~` = /home/steve/
* `cd /` = /
* `cd /var` = /var/
* `cd ~/vts` = /home/steve/vts/

**3 tipova:**
* `-` običan
* `d` dir/folder
* `l` - link

## cat

Pregledanje/napravinje/ažuriranje fajla

```
cat <fajl>
```
| Commands | Opis |
| -------- | ---- |
| `cat fajl.txt` | pogledati fajl |
| `cat > fajl.txt` | novi fajl |
| `cat >> fajl.txt` | dodati novi red u fajlu |

Dabi izađi iz editovanja, treba `Ctrl + D`

> Za editor i stvaranje bolje `nano <fajl>` ili `vim <fajl>` (vim treba instalirati)

## mv

Prenesenje fajla u drugo mesto

```
mv <old_path> <new_path>
```
> `new_path` potrebno pisati sa nazivom fajla

**Primeri:**
* `mv style.css static/css/style.css`
* `mv files/notes.txt notes.txt`

___
Mi možemo promeniti naziv fajla sa `mv`

`mv main.js script.js` - menjamo main.js na script.js

