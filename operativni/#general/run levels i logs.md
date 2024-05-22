# Pregled nivoa izvršavanja (run levels)

Nivo izvršavanja (run level) je indikator stanja init-a i preko toga celog sistema i određuje koji servisi se izvršavaju. 

Nivoi izvršavanja su označeni brojevima. Ne postoji univerzalno pravilo za izvršavanje korisničkih nivoa izvršavanja (2-5).

**Brojevi nivoa izvršavanja:**
| Broj | Opis |
| ---- | ---- |
| 0 | Zaustavljanje sistema (halt) |
| 1 | Jednokorisnički režim rada (single-user mode) |
| 2-5 | Korisnički definisano normalno izvršavanje |
| 6 | Ponovno pokretanje sistema (reboot) |

Nivoi izvršavanja se mogu konfigurisati u fajlu `/etc/inittab` na ovaj način: 
```
l2:2:wait:/etc/init.d/rc 2
```
1. `l2` - proizvoljna oznaka
2. `2` - ovaj red odnosi samo na 2. nivo izvršavanja
2. `wait` - znači da init samo jednom, kada ulazi u nivo izvršavanja treba da izvršava naredbu zadatu u četvrtom polju i treba da sačeka dok naredba ne završi sa radom
3. `/etc/init.d/rc 2` - pokrene bilo koje druge naredbe koji pokreću ili zaustavljaju procese koji definišu 2. nivo izvršavanja.    

    Naredba četvrtog polja radi sve poslove u vezi podešavanja nivoa izvršavanja. Pokreće servise koji se trenutno ne izvršavaju, zaustavlja one koji ne treba da se izvršavaju na datom nivou izvršavanja. Koje sve naredbe ovo obuhvata zavisi od date distribucije Linux-a i njenih mogućih modifikacija.


### Upravljanje

Naredbom `chkconfig` se uključuje ili isključuje neki proces po nivoima izvršavanja. 

Opcija `--list` izlistava trenutno stanje, iz ove dugačke liste se bira red koji sadrži ip6tables koristeći filtar grep.

```
chkconfig --list | grep ip6tables

isdn 0:off 1:off 2:on 3:on 4:on 5:off 6:off
```
Opcijom `--level` se određuje koji nivo izvršavanja se menja, sledi naziv servisa i potrebna akcija (`on` ili `off`):

```
[root@drvo1 ~]# chkconfig --level 5 ip6tables on
[root@drvo1 ~]# chkconfig --list | grep ip6tables

isdn 0:off 1:off 2:on 3:on 4:on 5:on 6:off
```

# Logs

U operativnom sistemu Linux programi koriste dva načina za unos u dnevnik njihovih informacija o radu ili o događajima. Jednostavnije ali manje fleksibilno rešenje je kada program zapisuje informacije u jedan ili više log fajlova koji su podešeni u konfiguracionom fajlu. Ovi log fajlovi se obično nalaze u direktorijumu `/var/log`, ili ako nisu tamo, svrsishodno je sistem tako konfigurisati da log fajlovi budu tamo.

sistemu se stalno izvršava servis `(daemon) syslogd`, koji može da prima događaje kako lokalno tako i preko mreže.

Konfiguracioni fajl servisa syslogd je `/etc/syslog.conf` koji određuje pravila logovanja. Svaki red pravila se sastoji od dva polja. Prvo polje služi za odabir grupe događaja na osnovu servisa i prioriteta događaja. Drugo polje određuje operaciju koju treba da izvrši syslog. Operacija je obično jedno ime fajla gde dati događaj treba da se sačuva.

Polje za odabir se deli na dva dela: `<servis>.<prioritet>`
* **Servis** može da se zadaje nekima od sledećih ključnih reči: *auth, authpriv, cron, daemon, kern, lpr, mail, news, syslog, user, uucp i local0-local7.*
* **Prioritet** se zadaje pomoću ključnih reči. Mogućnosti su (u rastućem redosledu): *debug, info, notice, warning, err, crit, alert, emerg.*
