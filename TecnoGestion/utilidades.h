#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

bool SioNo(){
int opc=30, aux;
bool ger;
rlutil::locate(39,17);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(BLACK);
cout<<"SI";
rlutil::setBackgroundColor(FONDO);
rlutil::locate(43,17);
rlutil::setColor(LETRA);
cout<<"NO";
aux=1;
while(aux!=0){
switch(rlutil::getkey()){
case KEY_LEFT:
    aux++;
    opc=39;
rlutil::locate(opc,17);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(BLACK);
cout<<"SI";
rlutil::setBackgroundColor(FONDO);
rlutil::locate(43,17);
rlutil::setColor(LETRA);
cout<<"NO";
break;
case KEY_RIGHT:
   aux++;
    opc=43;
rlutil::setBackgroundColor(FONDO);
rlutil::locate(39,17);
rlutil::setColor(LETRA);
cout<<"SI";
rlutil::locate(opc,17);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(BLACK);
cout<<"NO";
break;
case KEY_ENTER:
    aux=0;
break;
}

}
if(opc==39){
ger=false;
}
else{
    if(opc==43){
    ger=true;
    }

}
return ger;
}


///COLOR CAMBIO DE FONDO DE PALABRA:

void listaColor(int tam){
switch(tam){
case 1:
rlutil::locate(36, 13);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"1. ARTICULOS";
    break;
case 2:
rlutil::locate(36, 14);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"2. CLIENTES";
    break;
case 3:
rlutil::locate(36, 15);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"3. VENTAS";
    break;
case 4:
rlutil::locate(36, 16);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"4. BACKUP";
    break;
case 0:
rlutil::locate(36, 17);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"0. FIN DEL PROGRAMA";
    break;
}
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
}

void listaColorVerde(int tam){

switch(tam){
case 1:
rlutil::locate(36, 13);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"1. ARTICULOS";
    break;
case 2:
rlutil::locate(36, 14);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"2. CLIENTES";
    break;
case 3:
rlutil::locate(36, 15);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"3. VENTAS";
    break;
case 4:
rlutil::locate(36, 16);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"4. BACKUP";
    break;

case 0:
rlutil::locate(36, 17);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"0. FIN DEL PROGRAMA";
    break;
}
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
}

void busq(int yo, int tam){
int i;

for(i=0;i<=tam;i++){
    if(i!=yo){
        listaColorVerde(i);
    }
    else{
    listaColor(yo);
    }

}

}
///COLOR PARA ARTICULOS:

void listaColorArticulo(int tam){
switch(tam){
case 1:
rlutil::locate(36, 13);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"1. AGREGAR ARTICULOS";
    break;
case 2:
rlutil::locate(36, 14);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"2. LISTAR ARTICULO POR ID";
    break;
case 3:
rlutil::locate(36, 15);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"3. LISTAR TODOS LOS ARTICULOS";
    break;
case 4:
rlutil::locate(36, 16);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"4. MODIFICAR PRECIO";
    break;
case 5:
rlutil::locate(36, 17);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"5. BAJA LOGICA";
    break;
case 0:
rlutil::locate(36, 18);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"0. VOLVER AL MENU PRINCIPAL";
    break;
}
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
}

void listaColorVerdeArticulo(int tam){

switch(tam){
case 1:
rlutil::locate(36, 13);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"1. AGREGAR ARTICULOS";
    break;
case 2:
rlutil::locate(36, 14);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"2. LISTAR ARTICULO POR ID";
    break;
case 3:
rlutil::locate(36, 15);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"3. LISTAR TODOS LOS ARTICULOS";
    break;
case 4:
rlutil::locate(36, 16);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"4. MODIFICAR PRECIO";
    break;
case 5:
rlutil::locate(36, 17);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"5. BAJA LOGICA";
    break;
case 0:
rlutil::locate(36, 18);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"0. VOLVER AL MENU PRINCIPAL";
    break;
}
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
}


void busqArticulo(int yo, int tam){
int i;

for(i=0;i<=tam;i++){
    if(i!=yo){
        listaColorVerdeArticulo(i);
    }
    else{
    listaColorArticulo(yo);
    }

}

}

///COLOR PARA CLIENTES:

void listaColorCliente(int tam){
switch(tam){
case 1:
rlutil::locate(36, 13);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"1. AGREGAR CLIENTE";
    break;
case 2:
rlutil::locate(36, 14);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"2. LISTAR CLIENTE POR DNI";
    break;
case 3:
rlutil::locate(36, 15);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"3. LISTAR TODOS LOS CLIENTES";
    break;
case 4:
rlutil::locate(36, 16);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"4. MODIFICAR EMAIL";
    break;
case 5:
rlutil::locate(36, 17);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"5. ELIMINAR CLIENTE";
    break;
case 0:
rlutil::locate(36, 18);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"0. VOLVER AL MENU PRINCIPAL";
    break;
}
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
}

void listaColorVerdeCliente(int tam){

switch(tam){
case 1:
rlutil::locate(36, 13);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"1. AGREGAR CLIENTE";
    break;
case 2:
rlutil::locate(36, 14);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"2. LISTAR CLIENTE POR DNI";
    break;
case 3:
rlutil::locate(36, 15);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"3. LISTAR TODOS LOS CLIENTES";
    break;
case 4:
rlutil::locate(36, 16);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"4. MODIFICAR EMAIL";
    break;
case 5:
rlutil::locate(36, 17);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"5. ELIMINAR CLIENTE";
    break;
case 0:
rlutil::locate(36, 18);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"0. VOLVER AL MENU PRINCIPAL";
    break;
}
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
}


