#include <stdlib.h>
#include <stdio.h>


int main(){
char seg, ent; // seg = segmento; ent = entrada

// XOR: ~A&B | ~B&A = A soma exclusiva com B = A^B
scanf("%d", &ent);

// Mapeando cada bit da entrada
char A = ent&0x01?1:0;
char B = ent&0x02?1:0;
char C = ent&0x04?1:0;
char D = ent&0x08?1:0;

// Calculando a sa�da, conforme mapas de Karnaugh feitos na aula de Eletr�nica Digital
char a = D|B|!(A^C);
char b = !C|!(A^B);
char c = C|!B|A;
char d = D|((!A)^((!B)&C))|(B&(!C));
char e = !A&(B|!C);
char f = D|!B&C|(!A&(!B|C));
char g = (D|(C&!A))|B^C;

/*
O escravo Shiraga estava tentando fazer tudo sem declarar vari�veis, fez um c�digo enorme tudo literal, e deu infinitos problemas. J� cansado, o jovem escravo optou por armazenar
seus dados em vari�veis chars, e fez um c�digo mais organizado, que, teoricamente, n�o deixaria de ser poss�vel de se escrever em uma linha.

INFINITAS TENTATIVAS:

a = ent&0x08?1:0|~((~ent&0x02?1:0)&(ent&0x01?1:0^ent&0x04?1:0));
b = ~(ent&0x04?1:0&(ent&0x01?1:0^ent&0x02?1:0));
c = ent&0x04?1:0|~ent&0x02?1:0|ent&0x01?1:0;
d = (ent&0x08?1:0|((~ent&0x01?1:0)^(~(ent&0x02?1:0|~ent&0x04?1:0))))|(ent&0x02?1:0&~ent&0x04?1:0);
e = ~ent&0x01?1:0&(ent&0x02?1:0|~ent&0x04?1:0);
f = ent&0x08?1:0|~ent&0x02?1:0|ent&0x04?1:0|(~ent&0x01?1:0&~ent&0x02?1:0|ent&0x04?1:0);
g = (ent&0x08?1:0|(ent&0x04?1:0&ent&0x01?1:0))|ent&0x02?1:0^ent&0x04?1:0;

//seg = 1*((ent&0x08?1:0)|~((~ent&0x02?1:0)&((ent&0x01?1:0)^(ent&0x04?1:0))))+2*(~((ent&0x04?1:0)&((ent&0x01?1:0)^(ent&0x02?1:0))))+4*((ent&0x04?1:0)|((~ent&0x02?1:0)|(ent&0x01?1:0)))+8*(((ent&0x08?1:0)|((~ent&0x01?1:0)^(~((ent&0x02?1:0)|~(ent&0x04?1:0)))))|((ent&0x02?1:0)&~(ent&0x04?1:0)))+16*(~(ent&0x01?1:0)&((ent&0x02?1:0)|~(ent&0x04?1:0)))+32*((ent&0x08?1:0)|~((ent&0x02?1:0)|(ent&0x04?1:0)|(~(ent&0x01?1:0)&~(ent&0x02?1:0)|ent&0x04?1:0)))+64*(((ent&0x08?1:0)|((ent&0x04?1:0)&(ent&0x01?1:0)))|(ent&0x02?1:0)^(ent&0x04?1:0));
//seg = 1*(((ent&0x04?1:0)&(ent&0x02?1:0)^(ent&0x01?1:0)&(ent&0x04?1:0))|(ent&0x08?1:0)|(ent&0x02?1:0)|((!ent&0x01?1:0)&(!ent&0x04?1:0)))+2*(!((ent&0x04?1:0)&(ent&0x02?1:0)^(ent&0x01?1:0)&(ent&0x04?1:0)))+4*((!ent&0x01?1:0)&(!ent&0x02?1:0)|(!((!ent&0x01?1:0)&(!ent&0x04?1:0))))+8*((ent&0x08?1:0)|((ent&0x04?1:0)&(ent&0x02?1:0)^(ent&0x01?1:0)&(ent&0x04?1:0))|(!(ent&0x04?1:0)&(ent&0x02?1:0))|((!ent&0x01?1:0)&(!ent&0x04?1:0)))+16*((!(ent&0x01?1:0)&(ent&0x02?1:0))|((!ent&0x01?1:0)&(!ent&0x04?1:0)))+32*(((!ent&0x02?1:0)&(!ent&0x01?1:0))|(ent&0x08?1:0)|((ent&0x04?1:0)&(ent&0x02?1:0)^(ent&0x01?1:0)&(ent&0x04?1:0)))+64*((ent&0x04?1:0)|(ent&0x02?1:0)|(ent&0x08?1:0));

*/

seg = a+2*b+4*c+8*d+16*e+32*f+64*g; // Sa�da do display de 7 segmentos. As pot�ncias de 2 representam os bits ocupados no char.

// Operando bit a bit com os bin�rios correspondentes, determinamos se o bit correspondente � um 0 ou um 1.
printf("%d%d%d%d%d%d%d%d", seg&0x80?1:0, seg&0x40?1:0, seg&0x20?1:0, seg&0x10?1:0, seg&0x08?1:0, seg&0x04?1:0, seg&0x02?1:0, seg&0x01?1:0);

return 0;
}
