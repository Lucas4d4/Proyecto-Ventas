#ifndef CLASE_CLIENTE_H_INCLUDED
#define CLASE_CLIENTE_H_INCLUDED

class Fecha
{
private:
    int Dia, Mes, Anio;
public:
    ///sets
    void setDia(int d)
    {
        Dia=d;
    }
    void setMes(int m)
    {
        Mes=m;
    }
    void setAnio(int a)
    {
        Anio=a;
    }
    ///gets
    int getDia()
    {
        return Dia;
    }
    int getMes()
    {
        return Mes;
    }
    int getAnio()
    {
        return Anio;
    }
    ///Prototipos
    void Cargar(int x, int y);
    void Mostrar();
};

void Fecha::Cargar(int x, int y)/// CAMBIAR SI NO GUSTA, NP
{
    int c=0, c2=0, c3=0;
    rlutil::locate(x, y);
    cout<<"DIA: ";
    cin>>Dia;
        while(Dia<1||Dia>31){
                c++;
            rlutil::locate(x, y+c);
        rlutil::setBackgroundColor(12);
        cout<<"ERROR Nº DE DIA INVALIDO";
        c++;
        rlutil::locate(x, y+c);
        rlutil::setBackgroundColor(FONDO);
        cout<<"INGRESE DIA: ";
        cin>>Dia;
    }
    c=c+1;
    rlutil::locate(x, y+c);
    cout<<"MES: ";
    cin>>Mes;
       while(Mes<1||Mes>31){
            c++;
        rlutil::locate(x, y+c);
        rlutil::setBackgroundColor(12);
        cout<<"ERROR Nº DE MES INVALIDO";
        c++;
        rlutil::locate(x, y+c);
        rlutil::setBackgroundColor(FONDO);
        cout<<"INGRESE MES: ";
        cin>>Mes;
    }
    c=c+1;
    rlutil::locate(x, y+c);
    cout<<"ANO: ";
    cin>>Anio;
       while(Anio<1998){
        c++;
        rlutil::locate(x, y+c);
        rlutil::setBackgroundColor(12);
        cout<<"ERROR Nº DE ANIO INVALIDO";
        c++;
        rlutil::locate(x, y+c);
        rlutil::setBackgroundColor(FONDO);
        cout<<"INGRESE ANIO: ";
        cin>>Anio;
    }
}

void Fecha::Mostrar()
{
    cout<<Dia<<"/"<<Mes<<"/"<<Anio;
}

