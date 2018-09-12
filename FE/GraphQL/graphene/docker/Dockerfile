FROM python:3.6.6-slim-stretch

EXPOSE 80

# create app directory
RUN mkdir /app
WORKDIR /app

COPY . /tmp/

# Install pypi
RUN pip3 install --upgrade pip
RUN pip3 install --default-timeout=100 -r /tmp/requirements.txt 

# Set Timezone
RUN ln -sf /usr/share/zoneinfo/Asia/Seoul /etc/localtime~

CMD bash

