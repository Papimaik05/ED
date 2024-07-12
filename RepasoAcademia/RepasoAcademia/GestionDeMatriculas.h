// PON AQUÍ TU NOMBRE Y APELLIDOS, ASÍ COMO EL NÚMERO DE TU DOCUMENTO IDENTIFICATIVO
// NOMBRE:
// APELLIDOS: 
// DNI / NIE:

#include <string>
#include "lista.h"
#include "DiccionarioHash.h"

using namespace std;

class ECursoYaExiste {};
class EEstudianteYaRegistrado {};
class ESolicitud {};
class EEstudianteNoExiste {};
class ENoHaySolicitudes {};
class ECursoNoExiste {};


typedef string tCurso;
typedef string tEstudiante;

/* La operación 'estudiantes_en_curso'
   devuelve una lista de objetos de esta
   clase. El atributo 'estudiante' de esta clase
   contendrá el identificador del estudiante, y
   el atributo 'num_matricula' su número de
   matricula. */
class DatosEstudiante {
public:
    tEstudiante estudiante;
    unsigned int num_matricula;
    DatosEstudiante(tEstudiante estudiante, int num_matricula) :
        estudiante(estudiante), num_matricula(num_matricula) {};
};

/* La operación 'atiende_solicitud'
   devuelve un objeto de esta clase.
   El atributo 'estudiante' contendrá el
   identificador del estudiante atendido,
   el atributo 'curso' el identificador del
   curso solicitado, y el campo
   'aceptado' el resultado de
   la solicitud (si es 'true',
   la matrícula solicitada se habrá realizado,
   y si es 'false', la matrícula solicitada
   se habrá desestimado -no se habrá realizado
  */
class ResultadoSolicitud {
public:
    ResultadoSolicitud(tEstudiante estudiante, tCurso curso, bool aceptada) :
        estudiante(estudiante), curso(curso), aceptada(aceptada) {}
    tEstudiante estudiante;
    tCurso curso;
    bool aceptada;
};

class InfoCurso {
public:
    InfoCurso(int nplazas, Lista<tEstudiante> estudiantes, int contador);
    Lista<tEstudiante> estudiantes()const;
    int plazas()const;
    int contador()const;

private:
    int _nplazas;
    int _contador;
    Lista<tEstudiante> _estudiantesCurso;
};

typedef   Lista<tEstudiante>::Iterator Posicion;
typedef   Lista<pair<tEstudiante, tCurso>>::Iterator PosicionS;

class InfoEstudiante {
    public:
        InfoEstudiante(tCurso Curs, Posicion pos,PosicionS s);
        Posicion posicion() const;
        PosicionS posicionS() const;
        //bool estaMatriculado()const;
        tCurso curso()const;
    private:
    //bool _matriculado;
    Posicion _posicion;
    PosicionS _posicionS;
    tCurso _curso;
};

class GestionDeMatriculas {
public:
    GestionDeMatriculas();
    void registra_curso(const tCurso& curso, unsigned int plazas);
    void registra_estudiante(const tEstudiante& estudiante);
    void registra_solicitud(const tEstudiante& estudiante, const tCurso& curso);
    void cancela_solicitud(const tEstudiante& estudiante);
    ResultadoSolicitud atiende_solicitud();
    Lista<DatosEstudiante> estudiantes_en_curso(const tCurso& curso) const;
private:
    DiccionarioHash<tCurso, InfoCurso> _diccCurso;
    DiccionarioHash<tEstudiante, InfoEstudiante> _diccEstudiante;
    Lista<pair<tEstudiante, tCurso>> _solicitudes;
    // Incluir aquí los detalles relativos a la representación

};
