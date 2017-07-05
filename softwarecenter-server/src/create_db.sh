#!/bin/bash  
if [ $UID -ne 0 ];then
	exec sudo $0 $@
else
	mysql -uroot < create_db.sql
	if [ $? -eq 0 ]; then  
		echo "Create Datebase Success!"  
	fi  
fi
