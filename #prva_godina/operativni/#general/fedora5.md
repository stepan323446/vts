# 11 April

## Arhiviranje podataka

**Kreiranje archive**
```
tar -cf <archive_name>.tar <filename>
```
* `-c` - create
* `-f` - file
* `-t` - pogledati unutra archive (bez \<filename\>)
* `-v` - više informaciji za -t
* `-r` - 
* `-x` - unpack archive
* `-w` - pdtvrda da li treba unpack

**Unutra archive**

## Kompresija
```
gzip <filename> 
```
* `-l` informacija o kompresiji

Za kreiranje archive i zajedno kompresija:
```
tar -z <filenames>
```
* `-z` - kompresija

## Dekompresija
```
gunzip <zip_fajl>
```

> \<filenames\> - može biti i regex format

## find

```
find / -name '*naslov*' -print 2>/dev/null
```
* `-name`
* `-print`
* `o` ili or

## sed

## Koliko fajlvoa trenutno u direktoriji

```
echo `ls | wc -l` > nf.txt
cat nf.txt
```

## Korisniki

* `who` - broj korisnika trenutno

`sh nf.txt` - ?
