#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo con el listado de grupos a eliminar..."
   exit 1
fi

# Del archivo con el listado de usuarios a eliminar:
# Este es el formato:
# ejemplo
#    |   
#    f1  
#$f1 = nombreGrupo

eliminarGrupo(){
	#echo "----> Eliminar Grupos <----"
	eval nombreGrupo="$1"
	#echo "nombreGrupo 		  = ${nombreGrupo}"
	#echo "-------------------------"
	

	groupdel "${nombreGrupo}"
	if [ $? -eq $SUCCESS ];
	then
		echo "Grupo [${nombreGrupo}] eliminado correctamente..."
	else
		echo "Grupo [${nombreGrupo}] No se pudo eliminar..."
	fi
}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"	
done < ${file}

exit 0
