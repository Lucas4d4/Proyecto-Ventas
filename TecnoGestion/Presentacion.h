#ifndef PRESENTACION_H_INCLUDED
#define PRESENTACION_H_INCLUDED


void Ascii(){
    setlocale(LC_ALL, "C");
int i;
for(i=0;i<255;i++){
cout<<(char)i;
cout<<" "<<i;
cout<<endl;
}

}

void MarcoCircular(int alto, int bajo, int anchoIni, int anchoFin){
int i, j, k;
setlocale(LC_ALL, "C");
/// LINEA MARCO VERTICAL PRIMERA
for(i=alto;i<=bajo;i++){
    if(i==alto){
    rlutil::locate(anchoIni, i);
    cout<<(char)201;
    }
    rlutil::locate(anchoIni, i);
    cout<<(char)186;
    if(i==bajo){
       rlutil::locate(anchoIni, i);
       cout<<(char)200;
    }
}
/// LINEA MARCO HORIZONTAL
for(j=anchoIni+1;j<=anchoFin-1;j++){
    rlutil::locate(j, alto);
    cout<<(char)205;
    rlutil::locate(j, bajo);
    cout<<(char)205;
}
/// LINEA MARCO VERTICAL SEGUNDA
for(k=alto;k<=bajo;k++){
    if(i==alto){
    rlutil::locate(anchoFin, k);
    cout<<(char)187;
    }
    rlutil::locate(anchoFin, k);
    cout<<(char)186;
    if(i==bajo){
       rlutil::locate(anchoFin, k);
       cout<<(char)188;
    }
}

}

void LineaMedio(int anchoIni, int anchoFin, int lineaMedio){
int i;
setlocale(LC_ALL, "C");
for(i=anchoIni;i<=anchoFin;i++){
    if(i==anchoIni){
        rlutil::locate(i, lineaMedio);
        cout<<(char)204;
    }
    else{
    rlutil::locate(i, lineaMedio);
    cout<<(char)205;
    }
    if(i==anchoFin){
    rlutil::locate(i, lineaMedio);
    cout<<(char)185;
    }
}

}


void Marco2(int t){
int i, k;
char vtitulo[]=" TECNO GESTION ";
int vtamano=strlen(vtitulo);
int vcentro=(((t-vtamano)/2)+1);
    locate(1,1);
    cout<<(char)201;
    locate(1,2);
    cout<<(char)186;
    locate(1,3);
    cout<<(char)186;
    locate(1,4);
    cout<<(char)186;
    locate(1,5);
    cout<<(char)200;
for(i=2;i<t;i++){

rlutil::locate(i,1);
cout<<(char)205;
rlutil::locate(i,5);
cout<<(char)205;
}
    rlutil::locate(t,1);
    cout<<(char)187;
    rlutil::locate(t,2);
    cout<<(char)186;
    rlutil::locate(t,3);
    cout<<(char)186;
    rlutil::locate(t,4);
    cout<<(char)186;
    rlutil::locate(t,5);
    cout<<(char)188;

for(k=2;k<vcentro;k++){

    if(k==vcentro-1){
    rlutil::locate(k,3);
    rlutil::setColor(7);
    cout<<vtitulo;
    }
    else{
    rlutil::locate(k,3);
    rlutil::setColor(rand()%12);
    cout<<vtitulo;
    }
Sleep(20);
}
    rlutil::setColor(WHITE);
}
/// ACA VA
void PalabraCent(int alto, int ncentro, char *pa){
int i;

for(i=1;i<ncentro;i++){
   if(i==ncentro-1){
    rlutil::locate(i, alto);
    rlutil::setColor(7);
   cout<<pa;
   }
   else{
   rlutil::locate(i,alto);
   rlutil::setColor(rand()%12);
   cout<<pa;
   Sleep(20);
   }

}

}