void busqCliente(int yo, int tam){
int i;

for(i=0;i<=tam;i++){
    if(i!=yo){
        listaColorVerdeCliente(i);
    }
    else{
    listaColorCliente(yo);
    }

}

}

///COLOR PARA VENTAS:

void listaColorVenta(int tam){
switch(tam){
case 1:
rlutil::locate(36, 13);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"1. CARGAR VENTA";
    break;
case 2:
rlutil::locate(36, 14);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"2. MOSTRAR VENTAS";
    break;
case 3:
rlutil::locate(36, 15);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"0. MENU PRINCIPAL";
    break;

}
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
}

void listaColorVerdeVenta(int tam){

switch(tam){
case 1:
rlutil::locate(36, 13);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"1. CARGAR VENTA";
    break;
case 2:
rlutil::locate(36, 14);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"2. MOSTRAR VENTAS";
    break;
case 3:
rlutil::locate(36, 15);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"0. MENU PRINCIPAL";
    break;

}
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
}


void busqVenta(int yo, int tam){
int i;

for(i=1;i<=tam;i++){
    if(i!=yo){
        listaColorVerdeVenta(i);
    }
    else{
    listaColorVenta(yo);
    }

}

}
///COLOR PARA BACKUPS:

void listaColorBackup(int tam){
switch(tam){
case 1:
rlutil::locate(20, 13);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"1. HACER COPIA DE SEGURIDAD DEL ARCHIVO DE ARTICULOS";
    break;
case 2:
rlutil::locate(20, 14);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"2. HACER COPIA DE SEGURIDAD DEL ARCHIVO DE CLIENTES";
    break;
case 3:
rlutil::locate(20, 15);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"3. HACER COPIA DE SEGURIDAD DEL ARCHIVO DE VENTAS";
    break;
case 4:
rlutil::locate(20, 16);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"4. RESTAURAR EL ARCHIVO DE ARTICULOS";
    break;
case 5:
rlutil::locate(20, 17);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"5. RESTAURAR EL ARCHIVO DE CLIENTES";
    break;
case 6:
rlutil::locate(20, 18);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"6. RESTAURAR EL ARCHIVO DE VENTAS";
    break;
case 7:
rlutil::locate(20, 19);
rlutil::setBackgroundColor(YELLOW);
rlutil::setColor(0);
cout<<"0. MENU PRINCIPAL";
    break;
}
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
}

void listaColorVerdeBackup(int tam){
switch(tam){
case 1:
rlutil::locate(20, 13);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"1. HACER COPIA DE SEGURIDAD DEL ARCHIVO DE ARTICULOS";
    break;
case 2:
rlutil::locate(20, 14);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"2. HACER COPIA DE SEGURIDAD DEL ARCHIVO DE CLIENTES";
    break;
case 3:
rlutil::locate(20, 15);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"3. HACER COPIA DE SEGURIDAD DEL ARCHIVO DE VENTAS";
    break;
case 4:
rlutil::locate(20, 16);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"4. RESTAURAR EL ARCHIVO DE ARTICULOS";
    break;
case 5:
rlutil::locate(20, 17);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"5. RESTAURAR EL ARCHIVO DE CLIENTES";
    break;
case 6:
rlutil::locate(20, 18);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"6. RESTAURAR EL ARCHIVO DE VENTAS";
    break;
case 7:
rlutil::locate(20, 19);
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
cout<<"0. MENU PRINCIPAL";
    break;
}
rlutil::setBackgroundColor(GREEN);
rlutil::setColor(WHITE);
}


void busqBackup(int yo, int tam){
int i;

for(i=1;i<=tam;i++){
    if(i!=yo){
        listaColorVerdeBackup(i);
    }
    else{
    listaColorBackup(yo);
    }

}

}

///FIN COLOR
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            locate(i, j);
            setColor(colorLinea);
            setBackgroundColor(colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
    setlocale(LC_ALL, "spanish");
}

void LineaFinal(short iniX, short iniY, short ancho, short colorLinea=WHITE, short colorFondo=BLACK){
setlocale(LC_ALL, "C");
    int i, j=iniY;
    for(i=iniX; i<=iniX+ancho; i++){
            locate(i, j);
            setColor(colorLinea);
            setBackgroundColor(colorFondo);
            //Abajo izquierda
            if(i==iniX){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho){
                cout << (char) 188;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }

        }

    setlocale(LC_ALL, "spanish");


}

void separadorH(short iniX, short iniY, short ancho, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i;
    locate(iniX,iniY);
    cout<<(char)204;
    for(i=1; i<ancho; i++){
        cout<<(char)205;
    }
    cout<<(char)185;
    setlocale(LC_ALL, "spanish");
}

void separadorV(short iniX, short iniY, short alto, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i;
    locate(iniX,iniY);
    cout<<(char)203;
    for(i=1; i<alto; i++){
        locate(iniX,iniY+i);
        cout<<(char)186;
    }
    locate(iniX,iniY+alto);
    cout<<(char)202;
    setlocale(LC_ALL, "spanish");
}

bool AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;

	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ajustar el buffer al nuevo tamaño
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tamaño de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}

#endif // UTILIDADES_H_INCLUDED
