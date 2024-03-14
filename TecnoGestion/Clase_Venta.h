#ifndef CLASE_VENTA_H_INCLUDED
#define CLASE_VENTA_H_INCLUDED

/// Ventas_detalle:

///  Número de venta, ID artículo, Cantidad vendida, Importe(Acumulador)
class Venta_Detalle{
private:
    int Numero_Venta, ide_Articulo, Cant_Vendida;
    float importeIndi;
public:
/// sets()
    void setNumero_Venta(int ndve){Numero_Venta=ndve;}
    void setide_Articulo(int id){ide_Articulo=id;}
    void setCant_Vendida(int cven){Cant_Vendida=cven;}
    void setimporteIndi(float im){importeIndi=im;}
/// gets()
    int getNumero_Venta(){return Numero_Venta;}
    int getide_Articulo(){return ide_Articulo;}
    int getCant_Vendida(){return Cant_Vendida;}
    float getimporteIndi(){return importeIndi;}
/// Prototipos
    bool Cargar();
    void Mostrar();
    bool leerdeDisco(int t);
};

void Modificar_Stock(int idReg, int cvReg, int cv){
Articulo reg;
FILE *pArti;
int aux;
pArti=fopen("articulo.lgg", "rb+");
if(pArti==NULL){
    return;
}
aux=idReg-1;
reg=leerRegistro(aux);
reg.setStock(cvReg-cv);
fseek(pArti, aux*sizeof reg, 0);
fwrite(&reg, sizeof reg, 1, pArti);
fclose(pArti);
}

bool Comp_Estado(int t){
Articulo reg;
int pos=0;
while(reg.leerdeDisco(pos++)==1){
    if(t==reg.getID()){
        if(reg.getEstado()==false){
            return false;
        }
    }
}
return true;
}

bool Venta_Detalle::Cargar(){
Articulo reg;
int pos=0, m=0;
float c=0;
recuadro(20,POSMENUY, 40,8,LETRA,FONDO);
LineaMedio(20, 60, POSMENUY+2);
rlutil::locate(21, 11);
cout<<"NUMERO DE VENTA: "<<Numero_Venta;
rlutil::locate(21, 13);
cout<<"INGRESE ID ARTICULO: ";
cin>>ide_Articulo;
while(reg.leerdeDisco(pos++)==1){
    if(ide_Articulo!=reg.getID()){
    m++;
    }

}
/**
cout<<"m: "<<m<<endl;
cout<<"pos: "<<pos-1<<endl;
**/
if(m==pos-1){
    return false;
    }
if(Comp_Estado(ide_Articulo)==false){
    return false;
}
rlutil::locate(21,14);
cout<<"INGRESE CANTIDAD VENDIDA: ";
cin>>Cant_Vendida;
pos=0;

while(reg.leerdeDisco(pos++)==1){
    if(ide_Articulo==reg.getID()){
    if(Cant_Vendida>reg.getStock()){
   // cout<<"LIMITE DE STOCK SUPERADO"<<endl;
   // cout<<"ERROR DE ARCHIVO"<<endl;
    return false;
    }
    Modificar_Stock(reg.getID(), reg.getStock(), Cant_Vendida);
    c=Cant_Vendida*reg.getPrecio_Uni();
    cout<<"c: "<<c<<endl;
    }

}

importeIndi=c;
rlutil::locate(21, 15);
cout<<"IMPORTE: "<<importeIndi<<endl;
return true;
}

void Venta_Detalle::Mostrar(){
recuadro(20,POSMENUY, 40,6,LETRA,FONDO);
LineaMedio(20, 60, POSMENUY+2);
locate(21, 11);
cout<<"NUMERO DE VENTA: "<<Numero_Venta<<endl;
locate(21, 13);
cout<<"ID DE ARTICULO: "<<ide_Articulo<<endl;
locate(21, 14);
cout<<"CANTIDAD VENDIDA: "<<Cant_Vendida<<endl;
locate(21, 15);
cout<<"IMPORTE: "<<importeIndi<<endl;
}

