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
    deploy_allocator;
    deploy_vector;
    deploy_string;
    deploy_queue;
}

function deploy_allocator {
    sudo cp allocator.h /usr/local/include/lee/stl/
}

function deploy_vector {
    sudo cp vector.h /usr/local/include/lee/stl/
}

function deploy_string {
    sudo cp string.h /usr/local/include/lee/stl/
}

function deploy_queue {
    sudo cp queue.h /usr/local/include/lee/stl/
}

function help {
    echo "attention: use shell like this"
    echo "Usage: $0 [module_name]"  
    echo "Available modules: vector, allocator, string, queue"
}

module=$1
if [ -z "${module}" ];then
    help;
    exit;
fi

if [ ${module} == "vector" ];then
    deploy_vector;
elif [ ${module} == "allocator" ];then
    deploy_allocator;
elif [ "${module}" == "string" ];then
    deploy_string;
elif [ "${module}" == "queue" ];then
    deploy_queue;
else
    help
fi