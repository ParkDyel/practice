#!/bin/bash
cd ../
docker-compose build base_nginx_uwsgi
docker-compose up -d flask-app