bool Venta_Detalle::leerdeDisco(int pos){
FILE *pVenta;
    pVenta=fopen("ventaDetalle.lgg", "rb");

    if(pVenta==NULL){return false;}
    fseek(pVenta, pos*sizeof(Venta_Detalle), 0);
    bool leyo=fread(this,sizeof(Venta_Detalle),1,pVenta);

    fclose(pVenta);
    return leyo;
}

int Ultima_Posicion(int t){
Venta_Detalle reg;
FILE *pVenta;
pVenta=fopen("ventaDetalle.lgg", "rb");
if(pVenta==NULL){
    return -2;
}
fseek(pVenta, -sizeof reg, 2);
reg.setNumero_Venta(t);
fwrite(&reg, sizeof reg, 1, pVenta);
fclose(pVenta);
return reg.getNumero_Venta();
}

int consec_Ventasye(){
int c=1;
Venta_Detalle reg;
FILE *pVenta;
pVenta=fopen("ventaDetalle.lgg", "rb");
if(pVenta==NULL){
    return -2;
}
while(fread(&reg, sizeof reg, 1, pVenta)==1){
c++;
}

fclose(pVenta);
return c;
}



bool Grabar_Venta_Detalle(int t){
Venta_Detalle reg;
bool aux;
FILE *pVent;
pVent=fopen("ventaDetalle.lgg", "ab");
if(pVent==NULL){
    return false;
}
reg.setNumero_Venta(t);
aux=reg.Cargar();
if(aux==false){
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    rlutil::setColor(LETRA);
    cls();
    recuadro(30,POSMENUY-3, 30,2,LETRA,FONDO);
    locate(30+2, POSMENUY-2);
    cout<<"ERROR DE CARGA DE ARCHIVO"<<endl;
    return false;
}
fwrite(&reg, sizeof reg, 1, pVent);

fclose(pVent);


 return true;
}

bool ListarDetalle(){
Venta_Detalle reg;
FILE *pVent;
pVent=fopen("ventaDetalle.lgg", "rb");
if(pVent==NULL){
    return false;
}
while(fread(&reg, sizeof reg, 1, pVent)==1){
    reg.Mostrar();
}
fclose(pVent);
return true;
}

int fextra(){
Venta_Detalle reg;
Articulo obj;

int pos, c=0, aux, pos2;

pos=0;
while(reg.leerdeDisco(pos++)==1){
    pos2=0;
    while(obj.leerdeDisco(pos2++)==1){
        if(reg.getide_Articulo()==obj.getID()){
            aux=reg.getCant_Vendida()*obj.getPrecio_Uni();
        }
    }
    c+=aux;
}


return c;
}

void reinicio(){
Venta_Detalle reg;
FILE *pVenta;
int aux;
pVenta=fopen("ventaDetalle.lgg", "rb+");
if(pVenta==NULL){
    return;
}
while(fread(&reg, sizeof reg, 1, pVenta)==1){
aux=Ultima_Posicion(0);
reg.setNumero_Venta(aux);
reg.setCant_Vendida(0);
reg.setide_Articulo(0);
reg.setimporteIndi(0);
fwrite(&reg, sizeof reg, 1, pVenta);
}
fclose(pVenta);
}

void reinicio2(int t){
Venta_Detalle reg;
int aux, pos;
FILE *pVent;
pVent=fopen("ventaDetalle.lgg", "rb+");
if(pVent==NULL){
    return;
}
pos=0;
while(reg.leerdeDisco(pos++)==1){
    if(t==reg.getNumero_Venta()){
            aux=pos;
        aux=aux-1;
    reg.setNumero_Venta(0);
    reg.setimporteIndi(0);
    fseek(pVent, aux*sizeof reg, 0);
    fwrite(&reg, sizeof reg, 1, pVent);
    }
}


fclose(pVent);
}

