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

Fajlovi za logs:
* `tail /var/log/maillog` - Svaka poruka mail servera se zapisuje
* `tail /var/log/secure` - Događaji o prijavama korisnika
* `tail /var/log/dmesq` - poruke koje je sistem zapisao tokom pokretanja
* `tail /var/log/boot` - Fajl boot.log sadrži događaje o pokretanju i zaustavljenju servisa (događaji koje šalju servis skriptovi iz direktorijuma /etc/rc.d/init.d).

___

Pored jednostavnog zadavanja para servis-prioritet postoje i dalje mogućnosti:
- Umesto servisa ili prioriteta može da se koristi karakter `*` koji označava sve servise odnosno sve prioritete. Ključna reč none na mestu prioriteta znači "nijedan".
- Može da se nabroji više servisa razdvojenih zarezima kod datog nivoa prioriteta.
- Moguće je zadati listu polja za odabir nekoj operaciji tako da se razdvajaju tačkazarezima. U ovom slučaju polja za odabir mogu modifikovati uticaj ranijih polja u listi.
- U slučaju da se želi izvršiti operacija samo za jedan dati nivo prioriteta, tada treba zadati znak "`=`" ispred imena prioriteta.
- Zadavanje prioriteta se može negirati pomoću znaka "`!`". Tada će syslog ignorisati sve prioritete koji su isti ili veći od zadatog.
- Znaci "=" i "!" mogu da se kombinuju u znak "`!=`". Značenje toga je da syslog ignoriše samo dati nivo prioriteta.
Mogućnosti za operaciju pored pisanja u fajl su:
- Mogućnost ispisivanja na konzolu (/dev/console).
- Mogućnost da se ispisuje na ekran nekih korisnika (korisnička imena razdvojena znakom ",").
- Ispis se šalje na ekran svih prijavljenih korisnika ("*").
- Ispis se preusmerava u cevovod (pipe) (ispred imena fajla znak "|").
- Ispis se šalje na centralni računar (iza znaka "@" ime host-a).

