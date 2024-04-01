# March 28

## Znak >

Upisati nešto iz komandi u fajl
```
<command> > <filename>
```

Naprimer:
```
ls > files.txt
```

## Znak >>
Upisati na kraj fajla nešto novo
```
<command> >> <filename>
```

##  Filters

Dozvoljava upravljati output ili još nešto za komandu. Filter pišemo kroz znak `|`

```
<command> | <filter>
```

### | more
Pokazati postranično output `ls -l | more`
```
<command> | more
```

### | wc
Pokazati određenu količinu output
```
cat file.txt | wc
```
```
<broj_redova> <broj_reci> <broj_karaktera>
```

### | grep

Filter, koji pokazuje određeni lines, koji sadrži meki fragment

```
ls -l | grep <fragment>

ls -l | grep "minecraft.exe"
```
### | sort

Sortitanje 



## Regex (Regular izraz)

* `^` - pocetak reda 
* `$` - zavrsetak reda
* `?` - sve moze biti
* `[ ]` - negacija

```
ls 0?3*
ls [0-9][0-9]2*
```
```
echo "I like using regular expressions." | grep -Po 'r.*ar'
```
### Navodniki
* `''` - nepromenjene (ne mozemo koristiti variable)
* `""` - bred prvom (mozemo koristiti variable)
* `` - izvsrni navod. (mozemo koristiti komandi)

```
my_variable=dog

grep '$my_variable' // ce traziti sa $my_variable
grep "$my_variable" // ce traziti sa dog
grep `echo dog` // ce traziti sa dog
```