char tecla(){
char opc;
int aux=0;

while(aux==0){

cout<<"TECLA INCORRECTA"<<endl;
    cout<<"¿SALIR? s/n";
    cin>>opc;
    if(opc=='s'){
        aux++;
    }

        if(opc=='n'){
            aux++;
        }

}

return opc;

}
/**
Número de venta, DNI del cliente ,Importe total venta ,Fecha de la venta ,Estado
**/

class Venta_Principal{
private:
int Numero_Venta2, dni_cliente;
float Importe_Total;
Fecha fVenta;
bool Estado;

public:
/// sets()
void setNumero_Venta2(int nv){Numero_Venta2=nv;}
void setdni_cliente(int dcli){dni_cliente=dcli;}
void setImporte_Total(float imp){Importe_Total=imp;}
void setfVenta(Fecha fv){fVenta=fv;}
void setEstado(bool est){Estado=est;}
///gets()
int getNumero_Venta2(){return Numero_Venta2;}
int getdni_cliente(){return dni_cliente;}
float getImporte_Total(){return Importe_Total;}
Fecha getfVenta(){return fVenta;}
///Prototipos
bool Cargar();
void Mostrar();
bool leerdeDisco(int t);
};
/// "EN EL INGRESO DE LA VENTA PRINCIPAL NO DEBE CAMBIAR EL NUMERO DE VENTA DETALLE"

bool Venta_Principal::Cargar(){
bool comp, ger=true;
int pos=0, extra=0, ci=0;
float c=0;
Venta_Detalle reg;
Articulo obj;
Cliente ppt;
recuadro(20,POSMENUY, 40,4,LETRA,FONDO);
LineaMedio(20, 60, POSMENUY+2);
locate(21,11);
cout<<"INGRESE NUMERO DE VENTA: "<<Numero_Venta2<<endl;
locate(21,13);
cout<<"INGRESE DNI DEL CLIENTE: ";
cin>>dni_cliente;
rlutil::setBackgroundColor(COLOR_PANTALLA);
cls();
while(ppt.leerdeDisco(pos++)==1){
    if(dni_cliente!=ppt.getDNI()){
       extra++;
    }
}
if(extra==pos-1){
    return false;
}
pos=0;
while(ger==true){
comp=Grabar_Venta_Detalle(Numero_Venta2);
if(comp==false){
        reinicio2(Numero_Venta2);
    return false;
}
rlutil::hidecursor();
LineaMedio(20, 60, POSMENUY+6);
rlutil::locate(30, 17);
cout<<(char)168<<"SALIR? ";
ger=SioNo();
rlutil::setBackgroundColor(COLOR_PANTALLA);
rlutil::setColor(LETRA);
cls();
}
while(reg.leerdeDisco(pos++)==1){
if(Numero_Venta2==reg.getNumero_Venta()){
c+=reg.getimporteIndi();
}
}
recuadro(20,POSMENUY, 40,8,LETRA,FONDO);
LineaMedio(20, 60, POSMENUY+2);
locate(21,11);
cout<<"INGRESE NUMERO DE VENTA: "<<Numero_Venta2<<endl;
Importe_Total=c;
locate(21, 13);
cout<<"IMPORTE TOTAL DE LA VENTA: ";
cout<<Importe_Total<<endl;
locate(21, 14);
cout<<"INGRESE FECHA DE VENTA: ";
fVenta.Cargar(21, 15);
Estado=true;
return true;
}

void Venta_Principal::Mostrar(){
if(Estado==true){
recuadro(20,POSMENUY, 40,5,LETRA,FONDO);
locate(21, 11);
cout<<"NUMERO DE VENTA: "<<Numero_Venta2<<endl;
locate(21, 12);
cout<<"DNI CLIENTE: "<<dni_cliente<<endl;
locate(21, 13);
cout<<"IMPORTE TOTAL DE VENTA: "<<Importe_Total<<endl;
locate(21, 14);
cout<<"FECHA DE VENTA: ";
fVenta.Mostrar();
}

}

