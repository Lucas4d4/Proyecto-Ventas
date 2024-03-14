#ifndef CLASE_ARTICULO_H_INCLUDED
#define CLASE_ARTICULO_H_INCLUDED

class Articulo
{
private:
    int ID, Stock;
    char Descripcion[25];
    float Precio_Uni;
    bool Estado;
public:
    ///sets
    Articulo(int i=0, float pu=0.00, int s=0)
    {
        ID=i;
        Precio_Uni=pu;
        Stock=s;
    }
    Articulo(char *des)
    {
        strcpy(des, "NADA");
        strcpy(Descripcion, des);
    }
    void setID(int i)
    {
        ID=i;
    }
    void setDescripcion(char *des)
    {
        strcpy(Descripcion, des);
    }
    void setPrecio_Uni(float pu)
    {
        Precio_Uni=pu;
    }
    void setStock(int s)
    {
        Stock=s;
    }
    void setEstado(bool es)
    {
        Estado=es;
    }
    ///gets
    int getID()
    {
        return ID;
    }
    const char *getDescripion()
    {
        return Descripcion;
    }
    float getPrecio_Uni()
    {
        return Precio_Uni;
    }
    int getStock()
    {
        return Stock;
    }
    bool getEstado()
    {
        return Estado;
    }
    ///Prototipos
    void Cargar();
    void Mostrar(int c);
    bool leerdeDisco(int );
};



void Articulo::Cargar()
{
    int c=0;
    recuadro(1,1, 88,2,LETRA,FONDO);
    rlutil::locate(37,2);
    cout<<"AGREGAR ARTICULO";
    recuadro(1,4,88, 25, LETRA, FONDO);
    rlutil::locate(26, 5);
    cout<<"ID DE ARTICULO: ";
    cout<<ID;
    rlutil::locate(26, 6);
    cout<<"INGRESE DESCRIPCION: ";
    cin>>Descripcion;
    rlutil::locate(26, 7);
    cout<<"INGRESE PRECIO UNITARIO: ";
    cin>>Precio_Uni;
    while(Precio_Uni<0){
            c++;
        rlutil::locate(26, 7+c);
        rlutil::setBackgroundColor(12);
        cout<<"ERROR PRECIO UNITARIO INVALIDO"<<endl;
        c++;
        rlutil::locate(26, 7+c);
        rlutil::setBackgroundColor(FONDO);
        cout<<"INGRESE PRECIO UNITARIO: ";
        cin>>Precio_Uni;
    }
    rlutil::locate(26, 7+c+1);
    cout<<"INGRESE STOCK: ";
    cin>>Stock;
    Estado=true;
        rlutil::setBackgroundColor(1);
    system("cls");
}

void Articulo::Mostrar(int c)
{

    if(Estado==true)
    {
        recuadro(1, c+3, 88, 5, LETRA, FONDO);
        rlutil::locate(26,c+4);
        cout<<"ID: "<<ID;
        rlutil::locate(26,c+5);
        cout<<"DESCRIPCION: "<<Descripcion;
        rlutil::locate(26,c+6);
        cout<<"PRECIO UNITARIO: "<<Precio_Uni;
        rlutil::locate(26,c+7);
        cout<<"STOCK: "<<Stock;
    }


}

bool Articulo::leerdeDisco(int pos)
{
    FILE *pArticulo;
    pArticulo=fopen("articulo.lgg", "rb");

    if(pArticulo==NULL)
    {
        return false;
    }
    fseek(pArticulo, pos*sizeof(Articulo), 0);
    bool leyo=fread(this,sizeof(Articulo),1,pArticulo);

    fclose(pArticulo);
    return leyo;
}

int Ultima_Pos(int t)
{
    Articulo reg;
    FILE *pArticulo;
    pArticulo=fopen("articulo.lgg", "rb");
    if(pArticulo==NULL)
    {
        return -2;
    }
    fseek(pArticulo, -sizeof reg, 2);
    reg.setID(t);
    fwrite(&reg, sizeof reg, 1, pArticulo);
    fclose(pArticulo);
    return reg.getID();
}

int cantID()
{
    int c=1;
    Articulo reg;
    FILE *pArticulo;
    pArticulo=fopen("articulo.lgg", "rb");
    if(pArticulo==NULL)
    {
        return -2;
    }
    while(fread(&reg, sizeof reg, 1, pArticulo)==1)
    {
        c++;
    }

    fclose(pArticulo);
    return c;
}

bool Agregar_Articulo()
{
    Articulo reg;
    int aux, extra;
    FILE *pArticulo;
    pArticulo=fopen("articulo.lgg", "ab");
    if(pArticulo==NULL)
    {
        return false;
    }
    aux=cantID();
    extra=Ultima_Pos(aux);
    reg.setID(extra);
    reg.Cargar();

    bool escribio;
    escribio=fwrite(&reg, sizeof reg, 1, pArticulo);
    fclose(pArticulo);
    return escribio;
}




