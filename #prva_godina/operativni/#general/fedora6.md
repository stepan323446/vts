# 18 aprila

# sudo su
Ulogu se kao root korisnik

* `cat &` - 
* `jobs` - Pokazuje koji procesi sada otvoreni za rad u terminalu
* `fg %1` - Otvoriti ovaj proces za daleće rad
```bash
~ cat > test.txt
First line
^Z # pause process

~ ls
# Jos neki komandi...
# pokazati svi procesi koji sada otvoreni
~ jobs
[1]  + suspended  cat >> test.txt // index 1
~ fg %1
Second line
^D # zatvoriti process
```

* `date` - Vreme trenutno
* `at -f <filename>` - 
* `atq` - 
* `ps` - procesi 
* `ps aux` - svi procesi koji nalazi u sisteme
* `` - slanje poruke procesima
* `kill %1 (term)` - završiti proces (poruka, a term je signal)
* *  `kill broj_proces/ime_procesa`
* * `kill -stop %1`, gde -stop je signal 
* * `kill -HUP broj_procesa` - 

## Poruka
1. Okončati proces `sleep 60 &`
2. Slanje u suspenduvno stanje
3. ponovo pokretanje (restart)

## Kontakt sa drugimi korisnicami
* `last` - poslednji koji ulogu se
* `w` - 
* `write (korisnik) (broj_terminala)`
* `mail (ime_korisnika)`
* * `mail -d <broj>` - delete mail
* * `mail -q` - quit