bool Venta_Principal::leerdeDisco(int pos){
    FILE *pVenta;
    pVenta=fopen("ventaPrincipal.lgg", "rb");

    if(pVenta==NULL){return false;}
    fseek(pVenta, pos*sizeof(Venta_Principal), 0);
    bool leyo=fread(this,sizeof(Venta_Principal),1,pVenta);

    fclose(pVenta);
    return leyo;
}




int Ultima_Poside(int t){
Venta_Principal reg;
FILE *pVenta;
pVenta=fopen("ventaPrincipal.lgg", "rb");
if(pVenta==NULL){
    return -2;
}
fseek(pVenta, -sizeof reg, 2);
reg.setNumero_Venta2(t);
fwrite(&reg, sizeof reg, 1, pVenta);
fclose(pVenta);
return reg.getNumero_Venta2();
}

int consec_Ventade(){
int c=1;
Venta_Principal reg;
FILE *pVenta;
pVenta=fopen("ventaPrincipal.lgg", "rb");
if(pVenta==NULL){
    return -2;
}
while(fread(&reg, sizeof reg, 1, pVenta)==1){
c++;
}

fclose(pVenta);
return c;
}

bool Fecha_Inva(Fecha aux){
if(aux.getDia()<1&&aux.getDia()>31){
    if(aux.getMes()<1&&aux.getMes()>12){
        if(aux.getAnio()<1990){
            cout<<"FECHA INVALIDA"<<endl;
            return false;
        }
        else{
        cout<<"FECHA INVALIDA"<<endl;
        return false;
        }

    }
    else{
        cout<<"FECHA INVALIDA"<<endl;
        return false;
    }
}
else{
    if(aux.getMes()<1&&aux.getMes()>12){
        if(aux.getAnio()<1990){
        cout<<"FECHA INVALIDA"<<endl;
        return false;
        }
    }
    else{
        if(aux.getAnio()<1990){
        cout<<"FECHA INVALIDA"<<endl;
        return false;
        }
    }
}
    if(aux.getMes()==2){
                if(aux.getDia()>28){
                    cout<<"FECHA INVALIDA"<<endl;
                    return false;
                }
            }
return true;
}

bool Grabar_VentPrincipal(){
Venta_Principal reg;
int aux, extra;
bool escribio, dedo, inv;
FILE *pVent;
pVent=fopen("ventaPrincipal.lgg", "ab");
if(pVent==NULL){
    return false;
}
aux=consec_Ventade();
extra=Ultima_Poside(aux);
reg.setNumero_Venta2(extra);

dedo=reg.Cargar();

if(dedo==false){
    return false;
}
inv=Fecha_Inva(reg.getfVenta());
if(inv==false){
    reinicio2(reg.getNumero_Venta2());
    return false;
}
escribio=fwrite(&reg, sizeof reg, 1, pVent);
fclose(pVent);
return escribio;
}

bool Listar_VentPrincipal(){
Venta_Principal reg;
Venta_Detalle obj;
FILE *pVent, *p2;
pVent=fopen("ventaPrincipal.lgg", "rb");
p2=fopen("ventaDetalle.lgg", "rb");
if(pVent==NULL){
    return false;
}
if(p2==NULL){
    return false;
}
while(fread(&reg, sizeof reg, 1, pVent)==1){
    reg.Mostrar();
    while(fread(&obj, sizeof obj, 1, p2)==1){

        obj.Mostrar();

    }
}

fclose(pVent);
return true;
}

void ListarTodo(){
Venta_Principal reg;
Venta_Detalle obj;
int pos=0, pos2;
while(reg.leerdeDisco(pos++)==1){
    pos2=0;
    reg.Mostrar();
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    rlutil::setColor(LETRA);
    system("pause > nul");
    cls();
    while(obj.leerdeDisco(pos2++)==1){
    if(reg.getNumero_Venta2()==obj.getNumero_Venta()){
        obj.Mostrar();
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    rlutil::setColor(LETRA);
    system("pause > nul");
    cls();
    }

    }
}
}


#endif // CLASE_VENTA_H_INCLUDED
