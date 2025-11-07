PROCESSOR		16f84
#include		"p16f84.inc"
__CONFIG		_XT_OSC & _WDT_OFF & _PWRTE_ON & _CP_OFF

cblock 0x0c
	counter
endc

org		0x00
goto	Main

org		0x04
goto	Main

Main
	bsf		STATUS, RP0
	clrf	TRISB
	movlw	b'00000101'
	movwf	OPTION_REG
	bcf		STATUS, RP0
	clrf	PORTB
	bcf		INTCON, T0IF
	clrf	TMR0

myLoop1
	movlw	d'61'
	movwf	counter
	incf	PORTB

myLoop2
	btfss	INTCON, T0IF
	goto	$-1
	bcf		INTCON, T0IF
	decfsz	counter
	goto	myLoop2
	goto	myLoop1

end