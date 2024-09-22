TRABAJO PARCIAL ALGORITMOS UPC

## Enunciado
   
En este videojuego, el jugador tomará el rol de un "Guardián del Medio Ambiente" cuya misión es
restaurar el equilibrio natural de un ecosistema que ha sido dañado por la contaminación y la
deforestación.

El jugador debe moverse por un mapa (en consola) y recoger recursos como agua, plantas
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


## Elaboración del videojuego

El equipo de trabajo debe elegir un objetivo centrado
en la recolección y gestión de recursos naturales, con el propósito de restaurar el equilibrio
ambiental en un ecosistema afectado por la contaminación. La secuencia de inicio a fin deberá
ser diseñada por cada equipo, considerando las dinámicas de recolección de recursos, manejo de
la contaminación y reforestación. Para ello, el equipo de trabajo debe tener en cuenta un
conjunto de requisitos establecidos, que guiarán el desarrollo del videojuego y asegurarán la
correcta implementación de las mecánicas ambientales.

## Requisitos del videojuego
A continuación, se mostrarán todos los requisitos necesarios para el desarrollo del videojuego.
Misión
- Restaurar el ecosistema recolectando y gestionando recursos naturales (agua, semillas,
residuos reciclables) para reforestar el terreno afectado por la contaminación.
- El objetivo es reforestar al menos el 70% del mapa antes de que se acaben los recursos
o el tiempo.
- El equipo de trabajo deberá diseñar el mapa y distribuir los recursos estratégicamente.
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

### Recursos
Los recursos disponibles incluyen:
- Agua: Representada por "~", necesaria para reforestar.
- Semillas: Representadas por "*", usadas para plantar árboles.
- Residuos reciclables: Representados por "#", que el jugador debe recoger para limpiar el
ambiente.
- El jugador debe gestionar estos recursos de forma efectiva para lograr el objetivo del
juego.

### Aliados
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



## Instrucciones para la entrega del Trabajo Parcial terminado
Enviar un archivo ZIP: TP_CODIGO_ALUMNO.ZIP
Este archivo debe contener la carpeta con:
▪ Código fuente de la aplicación
▪ Archivo de diagrama de clases en donde podrá usar: StarUML, LucidChart, Draw.io, etc.. en
formato: PDF.
▪ Informe del proyecto según el formato indicado.
