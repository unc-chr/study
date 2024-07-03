#!/bin/bash

#================================================================
#   Copyright (C) 2024 Goldman Ltd. All rights reserved.
#   
#   File：sync.sh
#   Author：leekaihua
#   Date：20240701
#   Brife：
#
#================================================================

function deploy_all {
    deploy_myexception;
}

function deploy_myexception {
    sudo cp my_exception.h /usr/local/include/lee/exception/
    sudo cp libmyexception.so /usr/local/mylib/
}

function help {
    echo "attention: use shell like this"
    echo "Usage: sh/bash $0 [module_name]"  
    echo "Available modules: myexception"
}

module=$1
if [ -z "${module}" ];then
    help;
    exit;
fi

if [ "${module}" == "myexception" ];then
    deploy_myexception;
else
    help
fi