class Cliente
{
private:
    int DNI, Telefono;
    char Nombre[15], Apellido[20], Email[30];
    Fecha Fnacimiento;
    bool Estado;

public:
    Cliente(int dn=0, int tel=0)
    {
        DNI=dn;
        Telefono=tel;
    }
    Cliente(char *nom, char *ape, char*em)
    {
        strcpy(nom, "NINGUNO");
        strcpy(ape, "NINGUNO");
        strcpy(em, "NINGUNO");
        strcpy(Nombre, nom);
        strcpy(Apellido, ape);
        strcpy(Email, em);
    }
    Cliente(Fecha fn)
    {
        fn.setDia(0);
        fn.setMes(0);
        fn.setAnio(0000);
        Fnacimiento=fn;
    }
    ///sets
    void setDNI(int dn)
    {
        DNI=dn;
    }
    void setNombre(char *nom)
    {
        strcpy(Nombre, nom);
    }
    void setApellido(char *ape)
    {
        strcpy(Apellido, ape);
    }
    void setEmail(char *em)
    {
        strcpy(Email, em);
    }
    void setFnacimiento(Fecha fn)
    {
        Fnacimiento=fn;
    }
    void setTelefono(int tel)
    {
        Telefono=tel;
    }
    void setEstado(bool es)
    {
        Estado=es;
    }
    ///gets
    int getDNI()
    {
        return DNI;
    }
    const char *getNombre()
    {
        return Nombre;
    }
    const char *getApellido()
    {
        return Apellido;
    }
    const char *getEmail()
    {
        return Email;
    }
    Fecha getFnacimiento()
    {
        return Fnacimiento;
    }
    int getTelefono()
    {
        return Telefono;
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

int Vect_pos(int extra)
{
    Cliente reg;
    FILE *pCliente;
    pCliente=fopen("cliente.lgg", "rb");
    if(pCliente==NULL)
    {
        return -1;
    }
    while(fread(&reg, sizeof reg, 1, pCliente)==1)
    {
    if(extra==reg.getDNI()){
            return 0;
    }
    }


    fclose(pCliente);
    return -2;
}


void Cliente::Cargar()
{   int extra, c=0;
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    cls();
    recuadro(1,1, 88,2,LETRA,FONDO);
    rlutil::locate(37,2);
    cout<<"AGREGAR CLIENTE";
    recuadro(1,4,88, 25, LETRA, FONDO);
    rlutil::locate(26, 5);
    cout<<"INGRESE DNI: ";
    cin>>DNI;
    extra=Vect_pos(DNI);
    while(extra==0){
            c++;
        rlutil::locate(26, 5+c);
        rlutil::setBackgroundColor(12);
        cout<<"ERROR DNI REPETIDO";
        c++;
        rlutil::locate(26, 5+c);
        rlutil::setBackgroundColor(FONDO);
        cout<<"INGRESE DNI: ";
        cin>>DNI;
        extra=Vect_pos(DNI);
    }
    rlutil::locate(26, 5+c+1);
    cout<<"INGRESE NOMBRE: ";
    cin>>Nombre;
        rlutil::locate(26, 5+c+2);
    cout<<"INGRESE APELLIDO: ";
    cin>>Apellido;
        rlutil::locate(26, 5+c+3);
    cout<<"INGRESE EMAIL: ";
    cin>>Email;
    rlutil::locate(26, 5+c+4);
    cout<<"INGRESE TELEFONO: ";
    cin>>Telefono;
    rlutil::locate(26, 5+c+5);
    c=c+5+6;
    cout<<"INGRESE FECHA: ";
    Fnacimiento.Cargar(26,c);
    Estado=true;
}

void Cliente::Mostrar(int c)
{
    if(Estado==true)
    {
        recuadro(1, c+3, 88, 8, LETRA, FONDO);
        rlutil::locate(26,c+4);
        cout<<"DNI: "<<DNI;
        rlutil::locate(26,c+5);
        cout<<"NOMBRE: "<<Nombre;
        rlutil::locate(26,c+6);
        cout<<"APELLIDO: "<<Apellido;
        rlutil::locate(26,c+7);
        cout<<"EMAIL: "<<Email;
        rlutil::locate(26,c+8);
        cout<<"FECHA: ";
        rlutil::locate(26,c+9);
        Fnacimiento.Mostrar();
        rlutil::locate(26,c+10);
        cout<<"TELEFONO: "<<Telefono;
        Estado=true;
    }
}

bool Cliente::leerdeDisco(int pos)
{
    FILE *pCliente;
    pCliente=fopen("cliente.lgg", "rb");

    if(pCliente==NULL)
    {
        return false;
    }
    fseek(pCliente, pos*sizeof(Cliente), 0);
    bool leyo=fread(this,sizeof(Cliente),1,pCliente);

    fclose(pCliente);
    return leyo;
}

int Cantidad_Registro()
{
    Cliente reg;
    int ant=0;
    FILE *pCliente;
    pCliente=fopen("cliente.lgg", "rb");
    if(pCliente==NULL)
    {
        return -2;
    }
    while(fread(&reg, sizeof reg, 1, pCliente)==1)
    {
        ant++;
    }
    fclose(pCliente);
    return ant;
}




bool Fecha_Invalida(Fecha aux)
{
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    cls();
    if(aux.getDia()<1&&aux.getDia()>31)
    {
        if(aux.getMes()<1&&aux.getMes()>12)
        {
            if(aux.getAnio()<1900)
            {
                cout<<"FECHA INVALIDA"<<endl;
                return false;
            }
            else
            {
                cout<<"FECHA INVALIDA"<<endl;
                return false;
            }
        }
        else
        {
            cout<<"FECHA INVALIDA"<<endl;
            return false;
        }
    }
    else
    {
        if(aux.getMes()<1&&aux.getMes()>12)
        {
            if(aux.getAnio()<1900)
            {
                cout<<"FECHA INVALIDA"<<endl;
                return false;
            }
        }
        else
        {
            if(aux.getAnio()<1900)
            {
                cout<<"FECHA INVALIDA"<<endl;
                return false;
            }
        }
    }

    return true;
}


bool Grabar_Cliente()
{
    Cliente reg;
    int ant;
    bool compVec, compFecha;
    FILE *pCliente;
    pCliente=fopen("cliente.lgg", "ab");
    if(pCliente==NULL)
    {
        return false;
    }
    reg.Cargar();
    ant=Cantidad_Registro();
    compVec=Vect_pos(reg.getDNI());
    compFecha=Fecha_Invalida(reg.getFnacimiento());
    if(compVec==false)
    {
        return false;
    }
    if(compFecha==false)
    {
        return false;
    }
    bool escribio;
    escribio=fwrite(&reg, sizeof reg, 1, pCliente);
    fclose(pCliente);
    return escribio;
}

bool Listar_Cliente()
{
    Cliente reg;
    FILE *pCliente;
    int c=0;
    pCliente=fopen("cliente.lgg", "rb");
    if(pCliente==NULL)
    {
        return false;
    }
            recuadro(1,1, 88,2,LETRA,FONDO);
    rlutil::locate(37,2);
    cout<<"LISTAR CLIENTES";
    while(fread(&reg, sizeof reg, 1, pCliente)==1)
    {
        c++;
        if(c>1){
            c=c+8;
        }
        reg.Mostrar(c);
    }
            system("pause > nul");
    fclose(pCliente);
    return true;
}

bool Listar_porDNI()
{
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    cls();
    Cliente reg;
    int idn, comp;
    FILE *pCliente;
    pCliente=fopen("cliente.lgg", "rb");
    if(pCliente==NULL)
    {
        return false;
    }

    recuadro(POSMENUX,POSMENUY, 40,2,LETRA,FONDO);
    locate(POSMENUX+1,POSMENUY+1);
    cout<<"INGRESE DNI A MOSTRAR: ";
    cin>>idn;
    comp=0;
    while(fread(&reg, sizeof reg, 1, pCliente)==1)
    {
        if(idn==reg.getDNI())
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
    locate(31,POSMENUY-4);
    cout<<"NO EXISTE EL DNI";
    return false;
    }
    fclose(pCliente);
    return true;
}

int Buscar_Email()
{
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    cls();
    Cliente reg;
    int c=0, aux;
    char email[30];
    FILE *pCliente;
    pCliente=fopen("cliente.lgg", "rb+");
    if(pCliente==NULL)
    {
        return -1;
    }

    recuadro(POSMENUX-7,POSMENUY, 50,2,LETRA,FONDO);
    locate(POSMENUX-6,POSMENUY+1);
    cout<<"INGRESE EMAIL A BUSCAR: ";
    cin>>email;
    while(fread(&reg, sizeof reg, 1, pCliente)==1)
    {
        c++;
        if(strcmp(reg.getEmail(), email)==0)
        {
            aux=c;
            return aux;
        }
    }

    fclose(pCliente);
    return -2;
}



Cliente leerReg(int pos)
{
    Cliente reg;
    FILE *pCliente;
    pCliente=fopen("cliente.lgg", "rb");
    if(pCliente==NULL)
    {
        return -2;
    }
    fseek(pCliente, pos*sizeof reg, 0);
    fread(&reg,sizeof reg,1,pCliente);
    fclose(pCliente);
    return reg;
}


bool Modificar_Email()
{
    int posi, aux;
    char Email[30];
    Cliente reg;
    FILE *pCliente;
    pCliente=fopen("cliente.lgg", "rb+");
    if(pCliente==NULL)
    {
        return false;
    }
    posi=Buscar_Email();
    if(posi<0)
    {
        return false;
    }
    aux=posi-1;
    reg=leerReg(aux);
    recuadro(POSMENUX-7,POSMENUY, 50,2,LETRA,FONDO);
    locate(POSMENUX-6,POSMENUY+1);
    cout << "Ingrese el nuevo Email: ";
    cin >>Email;
    reg.setEmail(Email);

    fseek(pCliente, aux*sizeof reg, 0);
    bool escribio=fwrite(&reg,sizeof reg,1,pCliente);
    fclose(pCliente);
    return escribio;
}

int Bajas_Logica()
{
    rlutil::setBackgroundColor(COLOR_PANTALLA);
    cls();
    FILE *pCliente;
    Cliente reg;
    int escribio, idn;
    pCliente=fopen("cliente.lgg", "rb+");
    if(pCliente==NULL)
    {
        return -2;
    }

    recuadro(POSMENUX-7,POSMENUY, 50,2,LETRA,FONDO);
    locate(POSMENUX-6,POSMENUY+1);
    cout<<"INGRESE DNI A ELIMINAR: ";
    cin>>idn;
    system("pause > nul");
    while(fread(&reg, sizeof reg, 1, pCliente)==1)
    {
        if(reg.getDNI()==idn)
        {
            reg.setEstado(0);
            fseek(pCliente, ftell(pCliente)-sizeof reg, 0);
            escribio=fwrite(&reg, sizeof reg, 1, pCliente);
            fclose(pCliente);
            return escribio;
        }
    }
    fclose(pCliente);
    return -1;
}


#endif // CLASE_CLIENTE_H_INCLUDED