bool Listar_Articulos()
{
    Articulo reg;
    FILE *pArticulo;
    int c=0;
    pArticulo=fopen("articulo.lgg", "rb");
    if(pArticulo==NULL)
    {
        return false;
    }
        recuadro(1,1, 88,2,LETRA,FONDO);
    rlutil::locate(37,2);
    cout<<"LISTAR ARTICULOS";
    /// MAÑANA HACER FUNCION QUE CONTENGA SOLO EL BORDE DE ARRIBA
    while(fread(&reg, sizeof reg, 1, pArticulo)==1)
    {
        if(reg.getEstado()==true){
    c++;
    if(c>1){
    c=c+5;
    }
        reg.Mostrar(c);
        }
    }
    fclose(pArticulo);
    return true;
}


bool Listar_Articulos_ID()
{
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    cls();
    Articulo reg;
    int ide, comp;
    FILE *pArticulo;
    pArticulo=fopen("articulo.lgg", "rb");
    if(pArticulo==NULL)
    {
        return false;
    }
    recuadro(20,POSMENUY, 40,2,LETRA,FONDO);
    locate(21,11);
    cout<<"INGRESE ID A BUSCAR: ";
    cin>>ide;
    comp=0;
    while(fread(&reg, sizeof reg, 1, pArticulo)==1)
    {
        if(ide==reg.getID())
        {
        comp++;
        reg.Mostrar(0);
        }

    }
    if(comp==0){
        rlutil::setBackgroundColor(COLOR_PANTALLA);
        cls();
        hidecursor();
        recuadro(20,POSMENUY-5, 40,2,LETRA,FONDO);
    locate(32,POSMENUY-4);
    cout<<"NO EXISTE LA ID";
    return false;
    }
    fclose(pArticulo);
    return true;
}

int Buscar_Precio()
{
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    cls();
    Articulo reg;
    int ide, c=0, aux;
    FILE *pArticulo;
    pArticulo=fopen("articulo.lgg", "rb+");
    if(pArticulo==NULL)
    {
        return -1;
    }
    recuadro(POSMENUX-3,POSMENUY, 40,2,LETRA,FONDO);
    locate(POSMENUX-2,POSMENUY+1);
    cout<<"INGRESE ID A BUSCAR: ";
    cin>>ide;
    while(fread(&reg, sizeof reg, 1, pArticulo)==1)
    {
        c++;
        if(ide==reg.getID())
        {
            aux=c;
            return aux;
        }
    }

    fclose(pArticulo);
    return -2;
}

Articulo leerRegistro(int pos)
{
    Articulo reg;
    FILE *pArticulo;
    pArticulo=fopen("articulo.lgg", "rb");
    if(pArticulo==NULL)
    {
        return -2;
    }
    fseek(pArticulo, pos*sizeof reg, 0);
    fread(&reg,sizeof reg,1,pArticulo);
    fclose(pArticulo);
    return reg;
}


bool Modificar_Precio()
{
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    cls();
    int posi, aux;
    float Price;
    Articulo reg;
    FILE *pArticulo;
    pArticulo=fopen("articulo.lgg", "rb+");
    if(pArticulo==NULL)
    {
        return false;
    }
    posi=Buscar_Precio();
    if(posi<0)
    {
        return false;
    }
    aux=posi-1;
    reg=leerRegistro(aux);
    recuadro(POSMENUX-3,POSMENUY, 40,2,LETRA,FONDO);
    locate(POSMENUX-2,POSMENUY+1);
    cout<< "Ingrese un nuevo precio: ";
    cin>>Price;
    reg.setPrecio_Uni(Price);
    fseek(pArticulo, aux*sizeof reg, 0);
    bool escribio=fwrite(&reg,sizeof reg,1,pArticulo);
    fclose(pArticulo);
    return escribio;
}


bool Modificar_Reg()
{
    int posi, aux;
    Articulo reg;
    FILE *pArticulo;
    pArticulo=fopen("articulo.lgg", "rb+");
    if(pArticulo==NULL)
    {
        return false;
    }
    posi=Buscar_Precio();
    if(posi<0)
    {
        return false;
    }
    aux=posi-1;
    reg=leerRegistro(aux);
    reg.setEstado(0);
    fseek(pArticulo, aux*sizeof reg, 0);
    bool escribio=fwrite(&reg,sizeof reg,1,pArticulo);
    fclose(pArticulo);
    return escribio;
}

int Baja_Logica()
{
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    cls();
    FILE *pArticulo;
    Articulo reg;
    int escribio, ide;
    pArticulo=fopen("articulo.lgg", "rb+");
    if(pArticulo==NULL)
    {
        return -2;
    }
    recuadro(POSMENUX,POSMENUY, 30,2,LETRA,FONDO);
    locate(POSMENUX+1,POSMENUY+1);
    cout<<"INGRESE ID A ELIMINAR: ";
    cin>>ide;
    while(fread(&reg, sizeof reg, 1, pArticulo)==1)
    {
        if(reg.getID()==ide)
        {
            reg.setEstado(0);
            fseek(pArticulo, ftell(pArticulo)-sizeof reg, 0);
            escribio=fwrite(&reg, sizeof reg, 1, pArticulo);
            fclose(pArticulo);
            return escribio;
        }
    }
    fclose(pArticulo);
    return -1;
}


#endif // CLASE_ARTICULO_H_INCLUDED