void Nombres(int t){
char vtitulo[]=" PROGRAMADOR: ";
int vtamano=strlen(vtitulo);
int vcentro=(((t-vtamano)/2)+1);
char vtitulo2[]=" GOMEZ LUCAS ";
int vtamano2=strlen(vtitulo2);
int vcentro2=(((t-vtamano2)/2)+1);
PalabraCent(16, vcentro, vtitulo);
PalabraCent(17, vcentro2, vtitulo2);

}

void Objetivo(int t){
///
char vtitulo[]=" PROGRAMA DE VENTA DE INSUMOS DE INFORMATICA ";
int vtamano=strlen(vtitulo);
int vcentro=(((t-vtamano)/2)+1);

PalabraCent(7, vcentro, vtitulo);

}

void MarcoMenu2(int alto, int bajo, int centam, int divido){
int i, anchoInicio, anchoFinal, j;
anchoInicio=divido-1;
anchoFinal=(centam+divido)-2;
rlutil::locate(anchoInicio,alto);
    cout<<(char)201;
    rlutil::locate(anchoInicio,alto+1);
    cout<<(char)186;
    rlutil::locate(anchoInicio,alto+2);
    cout<<(char)204;
    rlutil::locate(anchoInicio,alto+3);
    cout<<(char)186;
    rlutil::locate(anchoInicio,alto+4);
    cout<<(char)186;
    rlutil::locate(anchoInicio,alto+5);
    cout<<(char)186;
    rlutil::locate(anchoInicio,alto+6);
    cout<<(char)186;
    rlutil::locate(anchoInicio,bajo);
    cout<<(char)200;
for(i=anchoInicio+1;i<anchoFinal;i++){
rlutil::locate(i,alto);
cout<<(char)205;
rlutil::locate(i,bajo);
cout<<(char)205;
}
for(j=anchoInicio+1;j<anchoFinal;j++){
rlutil::locate(j,alto+2);
cout<<(char)205;
}
rlutil::locate(anchoFinal,alto);
    cout<<(char)187;
    rlutil::locate(anchoFinal,alto+1);
    cout<<(char)186;
    rlutil::locate(anchoFinal,alto+2);
    cout<<(char)185;
    rlutil::locate(anchoFinal,alto+3);
    cout<<(char)186;
    rlutil::locate(anchoFinal,alto+4);
    cout<<(char)186;
    rlutil::locate(anchoFinal,alto+5);
    cout<<(char)186;
    rlutil::locate(anchoFinal,alto+6);
    cout<<(char)186;
    rlutil::locate(anchoFinal,bajo);
    cout<<(char)188;
}


void Objetivo2(int t){
/// PROGRAMA PARA GESTIONAR
/// INFORMACION DE ARTICULOS, CLIENTES Y VENTAS
char vtitulo[]=" PROGRAMA PARA GESTIONAR INFORMACION DE: ";
int vtamano=strlen(vtitulo);
int vcentro=(((t-vtamano)/2)+1);
char vtitulo2[]="  - ARTICULOS ";
int vtamano2=strlen(vtitulo2);
int vcentro2=(((t-vtamano2)/2)+1);
char vtitulo3[]="  - CLIENTES ";
int vtamano3=strlen(vtitulo3);
int vcentro3=(((t-vtamano3)/2)+1);
char vtitulo4[]="  - VENTAS ";
int vtamano4=strlen(vtitulo4);
int vcentro4=(((t-vtamano4)/2)+1);
PalabraCent(9, vcentro, vtitulo);
PalabraCent(11, vcentro2, vtitulo2);
PalabraCent(12, vcentro3, vtitulo3);
PalabraCent(13, vcentro4, vtitulo4);
MarcoMenu2(8, 14, vtamano, vcentro);
}

void Continuar(int t){
char vtitulo[]=" PRESIONE TECLA PARA COMENZAR ";
int vtamano=strlen(vtitulo);
int vcentro=(((t-vtamano)/2)+1);
PalabraCent(23, vcentro, vtitulo);
}


#endif // PRESENTACION_H_INCLUDED
