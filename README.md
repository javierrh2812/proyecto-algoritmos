TRABAJO PARCIAL ALGORITMOS UPC

4. Enunciado
En este videojuego, el jugador tomará el rol de un "Guardián del Medio Ambiente" cuya misión es
restaurar el equilibrio natural de un ecosistema que ha sido dañado por la contaminación y la
deforestación. El jugador debe moverse por un mapa (en consola) y recoger recursos como agua, plantas
y residuos reciclables, con el objetivo de limpiar el ambiente y reforestar la zona. El éxito del jugador
dependerá de su capacidad para gestionar estos recursos de manera efectiva y evitar que la
contaminación siga expandiéndose.
El videojuego se desarrollará en un entorno en el que el jugador tendrá que tomar decisiones rápidas y
estratégicas para restaurar el medio ambiente. A medida que avance, encontrará desafíos como evitar
fuentes de contaminación, gestionar correctamente los recursos recolectados y enfrentar el crecimiento
incontrolado de desechos.
Se debe tener en cuenta que los juegos son desarrollados en consola y aplicando el paradigma
de Programación Orientado a Objetos (POO) donde emplee polimorfismo, herencia, sobrecarga
de métodos, no se puede utilizar imágenes para este Trabajo Parcial.
Ejemplo de consola de videojuego
5. Elaboración del videojuego
En base a la información de la sección 4, el equipo de trabajo debe elegir un objetivo centrado
en la recolección y gestión de recursos naturales, con el propósito de restaurar el equilibrio
ambiental en un ecosistema afectado por la contaminación. La secuencia de inicio a fin deberá
ser diseñada por cada equipo, considerando las dinámicas de recolección de recursos, manejo de
la contaminación y reforestación. Para ello, el equipo de trabajo debe tener en cuenta un
conjunto de requisitos establecidos, que guiarán el desarrollo del videojuego y asegurarán la
correcta implementación de las mecánicas ambientales.
6. Requisitos del videojuego
A continuación, se mostrarán todos los requisitos necesarios para el desarrollo del videojuego.
Misión
• Restaurar el ecosistema recolectando y gestionando recursos naturales (agua, semillas,
residuos reciclables) para reforestar el terreno afectado por la contaminación.
• El objetivo es reforestar al menos el 70% del mapa antes de que se acaben los recursos
o el tiempo.
• El equipo de trabajo deberá diseñar el mapa y distribuir los recursos estratégicamente.
Consola
• El videojuego debe desarrollarse en consola de texto (pantalla negra).
• El equipo debe representar los recursos, personajes y elementos del juego usando
caracteres ASCII.
• El videojuego debe ser claro, intuitivo y amigable para el usuario, con una coherencia
entre los símbolos elegidos y el tema ambiental seleccionado.
• El mapa estará representado como una cuadrícula (ejemplo: 20x20).
Personaje principal
• El "Guardián del Medio Ambiente" es el personaje principal, encargado de recolectar
recursos y reforestar el terreno.
• Puede moverse por el mapa utilizando las teclas de dirección.
• Está representado por un carácter ASCII (ejemplo: "@" para el jugador).
• Tendrá un número limitado de vidas o energía que puede perder si colisiona con áreas
contaminadas o enemigos.
Recursos
Los recursos disponibles incluyen:
• Agua: Representada por "~", necesaria para reforestar.
• Semillas: Representadas por "*", usadas para plantar árboles.
• Residuos reciclables: Representados por "#", que el jugador debe recoger para limpiar el
ambiente.
• El jugador debe gestionar estos recursos de forma efectiva para lograr el objetivo del
juego.
Aliados
• No se requiere la presencia de aliados en este juego, pero el equipo de desarrollo puede
optar por incluir personajes que ayuden al jugador proporcionándole recursos
adicionales o información estratégica.
Enemigos
• Las fuentes de contaminación son los enemigos que se expanden a lo largo del mapa si
no se controlan.
• Están representadas por "X", y al colisionar con ellas, el jugador perderá una vida o
energía.
• El equipo puede elegir la cantidad de enemigos o fuentes de contaminación que se
expanden en el mapa.
• El jugador debe eliminar la contaminación plantando árboles o utilizando residuos
reciclables.
Dinámica del juego
• El jugador debe recolectar suficientes recursos para poder plantar árboles y limpiar
el ambiente antes de que el tiempo o sus vidas se agoten.
• Cuando el jugador logre reforestar el 70% del mapa, se mostrará un mensaje de
"GANASTE".
• Si las vidas del jugador llegan a 0 o no consigue suficientes recursos para reforestar el
terreno, se mostrará un mensaje de "PERDISTE".
• Mensaje de Perdiste (“Game Over”) cuando se cumpla la condición de derrota.
Diagrama de clases UML
▪ Desarrollar el diagrama de clases UML de todas las clases, incluyendo atributos, métodos
y relaciones entre clases, que se utilizarán en el videojuego.
7. Instrucciones para la entrega del Trabajo Parcial
El Trabajo Parcial será entregado de forma individual en el Aula Virtual. Dicha entrega se realizará
hasta las 23:30 horas del domingo 22 de septiembre de 2024. No se aceptará ningún Trabajo
Parcial por correo electrónico.
El plazo es impostergable y por ningún motivo y/o circunstancia se recibirán trabajos fuera de la
fecha y hora indicada con antelación. El Trabajo Parcial se realiza en equipo de trabajo (definido
previamente con el docente de la sección), si un equipo de trabajo no presenta el Trabajo Parcial
de acuerdo con el cronograma de entregas establecido por el docente a cargo de la sección,
recibirá la nota de cero (00) correspondiente.
8. De la calificación
El docente a cargo de la sección tiene la autonomía para solicitar a cada estudiante que
demuestre el conocimiento del código de programación que presenta. Asimismo, tiene la
potestad de penalizar con puntos en contra si lo considera pertinente.
9. Falta de probidad académica
Estamos seguros de que cada estudiante del equipo de trabajo realizará el Trabajo Parcial, sin
embargo, para evitar cualquier perspicacia, le recomendamos leer sus reglamentos de estudios
y disciplina del estudiante. Las faltas contra la probidad académica, entendida éstas como la falta
de honradez u honestidad académica que se manifiesta ante cualquier acción u omisión que
podría permitir a un alumno salir beneficiado injustamente sobre los resultados de un trabajo
académico y/o evaluación. Constituyen faltas contra la probidad académica las siguientes
conductas:
(i) Intentar o realizar un plagio o copia total o parcial, al rendir una evaluación, ya sea de manera
presencial o virtual, o al presentar un trabajo académico, usando cualquier medio, Internet,
objeto o equipo para tal fin, en forma directa o valiéndose de terceros para ello.
(ii) Alterar, destruir o sustraer una evaluación o trabajo académico antes, durante o después de
haberse rendido o entregado, aunque estuviese pendiente de calificación.
(iii) Presentar como propio el trabajo académico de otra persona o el desarrollado con otras
personas o utilizarlo sin citar o reconocer la fuente original.
(iv) Falsear el trabajo intelectual, citando autores que no existen, refiriéndose a trabajos no
realizados o tergiversando datos presentados como parte de un trabajo académico; o cometer
cualquier otra acción similar que revele falta de honestidad.
(v) Presentar un mismo trabajo, en todo o parte, en la misma u otra asignatura, sin el
consentimiento expreso de los profesores a cargo o director de Carrera.
(vi) Solicitar o recibir clases particulares, individuales o en grupo, remuneradas o no de docentes
de la Universidad, sean o no profesores de las asignaturas en que el participante se encuentre
matriculado, salvo autorización expresa de la Universidad.
(vii) La suplantación de identidad al momento de rendir cualquier evaluación o actividad
académica, ya sea que se trate de una evaluación presencial o virtual.
(viii) El ofrecimiento en venta, la adquisición, acceso indebido y/o divulgación de los contenidos
de cualquier evaluación académica previa a su aplicación.
(ix) Alterar, destruir o sustraer listas, registros de notas, calificaciones, certificados constancias
y/o documentos académicos.
(x) Encargar u ofrecer el desarrollo de las evaluaciones online que aplica la UPC.
(xi) Mentir dolosamente sobre el grado, nivel académico y/o nivel de inglés que se ha logrado en
la UPC.
(xii) Promover o divulgar información para acceder a beneficios y/o métodos que permitan
generar ventaja en una evaluación, a través de cualquier medio.
Instrucciones para la entrega del Trabajo Parcial terminado
Enviar un archivo ZIP: TP_CODIGO_ALUMNO.ZIP
Este archivo debe contener la carpeta con:
▪ Código fuente de la aplicación
▪ Archivo de diagrama de clases en donde podrá usar: StarUML, LucidChart, Draw.io, etc.. en
formato: PDF.
▪ Informe del proyecto según el formato indicado.
