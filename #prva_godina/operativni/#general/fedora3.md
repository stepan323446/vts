# March 21

## Linkovanje

Imamo 2 vrste veze

* Tvrde link `ln`
* Simboličke link `ln -s` (Mora biti apsolutni put za fajl)

A soft link or symbolic link will point to the original file on your system. A hard link will create a copy of the file.

## set

```
set
```

Pokazuje sve varijable

## echo 

```
echo <text>

echo $HOME // direktorija korisnika u /home/<user>
echo $PATH
echo $SHELL // komanda na put interpretora (/bin/bash ili /.zsh)
```

Pokazuje varijablu itd. 

## Varijable

Za stvaranje variable
```
picac='Ivo Andric'

echo $picac
```