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
   echo "Debe indicar el archivo del listado con Nombres de Usuario a ingresar..."
   exit 1
fi


crearUsuario(){
	#echo "----> Crear Usuario <----"
	eval username="$1" #nombre de usuario 
	eval password="$2" #contraseña
	eval user_id="$3" #id de uduario
	eval group_id="$4" #id del grupo creado
	eval home_directory="$6" #diretorio home donde se creara el usuario
	eval comand_shell="$7" #acceso a los servicios del sistema operativo
	
	if grep -q ${group_id} /etc/group
	then
		echo "Grupo"${group_id}" Existente"
	#verificamos que el grupo este existente en nuestro ordenador
	if grep -q ${username} /etc/passwd
	then 	
		echo "Usuario Existente"
		echo "El Usuario "${username}" ya esta agregado Exitosamente"
		#en caso de que ya este agregado el Usuario nos dice que usuario existente y cual es
	else
		echo "El Usuario: "${username}" fue agregado Exitosamente"
		echo "Contrsaeña de usuario: " ${password}
		# nos menciona que usurio fue agregado y con que contraseña 
	
	useradd -u "${user_id}" -c "${user_id_info}" -m -d "${home_directory}" "${username}" -p "${password}" -g "${group_id}" -s "${comand_shell}" 
		
		echo "$username:$password" | chpasswd --md5 
		chage -d 0 "${username}" #permite cambiar la contraseña del usuario cuando iniciamos sesiòn 
	fi
	#agregamos el usuario y contraseña 
else
		echo "El Usuario "${username}" no pudo ser agregado Exitosamente"
		echo "Grupo "${group_id}" no Existente"
	fi
	#en caso de que el grupo no exista mandamos dichos mensajes en pantalla 
}

while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do
 
    crearUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"
   
done < ${file}

exit 
