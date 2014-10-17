#!/bin/bash
#test if server is allowing sslv3 connection

for host in "$@"; do
    host_=$(echo $host|awk -F ':' '{print $1}')
    port_=$(echo $host|awk -F ':' '{print $2}')
    echo | timeout 3 openssl s_client -connect $host_:$port_ >/dev/null 2>&1;
    if [[ $? != 0 ]]; then 
        echo "UNKNOWN: $host timeout or connection error";
    else
        cipher=`echo | openssl s_client -connect $host_:$port_ -ssl3 2>&1 | grep "Cipher.*:" | awk -F':' '{print $2}' | tr -d ' '`
        if [ "${cipher}" == '0000' ] || [ "$cipher" == "(NONE)" ]; then
            echo "OK: $host Not vulnerable" ;
        else
            echo "FAIL:  $host vulnerable; sslv3 connection accepted ( $cipher )";
        fi
    fi
done
